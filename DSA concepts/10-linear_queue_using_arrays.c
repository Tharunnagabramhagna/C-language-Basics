/* Queue using arrays */

#include <stdio.h>
#define SIZE 5

int Queue[SIZE], front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear) ? 1 : 0;
}

int isFull() {
    return rear == SIZE - 1;
}

void enqueue(int val) {
    if(isFull()) {
        printf("Queue overflow.\n");
        return;
    }
    if(front == -1)
        front = 0;
    Queue[++rear] = val;
    printf("%d is pushed to Queue.\n",val);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Popped Element = %d\n",Queue[front++]);
}

void Front() {
    if(isEmpty()) {
        printf("Queue overflow.\n");
        return;
    }
    printf("Front Element = %d\n",Queue[front]);
}

void display() {
    if(isEmpty()) {
        printf("Queue overflow.\n");
        return;
    }
    printf("Elements of Queue : ");
    for(int i = front; i <= rear; i++)
        printf("%d ",Queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    if(isFull())
        display();
        
    dequeue();
    Front();
    
    while(!isEmpty())
        dequeue();
        
    display();
    
    return 0;
}