#define DISSAP (0.9f)
#define WHEIGHTSCALE (5.0f)

#define from(i,j,k) from[store(i,j,k)]
#define to(i,j,k) to[store(i,j,k)]
#define omega(i,j) omega[(i)*DIRECTIONS+(j)]

__kernel void update(__global float8* from, __global float8* to, 
	__global int* dist, __global float8* omega)
{
int j = get_global_id(0);
int i = get_global_id(1);
float8 new_density;
int k, n;

for(k=0;k<DIRECTIONS;k++){
	new_density = (float8)(0.0f);
	for(n=0;n<DIRECTIONS;n++) new_density += DISSAP*omega(k,n)*from(i,j,n);
	to[dist(i,j,k)] += (from(i,j,k) + new_density);
	}
for(k=0;k<DIRECTIONS;k++) from(i,j,k) = (float8)(0.0f);
}

__kernel void heights(__global float4* rbuffer, __global float8* to) 
{
int j = get_global_id(0);
int i = get_global_id(1);
int k, n;
float u, v, h;
float8 new_height;

new_height = (float8)(0.0f);
for(n=0;n<DIRECTIONS;n++) new_height += to(i,j,n);
h = new_height.s0 + new_height.s1 + new_height.s2 + new_height.s3 + 
	new_height.s4 + new_height.s5 + new_height.s6 + new_height.s7;
h /= WHEIGHTSCALE;
u = SCALE*(j/(float)(WIDTH-1))-SCALE/2.0f; 
v = SCALE*(i/(float)(LENGTH-1))-SCALE/2.0f; 
rbuffer[i*WIDTH+j] = (float4)(u, h, v, 1.0f);
}

__kernel void normals(__global float4* rbuffer,__global float4* nbuffer) 
{
int j = get_global_id(0);
int i = get_global_id(1);
int ni, si, ei, wi;
float n, s, e, w, nx, ny, nz;

// Get neighbor n, s, e, w heights with torroidal wrap. 
ni = ((i-1)+LENGTH)%LENGTH;
si = ((i+1)+LENGTH)%LENGTH;
ei = ((j+1)+WIDTH)%WIDTH;
wi = ((j-1)+WIDTH)%WIDTH;

n = rbuffer[WIDTH*ni+j].y;
s = rbuffer[WIDTH*si+j].y;
e = rbuffer[WIDTH*i+ei].y;
w = rbuffer[WIDTH*i+wi].y;

// Build approximate normal.
nx = w - e;
ny = 2.0f*SCALE/((float)(WIDTH));
nz = (n - s)*((float)(LENGTH)/(float)(WIDTH));
nbuffer[i*WIDTH+j] = normalize((float4)(nx,ny,nz,0.0f));
}

__kernel void colors(__global float4* rbuffer,float4 lightdir,float4 viewdir,
	__global float4* nbuffer) 
{
const float4 lightwater = (float4)(0.5f,0.8f,0.8f,1.0f);
const float4 darkwater = (float4)(0.0f,0.3f,0.3f,1.0f);
const float4 skycolor = (float4)(0.9f,0.9f,0.9f,1.0f);
const float Fresnel = 0.5f;

int j = get_global_id(0);
int i = get_global_id(1);
float NdotL, mixer;
float4 tnorm, eyen, mycolor;

tnorm = nbuffer[i*WIDTH+j];

// (N o L) is color scale factor; OCL dot uses 4 components, but tnorm.w = 0.0.
// Also, lightdir was normalized and points toward the sun.
NdotL = max(0.0f,dot(tnorm,lightdir));

// If view dir and wave normal are opposite, there's a big effect.
// viewdir was normalized.
mixer = -min(0.0f,dot(viewdir,tnorm));
mycolor = NdotL*(mix(darkwater,lightwater,mixer)+Fresnel*skycolor*
	(pow(1.0f-mixer,5.0f)));
rbuffer[COLOR_OFFSET+WIDTH*i+j] = mycolor;
}

