#ifndef __LIST_H_
#define __LIST_H_

#include <stdbool.h>
#include <stddef.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

typedef Node* Iter;

typedef struct {
    Iter Header;
    Iter Tail;
    int LstLen;
} LNode;

typedef LNode* List;

List GetList(void);

static inline Iter GetHeader(const List lst) {
    return lst->Header;
}
static inline Iter GetTail(const List lst) {
    return lst->Tail;
}

void ListPushElem(List lst, ElemType value);

ElemType ListPopElem(List lst, ElemType value);

static inline void IterSetElem(Iter lst, ElemType value) {
    lst->data = value;
}

static inline ElemType IterGetElem(const Iter it) {
    return it->data;
}

static inline Iter IterNext(const Iter it) {
    return it->next;
}

static inline Iter IterBump(Iter* it) {
    return *it = (*it)->next;
}

static inline Iter IterJump(Iter* it, int steps) {
    for (int i=1; i<=steps && *it != NULL; ++i, IterBump(it));
    return *it;
}

static inline bool IsEmptyList(const List lst) {
    return !lst->LstLen;
}

static inline int GetListLen(const List lst) {
    return lst->LstLen;
}

void ListInsert(List lst, Iter it, ElemType value);

void ListErase(List lst, Iter it);

void PrintList(const List lst);

void ClearList(List lst);

void DeleteList(List lst);

#endif