#include "kernel/types.h"
#include "user/user.h"

int main()
{
    int ticks = uptime();
    fprintf(1, "%d\n", ticks);
    exit(0);
}