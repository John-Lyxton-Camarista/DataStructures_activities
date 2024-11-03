#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 80000 //Change the value of SIZE for the desired number of data

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random number between 0 and 9999
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[SIZE];
    srand(time(0)); // Seed for random number generation

    // Generate random array
    generate_random_array(arr, SIZE);

    // Record start time
    clock_t start_time = clock();

    // Sort array
    selection_sort(arr, SIZE);

    // Record end time
    clock_t end_time = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

    // Print elapsed time
    printf("Elapsed time: %.2f ms\n", elapsed_time);

    return 0;
}
