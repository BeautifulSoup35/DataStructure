#ifndef __IN2POST_H__
#define __IN2POST_H__

#define DELIMIT " "

int char2int(char* expression, int exp_int[]);
void print_expression(int exp[], int n);
int prec(char op);
char* infix_to_post(char expression[]);
#endif
