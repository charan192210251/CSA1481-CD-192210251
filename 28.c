#include<stdio.h>
int main(){
	char c[100];
	int i;
	FILE *file;
	file=fopen("s28.c","r");
	if(file==NULL){
		printf("Error open file");
		return 1;
	}
	while(fgets(c,sizeof(c),file)){
		i=0;
		while(c[i]){
			if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'){
				printf("Operation found: %c\n",c[i]);
			}
			i++;
		}
	}
	fclose(file);
	return 0;
}
