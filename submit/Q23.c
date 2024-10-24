#include <stdio.h>

int main(){
	int cc = 0, sc = 0, nlc = 0, wc = 0;
	char c;
	FILE *f1 = fopen("txt1.txt", "r");
	if(!f1){
		printf("Something went wrong while opening file!");
		return 0;
	}
	c = fgetc(f1);
	while(c != EOF){
		if(c == 10) nlc++;
		if(c == ' '){
			sc++;
			wc++;
		};
		cc++;
		c = fgetc(f1);
	}
	nlc++;
	if(c) wc++;
	printf("Charcter : %d\n", cc);
	printf("Words : %d\n", wc);
	printf("Spaces : %d\n", sc);
	printf("Lines : %d\n", nlc);
	return 1;
}
