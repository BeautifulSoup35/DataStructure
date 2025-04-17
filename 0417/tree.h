#ifndef __TREE__
#define __TREE__
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* alloc_node(int data);
TreeNode* make_tree(char *postfix);
int evaluate(TreeNode *root);


#endif
