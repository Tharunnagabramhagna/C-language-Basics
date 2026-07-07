/* Reverse a singly Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *create_ll() {
    int n,val;
    printf("Enter the elements needed : ");
    scanf("%d",&n);
    if(n <= 0)
        return NULL;
    struct Node* head = NULL;
    struct Node* curr = NULL;
    for(int i = 0; i < n; i++) {
        printf("Enter a value : ");
        scanf("%d",&val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL)
            head = curr = newNode;
        else {
            curr->next = newNode;
            curr = newNode;
        }
    }
    return head;
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

struct Node* reverse_list(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return head;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    struct Node* head = NULL;
    head = create_ll();
    display(head);
    head = reverse_list(head);
    display(head);
    return 0;
}