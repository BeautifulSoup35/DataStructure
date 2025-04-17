#ifndef __LIST__
#define __LIST__

typedef  struct element {
	char* word;
	int freq;
} element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message);
//ListNode* insert_first(ListNode* head, element value);
ListNode* insert(ListNode* head, ListNode* pre, element value);
//ListNode* delete_first(ListNode* head);
ListNode* delete(ListNode* head, ListNode* pre);
void print_list(ListNode* head);
element make_element(char* word, int freq);
ListNode* search(const ListNode* head, char *word);
ListNode* insert_last(ListNode* head, element value);
ListNode* delete_last(ListNode* head);

#endif