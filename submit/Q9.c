#include <stdio.h>

int main(){
	int n1, n2, task;
	printf("choose : \n1. ADDITION\n2. SUBSTRACTION\n3. MULTIPLICATION\n4. DIVISION");
	printf("\nINPUT : ");
	scanf("%d", &task);
	printf("Enter the first Number : ");
	scanf("%d", &n1);
	printf("Enter the second Number : ");
	scanf("%d", &n2);
	switch(task){
		case 1:
			printf("Addition of given two Numbers is : %d", n1 + n2);
			break;
		case 2:
			printf("Substration of given two Numbers is : %d", n1 - n2);
			break;
		case 3:
			printf("Multiplication of given two Numbers is : %d", n1 * n2);
			break;
		case 4:
			printf("Division of given two Numbers is : %d", n1 / n2);
			break;
		default:
			printf("Not a valid input ! Plase choose number 1 to 4");	
	}
	return 0;
}


//output
//choose :
//1. ADDITION
//2. SUBSTRACTION
//3. MULTIPLICATION
//4. DIVISION
//INPUT : 3
//Enter the first Number : 234
//Enter the second Number : 23464
//Multiplication of given two Numbers is : 5490576
