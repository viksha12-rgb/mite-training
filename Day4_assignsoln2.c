#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef union {
    float daily_rent;
    float total_rent;
} Rent;

typedef struct {
    int car_id;
    char model[50];
    Rent rent;
    int is_total_rent; 
} Car;

void saveToFile(Car cars[], int count) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Car ID, Model, Rent (per day/total)\n");
    for (int i = 0; i < count; i++) {
        if (cars[i].is_total_rent)
            fprintf(file, "%d, %s, Total Rent: ₹%.2f\n", cars[i].car_id, cars[i].model, cars[i].rent.total_rent);
        else
            fprintf(file, "%d, %s, ₹%.2f/day\n", cars[i].car_id, cars[i].model, cars[i].rent.daily_rent);
    }

    fclose(file);
    printf("\nData saved in \"car_rentals.txt\"\n");
}
void updateRent(Car cars[], int count) {
    int car_id, choice;
    float new_rent;
    printf("\nEnter Car ID to update rent: ");
    scanf("%d", &car_id);

    for (int i = 0; i < count; i++) {
        if (cars[i].car_id == car_id) {
            printf("Update (1 - Daily Rent, 2 - Total Rent): ");
            scanf("%d", &choice);
            printf("Enter new rent amount: ");
            scanf("%f", &new_rent);

            if (choice == 1) {
                cars[i].rent.daily_rent = new_rent;
                cars[i].is_total_rent = 0;
            } else {
                cars[i].rent.total_rent = new_rent;
                cars[i].is_total_rent = 1;
            }
            printf("Rent updated successfully!\n");
            saveToFile(cars, count);
            return;
        }
    }
    printf("Car ID not found!\n");
}

int main() {
    int n;
    Car cars[MAX];
    printf("Enter number of cars: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].car_id);
        printf("Model: ");
        scanf(" %[^\n]", cars[i].model);
        printf("Rent Per Day (₹): ");
        scanf("%f", &cars[i].rent.daily_rent);
        cars[i].is_total_rent = 0; 
    }
    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - ₹%.2f/day\n", i + 1, cars[i].model, cars[i].rent.daily_rent);
    }
    saveToFile(cars, n);

    char choice;
    printf("\nDo you want to update rental information? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        updateRent(cars, n);
    }
    return 0;
  }
