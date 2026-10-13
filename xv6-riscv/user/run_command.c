#include "kernel/types.h"
#include "user/user.h"

int main(void)
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
    }
    exit(0);
}