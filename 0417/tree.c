#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#include "eval.h"
#include "tree.h"

#define MAX_SIZE 100

TreeNode* alloc_node(int data) {
	TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
TreeNode* make_tree(char* postfix) {
	TreeNode* stack[MAX_SIZE];
	char* exp = postfix;
	int top = -1;

	TreeNode* t, *t1, *t2;

	for (int i = 0; postfix[i] != '\0'; i++) {
		if (!is_operator2(exp[i])) {
			stack[++top] = alloc_node(exp[i]);
		}
		else {
			t = alloc_node(exp[i]);
			t1 = stack[top--];
			t2 = stack[top--];
			t->right = t1;            
			t->left = t2;          

			stack[++top] = t;
		}
	}

	return stack[top];
}
int evaluate(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산합니다. \n", op1, root->data, op2);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		default:
			break;

			
		}

	}return 0;
}