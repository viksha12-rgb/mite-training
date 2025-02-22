#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
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
void assignAmbulance(int distances[], int n) {
    selectionSort(distances, n);
    printf("Sorted Distances: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", distances[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
    printf("Nearest Ambulance Assigned: Distance %d km\n", distances[0]);
}

int main() {
    int distances[] = {10, 3, 7, 1, 5};
    int n = sizeof(distances) / sizeof(distances[0]);
    printf("Ambulances (Distance in km): [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", distances[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
    assignAmbulance(distances, n);
    return 0;
}
