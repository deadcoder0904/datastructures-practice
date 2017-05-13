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

void sortedInsert(node **head, dataType data) {
	if(*head == NULL) return;
	
	node*temp = *head;
	node* new_node = (node*) malloc(sizeof(node));
	new_node->data = data;

	if(temp->data > new_node->data) {
		new_node->next = temp;
		*head = new_node;
		return;
	}

	while(temp != NULL && temp->next != NULL) {
		if(temp->next->data > data) {
			new_node->next = temp->next;
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}
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
	sortedInsert(&head, 'D');
	printList(head);
	return 0;
}