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

bool triplet(node *x, node *yTemp, node *zTemp, dataType no) {
	mergeSort(&yTemp);
	mergeSort(&zTemp);
	iterativeReverse(&zTemp);

	while(x != NULL) {
		node *y = yTemp, *z = zTemp;
		while(y != NULL && z != NULL) {
			dataType sum = x->data + y->data + z->data;
			if(sum == no) {
				cout<<"Triplet Found : "<<x->data<<", "<<y->data<<", "<<z->data<<endl;
				return true;
			}
			else if(sum < no)
						y = y->next;
					else z = z->next;
		}
		x = x->next;
	}
	cout<<"No Triplet Found"<<endl;
	return false;
}

int main()
{
	node *x = NULL;
	insertAtEnd(&x, 14);
	insertAtEnd(&x, 21);
	insertAtEnd(&x, 32);
	insertAtEnd(&x, 61);
	insertAtEnd(&x, 71);
	printList(x);
	
	node *y = NULL;
	insertAtEnd(&y, 11);
	insertAtEnd(&y, 92);
	insertAtEnd(&y, 23);
	insertAtEnd(&y, 86);
	insertAtEnd(&y, 107);
	printList(y);
	
	node *z = NULL;
	insertAtEnd(&z, 321);
	insertAtEnd(&z, 212);
	insertAtEnd(&z, 32);
	insertAtEnd(&z, 65);
	insertAtEnd(&z, 77);
	printList(z);

	triplet(x,y,z,296);
	return 0;
}