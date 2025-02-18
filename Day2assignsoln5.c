#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    int marks;
} Student;

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student *students = (Student *)malloc(n * sizeof(Student));

    if (students == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        printf("Enter Student %d Name: ", i + 1);
        getchar(); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }
    free(students);

    return 0;
}
