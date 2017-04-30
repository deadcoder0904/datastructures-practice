#include <bits/stdc++.h>

using namespace std;

typedef char dataType;

typedef struct node {
	dataType data;
	struct node *next;
} node;

void printList(node *node) {
	if(node == NULL) {
		cout<<"The linked list is empty"<<endl;
		return;
	}

	while(node != NULL) {
		cout<<(node->data)<<" -> ";
		node = node->next;
	}
	cout<<"NULL"<<endl;
}

void insertAtStart(node **head, dataType data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

void swap(dataType *a, dataType *b) {
	dataType temp = *a;
	*a = *b;
	*b = temp;
}

void swapPairsIterative(node *head) {
	if(head == NULL) return;

	while(head != NULL && head->next != NULL) {
		swap(&(head->data),&(head->next->data));
		head = head->next->next;
	}
}

void swapPairsRecursive(node *head) {
	if(head == NULL || head->next == NULL) return;
	
	swap(&(head->data),&(head->next->data));
	swapPairsRecursive(head->next->next);
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	printList(head);
	swapPairsIterative(head);
	printList(head);
	swapPairsRecursive(head);
	printList(head);
	return 0;
}
