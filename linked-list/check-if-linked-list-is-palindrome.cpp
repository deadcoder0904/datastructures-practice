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

node* cloneLinkedListInReverse(node *temp) {
	node *reverse = NULL;
	while(temp != NULL) {
		insertAtStart(&reverse,temp->data);
		temp = temp->next;
	}
	return reverse;
}

int isPalindrome(node *head1,node *head2) {
	while(head1 != NULL && head2 != NULL)
		if(head1->data != head2->data)
			return 0;
		else {
			head1 = head1->next;
			head2 = head2->next;
		}
	return 1;
}

int main()
{
	node *head1 = NULL;
	insertAtStart(&head1, 'R');
	insertAtStart(&head1, 'A');
	insertAtStart(&head1, 'D');
	insertAtStart(&head1, 'A');
	insertAtStart(&head1, 'R');

	cout<<"1st Linked List : "<<endl;
	printList(head1);
	
	node *head2 = cloneLinkedListInReverse(head1);

	cout<<"2nd Linked List : "<<endl;
	printList(head2);

	int palindrome = isPalindrome(head1,head2);

	if(palindrome)
		cout<<"Palindrome"<<endl;
	else cout<<"Not Palindrome"<<endl;

	return 0;
}