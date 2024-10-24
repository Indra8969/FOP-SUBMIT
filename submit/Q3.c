#include <stdio.h>
int main(){
	int marks;
	printf("Enter the marks of the student : ");
	scanf("%d", &marks);
	if(marks <= 39){ 
		printf("Status : Fail");
	}else if(39 < marks && marks <= 59){
		printf("Status : Second Class");
	}else if(59 < marks && marks <= 80){
		printf("Status : First Class");
	}else if(marks > 80){
		printf("status : first class with distinct");
	}
}

//output
//Enter the marks of the student : 33
//Status : Fail
