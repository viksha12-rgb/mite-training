#include <stdio.h>
float calculateFinalAmount(float billAmount) {
    float discount = 0.0;

    if (billAmount >= 500 && billAmount <= 1000) 
    {
        discount = 0.10; 
    } else if (billAmount > 1000)
    {
        discount = 0.20; 
  
    float finalAmount = billAmount - (billAmount * discount);
    return finalAmount;
}
int main() {
    float billAmount;
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);
    float finalAmount = calculateFinalAmount(billAmount);
    if (billAmount >= 500 && billAmount <= 1000)
    {
        printf("Final Payable Amount: ₹%.2f (after 10%% discount)\n", finalAmount);
    } else if (billAmount > 1000)
    {
        printf("Final Payable Amount: ₹%.2f (after 20%% discount)\n", finalAmount);
    } else 
    {
        printf("Final Payable Amount: ₹%.2f (no discount)\n", finalAmount);
    }

    return 0;
}
