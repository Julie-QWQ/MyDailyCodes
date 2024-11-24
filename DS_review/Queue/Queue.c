#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue GetQueue(void) {
    Queue ret = (Queue)malloc(sizeof(QNode));
    ret->data = GetList();
    return ret;
}

QueueElemType QueuePopElem(Queue qe) {
    if (IsEmptyQueue(qe)) {
        puts("Error in QueuePopElem: Queue is empty !");
        return ;
    }
    QueueElemType ret = qe->data->Header->next->data;
    ListErase(qe->data, qe->data->Header);
    return ret;
}

void DeleteQueue(Queue qe) {
    DeleteList(qe->data);
    free(qe);
    qe = NULL;
}
