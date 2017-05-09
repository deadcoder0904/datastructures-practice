#include <bits/stdc++.h>

using namespace std;

typedef int dataType;

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

void sort(node *head) {
	node *temp = head;
	int count[3] = {0,0,0};
	
	while(temp != NULL) {
		count[temp->data]++;
		temp = temp->next;
	}

	temp = head;
	while(temp != NULL) {
		if(count[0]) {
			temp->data = 0;
			count[0]--;
		}
		else 
			if(count[1]) {
				temp->data = 1;
				count[1]--;
			}
			else temp->data = 2;
		temp = temp->next;	
	}
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 0);
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 0);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 0);
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 1);
	printList(head);
	sort(head);
	printList(head);
	return 0;
}