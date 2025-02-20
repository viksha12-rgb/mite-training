#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct 
{
    int ID;
    char Name[50];
    float Salary;
} Employee;

void writeToFile(Employee emp[], int n) {
    FILE *fp = fopen("employees.txt", "w"); 

    if (fp == NULL) 
    {
        perror("Error opening file for writing"); 
        exit(1); // Exit with an error code
    }
    fprintf(fp, "ID\tName\tSalary\n"); 
    for (int i = 0; i < n; i++) 
    {
        fprintf(fp, "%d\t%s\t%.2f\n", emp[i].ID, emp[i].Name, emp[i].Salary); 
    }
    fclose(fp);
    printf("Employee data written to employees.txt\n");
}
void readFromFile() 
{
    FILE *fp = fopen("employees.txt", "r"); 

    if (fp == NULL) 
    {
        perror("Error opening file for reading");
        exit(1);
    }
    printf("Employees Data from File:\n");
    char line[100]; 
    while (fgets(line, sizeof(line), fp) != NULL) 
    { 
        printf("%s", line); // Print the line
    }
    fclose(fp);
}
int main() 
{
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); 
    Employee employees[n];
    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %s %f", &employees[i].ID, employees[i].Name, &employees[i].Salary);
        getchar(); 
    }
    writeToFile(employees, n);
    readFromFile();
    return 0;
}
