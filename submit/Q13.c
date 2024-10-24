#include <stdio.h>

int main() {
    int row, col;
	printf("enter the row : ");
	scanf("%d", &row);
	printf("enter the column : ");
	scanf("%d", &col);
    int mat[5][5]={
        {1,2,33,4,3},
        {12,2,32,47,478},
        {754,2,32,4,3},
        {15,2,3,54,63},
        {145,2,3,44,32}
    };
    printf("element at %d %d : %d", row, col, mat[row-1][col-1]);
    return 0;
}

//output :enter the row : 3
//enter the column : 5
//element at 3 5 : 3
