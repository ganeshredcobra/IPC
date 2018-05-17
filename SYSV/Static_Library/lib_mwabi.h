#ifndef MWABI_H_INCLUDED
#define MWABI_H_INCLUDED

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define QNAME   "progfile"

// structure for message queue
struct mesg_buffer {
	long mesg_type;
    unsigned char   cmd; /* CMD id of the vehicle signal */
    unsigned char   subCmd; /* Sub Cmd id of the vehicle signal */
    unsigned char   divFactor; /* Division factor if applicable */
    unsigned int  data;
} message;

int AbiInit(void);

int AbiSend(int msgid);

int AbiReceive(int msgid);

int AbiClose(int msgid);



#endif // MWABI_H_INCLUDED
