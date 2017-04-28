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

int frequencyOfNode(node *head, dataType key) {
	int count = 0;
	while(head != NULL) {
		if(head->data == key)
			count++;
		head = head->next;
	}
	return count;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	cout<<"Node 'A' appeared "<<frequencyOfNode(head,'A')<<" times"<<endl;
	return 0;
}