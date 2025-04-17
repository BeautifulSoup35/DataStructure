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

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;	
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("(%s, %d) ->", p->data.word, p->data.freq);
	printf("NULL\n");
}

element make_element(char* word, int freq) {
	element e;
	e.word = strdup(word);
	e.freq = freq;
	return e;
}

ListNode* search(const ListNode* head, char* word) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (strcmp(p->data.word, word) == 0)
			return p;
	}
	return NULL;
}

ListNode* insert_last(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	if (head == NULL) return p;
	else {
		ListNode* temp = head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = p;
		return head;
	}
}

ListNode* delete_last(ListNode* head) {
	ListNode* delete, * p;
	if (head == NULL) return NULL;

	if (head->link == NULL) {
		delete = head;
		head = NULL;
		free(head);
		return head;
	}
	p = head;

	while (p->link->link != NULL) {
		p = p->link;
	}
	delete = p->link;
	p->link = NULL;
	free(delete);
	return head;
}

//ListNode* insert_first(ListNode* head, element value)
//{
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = head;
//	head = p;
//	return head;
//}

//ListNode* delete_first(ListNode* head) {
//	ListNode* removed;
//	if (head == NULL) return NULL;
//	removed = head;
//	head = removed->link;
//	free(removed);
//	return head;
//}