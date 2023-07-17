#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
int main(int argc, char *argv[]){
	DIR* directory=opendir(".");
	struct dirent* file;
	if(directory==NULL){
		return 0;
	}
	file=readdir(directory);
	if(!strcmp(argv[1],"no")){
		while(file!=NULL){
			char* dir;
			dir=file->d_name;
			if (!strcmp(dir,".")||!strcmp(dir,"..")){
				file=readdir(directory);
				continue;
			}
			else if(dir[0]=='.'){
				file=readdir(directory);
				continue;
			}
			else{
				printf("%s  ",dir);
				file=readdir(directory);
			}
		}
		
	}
	if(!strcmp(argv[1],"-a")){
		while(file!=NULL){
			char* dir;
			dir=file->d_name;
			printf("%s  ",dir);
			file=readdir(directory);
		}
	}
	if(!strcmp(argv[1],"-A")){
		while(file!=NULL){

			char* dir;
			dir=file->d_name;
			if (!strcmp(dir,".")||!strcmp(dir,"..")){
				file=readdir(directory);
				continue;
			}
			else{
				printf("%s  ",dir);
				file=readdir(directory);
			}
		}
	}
	printf("\n");
	return 0;
}