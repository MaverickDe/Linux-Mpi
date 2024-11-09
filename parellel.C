// ParallelSumMPI.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mydetails.h" 
#include <mpi.h>

int main(int argc, char *argv[]) {




      printf(Name); 
      printf("This total core used is  4  \n");



    // // Print the current date and time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
           local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
           local->tm_hour, local->tm_min, local->tm_sec);

    // Measure the start time of program execution
    clock_t start = clock();

 
    MPI_Init(&argc, &argv);
    
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int num_elements;
    int *array = NULL;
 
    if (world_rank == 0) {
        srand(time(0));
        num_elements = 50000 + rand() % 10001;


        array = (int*) malloc(num_elements * sizeof(int));
        for (int i = 0; i < num_elements; i++) {
            array[i] = i + 1;
        }
    }
    
 
    MPI_Bcast(&num_elements, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int elements_per_proc = num_elements / world_size;
    int *sub_array = (int*) malloc(elements_per_proc * sizeof(int));

    MPI_Scatter(array, elements_per_proc, MPI_INT, sub_array, elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    long long local_sum = 0;
    for (int i = 0; i < elements_per_proc; i++) {
        local_sum += sub_array[i];
    }

  
    long long global_sum = 0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printf("Parallel Sum: %lld\n", global_sum);
    }

    // Free dynamically allocated memory
    free(sub_array);
    if (world_rank == 0) {
        free(array);
    }

    MPI_Finalize();

    clock_t end = clock();
    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Total execution time: %.6f seconds\n", execution_time);



    return 0;



    
}
