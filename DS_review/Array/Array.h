#ifndef __ARRAY_H_
#define __ARRAY_H_

#include "../DS_config.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int MaxSize;
    int ArrLen;
    ArrayElemType* Data;
} ANode;

typedef ANode* Array;

Array GetArray(int maxsize);

bool ArrayExpansion(Array arr, int newsize);

bool ArrayResize(Array arr, int length);

ArrayElemType ArrayGetElem(const Array arr, int index);

void ArraySetElem(Array arr, int index, ArrayElemType value);

void ArrayPushElem(Array arr, ArrayElemType value);

ArrayElemType ArrayPopElem(Array arr);

static inline bool IsEmptyArray(const Array arr) {
    return !arr->ArrLen;
}

static inline bool IsFullArray(const Array arr) {
    return arr->ArrLen == arr->MaxSize;
}

static inline int GetArrLen(const Array arr) {
    return arr->ArrLen;
}

static inline int GetArrCapacity(const Array arr) {
    return arr->MaxSize;
}

void PrintArray(const Array arr);

void DeleteArray(Array arr);

#endif
