/* Stack using Arrays */
#include <stdio.h>
#define SIZE 3

int stack[SIZE], top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == SIZE - 1;
}

void push(int val) {
    if(isFull()) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = val;
    printf("%d is pushed to stack.\n",val);
}

void pop() {
    if(isEmpty()) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Popped Element = %d\n",stack[top--]);
}

void peek() {
    if(isEmpty()) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Top Element = %d\n",stack[top]);
}

void display() {
    if(isEmpty()) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Enter of stack : ");
    for(int i = top; i >= 0; i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    if(isFull())
        display();
    push(40);
    peek();
    pop();
    peek();
    while(!isEmpty())
        pop();
    display();
    return 0;
}