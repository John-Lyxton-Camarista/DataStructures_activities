#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 80000 //Change the value of SIZE for the desired number of data

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random number between 0 and 9999
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE];
    srand(time(0)); // Seed for random number generation

    // Generate random array
    generate_random_array(arr, SIZE);

    // Record start time
    clock_t start_time = clock();

    // Sort array using insertion sort
    insertion_sort(arr, SIZE);

    // Record end time
    clock_t end_time = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

    // Print elapsed time
    printf("Elapsed time: %.2f ms\n", elapsed_time);

    return 0;
}
