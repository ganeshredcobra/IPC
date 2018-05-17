#include "lib_mwabi.h"

int AbiInit(void)
{
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok(QNAME, 65);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    return msgid;
}

int AbiSend(int id)
{
    message.mesg_type = 1;
    int ret = msgsnd(id, &message, sizeof(message), 0);
    return ret;
}

int AbiReceive(int id)
{
    int ret = msgrcv(id, &message, sizeof(message), 1, 0);
    return ret;
}

int AbiClose(int id)
{
    // to destroy the message queue
    int ret = msgctl(id, IPC_RMID, NULL);
    return ret;
}


