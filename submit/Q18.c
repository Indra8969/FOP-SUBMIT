#include <stdio.h>

void swap(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void main(){
	int first = 234, second = 4564; 
	printf("Before swapping\nFirst  : %5d \nSecond : %5d", first, second);
	swap(&first, &second);
	printf("\n\nAfter swapping\nFirst  : %5d \nSecond : %5d", first, second);
}

//output : 
//How many elements you want into the array :  5
//Enter element at 1 : 3423
//Enter element at 2 : 534
//Enter element at 3 : 345
//Enter element at 4 : 345
//Enter element at 5 : 324
//Sum of all array elements is : 4971
