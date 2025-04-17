#define _CRT_NONSTDC_NO_DEPRECATE 
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "eval.h"
#include "infix2post.h"

int char2int(char *expression, int exp[]) {
	int i = 0;
	for (char *s = strtok(expression, " "); 
		s != NULL; s = strtok(NULL, " "), i++) {
		exp[i] = isdigit(*s) ? atoi(s): *s;
	}
	return i;//arry����
}

char* array2string(int result[], int n) {
	char buf[BUFSIZ];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (is_operator2(result[i]))
			index += sprintf(&buf[index], "%c ", result[i]);
		else
			index += sprintf(&buf[index], "%d ", result[i]);
	}
	return strdup(buf);
}


// �������� �켱������ ��ȯ�Ѵ�.
int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�� ���� -> ���� ǥ�� ����
char* infix_to_post(char expression[]){
	int exp[MAX_SIZE];
	int result[MAX_SIZE];
	int len = char2int(expression, exp);
	int i = 0;
	int ch, top_op;

	// ����� �޾ư��� ����
	int  ir = 0;

	StackType s;

	init_stack(&s);					// ���� �ʱ�ȭ 
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (is_operator2(ch)) {
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				result[ir] = pop(&s);
				ir++;
			}
			push(&s, ch);
		} else if (ch == '(')  { // ���� ��ȣ
			push(&s, ch);
		}
		else if (ch == ')') { // ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				result[ir] = top_op;
				ir++;
				top_op = pop(&s);
			}
		} else { 		// �ǿ�����
			result[ir] = ch;
			ir++;
		}
	}
	while (!is_empty(&s)) {	// ���ÿ� ����� �����ڵ� ���
		result[ir] = pop(&s);
		ir++;
	}
	free(s.data); // ���� ������ �����Ѵ�.

	return array2string(result, ir);
}

void print_expression(int exp[], int n) {
	for (int i = 0; i < n; i++) {
		if (is_operator(exp[i]))
			printf("%c ", exp[i]);
		else
			printf("%d ", exp[i]);
	}
	printf("\n");
	return;
}



