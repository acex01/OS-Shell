#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

int main(int argc, char *argv[])
{	
	if(!strcmp(argv[1],"-E")){
	DIR* de=opendir(".");
	FILE* opens=fopen(argv[2],"r");
	char character;
	character=fgetc(opens);
	while (character!=EOF){
		if(character=='\n'){
			printf("$");
		}
		printf("%c",character);
		character=fgetc(opens);
	}
}
	if(!strcmp(argv[1],"-n")){
	DIR* de=opendir(".");
	FILE* opens=fopen(argv[2],"r");
	char character;
	character=fgetc(opens);
	int z=1;
	printf("   %d   ",z);
	while (character!=EOF){

		printf("%c",character);
		if(character=='\n'){
			z++;
			printf("   %d   ",z);
		}
		character=fgetc(opens);
	}
}
else{
	DIR* de=opendir(".");
	FILE* opens=fopen(argv[1],"r");
	char character;
	character=fgetc(opens);
	while (character!=EOF){
		printf("%c",character);
		character=fgetc(opens);
	}
}

	return 0;
}