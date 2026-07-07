/* Moving Last El to First in a Linked List */

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

struct Node* LastToFirst(struct Node* head) {
	// Edge Case
	if(head == NULL || head->next == NULL) // single Node (or) 0
		return NULL;

	struct Node* last, *prev;
	last = head;
	prev = NULL;

	while(last->next != NULL) {
		prev = last;
		last = last->next;
	}

	prev->next = NULL;
	last->next = head;
	head = last;

	return head;
}

int main() {

	struct Node* head;
	head = create_ll();
	display(head);
	head = LastToFirst(head);
	display(head);

	return 0;
}