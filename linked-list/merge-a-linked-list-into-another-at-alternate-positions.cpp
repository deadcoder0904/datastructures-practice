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

void mergeAtAlternatePostions(node *a, node **b) {
	node *p = a, *q = *b;

	while(p != NULL && q != NULL) {
		node *p_next = p->next;
		node *q_next = q->next;

		p->next = q;
		q->next = p_next;

		p = p_next;
		q = q_next;
	}

	*b = q;
}

int main()
{
	node *a = NULL;
	insertAtStart(&a, 'C');
	insertAtStart(&a, 'B');
	insertAtStart(&a, 'A');
	cout<<"Linked List 1 : "<<endl;
	printList(a);

	node *b = NULL;
	insertAtStart(&b, 'H');
	insertAtStart(&b, 'G');
	insertAtStart(&b, 'F');
	insertAtStart(&b, 'E');
	insertAtStart(&b, 'D');
	cout<<"Linked List 2 : "<<endl;
	printList(b);

	mergeAtAlternatePostions(a,&b);
	cout<<"Modified Linked List 1 : "<<endl;
	printList(a);
	cout<<"Modified Linked List 2 : "<<endl;
	printList(b);

	return 0;
}