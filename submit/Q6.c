#include <stdio.h>

int main(){
	int input, i;
	printf("Enter the number you wanna print a multiplication table : ");
	scanf("%d", &input);
	for(i = 1; i <= 10; i++){
		printf("%d x %d = %d\n", input, i, input * i);
	}
	return 0;
}

//output
//Enter the number you wanna print a multiplication table : 45
//45 x 1 = 45
//45 x 2 = 90
//45 x 3 = 135
//45 x 4 = 180
//45 x 5 = 225
//45 x 6 = 270
//45 x 7 = 315
//45 x 8 = 360
//45 x 9 = 405
//45 x 10 = 450
