#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

typedef struct {
	char items[SIZE];
	int top;
} Stack;

void initStack(Stack *s) {
	s->top = -1;
}
int isEmpty(Stack *s) {
	return s->top == -1;
}
int isFull(Stack *s) {
	return s->top == SIZE - 1;
}

void push(Stack *s, char c) {
	if (!isFull(s))
		s->items[++s->top] = c;
}
char pop(Stack *s) {
	if (!isEmpty(s))
		return s->items[s->top--];
	return '\0';
}
char peek(Stack *s) {
	if (!isEmpty(s))
		return s->items[s->top];
	return '\0';
}

int precedence(char symbol) {
	if (symbol == '^')
		return 3;
	else if (symbol == '*' || symbol == '/')
		return 2;
	else if (symbol == '+' || symbol == '-')
		return 1;
	return 0;
}

// Convert infix to postfix (helper)
void infixToPostfix(char infix[], char postfix[]) {
	Stack s;
	initStack(&s);
	int i, j = 0;
	char symbol, next;

	for (i = 0; i < strlen(infix); i++) {
		symbol = infix[i];
		if (isalnum(symbol)) {
			postfix[j++] = symbol;
		} else {
			switch (symbol) {
			case '(':
				push(&s, symbol);
				break;
			case ')':
				while (!isEmpty(&s) && (next = pop(&s)) != '(')
					postfix[j++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(symbol))
					postfix[j++] = pop(&s);
				push(&s, symbol);
				break;
			}
		}
	}

	while (!isEmpty(&s))
		postfix[j++] = pop(&s);
	postfix[j] = '\0';
}

// Reverse a string
void reverse(char str[]) {
	int i, j;
	char temp;
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
	char revInfix[SIZE], revPostfix[SIZE];
	strcpy(revInfix, infix);

	// Step 1: Reverse infix
	reverse(revInfix);

	// Step 2: Swap parentheses
	for (int i = 0; i < strlen(revInfix); i++) {
		if (revInfix[i] == '(') revInfix[i] = ')';
		else if (revInfix[i] == ')') revInfix[i] = '(';
	}

	// Step 3: Convert reversed infix to postfix
	infixToPostfix(revInfix, revPostfix);

	// Step 4: Reverse postfix -> prefix
	strcpy(prefix, revPostfix);
	reverse(prefix);
}

int main() {
	char infix[SIZE], prefix[SIZE];
	printf("Enter the infix expression: ");
	fgets(infix, SIZE, stdin);
	infix[strcspn(infix, "\n")] = '\0'; // remove newline

	infixToPrefix(infix, prefix);

	printf("The equivalent prefix expression is: %s\n", prefix);
	return 0;
}