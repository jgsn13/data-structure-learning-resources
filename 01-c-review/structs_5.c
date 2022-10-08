#include <stdio.h>
#include <stdlib.h>

// Vector of structs

typedef struct student {
    char name[81];
    float ira;
} Student;

#define MAX 100
#define NO_STUDENT -1 // Non existent student in the vector

void init(int n, Student students[]) {
    for (int i = 0; i < n; i++)
        students[i].ira = NO_STUDENT;
}

void print(int n, Student students[], int i) {
    if (i < 0 || i >= n) {
        printf("Index out of vector limit!!!\n");
        exit(1);
    }
    if (students[i].ira != NO_STUDENT) {
        printf("Name: %s\n", students[i].name);
        printf("IRA: %.2f\n", students[i].ira);
    }
}

void print_all(int n, Student students[]) {
    printf("List of students\n");
    for (int i = 0; i < n; i++)
        print(n, students, i);
}

void update(int n, Student students[], int i) {
    float ira;
    if (i < 0 || i >= n) {
        printf("Index out of vector limit!!!\n");
        exit(1);
    }
    printf("Enter student name\n");
    scanf(" %[^\n]", students[i].name);
    while (1) {
        printf("Enter student IRA\n");
        scanf(" %f", &ira);
        if (ira < 0 || ira > 100)
            printf("IRA is out of interval [0.0, 100.0]\n");
        else
            break;
    }
    students[i].ira = ira;
}

int main() {
    Student *students;
    int n;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    init(n, students);
    for (int i = 0; i < n; i++)
        update(n, students, i);
    print_all(n, students);
    free(students);

    return 0;
}
