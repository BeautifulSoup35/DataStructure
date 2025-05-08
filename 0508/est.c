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
// 순환적인 탐색 함수
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
	temp->key = strdup(item);// heap에 복사해서 포인터로 반환해줌
	temp->freq = 1;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode * insert_node(TreeNode * node, element key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (strcmp(key , node->key) < 0 )
		node->left = insert_node(node->left, key);
	else if (strcmp(key , node->key) >0)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 


// 중위 순회
void inorder(TreeNode * root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("[%s %d] \n", root->key, root->freq);  // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (strcmp(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (strcmp(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		TreeNode* temp = min_value_node(root->right);
		free(root->key);

		// 중외 순회시 후계 노드를 복사한다. 
		root->key = strdup(temp->key);//추가
		root->freq = temp->freq;//추가
		// 중외 순회시 후계 노드를 삭제한다. 
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

