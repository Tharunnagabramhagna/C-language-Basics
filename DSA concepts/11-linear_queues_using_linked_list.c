/* Queue using Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

int isEmpty() {
    return front == NULL ? 1 : 0;
}

void enqueue(int val) { // same as linked list creation logic
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into Queue.\n",val);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    struct Node* temp = front;
    printf("Popped Element = %d\n",front->data);
    front = front->next;
    // For the last el dequeue case
    if(front == NULL)
        rear = NULL;
    free(temp);
}

void Front() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Front Element = %d\n",front->data);
}

void display() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    struct Node* temp;
    printf("Elements of Queue : ");
    for(temp = front; temp != NULL; temp = temp->next)
        printf("%d ",temp->data);
    printf("\n");
}

int main() {
    enqueue(2);
    enqueue(3);
    enqueue(9);
    enqueue(10);
    
    dequeue();
    
    Front();
    display();
    
    while(!isEmpty())
        dequeue();
    
    display();
    
    return 0;
}