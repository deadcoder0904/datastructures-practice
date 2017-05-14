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

int detectAndRemoveLoop(node *head) {
    node *slow_ptr = head, *fast_ptr = head->next;
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        if(slow_ptr == fast_ptr)
            break;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    
    if(slow_ptr != fast_ptr) 
        return 0;
    slow_ptr = head;
    while(slow_ptr != fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    fast_ptr->next = NULL;
    return 1;
}

int main()
{
    node *head = NULL;
    insertAtStart(&head, 'C');
    insertAtStart(&head, 'B');
    insertAtStart(&head, 'A');
    head->next->next->next = head->next;
    int loop = detectAndRemoveLoop(head);
    if(loop) {
        cout<<"Loop detected and removed"<<endl;
        printList(head);
    }
    else
        cout<<"Loop not detected"<<endl;
    return 0;
}