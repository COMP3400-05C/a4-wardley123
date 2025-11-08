#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
   

    if(argc < 2){
        printf("ERROR NO Arguments\n");
        return 1;
    }

    int num_args = argc -1;

    if(num_args %2 == 1){
        int middle = (num_args / 2) + 1;
        printf("%s\n",argv[middle]);
    }
    else{
        int middle = num_args / 2;
        int middle2 = middle +1;

        printf("%s %s\n", argv[middle], argv[middle2]);
    }

    if(execvp(argv[1], (char * const *)&argv[1]) == -1){
        perror("exec failed");
        return 1;

    }
    return 0;


}
