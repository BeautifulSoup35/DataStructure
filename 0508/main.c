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
int main(void)
{
	//���� ���� �ڵ�
	const char* fname = "news.txt";
	FILE* fin = fopen(fname, "r");
	if (fin == NULL) {
		fprintf(stderr, "Cant open %s\n", fname);
		exit(EXIT_FAILURE);// �������������
	}
	TreeNode* root = NULL;
	char* word[BUFSIZ];//�޸𸮸� �������Ѵ�
	while (fscanf(fin, "%s", word) == 1) {// 1�ϵ��� ����?
		TreeNode* found = search(root, word);
		if (found == NULL)root = insert_node(root, word);//������ ����ִ´� 
		
		else {
			found->freq ++;

		}
	}
	//�󵵼� 1�̸� ����� 




	fclose(fin);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	//inorder(root);
	// �󵵼��� 1 �ΰ͵��� ����� 

	root = delete_one(root);
	inorder(root);

	/*TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");*/
	return 0;
}