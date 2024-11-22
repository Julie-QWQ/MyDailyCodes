#include <stdio.h>
#include "DataStruct.h"
#include <ctype.h>

int main(void) {

    Stack stk = GetStack();
    
    char string[50];
    scanf("%s", string);
    const char* ptr = string;

    while (*ptr) {
        if (isdigit(*ptr)) {
            putchar(*ptr);
        }

        else if (*ptr == '+' || *ptr == '-') {
            while (!IsEmptyStack(stk) && StackTopElem(stk) != '(') {
                putchar(StackPopElem(stk));
            }
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == '*' || *ptr == '/') {
            char top;
            while (!IsEmptyStack(stk) && ((top = StackTopElem(stk)) == '*' || top == '/')) {
                putchar(StackPopElem(stk));
            }
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == '(') {
            StackPushElem(stk, *ptr);
        }

        else if (*ptr == ')') {
            while (!IsEmptyStack(stk) && (StackTopElem(stk) != '(')) {
                putchar(StackPopElem(stk));
            }
            StackPopElem(stk);
        }

        else {
            putchar(*ptr);
        }

        ++ptr;
    }

    while (!IsEmptyStack(stk)) {
        putchar(StackPopElem(stk));
    }

    putchar('\n');

    DeleteStack(stk);

    puts("Done !");
    return 0;
}

// MakeFile:
// gcc Test.c Array/Array.c List/List.c Stack/Stack.c Queue/Queue.c -o test.exe
