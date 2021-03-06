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

dataType getNthNodeFromLast(node *head, int n) {
	node *temp = head;
	int len;
	
	for(len = 0; temp != NULL; len++)
		temp = temp->next;

	if(len < n)
		return '0';
	
	temp = head;
	for(int i = 0; i < len - n; i++)
		temp = temp->next;
	
	return temp->data;
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
	cout<<"Get 1st Node From Last : "<<getNthNodeFromLast(head,1)<<endl;
	return 0;
}