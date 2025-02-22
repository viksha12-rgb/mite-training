#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    int marks;
} Student;

// Function to compare students for sorting (Descending order of marks)
int compare(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks;
}

// Binary search function to find student by roll number
int binary_search(Student students[], int left, int right, int roll_no) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].roll_no == roll_no)
            return mid;
        else if (students[mid].roll_no < roll_no)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to display students
void display_students(Student students[], int n) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Marks: %d\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS || n <= 0) {
        printf("Invalid number of students!\n");
        return 1;
    }

    Student students[MAX_STUDENTS];
    for (int i = 0; i < n; i++) {
        printf("Enter Roll No, Name, Marks for student %d: ", i + 1);
        scanf("%d %s %d", &students[i].roll_no, students[i].name, &students[i].marks);
    }

    // Sorting students by marks (Descending)
    qsort(students, n, sizeof(Student), compare);
   
    printf("\nSorted Student List (by Marks):\n");
    display_students(students, n);
   
    // Display top 3 students
    printf("\nTop 3 Students:\n");
    for (int i = 0; i < (n < 3 ? n : 3); i++) {
        printf("%s (Marks: %d)\n", students[i].name, students[i].marks);
    }
   
    // Search for a student by roll number
    int search_roll;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &search_roll);
   
    int index = binary_search(students, 0, n - 1, search_roll);
    if (index != -1) {
        printf("Student Found: %s, Marks: %d\n", students[index].name, students[index].marks);
    } else {
        printf("Student with Roll No %d not found.\n", search_roll);
    }
   
    return 0;
}
