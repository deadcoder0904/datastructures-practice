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

node* reverseInGroups(node *head, int n) {
	node *current = head, *prev = NULL, *next = NULL;
	for(int i = 0; current != NULL && i < n; i++) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	if(next != NULL)
		head->next = reverseInGroups(next,n);

	return prev;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'E');
	printList(head);
	printList(reverseInGroups(head,3));
	return 0;
}