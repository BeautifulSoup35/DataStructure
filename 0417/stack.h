#ifndef __STACK_H__
#define __STACK_H__
#include "tree.h"

typedef int element;
typedef struct {
	element* data;		// 동적할당; data은 포인터로 정의된다. 
	int capacity;		// 현재 크기
	int top;
} StackType;


void init_stack(StackType* s);
int is_empty(StackType* s);
int is_full(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
element peek(StackType* s);

#endif
