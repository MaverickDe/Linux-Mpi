#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mydetails.h"

int main() {


          printf(Name);
      printf("This total core used is 4 \n");



    // Print the current date and time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
           local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
           local->tm_hour, local->tm_min, local->tm_sec);

    // Measure the start time of program execution
    clock_t start = clock();
    srand(time(0)); // Seed for random number generation

    // Generate a random number between 50,000 and 60,000 for array size
    int num_elements = 50000 + rand() % 10001;
    int *array = (int*) malloc(num_elements * sizeof(int)); // Allocate memory for the array

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array with values from 1 to num_elements
    for (int i = 0; i < num_elements; i++) {
        array[i] = i + 1;
    }

    // Calculate the sum of all elements
    long long sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += array[i];
    }

    // Output the result
    printf("The sum of all elements in an array of size %d is: %lld\n", num_elements, sum);

    // Free the allocated memory
    free(array);

        clock_t end = clock();
    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Total execution time: %.6f seconds\n", execution_time);



    return 0;
}
