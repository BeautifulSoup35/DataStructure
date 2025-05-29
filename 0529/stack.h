#ifndef __STACK__
#define __STACK__

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s);// 스택 초기화 함수
int is_empty(StackType* s);// 공백 상태 검출 함수
int is_full(StackType* s);// 포화 상태 검출 함수
void push(StackType* s, element item);//삽입
element pop(StackType* s);//삭제
element rand_pop(StackType* s);
void change(StackType* s, int selected);
void swap(element *a, element *b);
#endif