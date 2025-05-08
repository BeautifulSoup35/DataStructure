#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "est.h"
// ��ȯ���� Ž�� �Լ�
TreeNode * search(TreeNode * node, element key)
{
	if (node == NULL) return NULL;
	//if (key == node->key) return node; 
	if (strcmp(key, node->key) == 0) return node;
	else if (strcmp(key , node->key) <0)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode * new_node(element item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = strdup(item);// heap�� �����ؼ� �����ͷ� ��ȯ����
	temp->freq = 1;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode * insert_node(TreeNode * node, element key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (strcmp(key , node->key) < 0 )
		node->left = insert_node(node->left, key);
	else if (strcmp(key , node->key) >0)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}
// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� 
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�. 


// ���� ��ȸ
void inorder(TreeNode * root) {
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%s %d] \n", root->key, root->freq);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (strcmp(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (strcmp(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root->key);
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root->key);
			free(root);
			return temp;
		}
		// �� ��° ���
		TreeNode* temp = min_value_node(root->right);
		free(root->key);

		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->key = strdup(temp->key);//�߰�
		root->freq = temp->freq;//�߰�
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
TreeNode* delete_one(TreeNode* root) {
	if (root == NULL) return NULL;
	root->left = delete_one(root->left);
	root->right = delete_one(root->right);

	if (root->freq == 1) {
		root = delete_node(root, root->key);
	}
	return root;
}

