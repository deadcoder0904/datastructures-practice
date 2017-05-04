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

void deleteAlternateNodesIterative(node *head) {
	node *current = head, *next_ptr;

	while(current != NULL && current->next != NULL) {
		next_ptr = current->next;
		current->next = next_ptr->next;
		free(next_ptr);
		current = current->next;
	}
}

void deleteAlternateNodesRecursive(node *head) {
	if(head == NULL || head->next == NULL) return;

	node *next_ptr = head->next;
	head->next = next_ptr->next;
	free(next_ptr);
	deleteAlternateNodesRecursive(head->next);
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	printList(head);
	cout<<"Delete Alternate Nodes Iteratively : "<<endl;
	deleteAlternateNodesIterative(head);
	printList(head);
	cout<<"Delete Alternate Nodes Recursively : "<<endl;
	deleteAlternateNodesRecursive(head);
	printList(head);
	return 0;
}