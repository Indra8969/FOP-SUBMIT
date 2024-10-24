#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define FILENAME "employees.dat"

struct Employee {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

void addRecord();
void deleteRecord();
void modifyRecord();
void retrieveRecord();
void listRecords();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Modify an existing record\n");
        printf("4. Retrieve and display a record\n");
        printf("5. Generate a complete list of employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addRecord(); break;
            case 2: deleteRecord(); break;
            case 3: modifyRecord(); break;
            case 4: retrieveRecord(); break;
            case 5: listRecords(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addRecord() {
    struct Employee emp;
    FILE *file = fopen(FILENAME, "ab"); 

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &emp.id);
    clearBuffer();
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    strtok(emp.name, "\n"); 
    printf("Enter Address: ");
    fgets(emp.address, sizeof(emp.address), stdin);
    strtok(emp.address, "\n"); 
    printf("Enter Phone: ");
    fgets(emp.phone, sizeof(emp.phone), stdin);
    strtok(emp.phone, "\n");

    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
    printf("Record added successfully.\n");
}

void deleteRecord() {
    int id;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID of the employee to delete: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(struct Employee), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record with ID %d not found.\n", id);
    }
}

void modifyRecord() {
    int id;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "r+b");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID of the employee to modify: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == id) {
            found = 1;
            printf("Enter new Name: ");
            clearBuffer();
            fgets(emp.name, sizeof(emp.name), stdin);
            strtok(emp.name, "\n"); // Remove newline character
            printf("Enter new Address: ");
            fgets(emp.address, sizeof(emp.address), stdin);
            strtok(emp.address, "\n"); // Remove newline character
            printf("Enter new Phone: ");
            fgets(emp.phone, sizeof(emp.phone), stdin);
            strtok(emp.phone, "\n"); // Remove newline character

            fseek(file, -sizeof(struct Employee), SEEK_CUR); // Move to the record's position
            fwrite(&emp, sizeof(struct Employee), 1, file);
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("Record modified successfully.\n");
    } else {
        printf("Record with ID %d not found.\n", id);
    }
}

void retrieveRecord() {
    int id;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID of the employee to retrieve: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == id) {
            found = 1;
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Address: %s\n", emp.address);
            printf("Phone: %s\n", emp.phone);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void listRecords() {
    struct Employee emp;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nList of Employees:\n");
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        printf("ID: %d, Name: %s, Address: %s, Phone: %s\n", emp.id, emp.name, emp.address, emp.phone);
    }

    fclose(file);
}

