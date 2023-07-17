#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
char previous[500]="agam";
char previous1[500]="wow";

// char* removeEOL(char arr[]){
// 	char copy[strlen(arr)];
// 	strncpy(copy,arr,strlen(arr)-1);
// 	copy[strlen(arr)-1]=0;
// 	return copy;
// }
void echo(char** string,int i){
	string[1][strcspn(string[1],"\n")] = 0;
	if(!strcmp(string[1],"-n")){
		for(int j=2;j<i-2;j++){
			printf("%s ",string[j]);
		}
		string[i-2][strcspn(string[i-2],"\n")] = 0;
		printf("%s",string[i-2]);
	}
	else if(!strcmp(string[1],"--help")){
		printf("ECHO(1)                          User Commands  \n                    ECHO(1)\n\nNAME\n       echo - display a line of text\n\nSYNOPSIS\n       echo [SHORT-OPTION]... [STRING]...\n       echo LONG-OPTION\n\nDESCRIPTION\n       Echo the STRING(s) to standard output.\n\n       -n     do not output the trailing newline\n\n       --help display this help and exit\n\n");
	}
	else{
		for(int j=1;j<i-2;j++){
			printf("%s ",string[j]);
		}
		printf("%s\n",string[i-2]);

	}
}

void pwd(){
	char directory[100];
	printf("%s\n",getcwd(directory,100));
}
void cd(char* directory){
	if(chdir(directory)==0){
	}
	else{
		perror("Error");
	}

}
int main(int argc, char *argv[]){
	while(1){
		char* command;
		command=(char*)malloc(1000*sizeof(char*));
		char commandcopy[1000];
		char** tokens;
		tokens=(char**)malloc(1000*sizeof(char**));
		size_t commandsize=1000;
		printf("diwalienjoyer:~$ ");
		getline(&command,&commandsize,stdin);
		strcpy(commandcopy,command);
		char* token;
		token=(char*)malloc(sizeof(char*));
		token=strtok(commandcopy," ");
		char singletoken[strlen(token)];
		strncpy(singletoken,token,strlen(token)-1);
		singletoken[strlen(token)-1]=0;
		tokens[0]=token;
		tokens[0][strcspn(tokens[0],"\n")] = 0;
		int i=1;
		while(token!=NULL){
			token=strtok(NULL," ");
			tokens[i]=token;
			i++;
		}
		// char singletoken[strlen(commandcopy)-1];
		// int x=strlen(commandcopy);
		// for(int i=0;i<x;i++){
		// 	if (commandcopy[i]!='\n'){
		// 	singletoken[i]=commandcopy[i];
		// }
		// }
		if (!strcmp(tokens[0],"exit")){
			exit(0);
		}
		if(!strcmp(tokens[0],"date&t")){
			char* command1;
			command1=(char*)malloc(sizeof(char*)*100);
			tokens[0][strcspn(tokens[0],"&")] = 0;
			strcpy(command1,tokens[0]);
			for(int j=1;j<i;j++){
				if(tokens[j]!=NULL){
					strcat(command1," ");
					strcat(command1,tokens[j]);}

				}
				pthread_t id;
				pthread_create(&id,NULL,(void*)system,command1);
				pthread_join(id,NULL);
			}
			else if(!strcmp(tokens[0],"date")){
				if(i>2){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					if(!strcmp(tokens[1],"-u")){
						int n=fork();
						if (n==0){
							execl("date","date",tokens[1],NULL);
						}
						else{
							wait(NULL);
						}
					}
					if(!strcmp(tokens[1],"-R")){
						int n=fork();
						if (n==0){
							execl("date","date",tokens[1],NULL);
						}
						else{
							wait(NULL);
						}
					}
				}
				else{
					int n=fork();
					if (n==0){
						execl("date","date","1",NULL);
					}
					else{
						wait(NULL);
					}
				}
			}


			else if (!strcmp(tokens[0],"pwd")){
				if (i>2){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					if(!strcmp(tokens[1],("-L"))){
						char* x =getenv("PWD");
						printf("%s\n",x);
					}
					if(!strcmp(tokens[1],("-P"))){
						pwd();
					}
				}
				else{
					pwd();
				}
			}
			else if (!strcmp(tokens[0],"cd")){
				if(i>2){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					if(!strcmp(tokens[1],"-")){
						if(!strcmp(previous,"agam")){
							printf("OLDPWD not set\n");
						}
						else{
							strcpy(previous1,previous);
							if (strcmp(previous1,"wow")){
							printf("%s\n",previous);
							cd(previous1);
							strcpy(previous,previous1);
						}
						else{
							printf("%s\n",previous);
							cd(previous);
						}
						}
					}
					else if(!strcmp(tokens[1],"~")){
						getcwd(previous,sizeof(previous));
						cd("/home/gum");
					}
					else{
						getcwd(previous,sizeof(previous));
						cd(tokens[1]);
					}
				}
				else{
				}
			}
			else if (!strcmp(tokens[0],"echo")){
				echo(tokens,i);
			}
			else if(!strcmp(tokens[0],"ls")){
				if(i>2){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					int n=fork();
					if (n==0){
						execl("ls","ls",tokens[1],NULL);
					}
					else{
						wait(NULL);
					}
				}
				else{
					int n=fork();
					if (n==0){
						execl("ls","ls","no",NULL);
					}
					else{
						wait(NULL);
					}
				}
			}
			else if(!strcmp(tokens[0],"rm")){
				if(i>3){
					tokens[2][strcspn(tokens[2],"\n")] = 0;
					int n=fork();
					if (n==0){
						execl("rm","rm",tokens[1],tokens[2],NULL);
					}
					else{
						wait(NULL);
					}
				}
				else{
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					int n=fork();
					if (n==0){
						execl("rm","rm",tokens[1],NULL);
					}
					else{
						wait(NULL);
					}
				}
			}
			else if(!strcmp(tokens[0],"cat")){
				if(i>3){
					tokens[2][strcspn(tokens[2],"\n")] = 0;
					int n=fork();
					if (n==0){
						execl("cat","cat",tokens[1],tokens[2],NULL);
					}
					else{
						wait(NULL);
					}
				}
				else{
					if(i>2){
						tokens[1][strcspn(tokens[1],"\n")] = 0;
						int n=fork();
						if (n==0){
							execl("cat","cat",tokens[1],NULL);
						}
						else{
							wait(NULL);
						}
					}
				}
			}
			else if(!strcmp(tokens[0],"mkdir")){
				if(i>4){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					if (!strcmp(tokens[1],"-m")){
						tokens[2][strcspn(tokens[2],"\n")] = 0;
						if(!strcmp(tokens[2],"a=rwx")){
							tokens[3][strcspn(tokens[3],"\n")] = 0;
							int n=fork();
							if (n==0){
								execl("mkdir","mkdir","-m","0777",tokens[3],NULL);

							}
							else{
								wait(NULL);
							}
						}
						else if(!strcmp(tokens[2],"a=rw")){
							tokens[3][strcspn(tokens[3],"\n")] = 0;
							int n=fork();
							if (n==0){
								execl("mkdir","mkdir","-m","0666",tokens[3],NULL);

							}
							else{
								wait(NULL);
							}
						}
					}
				}
				else if(i>3){
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					if (!strcmp(tokens[1],"-v")){
						tokens[2][strcspn(tokens[2],"\n")] = 0;
						int n=fork();
						if (n==0){
							execl("mkdir","mkdir","-v",tokens[2],NULL);

						}
						else{
							wait(NULL);
						}
					}
				}
				else{
					tokens[1][strcspn(tokens[1],"\n")] = 0;
					int n=fork();
					if (n==0){
						execl("mkdir","mkdir",tokens[1],NULL);
					}
					else{
						wait(NULL);
					}
				}
			}
			else if(strcmp(tokens[0],"")){
				printf("Invalid input\n");
			}
		}


		return 0;
	}