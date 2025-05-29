#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

#include "stack.h"

// 스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}


element rand_pop(StackType* s) {
	
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	int selected = rand() % (s->top +1) ;
	//0~top사이의 값 나오도록
	//selected 와 top 
	
	//swap(s->stack[selected], s->stack[s->top]);
	swap(&(s->stack[selected]), &(s->stack[s->top]));
	

	return s->stack[(s->top)--];
}
void swap(element* a, element* b) {
    element bin = *a;
    *a = *b;
    *b = bin;
}

void change(StackType* s, int selected) {
	element bin;

	bin = s->stack[selected];
	s->stack[selected] = s->stack[s->top];
	s->stack[s->top - 1] = bin;

}
//change(s, selected);