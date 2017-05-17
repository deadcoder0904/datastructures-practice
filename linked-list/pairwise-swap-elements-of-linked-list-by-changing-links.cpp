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

void pairWiseSwap(node **head) {
	
	if(*head == NULL || (*head)->next == NULL)
		return;
		
	node *prev = *head, *curr = prev->next;
	*head = curr;
	
	while(true) {
		node *next_ptr = curr->next;
		curr->next = prev;

		if(next_ptr == NULL || next_ptr->next == NULL) {
			prev->next = next_ptr;
			break;
		}

		prev->next = next_ptr->next;

		prev = next_ptr;
		curr = prev->next;
	}
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	printList(head);
	pairWiseSwap(&head);
	printList(head);
	return 0;
}