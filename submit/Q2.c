#include <stdio.h>

int main(){
	int first = 4234, second = 6456, temp;
	printf("In initial state : first = %d and second = %d", first, second);
	temp = first;
	first = second; 
	second = temp;
	printf("\n\nAfter swap state : first = %d and second = %d", first, second);
}

//output
//In initial state : first = 4234 and second = 6456
//After swap state : first = 6456 and second = 4234
