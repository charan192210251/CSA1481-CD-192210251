#include<stdio.h>
int main(){
	char c[1000];
	int i;
	FILE *file;
	file=fopen("s27.c","r");
	if(file==NULL){
		printf("Error opening file");
		return 1;
	}
	while(fgets(c,sizeof(c),file)){
		i=0;
		while(c[i]){
			if(c[i]=='/' && c[i+1]=='/'){
				printf("single line comment: %s",&c[i]);
				break;
			}
			else if(c[i]=='/'&&c[i+1]=='*'){
				printf("multi line comment : %s",&c[i]);
				break;
			}
			i++;
		}
	}
	fclose(file);
	return 0;
}
