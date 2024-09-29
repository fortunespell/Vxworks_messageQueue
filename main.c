#include <stdio.h>
#include <vxWorks.h>
#include <taskLib.h>
#include <msgQLib.h>

#define MAX_MSGS 5
#define MAX_MSG_LEN 100
#define MESSAGE "RV College of Engineering"

void task1(), task2();
MSG_Q_ID MsgQId;

void start (void) {
    printf("\nBeginning of start task\n");

    /* Spawning task1 and task2 from start task */
    taskSpawn("task1", 80, 0, 2000, (FUNCPTR) task1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskSpawn("task2", 90, 0, 2000, (FUNCPTR) task2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    printf("\nEnd of start task\n");
}

void task1 (void) {
    /* Message queue created from task1 */
    MsgQId = msgQCreate(MAX_MSGS, MAX_MSG_LEN, MSG_Q_PRIORITY);
    if (MsgQId == NULL) {
        printf("Error creating message queue\n");
        return;
    }

    /* Sending message to task2 */
    if (msgQSend(MsgQId, MESSAGE, sizeof(MESSAGE), WAIT_FOREVER, MSG_PRI_NORMAL) == ERROR) {
        printf("Error sending message\n");
        return;
    }
}

void task2 (void) {
    char msgBuf[MAX_MSG_LEN];

    /* Receiving message in task2 */
    if (msgQReceive(MsgQId, msgBuf, MAX_MSG_LEN, WAIT_FOREVER) == ERROR) {
        printf("Error receiving message\n");
        return;
    }

    printf("Message from task 1: %s\n", msgBuf);
}
