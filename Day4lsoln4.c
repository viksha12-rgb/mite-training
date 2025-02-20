#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for Marks
typedef struct {
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
void calculateGrade(Student *student) {
    student->total = student->Marks.subject1 + student->Marks.subject2 + student->Marks.subject3;
    student->average = (float)student->total / 3;

    if (student->average >= 90) 
    {
        student->grade = 'A';
    } else if (student->average >= 75) 
    {
        student->grade = 'B';
    } else if (student->average >= 60) 
    {
        student->grade = 'C';
    } else if (student->average >= 45) 
    {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}
void appendStudentRecord() 
{
    FILE *fp = fopen("students.txt", "a"); 
    if (fp == NULL) 
    {
        perror("Error opening file for appending");
        return;
    }
    Student newStudent;
    printf("Appending student:\n");
    scanf("%d,%49[^,],%d,%d,%d", &newStudent.ID, newStudent.Name, &newStudent.Marks.subject1, &newStudent.Marks.subject2, &newStudent.Marks.subject3);
    calculateGrade(&newStudent); 
    fprintf(fp, "%d %s %d %d %d\n", newStudent.ID, newStudent.Name, newStudent.Marks.subject1, newStudent.Marks.subject2, newStudent.Marks.subject3);
    fclose(fp);
    printf("Student record appended.\n");
}
void displayStudentRecords() 
{
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) 
    {
        perror("Error opening file for reading");
        return;
    }
    Student student;
    printf("Student Records:\n");

     while (fscanf(fp, "%d %49[^ ] %d %d %d", &student.ID, student.Name, &student.Marks.subject1, &student.Marks.subject2, &student.Marks.subject3) == 5) {
        calculateGrade(&student);
        printf("%d %s %d %d %d\n", student.ID, student.Name, student.Marks.subject1, student.Marks.subject2, student.Marks.subject3);
    }
    fclose(fp);
}
int main() 
{
    int choice;
    do {
        printf("\nStudent Record Management\n");
        printf("1. Append Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) 
        {
            case 1:
                appendStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
