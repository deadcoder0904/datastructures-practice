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

void removeDuplicatesFromUnsortedList(node *head) {
	if(head == NULL)
		return;

	node *fixed = head, *moving;
	while(fixed != NULL && fixed->next != NULL) {
		moving = fixed;
		while(moving->next != NULL) {
			if(fixed->data == moving->next->data) {
				node *next_ptr = moving->next;
				moving->next = next_ptr->next;
				free(next_ptr);
			}
			else moving = moving->next;
		}
		fixed = fixed->next;
	}
}

void removeDuplicatesFromUnsortedListUsingHashing(node *head) {
	unordered_set<int> seen;
	node *current = head, *prev = NULL;
	while(current != NULL) {
		if(seen.find(current->data) != seen.end()) {
			prev->next = current->next;
			free(current);
		}
		else {
			seen.insert(current->data);
			prev = current;
		}
		current = prev->next;
	}
}

int main()
{
	node *head = NULL;
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	removeDuplicatesFromUnsortedList(head);
	printList(head);
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	removeDuplicatesFromUnsortedListUsingHashing(head);
	printList(head);
	return 0;
}