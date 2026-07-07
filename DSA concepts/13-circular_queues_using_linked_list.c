/* Circular Queue using Linked List */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL, *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("%d inserted into queue.\n",x);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    if(front == rear) {
        printf("Dequeued Element : %d\n",front->data);
        free(front);
        front = rear = NULL;
    } else {
        struct Node *temp = front;
        front = front->next;
        rear->next = front;
        printf("Dequeued Element : %d\n",temp->data);
        free(temp);
    }
}

void peek() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Peek Element : %d\n",front->data);
}

void display() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    struct Node* temp;
    for(temp = front; ; temp = temp->next) {
        printf("%d ",temp->data);
        if(temp == rear)
            break;
    }
    printf("\n");
}

int main() {
    int choice,val;
    while(1) {
        printf("__Circular Queue Functions__\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1 :
                    printf("Enter the value : ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2 :
                    dequeue();
                    break;
            case 3 :
                    peek();
                    break;
            case 4 :
                    display();
                    break;
            case 5 : 
                    return 0;
                    break;
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}
