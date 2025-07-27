#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

    pid_t child_process;
    child_process = fork();
    if (child_process >= 0)
    {
        if (child_process == 0)
        {
            exit(0);
        }
        else {
            sleep(10);
        }
    }
    else {

        printf("khong tao duoc process con");
    }



}