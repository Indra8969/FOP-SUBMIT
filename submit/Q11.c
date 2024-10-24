#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;
    printf("Enter the number of elements you want in the array (max 100): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 100) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Enter the value of an element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("sorted : [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", "); 
        }
    }
    printf("]\n");

    return 0;
}

//output :
//Enter the number of elements you want in the array (max 100): 12
//Enter the value of an element at index 0: 32
//Enter the value of an element at index 1: 5
//Enter the value of an element at index 2: 3242
//Enter the value of an element at index 3: 342
//Enter the value of an element at index 4: 35
//Enter the value of an element at index 5: 235
//Enter the value of an element at index 6: 36
//Enter the value of an element at index 7: 45
//Enter the value of an element at index 8: 758
//Enter the value of an element at index 9: 56
//Enter the value of an element at index 10: 65
//Enter the value of an element at index 11: 645
//sorted : [5, 32, 35, 36, 45, 56, 65, 235, 342, 645, 758, 3242]
