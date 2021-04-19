#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char str[1024];
	char *text1 = NULL;
	char *text2 = NULL;
	char *command1[4];
	char *command2[5];

	int i;
	char *pch;

	int fd[2];
	int fdr;
	pid_t pid;

	while(1)
	{
		for(i=0;i<1024;i++){
			str[i]='\0';
		}
		command1[0] = NULL;
		command2[0] = NULL;
		printf("$");
		fgets(str, sizeof(str), stdin);
		
		if(feof(stdin)){
			printf("Ctrl+D exit \n");
			exit(0);
		}
		str[strlen(str)-1] = '\0';
		fflush(stdin);

		if(strchr(str,'|') != NULL){
			text1 = strtok(str, "|");
			text2 = strtok(NULL, "|");
			strcat(text1, "\0");
			strcat(text2, "\0");
			i=0;
			pch = strtok(text1, " ");
			while(pch != NULL && i<3)
			{
				command1[i] =pch;
				pch=strtok(NULL, " ");
				i++
			}

		}
	}
}
