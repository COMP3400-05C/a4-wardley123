#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    if(argc < 2){
        printf("ERROR no arguments");
        return 1;
    }

    pid_t pid = fork();


    if(pid < 0){
        perror("fork failed");
        return 1;
    }

    else if (pid == 0){
        char *grep_args[] = {"/bin/grep", "-sq", argv[1],argv[2], NULL};
        execv("/usr/bin/grep", grep_args);
        perror("exec failed");
        exit(2);
    }
    else{
        int status;
        waitpid(pid, &status, 0);

        if(WIFEXITED(status)){
            int grep_exit = WEXITSTATUS(status);

            if(grep_exit = 0){
                printf("FOUND %s\n", argv[1]);
                return 0;
            } else if (grep_exit == 2){
                printf("ERROR: %s doesnt exist\n", argv[2]);
                return 2;
            } else{
                printf("ERROR: child process did not exist normally\n", grep_exit);
                return 2;
            }

        }
    }

}
