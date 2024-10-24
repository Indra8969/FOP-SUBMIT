#include <stdio.h>

int fact(int num){
	if(num == 2) return num;
	return num * fact(num-1);
}

int main(){
	int number, factorial;
	printf("Enter the number you want to find the factorail : ");
	scanf(" %d", &number);
	factorial = fact(number);
	printf("Factorial of the %d is %d", number, factorial);
}
//output: 
//Enter the number you want to find the factorail : 12
//Factorial of the 12 is 479001600
