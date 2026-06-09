/* Reverse a String using Stack 
    => Application of Stack */
#include <stdio.h>
#define max 100

char stack[max];
int top = -1;

int isEmpty() {
	return top == -1;
}

int isFull() {
	return top == max - 1;
}

void push(char x) {
	if(isFull()) {
		printf("Stack overflow.\n");
		return;
	}
	stack[++top] = x;
}

int pop() {
	if(isEmpty())
		return -1;
	return stack[top--];
}

void reverseString(char str[]) {
	for(int i = 0; str[i] != '\0'; i++)
		push(str[i]);
	// Reversly Inserted
	for(int i = 0; str[i] != '\0'; i++)
		str[i] = pop();
}

void display(char str[]) {
	for(int i = 0; str[i] != '\0'; i++)
		printf("%c ",str[i]);
	printf("\n");
}

int main() {
	char str[max];
	printf("Enter the string : ");
	scanf("%s",str);
	printf("Original String : \n");
	display(str);
	reverseString(str);
	printf("Reversed String : \n");
	display(str);
	return 0;
}