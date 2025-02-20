#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct 
{
    int id;
    char name[50];
    char expiry_date[11]; 
    float price;
} Medicine;

void sort_by_expiry(Medicine meds[], int n) 
{
    Medicine temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(meds[i].expiry_date, meds[j].expiry_date) > 0) {
                temp = meds[i];
                meds[i] = meds[j];
                meds[j] = temp;
            }
        }
    }
}
void save_to_file(Medicine meds[], int n) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    fprintf(file, "ID,Name,Expiry Date,Price\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d,%s,%s,₹%.2f\n", meds[i].id, meds[i].name, meds[i].expiry_date, meds[i].price);
    }
    fclose(file);
    printf("Records saved in \"medicine_inventory.txt\"\n");
}
int main() {
    int n;
    Medicine meds[MAX];
    printf("Enter number of medicines: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &meds[i].id);
        printf("Enter Name: ");
        scanf(" %[^\n]", meds[i].name);  
        printf("Enter Expiry Date (YYYY-MM-DD): ");
        scanf("%s", meds[i].expiry_date);
        printf("Enter Price: ₹");
        scanf("%f", &meds[i].price);
    }
    sort_by_expiry(meds, n);

    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, meds[i].name, meds[i].expiry_date);
    }
    save_to_file(meds, n);
    return 0;
}
