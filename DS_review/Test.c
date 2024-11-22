#include <stdio.h>
#include "DataStruct.h"

int main(void) {

    Stack stk = GetStack();
    for (int i=1; i<=100; ++i) {
        StackPushElem(stk, i*i);
    }
    int cnt = 1;
    while (!IsEmptyStack(stk)) {
        printf("%d: %d\n", cnt++, StackPopElem(stk));
    }
    putchar('\n');
    DeleteStack(stk);

    puts("Done !");
    return 0;
}

// MakeFile:
// gcc Test.c Array/Array.c List/Lists.c Stack/Stack.c Queue/Queue.c -o test.exe
