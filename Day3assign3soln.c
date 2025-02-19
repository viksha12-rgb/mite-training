#include <stdio.h>

int main() 
{
    int n, scores[100], highest, lowest, sum = 0;
    float average;
    printf("Enter number of matches: ");
    scanf("%d", &n);
    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &scores[i]);
    }
    highest = lowest = scores[0];
    for (int i = 0; i < n; i++) 
    {
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
        sum += scores[i];
    }
    average = (float)sum / n;
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);
    return 0;
}
