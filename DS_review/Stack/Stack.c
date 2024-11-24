#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack GetStack(void) {
    Stack ret = (Stack)malloc(sizeof(SNode));
    ret->data = GetList();
    return ret;
}

StackElemType StackPopElem(Stack stk) {
    if (IsEmptyStack(stk)) {
        puts("Error in StackPopElem: Stack is empty !");
        return ;
    }
    StackElemType ret = stk->data->Header->next->data;
    ListErase(stk->data, stk->data->Header);
    return ret;
}

StackElemType StackTopElem(Stack stk) {
    if (IsEmptyStack(stk)) {
        puts("Error in StackTopElem: Stack is empty !");
        return ;
    }
    return stk->data->Header->next->data;
}

void DeleteStack(Stack stk) {
    DeleteList(stk->data);
    free(stk);
    stk = NULL;
}
