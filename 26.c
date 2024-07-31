#include<stdio.h>
#include<ctype.h>
int main(){
	char c[50];
	int i=0;
	FILE *file;
	file=fopen("s26.cpp","r");
	if(file==NULL){
		printf("Error opening file");
		return 1;
	}
	while(fgets(c,sizeof(c),file)){
		while(c[i]){
		if(isalpha(c[i])){
			printf("%c is an identifier\n",c[i]);
		}
		else if(isdigit(c[i])){
			printf("%c is a constant\n",c[i]);
		}
		else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'){
			printf("%c is an operator\n",c[i]);
		}
		i++;
		}
	}
	fclose(file);
	return 0;
}
