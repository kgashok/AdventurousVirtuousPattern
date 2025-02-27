
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// C equivalent of selection_sort2 function
void selection_sort(int arr[], int n) {
    // STEP 0 - iterate through the array
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        // STEP 1 - update min_idx with index
        // of min value in unsorted arr[i+1:]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // STEP 2 - swap it with element at index 'i'
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
        print_array(arr, n);
    }
}

// Function to generate a random array
void generate_RandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    
    // Fisher-Yates shuffle
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int size = 5;
    int arr[size];
    
    // Generate a random array
    generate_RandomArray(arr, size);
    
    // Print array before sorting
    printf("Before sorting: ");
    print_array(arr, size);
    
    // Sort the array
    selection_sort(arr, size);
    
    // Print array after sorting
    printf("After selection sort: ");
    print_array(arr, size);
    
    return 0;
}
