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

void recursiveReversePrintList(node *head) {
	if(head == NULL) return;
	recursiveReversePrintList(head->next);
	cout<<head->data<<" -> ";
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	printList(head);
	recursiveReversePrintList(head);
	cout<<"NULL";
	return 0;
}