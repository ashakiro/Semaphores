#define ASSERT_snd( cond, message ) \
 if (!(cond)) {                     \
    printf ("(sender) ");           \
    perror (message);               \
    putchar ('\n');                 \
    return -1;                      \
 }

#define ASSERT_rcv( cond, message ) \
 if (!(cond)) {                     \
    printf ("(reciever) ");         \
    perror (message);               \
    putchar ('\n');                 \
    return -1;                      \
 }

#define smart_ASSERT_snd( cond, message ) \
 if (!(cond)) {                           \
    semctl (semid, IPC_RMID, 0);          \
    shmctl (shmid, IPC_RMID, 0);          \
    printf ("(sender) ");                 \
    perror (message);                     \
    putchar ('\n');                       \
    return -1;                            \
 }

#define smart_ASSERT_rcv( cond, message ) \
 if (!(cond)) {                           \
    semctl (semid, IPC_RMID, 0);          \
    shmctl (shmid, IPC_RMID, 0);          \
    printf ("(reciever) ");               \
    perror (message);                     \
    putchar ('\n');                       \
    return -1;                            \
 }



const int BUF_SIZE = 1024;
const int NSEMS = 9;
const int SOPS_SIZE = 9;

const int SEM_SND_CAN_START = 0;
const int SEM_RCV_CAN_START = 1;
const int SEM_RCV_READY     = 2;
const int SEM_SND_READY     = 3;
const int SEM_SND_ALIVE     = 4;
const int SEM_RCV_ALIVE     = 5;
const int SEM_SND_MUTEX     = 6;
const int SEM_RCV_MUTEX     = 7;
const int SEM_SUCCESS       = 8;

int set_sop (struct sembuf *sops, int sop_num,
             unsigned short sem_num, short sem_op, short sem_flg);
