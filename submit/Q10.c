#include <stdio.h>

int main() {
    int arr[100], n, i, max, min;
    printf("Enter the number of element you want in the array : ");
    scanf("%d", &n);
    for(i = 0; i<n ; i++){
        printf("\nEnter the value of an element at the index %d : ", i);
        scanf(" %d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for(i = 0; i<n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("\nMax number is %d", max);
    printf("\nMin number is %d", min);
    return 0;
}


//output : 
//Enter the number of element you want in the array : 5
//Enter the value of an element at the index 0 : 34
//Enter the value of an element at the index 1 : 534
//Enter the value of an element at the index 2 : 43
//Enter the value of an element at the index 3 : 53
//Enter the value of an element at the index 4 : 43
//Max number is 534
//Min number is 34
