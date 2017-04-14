#include <bits/stdc++.h>

using namespace std;

typedef char dataType;

typedef struct node {
	dataType data;
	struct node *next;
} node;

void insertAtStart(node **head, dataType data) {
	node* new_node = (node*) malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

bool iterativeSearch(node *head, dataType key) {
	node *temp = head;
	while(temp != NULL) {
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

bool recursiveSearch(node *head, dataType key) {
	if(head == NULL)
		return false;
	if(head->data == key)
		return true;
	return recursiveSearch(head->next,key);
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	cout<<"Search key in a Linked List using Iterative Method : "<<iterativeSearch(head,'C')<<endl;
	cout<<"Search key in a Linked List using Recursive Method : "<<recursiveSearch(head,'Z')<<endl;
	return 0;
}