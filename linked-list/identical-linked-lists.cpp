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

bool identicalLinkedListsIterative(node *x, node *y) {
	while(x != NULL && y != NULL) {
		if(x->data != y->data)
			return false;
		x = x->next;
		y = y->next;
	}
	
	return x == NULL && y == NULL;
}

bool identicalLinkedListsRecursive(node *x, node *y) {
	if(x == NULL && y == NULL) return true;

	if(x != NULL && y != NULL) 
		return (x->data == y->data) && identicalLinkedListsRecursive(x->next,y->next);
	return false;
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
	
	cout<<"Iterative Method - "<<endl;
	if(identicalLinkedListsIterative(x,y))
		cout<<"Linked Lists are Identical"<<endl;
	else cout<<"Linked Lists are Not Identical"<<endl;

	cout<<"Recursive Method - "<<endl;
	if(identicalLinkedListsRecursive(x,y))
		cout<<"Linked Lists are Identical"<<endl;
	else cout<<"Linked Lists are Not Identical"<<endl;

	return 0;
}