//
// This is a Lattice-Boltzmann solution to the 1D heat equation,
// âˆ‚Ï/âˆ‚t = D âˆ‚^2Ï/âˆ‚x^2
//
// In terms of the program parameters, D = (lambda^2/tau)*(SIGMA/(2-2*SIGMA)).
//
// Note that tau and the final time determine iteration count, but otherwise 
// lambda and tau don't affect the computation.  If we rescale sufficiently, 
// the GPU version is way faster than the CPU version.
//
// Also, note that LWS should divide GWS = WIDTH+1, but the node at location
// "WIDTH" is fixed at zero, and so we can use GWS = WIDTH, which is more
// convenient.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glx.h>
#include <unistd.h>
#include <CL/cl.h>
#include <CL/cl_gl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl_ext.h>
#include <CL/cl_platform.h>
#include <CL/opencl.h>
#include "heatflowF16.h"
#include "RGU.h"

// OpenCL vars
cl_command_queue mycq;
cl_kernel mykrn_update;
cl_context mycontext;
cl_program myprogram;
cl_mem focl[2], omega_ocl;

double f[2][WIDTH+2][DIRECTIONS];	// two buffers for ping-pong
double omega[DIRECTIONS][DIRECTIONS];	// collision matrix
int ci[DIRECTIONS] = {1, -1};

void load_omega()
{
omega[0][0] = SIGMA - 1.0;
omega[0][1] = 1.0 - SIGMA;
omega[1][0] = 1.0 - SIGMA;
omega[1][1] = SIGMA - 1.0;
}

void init_lattice()
{
int j,k;
// Initial flow is a hat with peak at midpoint (1.0), equal in both directions.
for(j=0;j<=WIDTH/2;j++)
	for(k=0;k<DIRECTIONS;k++){ 
		f[0][j][k] = node(j)/2.0;
		f[1][j][k] = 0.0;
		}
for(j=WIDTH/2;j<=WIDTH;j++)
	for(k=0;k<DIRECTIONS;k++){ 
		f[0][j][k] = 1.0 - node(j)/2.0;
		f[1][j][k] = 0.0;
		}
}

double analytic(double x, double t)
{
int k;
double sign = -1.0;
double sum = 0.0;
double coeff;

for(k=0;k<1000;k++){
	sign *= -1.0;	
	coeff = (2.0*(double)(k)+1.0)*M_PI;
	sum += 8.0*sign*exp(-coeff*coeff*t/4.0)*sin(coeff*x/2.0)/(coeff*coeff);
	}
return(sum);
}

void dump()
{
int j;
double avalue, rho, err;
	
printf("x\t LB\t  exact\t   difference\n");
for(j=0;j<=WIDTH;j+=2){
	avalue = analytic(node(j),FINAL_TIME);
	rho = (double)(f[0][j][0] + f[0][j][1]);
	err = fabs(rho - avalue);
	printf("%f %f %f %f\n",node(j),rho,avalue,err);
	}
}

void run_updates()
{
// We need lws | gws, as always. 
size_t gws[1] = {WIDTH}; 
size_t lws[1] = {128}; 
int err, from = 0;
cl_event wait[1];
double t;

for(t=0.0;t<FINAL_TIME;t+=tau,from = 1-from){
	clSetKernelArg(mykrn_update,0,sizeof(cl_mem),(void *)&focl[from]);
	clSetKernelArg(mykrn_update,1,sizeof(cl_mem),(void *)&focl[1-from]);
	clEnqueueNDRangeKernel(mycq,mykrn_update,1,NULL,gws,lws,0,0,&wait[0]);
	clWaitForEvents(1,wait);
	}
clEnqueueReadBuffer(mycq,focl[from],CL_TRUE,0,SIZE,f[0][0],0,NULL,NULL);
clReleaseEvent(wait[0]);
return;
}

void setup_ocl()
{
size_t program_length;
unsigned int gpudevcount;
cl_platform_id myplatform;
cl_device_id *mydevice;
cl_int err;
char* oclsource; 
const char *header; 

err = RGUGetPlatformID(&myplatform);

cl_context_properties props[] = {
      CL_CONTEXT_PLATFORM, (cl_context_properties)myplatform,
      0};

err = clGetDeviceIDs(myplatform,CL_DEVICE_TYPE_GPU,0,NULL,&gpudevcount);
mydevice = new cl_device_id[gpudevcount];
err = clGetDeviceIDs(myplatform,CL_DEVICE_TYPE_GPU,gpudevcount,mydevice,NULL);

mycontext = clCreateContext(props,1,&mydevice[0],NULL,NULL,&err);

mycq = clCreateCommandQueue(mycontext,mydevice[0],0,&err);
header = RGULoadProgSource("heatflowF16.h","",&program_length);
oclsource = RGULoadProgSource("heatflowF16.cl",header,&program_length);
myprogram = clCreateProgramWithSource(mycontext,1,
	(const char **)&oclsource, &program_length, &err);
clBuildProgram(myprogram, 0, NULL, NULL, NULL, NULL);
mykrn_update = clCreateKernel(myprogram, "update", &err);
if(err==CL_SUCCESS) fprintf(stderr,"kernel build ok\n");
else fprintf(stderr,"kernel build err %d\n",err);

focl[0] = clCreateBuffer(mycontext,CL_MEM_READ_WRITE|CL_MEM_COPY_HOST_PTR,
	SIZE,&f[0][0][0],&err);
focl[1] = clCreateBuffer(mycontext,CL_MEM_READ_WRITE|CL_MEM_COPY_HOST_PTR,
	SIZE,&f[1][0][0],&err);
omega_ocl = clCreateBuffer(mycontext,CL_MEM_READ_ONLY|CL_MEM_COPY_HOST_PTR,
	DIRECTIONS*DIRECTIONS*sizeof(double),&omega[0][0],&err);

clSetKernelArg(mykrn_update,2,sizeof(cl_mem),(void *)&omega_ocl);
}

void cleanup()
{
clReleaseMemObject(focl[0]);
clReleaseMemObject(focl[1]);
clReleaseMemObject(omega_ocl);
clReleaseCommandQueue(mycq);
clReleaseContext(mycontext);
clReleaseKernel(mykrn_update);
clReleaseProgram(myprogram);
}

int main(int argc, char **argv)
{
init_lattice();
load_omega();
setup_ocl();
run_updates();
dump();
cleanup();
return 0;
}
