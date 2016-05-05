#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ipc.h>
#include "ltask_3.h"
#include <fcntl.h>

int main (int argc, char** argv)
{
    creat ("key_file", 0644);
    int shmkey = ftok ("key_file", 1);
    int shmid = shmget (shmkey, BUF_SIZE + sizeof(int) + 1, 0666 | IPC_CREAT);
    void *buf = calloc (BUF_SIZE, 1);
    printf ("\n******** [%p] *********\n", shmat (shmid, NULL, 0));

    int input_d = open ("input", O_RDONLY);
    /*void *shmptr = shmat (shmid, NULL, 0);
    printf ("\n*****[%p] [%p]******\n", buf, shmptr);*/
    //memcpy (shmat (shmid, NULL, 0), buf, 1);

    read (input_d, shmat (shmid, NULL, 0), 100);


    //shmdt (shmptr);
    shmctl (shmid, IPC_RMID, 0);
    free (buf);

    return 0;
}
