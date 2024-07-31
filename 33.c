#include<stdio.h>
#include<ctype.h>
int main(){
	char c[100];
	int i=0;
	int j=2000;
	printf("Enter an expression: ");
	fgets(c,sizeof(c),stdin);
	printf("Symbol \t Address \t Type\n");
	while(c[i]){
		if(isalpha(c[i])){
		printf("%c \t %d \t identifier\n",c[i],j);
	}
	else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='=')
	{
		printf("%c \t %d \t operator\n",c[i],j);
	}
	j++;
	i++;
	}
	return 0;
}
