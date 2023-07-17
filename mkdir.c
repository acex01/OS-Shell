#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	if(!strcmp(argv[1],"-m")){
		char* mode;
		mode=(char*)malloc(sizeof(char*)*100);
		mode=argv[2];
		char* name=argv[3];
		int ret;
		ret=mkdir(name,0777);
		if(ret==-1){
			perror("Error");
		}
		int i; 
		i= strtol(mode, 0, 8);
		chmod(name,i);
	}
	else if(!strcmp(argv[1],"-v")){
		char* name=argv[2];
		int ret;
		ret=mkdir(name,0777);
		if(ret==0){
		printf("mkdir: created directory '%s'\n",argv[2]);}
		if(ret==-1){
			perror("Error");
		}
	}
	else{
		char* name=argv[1];
		int ret;
		ret=mkdir(name,0777);
		if(ret==-1){
			perror("Error");
		}
	}

	return 0;
}