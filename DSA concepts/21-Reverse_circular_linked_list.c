/* Reverse a circular linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_ll() {
    int n,val;
    printf("Enter the number of elements needed : ");
    scanf("%d",&n);
    if(n <= 0)
        return NULL;
    struct Node* head = NULL;
    struct Node* curr = NULL;
    for(int i = 0; i < n; i++) {
        printf("Enter a value : ");
        scanf("%d",&val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        if(head == NULL) {
            head = curr = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            curr->next = newNode;
            newNode->next = head;
            curr = newNode;
        }
    }
    return head;
}

struct Node* reverse_list(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return head;
    }
    if(head->next == head) // only Single Node exists
        return head;
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while(curr != head);
    
    head->next = prev;
    head = prev;
    
    return prev;
}

void display(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = head;
    
    do {
        printf("%d -> ",temp->data);
        temp = temp->next;
    } while(temp != head);
    
    printf("(back to head)\n");
}

int main() {
    struct Node *head = NULL;
    head = create_ll();
    display(head);
    printf("\nReversed the circular list :\n");
    head = reverse_list(head);
    display(head);
    return 0;
}