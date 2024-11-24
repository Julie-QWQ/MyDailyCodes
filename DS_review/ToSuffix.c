#include <stdio.h>
#include "DataStruct.h"
#include <ctype.h>

int main(void) {

    Stack stk = GetStack();
    Queue qe = GetQueue();
    
    char string[50];
    scanf("%s", string);
    const char* ptr = string;

    while (*ptr) {
        if (isdigit(*ptr)) {
            QueuePushElem(qe, *ptr);
        }

        else if (*ptr == '+' || *ptr == '-') {
            while (!IsEmptyStack(stk) && StackTopElem(stk) != '(') {
                QueuePushElem(qe, StackPopElem(stk));
            }
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == '*' || *ptr == '/') {
            char top;
            while (!IsEmptyStack(stk) && ((top = StackTopElem(stk)) == '*' || top == '/')) {
                QueuePushElem(qe, StackPopElem(stk));
            }
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == '(') {
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == ')') {
            while (!IsEmptyStack(stk) && (StackTopElem(stk) != '(')) {
                QueuePushElem(qe, StackPopElem(stk));
            }
            StackPopElem(stk);
        }

        else {
            QueuePushElem(qe, *ptr);
        }

        ++ptr;
    }

    while (!IsEmptyStack(stk)) {
        QueuePushElem(qe, StackPopElem(stk));
    }

    while (!IsEmptyQueue(qe)) {
        char top = QueuePopElem(qe);

        if (isdigit(top)) {
            StackPushElem(stk, top);
        }

        else {
            int oprd1 = StackPopElem(stk) - '0';
            int oprd2 = StackPopElem(stk) - '0';
            int res;

            switch (top) {
                case '+':
                    res = oprd2 + oprd1;
                    break;
                case '-':
                    res = oprd2 - oprd1;
                    break;
                case '*':
                    res = oprd2 * oprd1;
                    break;
                case '/':
                    res = oprd2 / oprd1;
                    break;
            }

            StackPushElem(stk, res + '0');
        }
    }

    printf(" = %d\n", StackPopElem(stk) - '0');

    DeleteQueue(qe);
    DeleteStack(stk);

    puts("Done !");
    return 0;
}

// MakeFile:
// gcc ToSuffix.c Array/Array.c List/List.c Stack/Stack.c Queue/Queue.c -o test.exe
