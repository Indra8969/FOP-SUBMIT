#include <stdio.h>

int main(){
    int i, j, r, c;
    int a[100][100], b[100][100], added[4][4];
    
    printf("Enter the number of rows : ");
    scanf("%d", &r);
    printf("Enter the number of columns : ");
    scanf("%d", &c);
    
    for(i = 0; i<r; i++){
    	for(j = 0; j<c; j++){
    		printf("Enter the value at row %d and the column %d of matrix one : ",i ,j);
    		scanf("%d", &a[i][j]);
		}		
	}
	for(i = 0; i<r; i++){
    	for(j = 0; j<c; j++){
    		printf("Enter the value at row %d and the column %d of second matrix : ",i ,j);
    		scanf("%d", &b[i][j]);
		}		
	}
    

    printf("Added matrix : \n[");
    for(i = 0; i<r; i++){
        printf("\n[");
        for(j = 0; j<c; j++){
            added[i][j] = a[i][j] + b[i][j];
            printf("%d", added[i][j]);
            if(j < r-1){
                printf(",");
            }
        }
        printf("],");
        // printf("\n");
    }
    printf("\n]");
    return 0;
}

//output: 
//Enter the number of rows : 2
//Enter the number of columns : 2
//Enter the value at row 0 and the column 0 of matrix one : 546
//Enter the value at row 0 and the column 1 of matrix one : 345
//Enter the value at row 1 and the column 0 of matrix one : 75
//Enter the value at row 1 and the column 1 of matrix one : 345
//Enter the value at row 0 and the column 0 of second matrix : 54
//Enter the value at row 0 and the column 1 of second matrix : 43
//Enter the value at row 1 and the column 0 of second matrix : 5
//Enter the value at row 1 and the column 1 of second matrix : 756
//Added matrix :
//[
// [600,388],
// [80,1101],
//]
