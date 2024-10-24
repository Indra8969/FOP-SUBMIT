#include <stdio.h>
int find(int a, int b, int c){
	int res;
	
	if(a > b && a > c) res = a;
	else if(b > c) res = b;
	else res = c;
	return res;
}

int main(){
	int a,b,c;
	
	printf("\nEnter first number : ");
	scanf("%d", &a);
	printf("\nEnter second number : ");
	scanf("%d", &b);
	printf("\nEnter third number : ");
	scanf("%d", &c);
	
	printf("\nMax value is : %d", find(a,b,c));
	
	return 0;
}


//output
//Enter first number : 23
//Enter second number : 534
//Enter third number : 65
//Max value is : 534
