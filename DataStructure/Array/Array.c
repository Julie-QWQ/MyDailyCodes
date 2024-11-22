#include "Array.h"
#include <stdio.h>
#include <stdbool.h>

Array GetArray(int maxsize) {
    Array ret = (Array)malloc(sizeof(ANode));
    ret->MaxSize = maxsize;
    ret->ArrLen = 0;
    ret->Data = (ElemType*)malloc(ret->MaxSize * sizeof(ElemType));
    return ret;
}

bool ArrayResize(Array arr, int length) {
    if (length < 0 || length > arr->MaxSize) {
        puts("Error in ArrayResize: Target length is larger than array maxsize !");
        return false;
    }
    return arr->ArrLen = length;
}

ElemType ArrayGetElem(const Array arr, int index) {
    if (index < 0 || index >= arr->ArrLen) {
        puts("Error in ArrayGetElem: Array index out of range !");
        return ;
    }
    return arr->Data[index];
}

void ArraySetElem(Array arr, int index, ElemType value) {
    if (index < 0 || index >= arr->ArrLen) {
        puts("Error occurred in Array function: ArraySetElem");
        puts("Array index out of range !");
        return ;
    }
    arr->Data[index] = value;
}

bool ArrayPushElem(Array arr, ElemType value) {
    if (arr->ArrLen == arr->MaxSize) {
        puts("Error in ArrayPushElem: Array is full !");
        return false;
    }
    return arr->Data[arr->ArrLen++] = value;
}

ElemType ArrayPopElem(Array arr) {
    if (!arr->ArrLen) {
        puts("Error in ArrayPopElem: Array is empty !");
        return ;
    }
    return arr->Data[--arr->ArrLen];
}

void PrintArray(const Array arr) {
    puts("Array: ");
    for (int i=0; i<arr->ArrLen; ++i) {
        printf("%d ", arr->Data[i]);
    }
    putchar('\n');
}

