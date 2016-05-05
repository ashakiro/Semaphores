#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ipc.h>
#include "task_3.h"
#include <fcntl.h>

int main (int argc, char** argv)
{
    printf ("%d %d\n", ERANGE, E2BIG);
    return 0;
}
