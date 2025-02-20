#include <stdio.h>
#include <string.h>
typedef struct 
{
    int subject1;
    int subject2;
    int subject3;
} Marks;

typedef struct 
{
    int ID;
    char Name[50]; 
    Marks Marks;
    int total;
    float average;
    char grade;
} Student;
void readStudents(Student students[], int n) 
{
    printf("Enter details (ID, Name, Marks in 3 subjects):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &students[i].ID, students[i].Name,
              &students[i].Marks.subject1, &students[i].Marks.subject2, &students[i].Marks.subject3);
    }
}
void calculateGrades(Student students[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        students[i].total = students[i].Marks.subject1 + students[i].Marks.subject2 + students[i].Marks.subject3;
        students[i].average = (float)students[i].total / 3;

        if (students[i].average >= 90) 
        {
            students[i].grade = 'A';
        } else if (students[i].average >= 75) 
        {
            students[i].grade = 'B';
        } else if (students[i].average >= 60) 
        {
            students[i].grade = 'C';
        } else if (students[i].average >= 45) 
        {
            students[i].grade = 'D';
        } else 
        {
            students[i].grade = 'F';
        }
    }
}
void displayStudents(Student students[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%s - Total: %d, Average: %.2f, Grade: %c\n",
               students[i].Name, students[i].total, students[i].average, students[i].grade);
    }
}
int main() 
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student students[n];
    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);
    return 0;
}
