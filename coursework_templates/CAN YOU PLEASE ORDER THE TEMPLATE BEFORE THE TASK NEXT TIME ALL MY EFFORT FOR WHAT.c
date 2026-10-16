#include "kernel/types.h"
#include "user/user.h"
#include <stddef.h>

int main(int argc, char *argv[])
{
    char input[100];
    while (1)
    {
        
        fprintf(2, "Please enter command and press enter (type 'q' to exit):");
        scanf("%s", input);
        if(strcmp(input,"q") == 0)
        {
            break;
        }
        else
        {
            char *args[2];
            args[0] = input;
            args[1] = NULL;
            int processID = fork();
            if (processID < 0)
            {
                fprintf(2, "Error: ");
                exit(1);
            }
            else if (processID == 0)
            {
                exec(args[0], args);
                
                fprintf(2, "Error: ");
                exit(1);
            }
            else
            {

                wait(0);
            }
        }
    }
    exit(0);
}