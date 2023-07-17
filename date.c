#include <stdio.h>
#include <time.h>
#include <string.h>
int main(int argc, char *argv[])
{	
	if(!strcmp(argv[1],"-u")){
		char str[500];
		struct tm t;
		time_t timez;
		time(&timez);
		struct tm *timer = gmtime(&timez);
	// printf("%s",asctime(ptm));
		strftime(str,500,"%A %d %B %G %r UTC",timer);
		puts(str);

	}
	else if(!strcmp(argv[1],"-R")){
		char str[500];
		struct tm t;
		time_t timez;
		time(&timez);
		struct tm *timer = localtime(&timez);
	// printf("%s",asctime(ptm));
		strftime(str,500,"%a, %d %b %G %T %z",timer);
		puts(str);
	}
	else{
		char str[500];
		struct tm t;
		time_t timez;
		time(&timez);
		struct tm *timer = localtime(&timez);
	// printf("%s",asctime(ptm));
		strftime(str,500,"%A %d %B %G %r %Z",timer);
		puts(str);
	}
	return 0;
}
