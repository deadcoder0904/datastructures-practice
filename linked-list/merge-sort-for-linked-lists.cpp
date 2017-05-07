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

node* iterativeMergeSort(node *x, node *y) {
    node *head = NULL;
    while(x != NULL && y != NULL) {
        if(x->data <= y->data) {
            insertAtEnd(&head,x->data);
            x = x->next;
        }
        else {
            insertAtEnd(&head,y->data);
            y = y->next;
        }
    }
    if(x == NULL) 
        while(y != NULL) {
            insertAtEnd(&head,y->data);
            y = y->next;    
        }
    else 
        while(x != NULL) {
            insertAtEnd(&head,x->data);
            x = x->next;    
        }    

    return head;
}

void FrontBackSplit(node *head, node **x, node **y) {	
	if(head == NULL || head->next == NULL) {
		*x = head;
		*y = NULL;
		return;
	}

	node *slow = head, *fast = head->next;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*x = head;
	*y = slow->next;
	slow->next = NULL;
}

void mergeSort(node **headRef) {
	node *head = *headRef;
	
	if(head == NULL || head->next == NULL) return;

	node *x, *y;
	FrontBackSplit(head,&x,&y);
	mergeSort(&x);
	mergeSort(&y);
	*headRef = iterativeMergeSort(x,y);
}

int main()
{
	node *head = NULL;
	insertAtEnd(&head, 'F');
	insertAtEnd(&head, 'E');
	insertAtEnd(&head, 'C');
	insertAtEnd(&head, 'B');
	insertAtEnd(&head, 'A');
	printList(head);
	mergeSort(&head);
	printList(head);
	return 0;
}