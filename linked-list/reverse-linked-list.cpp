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

void reverseList(node **head) {
	node *prev = NULL, *current = *head, *next;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	reverseList(&head);
	printList(head);
	return 0;
}