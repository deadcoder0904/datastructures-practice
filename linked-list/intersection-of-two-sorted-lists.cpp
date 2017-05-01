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

node* intersectionOfTwoSortedListsUsingDummyNode(node *head1, node *head2) {
	node head, *tail = &head;
	head.next = NULL;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data == head2->data) {
			insertAtEnd(&tail->next,head1->data);
			tail = tail->next;
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
					head1 = head1->next;
				else head2 = head2->next;
	}
	return head.next;
}

node* intersectionOfTwoSortedListsUsingPointerOfPointer(node *head1, node *head2) {
	node *head = NULL, **tail = &head;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data == head2->data) {
			insertAtEnd(tail,head1->data);
			tail = &((*tail)->next);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
					head1 = head1->next;
				else head2 = head2->next;
	}
	return head;
}

node* intersectionOfTwoSortedListsUsingRecursion(node *head1, node *head2) {
	node *head = NULL;
	if(head1 == NULL || head2 == NULL) return NULL;

	if(head1->data < head2->data)
		return intersectionOfTwoSortedListsUsingRecursion(head1->next, head2);

	if(head1->data > head2->data)
		return intersectionOfTwoSortedListsUsingRecursion(head1, head2->next);
	
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = head1->data;

	new_node->next = intersectionOfTwoSortedListsUsingRecursion(head1->next, head2->next);
	return new_node;
}

int main()
{
	node *head1 = NULL;
	insertAtEnd(&head1, 'A');
	insertAtEnd(&head1, 'B');
	insertAtEnd(&head1, 'C');
	insertAtEnd(&head1, 'D');
	insertAtEnd(&head1, 'E');
	cout<<"1st linked list : "<<endl;
	printList(head1);
	node *head2 = NULL;
	insertAtEnd(&head2, 'C');
	insertAtEnd(&head2, 'D');
	insertAtEnd(&head2, 'E');
	cout<<"2nd linked list : "<<endl;
	printList(head2);
	node *head3 = intersectionOfTwoSortedListsUsingDummyNode(head1,head2);
	cout<<"Intersection using Dummy Node : "<<endl;
	printList(head3);
	node *head4 = intersectionOfTwoSortedListsUsingPointerOfPointer(head1,head2);
	cout<<"Intersection using Pointer of Pointer : "<<endl;
	printList(head4);
	node *head5 = intersectionOfTwoSortedListsUsingRecursion(head1,head2);
	cout<<"Intersection using Recursion : "<<endl;
	printList(head5);
	return 0;
}
