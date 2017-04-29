#include <bits/stdc++.h>

using namespace std;

typedef char dataType;

typedef struct node {
	dataType data;
	struct node *next;
} node;

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

node* iterativeMergeSort(node *x, node *y) {
	node *head = NULL;
	while(x != NULL && y != NULL) {
		if(x->data <= y->data) {
			insertAtEnd(&head,x->data);
			x = x->next;
		}
		else {
			insertAtEnd(&head,y->data);
			y = y->next;
		}
	}
	if(x == NULL) 
		while(y != NULL) {
			insertAtEnd(&head,y->data);
			y = y->next;	
		}
	else 
		while(x != NULL) {
			insertAtEnd(&head,x->data);
			x = x->next;	
		}	

	return head;
}

node* recursiveMergeSort(node *x, node *y) {
	node *head = NULL;

	if(x == NULL) return y;
	if(y == NULL) return x;

	if(x->data <= y->data) {
		head = x;
		head->next = recursiveMergeSort(head->next,y);
	}
	else {
		head = y;
		head->next = recursiveMergeSort(x,head->next);
	}
	return head;
}

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

int main()
{
	node *head1 = NULL;
	insertAtEnd(&head1, 'A');
	insertAtEnd(&head1, 'B');
	cout<<"1st linked list is :"<<endl;
	printList(head1);

	node *head2 = NULL;
	insertAtEnd(&head2, 'E');
	insertAtEnd(&head2, 'F');
	insertAtEnd(&head2, 'G');
	cout<<"2nd linked list is :"<<endl;
	printList(head2);

	cout<<"Iteratively Merged linked list is :"<<endl;
	node *head3 = iterativeMergeSort(head1, head2);
	printList(head3);

	cout<<"Recursively Merged linked list is :"<<endl;
	head3 = recursiveMergeSort(head1, head2);
	printList(head3);
	
	return 0;
}