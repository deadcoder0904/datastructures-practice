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

void deleteNodeWithSpecifiedKey(node **head, dataType key) {
	node *temp = *head, *prev;
	if(temp != NULL && temp->data == key) {
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		cout<<"Key "<<key<<" not found"<<endl;
		return;
	}
	
	prev->next = temp->next;
	free(temp);
}

void deleteNodeWithSpecifiedPostion(node **head,int position) {
	node *temp = *head;
	
	if(temp == NULL) 
		return;

	if(position == 0) {
		*head = temp->next;
		free(temp);
		return;
	}

	for(int i = 0; temp != NULL && i < position-1; i++) 
		temp = temp->next;
	
	if(temp == NULL || temp->next == NULL)
		return;

	node *next = temp->next->next;

	free(temp->next);
	temp->next = next;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	cout<<"Deleting node with key 'C' : "<<endl;
	deleteNodeWithSpecifiedKey(&head, 'C');
	printList(head);
	cout<<"Deleting node at position 1 : "<<endl;
	deleteNodeWithSpecifiedPostion(&head,1);
	printList(head);
	return 0;
}
