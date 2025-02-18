#include<stdio.h>
int main() 
{
    int productcount;
    int weight;
    
    printf("Enter the number of products:");
    scanf("%d",&productcount);
    
    int acceptedCount=0;
    int rejectedCount=0;
    for(int I=1;I<=productcount;I++)
    {
       printf("Enter the number of weights(in grams):");
       scanf("%d",&weight);
       if(weight>=950 && weight <=1050)
        {
          acceptedCount++;  
        }
        else
        {
          rejectedCount++;
        }
    }
    printf("Accepted Products:%d\n",acceptedCount);
    printf("Rejected Products:%d\n",rejectedCount);
    
    return 0;
}
