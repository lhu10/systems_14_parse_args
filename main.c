#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line){
    char *curr, *token;
    char **args; 
    int i;
    i = 0; 
    curr = line; 

    while((token = strsep(&curr, " ")) != NULL){
        args[i] = token; 
        //printf("args[%d]: %s\n", i, args[i]);
        i++;
    }
    args[i] = NULL; 

    return args; 
}

int main(int argc, char **argv){
    char buff[100];

    printf("Enter a command: ");
    fgets(buff, sizeof(buff), stdin); 
    //gets rid of new line
    char *sp; 
    if((sp = strchr(buff, '\n')) != NULL){
        *sp = '\0';
    }
    
    char **args = parse_args(buff);
    execvp(args[0], args);
    
    return 0; 
}
