#include "Array.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Array GetArray(int maxsize) {
    if (maxsize < 0) {
        puts("Error in GetArray: Array maxsize invalid !");
        return NULL;
    }
    Array ret = (Array)malloc(sizeof(ANode));
    ret->MaxSize = maxsize;
    ret->ArrLen = 0;
    ret->Data = (ArrayElemType*)malloc(ret->MaxSize * sizeof(ArrayElemType));
    return ret;
}

bool ArrayExpansion(Array arr, int newsize) {
    if (newsize < 0) {
        puts("Error in ArrayExpansion: Target size cannot be negative !");
        return false;
    }
    else if (newsize <= arr->MaxSize) {
        puts("Error in ArrayExpansion: Target size not larger than current maxsize !");
        return false;
    }
    ArrayElemType* new = (ArrayElemType*)malloc(newsize * sizeof(ArrayElemType));
    memcpy(new, arr->Data, arr->ArrLen * sizeof(ArrayElemType));
    free(arr->Data);
    arr->Data = new;
    arr->MaxSize = newsize;
    return true;
}

bool ArrayResize(Array arr, int length) {
    if (length < 0) {
        puts("Error in ArrayResize: Target length cannot be negative !");
        return false;
    } else if (length > arr->MaxSize) {
        puts("Error in ArrayResize: Target length larger than array maxsize !");
        return false;
    }
    arr->ArrLen = length;
    return true;
}

ArrayElemType ArrayGetElem(const Array arr, int index) {
    if (index < 0 || index >= arr->ArrLen) {
        puts("Error in ArrayGetElem: Array index out of range !");
        return ;
    }
    return arr->Data[index];
}

void ArraySetElem(Array arr, int index, ArrayElemType value) {
    if (index < 0 || index >= arr->ArrLen) {
        puts("Error in ArraySetElem: Array index out of range !");
        return ;
    }
    arr->Data[index] = value;
}

void ArrayPushElem(Array arr, ArrayElemType value) {
    if (arr->ArrLen == arr->MaxSize) {
        ArrayExpansion(arr, 2 * arr->MaxSize);
    }
    arr->Data[arr->ArrLen++] = value;
}

ArrayElemType ArrayPopElem(Array arr) {
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

void DeleteArray(Array arr) {
    free(arr->Data);
    arr = NULL;
}
