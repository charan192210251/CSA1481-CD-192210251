#include<stdio.h>
#include<ctype.h>
int main(){
	char c[100];
	int i;
	FILE *file;
	file=fopen("s30.c","r");
	if(file==NULL){
		printf("Error open file");
		return 1;
	}
	while(fgets(c,sizeof(c),file)){
		i=0;
		while(c[i]){
			if(isalpha(c[i])||c[i]=='_'){
				printf("valid :%s",&c[i]);
				break;
			}
			else{
				printf("not valid :%s",&c[i]);
				break;
			}
			i++;
		}
	}
	fclose(file);
	return 0;
}
