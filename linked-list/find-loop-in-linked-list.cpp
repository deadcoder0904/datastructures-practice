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

int detectLoop(node *head) {
	node *slow_ptr = head, *fast_ptr = head;
	while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr)
			return 1;
	}
	return 0;
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	head->next->next = head;
	int loop = detectLoop(head);
	if(loop)
		cout<<"Loop detected"<<endl;
	else
		cout<<"Loop not detected"<<endl;
	return 0;
}