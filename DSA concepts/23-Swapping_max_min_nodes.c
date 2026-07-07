/* Swapping Max and Min Nodes in LL */
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* create_ll() {
	int n,val;
	printf("Enter the size : ");
	scanf("%d",&n);
	if(n <= 0)
		return NULL;
	struct Node* head = NULL;
	struct Node* curr = NULL;
	for(int i = 0; i < n; i++) {
		printf("Enter a value : ");
		scanf("%d",&val);
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

struct Node* swapMinMax(struct Node* head) {
	if(head == NULL) {
		printf("List is Empty.\n");
		return NULL;
	}
	struct Node* minNode, *maxNode,* temp = head;
	minNode = maxNode = head;
	while(temp != NULL) {
		if(temp->data < minNode->data)
			minNode = temp;
		else if(temp->data > maxNode->data)
			maxNode = temp;
		temp = temp->next;
	}
	int swap = minNode->data;
	minNode->data = maxNode->data;
	maxNode->data = swap;
	return head;
}

int main() {
	struct Node* head = NULL;
	head = create_ll();
	printf("Before Swapping : ");
	display(head);
	head = swapMinMax(head);
	printf("After Swapping : ");
	display(head);
	return 0;
}