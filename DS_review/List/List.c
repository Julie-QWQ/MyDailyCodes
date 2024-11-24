#include "List.h"
#include <stdio.h>
#include <stdlib.h>

List GetList(void) {
    List ret = (List)malloc(sizeof(LNode));
    ret->Header = (Iter)malloc(sizeof(Node));
    ret->Header->next = NULL;
    ret->Tail = ret->Header;
    ret->LstLen = 0;
    return ret;
}

void ListInsert(List lst, Iter it, ListElemType value) {
    if (it == NULL) {
        puts("Error in ListInsert: Iter not in list !");
        return ;
    }
    Iter NewNode = (Iter)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->next = it->next;
    if (it == lst->Tail) {
        lst->Tail = NewNode;
    }
    it->next = NewNode;
    lst->LstLen++;
}

void ListErase(List lst, Iter it) {
    if (it == NULL) {
        puts("Error in ListErase: Iter not in list !");
        return ;
    }
    if (it == lst->Tail) {
        puts("Error in ListErase: Iter at tail of list !");
        return ;
    }
    Iter tmp = it->next;
    if (tmp == lst->Tail) {
        lst->Tail = it;
    }
    it->next = tmp->next;
    free(tmp);
    lst->LstLen--;
}

void PrintList(const List lst) {
    puts("List: ");
    for (Iter it = lst->Header->next; it != NULL; IterBump(&it)) {
        printf("%d ", it->data);
    }
    putchar('\n');
}

void ClearList(List lst) {
    Iter it = lst->Header->next;
    Iter tmp;
    while (it != NULL) {
        tmp = it->next;
        free(it);
        it = tmp;
    }
    lst->Tail = lst->Header;
    lst->LstLen = 0;
    lst->Header->next = NULL;
}

void DeleteList(List lst) {
    ClearList(lst);
    free(lst->Header);
    lst = NULL;
}
