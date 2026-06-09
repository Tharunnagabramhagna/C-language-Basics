#include <stdio.h>
#define max 5

struct STACK {
    int arr[max];
    int top;
};

int isEmpty(struct STACK *s) {
    return (s->top == -1);
}

int isFull(struct STACK *s) {
    return (s->top == max - 1);
}

void push(struct STACK *s, int val) {
    if(isFull(s)) {
        printf("Stack overflow.\n");
        return;
    }
    s->arr[++s->top] = val;
}

void pop(struct STACK *s) {
    if(isEmpty(s)) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Deleted Element = %d\n",s->arr[s->top--]);
}

void peek(struct STACK *s) {
    if(isEmpty(s)) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Peek Element = %d\n",s->arr[s->top]);
}

void print(struct STACK s) {
    if(isEmpty(&s)) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Elements of STACK : ");
    for(int i = s.top; i >= 0; i--)
        printf("%d ",s.arr[i]);
    printf("\n");
}

int main() {
    struct STACK *s1;
    s1->top = -1;
    int choice,val;
    while(1) {
        printf("\n__STACK FUNNCTIONS__\n");
        printf("Enter your choice :\n1.Push\n2.Pop\n");
        printf("3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1 :
                printf("Enter the value : ");
                scanf("%d",&val);
                push(s1,val);
                break;
            case 2 :
                pop(s1);
                break;
            case 3 :
                peek(s1);
                break;
            case 4 :
                print(*s1);
                break;
            case 5 :
                return 0;
            default : printf("Enter a valid choice.\n");
        }
    }
    return 0;
}