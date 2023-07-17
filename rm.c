#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int filecheck(char *path)
{
	struct stat* p;
	struct stat path_stat;
	p=&path_stat;
	stat(path, p);
	int z;
	z=S_ISREG(path_stat.st_mode);
	return z;
}

int main(int argc, char *argv[])
{	
	if (!strcmp(argv[1],"-f") ){
		if(filecheck(argv[2])){
			remove(argv[2]);
		}
	}
	else if (!strcmp(argv[1],"-v") ){
		if(filecheck(argv[2])){
			printf("removed '%s'\n",argv[2]);
			remove(argv[2]);
		}
		else{
			printf("Cannot delete , it is a directory or doesn't exist\n");
			return 0;

		}
	}

	else{
		if (filecheck(argv[1])){
			remove(argv[1]);
		}
		else{
			printf("Cannot delete %s , it is a directory\n",argv[1]);
			return 0;
		}
	}
}
