#include <stdio.h>
#include <string.h>
int main()
{
    int id;
    char name[250];
    float salary;
    int attendence;
    printf("Enter the employee name:");
    scanf("%s",name);
    printf("Enter the employee id:");
    scanf("%d",&id);
    printf("Enter the employee salary:");
    scanf("%f",&salary);
    printf("Enter the number of days worked:");
    scanf("%d",&attendence);
    
    float bonus=0.0f;
    float gross_salary=0.0f;
    char category[50]="Good";
    
    if(attendence>25){
        bonus=(salary/100.0f)*5.0f;
    }else if(attendence<10){
        bonus=(-1.0f*((salary/100.0f)*50.0f));
    }
    
    gross_salary=(salary+bonus);
    
    if(attendence>25){
        strcpy(category,"Excellent");
    }else if(attendence<15){
        strcpy(category,"Need Improvement");
    }
    printf("\tPayroll Details:\n");
    printf("\tId:%d\n",id);
    printf("\tName:%s\n",name);
    printf("Basic salary:%2.f\n",salary);
    if(bonus>0){
        printf("Bonus:%.2f",bonus);
    }
    printf("\tFinal salary:%.2f",gross_salary);
    printf("\tEmployeee Performance Category:%s\n",category);
    return 0;
}    
