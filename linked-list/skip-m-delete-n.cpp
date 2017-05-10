#include <bits/stdc++.h>

using namespace std;

typedef int dataType;

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

void skipMDeleteN(node *head, int M, int N) {
	node *temp = head;
	while(temp != NULL) {

		for(int i = 0; i < M-1; i++)
			temp = temp->next;

		node *prev_ptr = temp;
		temp = temp->next;

		for(int i = 0; i < N; i++) {
			node *next_ptr = temp->next;
			free(temp);
			temp = next_ptr;
		}

		prev_ptr->next = temp;
	}
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtEnd(&head, 4);
	insertAtEnd(&head, 5);
	insertAtEnd(&head, 6);
	insertAtEnd(&head, 7);
	insertAtEnd(&head, 8);
	insertAtEnd(&head, 9);
	insertAtEnd(&head, 10);
	printList(head);
	skipMDeleteN(head,3,2);
	printList(head);
	return 0;
}