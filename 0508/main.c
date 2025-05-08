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
	//파일 열기 코드
	const char* fname = "news.txt";
	FILE* fin = fopen(fname, "r");
	if (fin == NULL) {
		fprintf(stderr, "Cant open %s\n", fname);
		exit(EXIT_FAILURE);// 빠져나가기까지
	}
	TreeNode* root = NULL;
	char* word[BUFSIZ];//메모리를 가져야한다
	while (fscanf(fin, "%s", word) == 1) {// 1일동안 돈다?
		TreeNode* found = search(root, word);
		if (found == NULL)root = insert_node(root, word);//없으면 집어넣는다 
		
		else {
			found->freq ++;

		}
	}
	//빈도수 1이면 지우기 




	fclose(fin);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	//inorder(root);
	// 빈도수가 1 인것들을 지운다 

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
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");*/
	return 0;
}