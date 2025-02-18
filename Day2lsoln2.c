#include <stdio.h>
long factorial(int n);
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) 
    {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %ld\n", num, factorial(num));
    }
    return 0;
}
long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    } else {
        return n * factorial(n - 1); 
    }
}
