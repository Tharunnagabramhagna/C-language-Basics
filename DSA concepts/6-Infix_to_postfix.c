#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

// Define stack structure
typedef struct {
    char items[SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == SIZE - 1;
}

// Push element onto stack
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++s->top] = c;
}

// Pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->items[s->top--];
}

// Peek top element
char peek(Stack *s) {
    if (isEmpty(s))
        return '\0';
    return s->items[s->top];
}

// Precedence function
int precedence(char symbol) {
    if (symbol == '^') return 3;
    else if (symbol == '*' || symbol == '/') return 2;
    else if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);
    int i, j = 0;
    char symbol, next;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(&s, symbol);
                break;
            case ')':
                while (!isEmpty(&s) && (next = pop(&s)) != '(')
                    postfix[j++] = next;
                break;
            case '+': case '-': case '*': case '/': case '^':
                while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(symbol))
                    postfix[j++] = pop(&s);
                push(&s, symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }

    while (!isEmpty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    infixToPostfix(infix, postfix);

    printf("The equivalent postfix expression is: %s\n", postfix);
    return 0;
}