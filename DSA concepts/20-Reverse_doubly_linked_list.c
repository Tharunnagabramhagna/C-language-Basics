/* Reverse a doubly Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev, *next;
};

struct Node* create_ll() {
    int n,val;
    printf("Enter number of elements needed : ");
    scanf("%d",&n);
    if(n <= 0)
        return NULL;
    struct Node* head = NULL;
    struct Node* curr = NULL;
    for(int i = 0; i < n; i++) {
        printf("Enter the value : ");
        scanf("%d",&val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = NULL;
        if(head == NULL)
            head = curr = newNode;
        else {
            curr->next = newNode;
            newNode->prev = curr;
            curr = newNode;
        }
    }
    return head;
}

struct Node* Reverse_list(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return NULL;
    }
    struct Node* curr = head;
    struct Node* next = NULL;
    struct Node* new_head = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        new_head = curr;
        curr = next;
    }
    // head = curr;
    return new_head;
}

void display(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp;
    for(temp = head; temp != NULL; temp = temp->next)
        printf("%d ",temp->data);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = create_ll();
    display(head);
    head = Reverse_list(head);
    display(head);
    return 0;
}