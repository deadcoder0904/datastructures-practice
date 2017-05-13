#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct node {
	ll data;
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

void insertAtStart(node **head, ll data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

void insertAtEnd(node **head, ll data) {
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

void putNumberIntoLinkedList(node **ptr, ll no) {
	while(no) {
		insertAtEnd(&(*ptr), no%10);
		no /= 10;
	}
}

ll getNumberFromLinkedList(node *ptr) {
	ll multiplier = 1, no = 0;
	while(ptr != NULL) {
		no += ptr->data * multiplier;
		multiplier *= 10;
		ptr = ptr->next;
	}
	return no;
}

node* addTwoLists(node *x, node *y) {
	ll x_no = 0, y_no = 0;
	
	x_no = getNumberFromLinkedList(x);
	y_no = getNumberFromLinkedList(y);
	
	node *ptr = NULL;
	putNumberIntoLinkedList(&ptr,x_no + y_no);
	return ptr;
}

int main()
{
	ll m, n;
	cout<<"Enter 1st number: ";
	cin>>m;
	cout<<"Enter 2nd number: ";
	cin>>n;
	node *m_ptr = NULL, *n_ptr = NULL;

	putNumberIntoLinkedList(&m_ptr, m);
	putNumberIntoLinkedList(&n_ptr, n);
	
	cout<<"1st number: ";
	printList(m_ptr);

	cout<<"2nd number: ";
	printList(n_ptr);

	node *sum = addTwoLists(m_ptr, n_ptr);
	cout<<"Sum of Linked Lists: ";
	printList(sum);

	return 0;
}