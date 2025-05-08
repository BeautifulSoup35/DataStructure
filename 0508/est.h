#ifndef __BST__
#define __BST__

typedef char * element;
typedef struct TreeNode {
	element key;
	int freq;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, element key);
TreeNode* new_node(element item);
TreeNode* insert_node(TreeNode* node, element key);
TreeNode* min_value_node(TreeNode* node);
TreeNode* delete_node(TreeNode* root, element key);
void inorder(TreeNode* root);
TreeNode* delete_one(TreeNode* root);
#endif 
