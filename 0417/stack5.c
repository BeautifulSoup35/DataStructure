#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_STACK_SIZE 100

#include "stack.h"

// ���� ���� �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (s->capacity -  1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity = s->capacity * 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->top = s->top + 1;
	s->data[s->top] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	} else {
		element e = s->data[s->top];
		s->top = s->top - 1;
		return e;
	}
}

// top�� �ִ� ����(element)�� Ȯ��
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}
