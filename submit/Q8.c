#include <stdio.h>

int main(){
    int num, sum  = 0, rev = 0, rem;
    printf("Enter the number to check the sum of digits and rev number : ");
    scanf("%d", &num);
    
    while(num > 0){
        rem = num % 10;
        rev = rev * 10 + rem;
        sum += rem;
        num /= 10;
    }
    printf("sum is %d and the rev number is %d", sum, rev);
    return 0;
}

//output
//Enter the number to check the sum of digits and rev number : 43654
//sum is 22 and the rev number is 45634
