#include <stdio.h>

int main(){	
	char task;	
	float radius, width, height, base;
	const float PIE = 3.141592653589793;
	
	printf("Choose what you want to do...\nc - Area of the circle\nr - Area of the Retangle\nt - Area of the Trinangle\n");
	printf("\nInput : ");
	scanf("%c", &task);
	
	switch(task){
		case 'c':
			printf("\nEnter the radius of the cricle : ");
			scanf("%f", &radius);
			printf("\nArea of the circle is : %f", PIE * radius * radius);
			break;
		case 'r':
			printf("\nEnter the width of the retangle : ");
			scanf("%f", &width);
			printf("\nEnter the height of the retangle : ");
			scanf("%f", &height);
			printf("\nArea of the Retangle is : %f", width * height);
			break;
		case 't':
			printf("\nEnter height of the Triangle : ");
			scanf("%f", &height);
			printf("\nEnter base of the Triangle : ");
			scanf("%f", &base);
			printf("\nArea of the Trianlle is : %f", (base * height)/2);
			break;	
	}
	
	return 0;
}

//output
//Choose what you want to do...
//c - Area of the circle
//r - Area of the Retangle
//t - Area of the Trinangle
//Input : r
//Enter the width of the retangle : 45
//Enter the height of the retangle : 43
//Area of the Retangle is : 1935.000000
