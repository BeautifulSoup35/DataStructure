#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "eval.h"

int is_operator(char ch) {
	if (ch == '+') return ch;
	if (ch == '-') return ch;
	if (ch == '*') return ch;
	if (ch == '/') return ch;
	if (ch == '(') return ch;
	if (ch == ')') return ch;
	return 0;
}

int is_operator2(char ch) {
	if (ch == '+') return ch;
	if (ch == '-') return ch;
	if (ch == '*') return ch;
	if (ch == '/') return ch;
	return 0;
}

// 후위 표기 수식 계산 함수
int evaluation(int exp[], int n) {
	int op1, op2, i = 0;
	int len = n;
	int ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (is_operator2(ch)) {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //연산을 수행하고 스택에 저장 
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
		else {
			push(&s, ch);
		}
	}
	int result = pop(&s);
	free(s.data);
	return result;
}

