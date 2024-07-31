#include<stdio.h>
int main(){
	char c[100];
	int i;
	int w=0,l=0;
	FILE *file;
	file=fopen("s29.c","r");
	if(file==NULL){
		printf("Error open file");
		return 1;
	}
	while(fgets(c,sizeof(c),file)){
		i=0;
		while(c[i]){
			if(c[i]==' '){
				w++;
			}
			if(c[i]=='\n'){
				l++;
			}
			i++;
		}
	}
	printf("White space count: %d\n",w);
	printf("New line count: %d",l);
	fclose(file);
	return 0;
}
