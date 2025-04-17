#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_STACK_SIZE 100

#include "stack.h"

// 스택 생성 함수
void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
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
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	} else {
		element e = s->data[s->top];
		s->top = s->top - 1;
		return e;
	}
}

// top에 있는 원소(element)를 확인
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}
