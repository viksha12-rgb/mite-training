#include <stdio.h>
float calculateBill(char wardType, int days);
int main() 
{
    char name[200];
    char wardType;
    int days;
    float bill;

    printf("Enter the patient name: ");
    scanf("%s", name);

    printf("Enter the ward type (G/S/P): ");
    scanf(" %c", &wardType); 

    printf("Enter the number of days admitted: ");
    scanf("%d", &days);

    bill = calculateBill(wardType, days);

    printf("Final Bill Amount: %.2f\n", bill);

    return 0;
}

float calculateBill(char wardType, int days) {
    float bill = 0.0f;
    float discount = 0.0f;

    if (days <= 7) {
        if (wardType == 'G') {
            bill = 1000.0f * days;
        } else if (wardType == 'S') {
            bill = 2000.0f * days;
        } else if (wardType == 'P') {
            bill = 5000.0f * days;
        }
        printf("Total Bill Before Discount: %.2f\n", bill);
    } else {
        if (wardType == 'G') {
            bill = 1000.0f * days;
        } else if (wardType == 'S') {
            bill = 2000.0f * days;
        } else if (wardType == 'P') {
            bill = 5000.0f * days;
        }
        discount = bill * 0.05f; 
        bill -= discount;
        printf("Total Bill Before Discount: %.2f\n", bill+discount);
        printf("Discount applied : %.2f\n", discount);
    }

    return bill;
}
