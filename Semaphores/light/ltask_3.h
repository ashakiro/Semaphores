//#define DEBUG_MOD
#ifdef DEBUG_MOD
#define DEBUG
#else
#define DEBUG if(0)
#endif

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



enum SOME_CONSTS
{
    BUF_SIZE = 4,
    NSEMS = 9,
    SOPS_SIZE = 9,
};

enum SEM_NUMS
{
    SEM_SND_CAN_START = 0,
    SEM_RCV_CAN_START,
    SEM_RCV_READY,
    SEM_SND_READY,
//  SEM_SND_CAN_WORK,
//  SEM_RCV_CAN_WORK,
    SEM_SND_ALIVE,
    SEM_RCV_ALIVE,
    SEM_SND_MUTEX,
    SEM_RCV_MUTEX,
    SEM_SUCCESS,
};

int set_sop (struct sembuf *sops, int sop_num,
             unsigned short sem_num, short sem_op, short sem_flg);
