#include <stdio.h>
int main(){
	int input, i;
	printf("Enter the number which you want to check is the number is a prime or not : ");
	scanf("%d", &input);
	for(i = 22; i < input /2; i++){
		if((input % i)){
			printf("%d is not a prime number \n", input);
			return 1;
		}
	}
	printf("%d is a prime number ", input);
	return 0;
}

//output
//Enter the number which you want to check is the number is a prime or not : 13
//13 is a prime number
