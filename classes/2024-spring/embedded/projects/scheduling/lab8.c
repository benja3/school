#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0

#define NUM_TASKS 8
#define SYS_OVERHEAD 0.153
#define TOLERANCE 0.000001

// ALL TIME UNITS IN ms

int main(int argc, char **argv)
{
    double sum;

    // sort by priorities
    double periods[NUM_TASKS] = {10.56, 40.96, 61.44, 100.0, 165.0, 285.0, 350.0, 700.0};
    double runtimes[NUM_TASKS] = {1.30, 4.7, 9.0, 23.0, 38.30, 10.0, 3.0, 2.0};

    // assuming resources can be accessed in parallel
    double max_blocking[NUM_TASKS] = {3.3, 3.3, 9.3, 9.2, 5.2, 5.2, 2.0, 0};

    // RMA algorithm

    printf("i,k,l,result\n");

    for(int i = 1; i <= NUM_TASKS; i++)
        for(int k = 1; k <= i; k++)
            for(int l = 1; l <= floor(periods[i - 1] / periods[k - 1]); l++)
                {
                    sum = 0;

                    for(int j = 1; j <= i - 1; j++)
                        sum += (runtimes[j - 1] + SYS_OVERHEAD) * ceil(l * periods[k - 1] / periods[j - 1]);

                    sum += runtimes[i - 1] + SYS_OVERHEAD + max_blocking[i - 1];

                    if (DEBUG) printf("%f\t%f\n", sum, l * periods[k - 1]);

                    if(sum <= l * periods[k - 1])
                    {
                        if (DEBUG) printf("Successfully scheduled (k = %d, l = %d)\n", k, l);
                        if (!DEBUG) printf("%d,%d,%d,success\n", i, k, l);
                    }
                    else 
                    {
                        if (DEBUG) printf("Failed to schedule (i = %d)\n", i);
                        // if (!DEBUG) printf("%d,%d,%d,failure\n", i, k, l);
                    }
                    
                }
}