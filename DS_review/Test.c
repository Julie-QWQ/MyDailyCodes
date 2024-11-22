#include <stdio.h>
#include "Array/Array.h"
#include "List/List.h"

int main(void) {
    List lst = GetList();
    // ArrayResize(arr, maxSize);
    for (int i=0; i<100; ++i) {
        ListPushElem(lst, i*i);
    }
    PrintList(lst);
    DeleteList(lst);


    return 0;
}