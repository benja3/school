__kernel void update(__global double* from, __global double* to, __constant double* omega)
{
double new_energy;
int k, n, t; 
unsigned int j = get_global_id(0);
int ci[DIRECTIONS] = {1,-1};

for(k=0;k<DIRECTIONS;k++){
	t = j+ci[k];
	if(t<=0 || t>=WIDTH) continue;
	new_energy = from[store(j,k)];
	for(n=0;n<DIRECTIONS;n++){
		new_energy += omega[store(k,n)]*from[store(j,n)];
		}
	to[store(t,k)] = new_energy;
	}
}

