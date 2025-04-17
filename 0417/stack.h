#ifndef __STACK_H__
#define __STACK_H__
#include "tree.h"

typedef int element;
typedef struct {
	element* data;		// �����Ҵ�; data�� �����ͷ� ���ǵȴ�. 
	int capacity;		// ���� ũ��
	int top;
} StackType;


void init_stack(StackType* s);
int is_empty(StackType* s);
int is_full(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
element peek(StackType* s);

#endif
