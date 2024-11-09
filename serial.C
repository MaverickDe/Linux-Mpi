// SerialSum.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mydetails.h"


int main() {


       printf(Name);
      printf("This total core used is  1  \n");



    // Print the current date and time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
           local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
           local->tm_hour, local->tm_min, local->tm_sec);

    // Measure the start time of program execution
    clock_t start = clock();
    srand(time(0));

    // Generate a random number between 50,000 and 60,000 for array size
    int num_elements = 50000 + rand() % 10001;
    int *array = (int*) malloc(num_elements * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array with values from 1 to num_elements
    for (int i = 0; i < num_elements; i++) {
        array[i] = i + 1;
    }

    // Start timer
    clock_t start_time = clock();

    // Calculate the sum of all elements
    long long sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += array[i];
    }

    // End timer
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Serial Sum: %lld\n", sum);
    printf("Time taken in serial computation: %f seconds\n", time_taken);

    free(array);
        clock_t end = clock();
    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Total execution time: %.6f seconds\n", execution_time);


    return 0;
}
