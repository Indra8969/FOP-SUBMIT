#include <stdio.h>

int findOccurance(char str[], char ch){
	int count = 0, i=0;
	while(str[i] != '\0'){
		if(str[i] == ch){
			count++;
		}
		i++;
	}
	return count;
}

int main(){
	char str[100], ch;
	int count;
	printf("Enter the string : ");
	gets(str);
	printf("Enter the character you want to check occurance : ");
	scanf(" %c", &ch);
	count = findOccurance(str, ch);
	printf("\nOcuurance of the %c in the %s is : %d", ch, str, count);
}

//output : 
//Enter the string : sfjjadjfkjadfkjkaj fakjdfkajsdfk
//Enter the character you want to check occurance : f
//Ocuurance of the f in the sfjjadjfkjadfkjkaj fakjdfkajsdfk is : 6
