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
	return i;//arry길이
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


// 연산자의 우선순위를 반환한다.
int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
char* infix_to_post(char expression[]){
	int exp[MAX_SIZE];
	int result[MAX_SIZE];
	int len = char2int(expression, exp);
	int i = 0;
	int ch, top_op;

	// 결과를 받아가는 변수
	int  ir = 0;

	StackType s;

	init_stack(&s);					// 스택 초기화 
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (is_operator2(ch)) {
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				result[ir] = pop(&s);
				ir++;
			}
			push(&s, ch);
		} else if (ch == '(')  { // 왼쪽 괄호
			push(&s, ch);
		}
		else if (ch == ')') { // 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				result[ir] = top_op;
				ir++;
				top_op = pop(&s);
			}
		} else { 		// 피연산자
			result[ir] = ch;
			ir++;
		}
	}
	while (!is_empty(&s)) {	// 스택에 저장된 연산자들 출력
		result[ir] = pop(&s);
		ir++;
	}
	free(s.data); // 스택 공간을 해제한다.

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



