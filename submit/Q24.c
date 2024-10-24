#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[20];
    char telephone[10];
};

struct Customer *custs = NULL; 
struct Customer s;
FILE *file;
int n = 0; 

void printRecord(struct Customer record) {
    printf("\n--------\n");
    printf("Name: %s\n", record.name);
    printf("Telephone Number: %s\n", record.telephone);
    printf("----------\n");
}

void printall(){
	int i;
	for(i = 0; i< n; i++){
		printRecord(custs[i]);
	}
}

void extractData() {
    while (fread(&s, sizeof(s), 1, file) == 1) {
        struct Customer *temp = realloc(custs, (n + 1) * sizeof(struct Customer));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        custs = temp; 
        custs[n++] = s; 
    }
    printf("\nData extracted from the file.\n");
}

void openFile() {
    char filename[50];
    printf("Enter the name of the file to open or create: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; 

    file = fopen(filename, "a+b");
    if (!file) {
        printf("Could not open file!\n");
        return; 
    }

    printf("File opened successfully.\n");
    extractData();
}


void writeBinary() {
	int i;
    if (file) {
        fseek(file, 0, SEEK_SET); 
        for (i = 0; i < n; i++) {
            fwrite(&custs[i], sizeof(struct Customer), 1, file);
        }
        printf("\nSuccessfully saved data to the file.\n");
    } else {
        printf("File is not opened!\n");
    }
}

void inputRecord() {
    printf("\nEnter the details of the new customer:\n");
    printf("Enter the name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter the telephone number: ");
    fgets(s.telephone, sizeof(s.telephone), stdin);
    s.telephone[strcspn(s.telephone, "\n")] = 0; 
    
    struct Customer *temp = realloc(custs, (n + 1) * sizeof(struct Customer));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    custs = temp; 
    custs[n++] = s; 
    printf("\nRecord added to the list.\n");
}


void deleteRecord() {
	int i, j;
    char str[20];
    printf("Enter the mobile number or the name of the customer to delete: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    int found = 0; 
    for (i = 0; i < n; i++) {
        if (strcmp(custs[i].name, str) == 0 || strcmp(custs[i].telephone, str) == 0) {
            for (j = i; j < n - 1; j++) {
                custs[j] = custs[j + 1];
            }
            n--; 
            struct Customer *temp = realloc(custs, n * sizeof(struct Customer)); 
            if (temp == NULL && n > 0) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            custs = temp; 
            found = 1; 
            printf("Record deleted.\n");
            break; 
        }
    }
    if (!found) {
        printf("No such record found to delete.\n");
    }
}

void getRecord() {
	int i;
    char str[20];
    printf("\nEnter the telephone number or name: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    for (i = 0; i < n; i++) {
        if (strcmp(custs[i].name, str) == 0 || strcmp(custs[i].telephone, str) == 0) {
            printRecord(custs[i]);
            getchar();
            return;
        }
    }
    printf("No such record found.\n");
    getchar();
}


void menu() {
	if(!file) openFile();
    char c;
    printf("\n--- MENU ---");
    printf("\nOpen or create file (o)\n");
    printf("Add new record (a)\n");
    printf("Get record (g)\n");
    printf("Delete customer (d)\n");
    printf("Save changes (s)\n");
    printf("Print all record (l)\n");
    printf("Exit (x)\n");
    printf("Input: ");
    scanf(" %c", &c);
    while (getchar() != '\n'); 

    switch (c) {
        case 'a': inputRecord(); break;
        case 'g': getRecord(); break;
        case 'd': deleteRecord(); break;
        case 's': writeBinary(); break;
        case 'o': openFile(); break;
        case 'l': printall(); break;
        case 'x':
            if (file) fclose(file); 
            free(custs); 
            exit(0);
        default: printf("\nInvalid input!!!\n");
    }
    menu();
}


int main() {
    menu();
    free(custs);
    return 0;
}
