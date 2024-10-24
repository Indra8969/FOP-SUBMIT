#include <stdio.h>
#include <stdlib.h>

void main(){
	int nline;
	char c;
	FILE *f1, *f2;
	f1 = fopen("txt1.txt", "r");
	f2 = fopen("txt2.txt", "w");
	if(!f1){
		printf("Something went wrong while opening the file one");
		exit(1);
	}
	if(!f2){
		printf("Something went wrong whie opening the file two");
		exit(1);
	}
	c = fgetc(f1);
	while(c != EOF){
		if(c == '\n') nline++;
		fputc(c, f2);
		c = fgetc(f1);
	}
	printf("Number of line in the file one is : %d", nline);
}

