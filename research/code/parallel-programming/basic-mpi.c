#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    // printf("Hello world from before MPI_Init\n");

    MPI_Init(&argc, &argv); // initialize MPI environment 

    // get hostname of node
    int name_length = MPI_MAX_PROCESSOR_NAME;
    char proc_name[name_length];
    MPI_Get_processor_name(proc_name, &name_length);
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if(rank == 0)
            printf("Total number of processes: %d\n", size);
        
    printf("Hello world from process %d out of %d\n", rank, size);

    
        

    // MPI_Abort(MPI_COMM_WORLD, 17);
    
    MPI_Finalize();
}