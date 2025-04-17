#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "list.h"

int main(void)
{
	ListNode* head = NULL;
	const char* fname = "news.txt";
	FILE* fin = fopen(fname, "r");
	if (fin == NULL) {
		fprintf(stderr, "Can't open %s\n", fname);
		exit(EXIT_FAILURE);
	}
	char word[BUFSIZ];
	while (fscanf(fin, "%s", word) >= 1) {
		//printf("%s\n", word);
		ListNode* found = search(head, word);
		if (found == NULL)
			head = insert_last(head, make_element(word, 1));
		else
			found->data.freq = found->data.freq + 1;
	}
	print_list(head);
	fclose(fin);

	while(head != NULL) {
		head = delete_last(head);
	}
	print_list(head);

	return 0;
}

/*for (int i = 0; i < 5; i++) {
	head = insert_first(head, i);
	print_list(head);
}
for (int i = 0; i < 5; i++) {
	head = delete_first(head);
	print_list(head);
}*/

//인서트 라스트, 딜리트 라스트를 구현해라