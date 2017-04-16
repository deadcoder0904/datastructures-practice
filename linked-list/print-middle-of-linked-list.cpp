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

dataType getMiddleNode1(node *head) {
	if(head == NULL)
		return '0';

	int count = 0;
	node *temp = head;
	
	for(count = 0; temp != NULL; count++) 
		temp = temp->next;
	
	temp = head;
	
	for(int i = 0; i < count/2; i++)
		temp = temp->next;
	
	return temp->data;
}

dataType getMiddleNode2(node *head) {
	if(head == NULL)
		return '0';

	node *slow_ptr = head, *fast_ptr = head;

	while(fast_ptr != NULL && fast_ptr->next != NULL ) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	return slow_ptr->data;
}

dataType getMiddleNode3(node *head) {
	if(head == NULL)
		return '0';
	
	node *mid = head;
	
	for(int count = 0; head != NULL; count++) {
		if(count & 1)
			mid = mid->next;
		head = head->next;
	}
	
	return mid->data;
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
	cout<<"Get Middle Node 1 : "<<getMiddleNode1(head)<<endl;
	cout<<"Get Middle Node 2 : "<<getMiddleNode2(head)<<endl;
	cout<<"Get Middle Node 3 : "<<getMiddleNode3(head)<<endl;
	return 0;
}