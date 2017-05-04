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

string identicalLinkedLists(node *x, node *y) {
	if(x == y) return "Linked Lists are Identical";

	while(x != NULL && y != NULL) {
		if(x->data != y->data)
			return "Linked Lists are Not Identical";
		x = x->next;
		y = y->next;
	}
	
	if(x == NULL && y == NULL) 
		return "Linked Lists are Identical";
	return "Linked Lists are Not Identical";
}

int main()
{
	node *x = NULL;
	insertAtStart(&x, 'A');
	insertAtStart(&x, 'B');
	insertAtStart(&x, 'C');
	insertAtStart(&x, 'D');
	insertAtStart(&x, 'E');
	cout<<"Linked List 1 : "<<endl;
	printList(x);

	node *y = NULL;
	insertAtStart(&y, 'A');
	insertAtStart(&y, 'B');
	insertAtStart(&y, 'C');
	insertAtStart(&y, 'D');
	insertAtStart(&y, 'E');
	cout<<"Linked List 2 : "<<endl;
	printList(y);

	cout<<identicalLinkedLists(x,y);

	return 0;
}