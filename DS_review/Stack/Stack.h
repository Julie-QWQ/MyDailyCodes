#ifndef __STACK_H_
#define __STACK_H_

#include "../List/List.h"
#include <stdbool.h>

typedef struct {
    List data;
} SNode;

typedef SNode* Stack;

Stack GetStack(void);

static inline void StackPushElem(Stack stk, StackElemType value) {
    ListInsert(stk->data, stk->data->Header, value);
}

StackElemType StackPopElem(Stack stk);

StackElemType StackTopElem(Stack stk);

void DeleteStack(Stack stk);

static inline bool IsEmptyStack(const Stack stk) {
    return IsEmptyList(stk->data);
}

#endif
