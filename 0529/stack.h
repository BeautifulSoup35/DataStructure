#ifndef __STACK__
#define __STACK__

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s);// ���� �ʱ�ȭ �Լ�
int is_empty(StackType* s);// ���� ���� ���� �Լ�
int is_full(StackType* s);// ��ȭ ���� ���� �Լ�
void push(StackType* s, element item);//����
element pop(StackType* s);//����
element rand_pop(StackType* s);
void change(StackType* s, int selected);
void swap(element *a, element *b);
#endif