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

void removeDuplicates(node *head) {
	if(head == NULL)
		return;

	node *next_ptr;

	while(head->next != NULL)
		if(head->data == head->next->data) {
			next_ptr = head->next->next;
			free(head->next);
			head->next = next_ptr;
		}
		else
			head = head->next;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	removeDuplicates(head);
	printList(head);
	return 0;
}