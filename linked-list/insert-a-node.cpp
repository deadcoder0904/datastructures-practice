#include <bits/stdc++.h>

using namespace std;

typedef char dataType;

typedef struct node {
	dataType data;
	struct node *next;
} node;

void printList(node *node) {
	while(node != NULL) {
		cout<<(node->data)<<" -> ";
		node = node->next;
	}
	cout<<"NULL";
}

void insertAtStart(node **head, dataType data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

void insertAfter(node *prev_node, dataType data) {
	if(prev_node == NULL) {
		cout<<"Previous Node cannot be NULL"<<endl;
		return;
	}

	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = prev_node->next;

	prev_node->next = new_node;
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

int iterativeLength(node *head) {
	int length = 0;
	node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

int recursiveLength(node *head) {
	int length = 0;
	if(head == NULL)
		return 0;
	return recursiveLength(head->next) + 1;	
}

bool iterativeSearch(node *head, dataType key) {
	node *temp = head;
	while(temp != NULL) {
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

bool recursiveSearch(node *head, dataType key) {
	if(head == NULL)
		return false;
	if(head->data == key)
		return true;
	return recursiveSearch(head->next,key);
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 'B');
	insertAtStart(&head, 'A');
	insertAfter(head->next, 'C');
	insertAtEnd(&head, 'D');
	insertAtEnd(&head, 'E');
	printList(head);
	cout<<"Length of Linked List using Iterative Method : "<<iterativeLength(head)<<endl;
	cout<<"Length of Linked List using Recursive Method : "<<recursiveLength(head)<<endl;
	cout<<"Search key in a Linked List using Iterative Method : "<<iterativeSearch(head,'C')<<endl;
	cout<<"Search key in a Linked List using Recursive Method : "<<recursiveSearch(head,'Z')<<endl;
	return 0;
}