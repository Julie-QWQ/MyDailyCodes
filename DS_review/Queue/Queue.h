#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "../List/List.h"

typedef struct {
    List data;
} QNode;

typedef QNode* Queue;

Queue GetQueue(void);

static inline void QueuePushElem(Queue qe, ElemType value) {
    ListInsert(qe->data, qe->data->Tail, value);
}

ElemType QueuePopElem(Queue qe);

void DeleteQueue(Queue qe);

static inline bool IsEmptyQueue(const Queue qe) {
    return IsEmptyList(qe->data);
}


#endif