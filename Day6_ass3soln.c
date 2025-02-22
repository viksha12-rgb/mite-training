#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort distances using Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to assign the nearest ambulance
void assignAmbulance(int distances[], int n) {
    // Sort distances
    selectionSort(distances, n);
   
    // Display sorted distances
    printf("Sorted Distances: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", distances[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
   
    // Assign nearest ambulance
    printf("Nearest Ambulance Assigned: Distance %d km\n", distances[0]);
}

int main() {
    int distances[] = {10, 3, 7, 1, 5};
    int n = sizeof(distances) / sizeof(distances[0]);
   
    // Display original distances
    printf("Ambulances (Distance in km): [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", distances[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
   
    // Assign ambulance
    assignAmbulance(distances, n);
   
    return 0;
}
