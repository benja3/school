#define DIRECTIONS 2
#define store(row,col) (DIRECTIONS*(row)+(col))
#define WIDTH (2048)
#define FIRST 0.0
#define LAST 2.0
#define FINAL_TIME (0.125)
#define node(ix) (((double)(ix)/(double)(WIDTH))*(LAST - FIRST) + FIRST)
#define lambda (1.0/(1024.0))		// lattice spacing 
#define tau    (lambda*lambda/2.0) 	// time step 
#define SIGMA 0.5
#define SIZE ((WIDTH+2)*DIRECTIONS*sizeof(double))

