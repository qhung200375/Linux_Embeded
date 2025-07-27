#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>


int main() {

    pid_t child_process;

    child_process = fork();

    if (child_process >= 0)
    {
        if (child_process == 0)
        {
            for (size_t i = 0; i < 5; i++)
            {
                printf("pid cua cha la: %d\n", getppid());
                sleep(1);
            }
            
        }
        else {
            exit(0);

        }
    }
    else{

        printf("khong toa duoc tien trinh con");
    }
    
}