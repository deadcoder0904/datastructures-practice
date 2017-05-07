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

void iterativeReverse(node **head) {
	node *prev = NULL, *current = *head, *next;
	
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head = prev;
}

void delNodes(node *head) {
	node *current = head, *maxnode = head;
	while(current != NULL && current->next != NULL)
		if(current->next->data < maxnode->data) {
			node *temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		else {
			current = current->next;
			maxnode = current;
		}
}

void deleteNodesHavingGreaterValueOnRightSideIterative(node **head) {
	if(*head == NULL) return;

	iterativeReverse(head);
	delNodes(*head);
	iterativeReverse(head);
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'E');
	printList(head);
	deleteNodesHavingGreaterValueOnRightSideIterative(&head);
	printList(head);
	return 0;
}