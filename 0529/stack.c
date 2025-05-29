#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

#include "stack.h"

// ���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}


element rand_pop(StackType* s) {
	
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	int selected = rand() % (s->top +1) ;
	//0~top������ �� ��������
	//selected �� top 
	
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