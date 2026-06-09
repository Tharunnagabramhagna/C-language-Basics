/* stack using linked list */
#include <stdio.h>
#include <stdlib.h>

// structure 3(top)->2->1->NULL

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL ? 1 : 0;
}

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d is pushed to stack.\n",val);
}

void pop() {
    if(isEmpty()) {
        printf("Stack is Empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped Element : %d\n",top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if(isEmpty()) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Top Element = %d\n",top->data);
}

void display() {
    if(isEmpty()) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack Elements : ");
    struct Node* temp;
    for(temp = top; temp != NULL; temp = temp->next)
        printf("%d ",temp->data);
    printf("\n");
}

int main() {
    push(5);
    push(10);
    push(15);
    display();
    peek();
    pop();
    while(!isEmpty())
        pop();
    display();
    return 0;
}