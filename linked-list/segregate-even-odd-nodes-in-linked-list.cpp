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

void segregateEvenAndOdd(node **head) {
	if(*head == NULL) return;

	node *temp = *head, *even = NULL, *odd = NULL;
	while(temp != NULL) {
		if(temp->data & 1)
			insertAtEnd(&odd,temp->data);
		else insertAtEnd(&even,temp->data);
		temp = temp->next;
	}

	if(even == NULL) {
		*head = odd;
		return;
	}

	temp = even;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = odd;
	*head = even;	
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 'B');
	insertAtEnd(&head, 'A');
	insertAtEnd(&head, 'C');
	insertAtEnd(&head, 'D');
	insertAtEnd(&head, 'E');
	printList(head);
	segregateEvenAndOdd(&head);
	printList(head);
	return 0;
}