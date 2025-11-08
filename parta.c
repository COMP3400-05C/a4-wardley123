#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    //base case for no arguments provided
    if(argc < 2){
        printf("ERROR: no arguements\n");
        return 1;
    }
    //loop thru the argv array from index 1 to index argc -1
    for(int i = 1; i < argc; i++){
        for(int j = 0; j < argv[i][j]; j++){
            printf("%c", toupper((unsigned char) argv[i][j]));
        }
        if(i < argc-1){
            printf(",");
        }
    }
    return 0;
}
