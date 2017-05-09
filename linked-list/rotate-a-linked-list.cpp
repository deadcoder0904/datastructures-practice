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

void rotate(node **head, int n) {
	node *temp = *head;
	
	while(temp->next != NULL)
		temp = temp->next;

	temp->next = *head;

	temp = *head;
	while(--n)
		temp = temp->next;
	*head = temp->next;
	temp->next = NULL;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	printList(head);
	rotate(&head,4);
	printList(head);
	return 0;
}