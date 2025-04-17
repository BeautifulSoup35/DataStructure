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
	char* postfix = infix_to_post(expression);  // ���α׷� 4.8�� �����ض�.
	printf("%s\n", postfix);
	TreeNode* root = make_tree(postfix);
	int value = evaluate(root ); // ���α׷� 8,6�� �����ض�.
	printf("������ ���� %d�Դϴ�.\n", value);
	free(postfix);
	return 0;
}
