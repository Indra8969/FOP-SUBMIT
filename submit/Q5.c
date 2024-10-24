#include <stdio.h>
int main(){
	int basic, HRA, DA, total_salary;
	printf("Enter the Basic Salary : ");
	scanf("%d", &basic);
	printf("Enter the HRA (HOME RENT ALLOWANCE) : ");
	scanf("%d", &HRA);
	printf("Enter the DA (DEARNESS ALLOWANCE) : ");
	scanf("%d", &DA);
	total_salary = basic + HRA + DA;
	printf("\nTotal Salary of the employee is : %d\n", total_salary);
	return 0;
}

//output
//Enter the Basic Salary : 34444
//Enter the HRA (HOME RENT ALLOWANCE) : 234
//Enter the DA (DEARNESS ALLOWANCE) : 335
//Total Salary of the employee is : 35013
