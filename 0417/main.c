#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#include "eval.h"
#include "infix2post.h"
#include "tree.h"

int main(void)
{
	char expression[BUFSIZ] = "3 * 4 + 16 + 25";
	printf("%s\n", expression);
	char* postfix = infix_to_post(expression);  // 프로그램 4.8을 참조해라.
	printf("%s\n", postfix);
	TreeNode* root = make_tree(postfix);
	int value = evaluate(root ); // 프로그램 8,6을 참조해라.
	printf("수식의 값은 %d입니다.\n", value);
	free(postfix);
	return 0;
}
