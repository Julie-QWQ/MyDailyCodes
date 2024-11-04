#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 50

typedef int DataType;

typedef enum {
    RootBiggest,
    RootSmallest,
} HeapType;

typedef struct {
    DataType heap[MAXSIZE];
    int size;
    HeapType type;
 } Heap;

void swap(DataType* data1, DataType* data2) {
    DataType tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

int cmp(DataType data1, DataType data2, HeapType type) {
    int ret;
    if (data1 > data2) ret = 1;
    else if (data1 < data2) ret = -1;
    else ret = 0;
    return (type==RootBiggest)? ret: -ret;
}

void ElemSink(Heap* pHeap, int position) {
    int pos = position;
    while (1) {
        if (pos*2 > pHeap->size)
            break;
        
        else if (pos*2 == pHeap->size) {
            if (cmp(pHeap->heap[pos-1], pHeap->heap[pos*2-1], pHeap->type) < 0)
                swap(pHeap->heap + pos-1, pHeap->heap + pos*2-1);
            break;
        }
        
        else {
            if (cmp(pHeap->heap[pos*2+1-1], pHeap->heap[pos*2-1], pHeap->type) < 0) {
                if (cmp(pHeap->heap[pos-1], pHeap->heap[pos*2-1], pHeap->type) < 0) {
                    swap(pHeap->heap + pos-1, pHeap->heap + pos*2-1);
                    pos *= 2;
                } else break;
            } else {
                if (cmp(pHeap->heap[pos-1], pHeap->heap[pos*2+1-1], pHeap->type) < 0) {
                    swap(pHeap->heap + pos-1, pHeap->heap + pos*2+1-1);
                    pos = 2*pos + 1;
                } else break;
            }
        }
    }
}

void ElemFloat(Heap* pHeap, int position) {
    int pos = position;
    while (pos > 1) {
        if (cmp(pHeap->heap[pos-1], pHeap->heap[pos/2-1], pHeap->type) > 0) {
            swap(pHeap->heap + pos-1, pHeap->heap + pos/2-1);
            pos /= 2;
        } else break;
    }
}

bool CreateHeap(Heap* pHeap, DataType* initList, int size, HeapType type) {
    if (size > MAXSIZE) return false;
    memcpy(pHeap->heap, initList, size*sizeof(DataType));
    pHeap->size = size;
    pHeap->type = type;
    for (int i=size/2; i>=1; --i)
        ElemSink(pHeap, i);
    return true;
}

void HeapPush(Heap* pHeap, DataType data) {
    if (pHeap->size == MAXSIZE) return;
    pHeap->heap[pHeap->size+1-1] = data;
    ElemFloat(pHeap, pHeap->size+1);
    ++pHeap->size;
}

DataType HeapPop(Heap* pHeap) {
    if (!pHeap->size) return -1;
    DataType ret = *pHeap->heap;
    swap(pHeap->heap, pHeap->heap + pHeap->size-1);
    --pHeap->size;
    ElemSink(pHeap, 1);
    return ret;
}

// --------------------------------------------------------------------------------------

int main(void) {
    DataType init[] = {114,514,1919,810,666,8888};
    DataType add[] = {250,999,290,414};
    Heap heap;
    CreateHeap(&heap, init, sizeof(init)/sizeof(*init), RootSmallest);
    for (int i=1; i<=(int)(sizeof(add)/sizeof(*add)); ++i)
        HeapPush(&heap, add[i-1]);
    DataType toPrint;
    while ((toPrint = HeapPop(&heap)) != -1)
        printf("%d ", toPrint);
    return 0;
}
