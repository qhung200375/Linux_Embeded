#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	int status;
	pid_t child_process;

	setenv("my_command", "ls", 1);
	child_process = fork();

	if(child_process >= 0){
		if(child_process == 0){
			char *cmd = getenv("my_command");
			if(cmd != NULL){
				printf("doc duoc gia tri tu cmd la: %s\n", cmd);
				execlp(cmd, cmd, NULL);
			}
			else printf("khong tim thay bien moi truong");
		}


		else {
			wait(&status);
		
		
		
		}

	}
	else printf("khong tao duoc tien trinh con");
}




