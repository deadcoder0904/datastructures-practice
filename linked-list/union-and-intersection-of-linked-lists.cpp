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

node* intersectionofLinkedLists(node *x, node *y) {
	node *head = NULL;
	unordered_set<char> seen;
	while(x != NULL) {
		seen.insert(x->data);
		x = x->next;
	}

	while(y != NULL) {
		if(seen.find(y->data) != seen.end())
			insertAtEnd(&head,y->data);
		y = y->next;
	}

	return head;
}

node* unionofLinkedLists(node *x, node *y) {
	node *head = NULL;
	unordered_set<char> seen;

	while(x != NULL) {
		seen.insert(x->data);
		insertAtEnd(&head,x->data);
		x = x->next;
	}

	while(y != NULL) {
		if(seen.find(y->data) == seen.end())
			insertAtEnd(&head,y->data);
		y = y->next;
	}

	return head;
}

int main()
{
	node *x = NULL;
	insertAtEnd(&x, 'B');
	insertAtEnd(&x, 'C');
	insertAtEnd(&x, 'A');
	insertAtEnd(&x, 'D');
	insertAtEnd(&x, 'E');
	printList(x);

	node *y = NULL;
	insertAtEnd(&y, 'F');
	insertAtEnd(&y, 'C');
	insertAtEnd(&y, 'G');
	insertAtEnd(&y, 'D');
	insertAtEnd(&y, 'H');
	printList(y);
	
	cout<<"Intersection: "<<endl;
	printList(intersectionofLinkedLists(x,y));

	cout<<"Union: "<<endl;
	printList(unionofLinkedLists(x,y));
	
	return 0;
}