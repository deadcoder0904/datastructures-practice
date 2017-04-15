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
	cout<<"NULL"<<endl;
}

void insertAtStart(node **head, dataType data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

dataType getMiddleNode1(node *head) {
	node *temp = head;
	int count = 0;

	while(temp != NULL) {
		count++;
		temp = temp->next;
	}

	int middle = count / 2 + 1;
	temp = head;
	count = 0;

	while(count != middle-1) {
		count++;
		temp = temp->next;
	}
	if(temp == NULL)
        return '0';
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
	node *mid = head;
	int count = 0;

	while(head != NULL) {
		if(count & 1)
			mid = mid->next;
		count++;
		head = head->next;
	}
	if(mid == NULL)
		return '0';
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