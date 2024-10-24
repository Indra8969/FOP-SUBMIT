#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks[3];
    float totalmarks;
    float percentage;
    char division[20];
};

void calculateResults(struct Student* student) {
    student->totalmarks = student->marks[0] + student->marks[1] + student->marks[2];
    student->percentage = (student->totalmarks / 300) * 100;
    
    if (student->percentage >= 60) {
        strcpy(student->division, "First Class");
    } else if (student->percentage >= 50) {
        strcpy(student->division, "Second Class");
    } else if (student->percentage >= 40) {
        strcpy(student->division, "Third Class");
    } else {
        strcpy(student->division, "Fail");
    }
}

void displayMarksheet(struct Student student) {
    printf("----- Marksheet -----\n");
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Marks in Maths: %.2f\n", student.marks[0]);
    printf("Marks in Science: %.2f\n", student.marks[1]);
    printf("Marks in English: %.2f\n", student.marks[2]);
    printf("Total Marks: %.2f / 300\n", student.totalmarks);
    printf("Percentage: %.2f%%\n", student.percentage);
    printf("Division: %s\n", student.division);
    printf("------------------------------\n");
}

int main() {
    int n, i;
    struct Student students[15];

    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Enter student ID: ");
        scanf("%d", &students[i].id);
        printf("Enter student name: ");
        getchar(); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n"); 
        
        printf("Enter marks for Maths: ");
        scanf("%f", &students[i].marks[0]);
        printf("Enter marks for Science: ");
        scanf("%f", &students[i].marks[1]);
        printf("Enter marks for English: ");
        scanf("%f", &students[i].marks[2]);

        calculateResults(&students[i]);
    }

    printf("\n----- All Students' Marksheet -----\n");
    for (i = 0; i < n; i++) {
        displayMarksheet(students[i]);
    }

    return 0;
}

//output : 
//Enter the number of students: 2
//
//Enter details for student 1
//Enter student ID: 34
//Enter student name: idfas
//Enter marks for Maths: 34
//Enter marks for Science: 534
//Enter marks for English: 34
//
//Enter details for student 2
//Enter student ID: 43
//Enter student name: fadjk
//Enter marks for Maths: 54
//Enter marks for Science: 345
//Enter marks for English: 54
//
//----- All Students' Marksheet -----
//----- Marksheet -----
//ID: 34
//Name: idfas
//Marks in Maths: 34.00
//Marks in Science: 534.00
//Marks in English: 34.00
//Total Marks: 602.00 / 300
//Percentage: 200.67%
//Division: First Class
//------------------------------
//----- Marksheet -----
//ID: 43
//Name: fadjk
//Marks in Maths: 54.00
//Marks in Science: 345.00
//Marks in English: 54.00
//Total Marks: 453.00 / 300
//Percentage: 151.00%
//Division: First Class
//------------------------------
