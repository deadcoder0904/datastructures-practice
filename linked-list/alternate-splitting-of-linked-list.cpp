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

void insertAtEnd(node **head, dataType data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = NULL;

	if(*head == NULL) {
		*head = new_node;
		return;
	}

	node *last = *head;

	while(last -> next != NULL)
		last = last->next;
	
	last->next = new_node;
}

void alternateSplitting(node *head, node **x, node **y) {
	if(head == NULL) return;
	int count = 1;
	while(head != NULL) {
		if(count%2 == 1)
			insertAtEnd(x, head->data);
		else insertAtEnd(y, head->data);
		count++;
		head = head->next;
	}
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 'A');
	insertAtEnd(&head, 'B');
	insertAtEnd(&head, 'C');
	insertAtEnd(&head, 'D');
	insertAtEnd(&head, 'E');
	printList(head);
	cout<<"Alternate Splitting of Linked List : "<<endl;
	node *x = NULL, *y = NULL;
	alternateSplitting(head, &x, &y);
	printList(x);
	printList(y);
	return 0;
}