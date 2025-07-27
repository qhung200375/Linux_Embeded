#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    int status;
    pid_t child_process;

    child_process = fork();
    if (child_process >= 0)
    {
        if (child_process == 0)
        {
            printf("day la pid cua con: %d\n", getpid());
            exit(0);
        }
        else{

            printf("day la pid cua bo: %d, day la pid cua con: %d\n", getpid(), getppid());
            wait(&status);

            if (WIFEXITED(status))
            {
                printf("chuong trinh con ket thuc chuan voi status: %d\n", WEXITSTATUS(status));
            }
            else if (WEXITSTATUS(status))
            {
                printf("chuong trinh con ket thuc bat thuong voi status: %d\n", WTERMSIG(status));
            }
            
            
        }

        
    }
    else printf("chuong trinh khong tao dc process con");
    return 0;
    

}