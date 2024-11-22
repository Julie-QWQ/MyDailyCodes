#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack GetStack(void) {
    Stack ret = (Stack)malloc(sizeof(SNode));
    ret->data = GetList();
    return ret;
}

ElemType StackPopElem(Stack stk) {
    if (IsEmptyStack(stk)) {
        puts("Error in StackPopElem: Stack is empty !");
        return ;
    }
    ElemType ret = stk->data->Header->next->data;
    ListErase(stk->data, stk->data->Header);
    return ret;
}

void DeleteStack(Stack stk) {
    DeleteList(stk->data);
    free(stk);
    stk = NULL;
}
