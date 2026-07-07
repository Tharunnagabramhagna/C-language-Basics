#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* create_list() {
	int n, val;
	printf("Enter elements needed : ");
	scanf("%d",&n);
	if(n <= 0)
		return NULL;
	struct Node *head = NULL;
	struct Node *curr = NULL;
	for(int i = 0; i < n; i++) {
		printf("Enter a value : ");
		scanf("%d",&val);
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = val;
		newNode->next = NULL;
		if(newNode == NULL) {
			printf("Memory allocation failed.\n");
			return head;
		}
		if(head == NULL)
			head = curr = newNode;
		else {
			curr->next = newNode;
			curr = newNode;
		}
	}
	return head;
}

/* Display List */
void display(struct Node *head) {
	if(head == NULL) {
		printf("Linked List is Empty.\n");
		return;
	}
	struct Node *iterator;
	for(iterator = head; iterator != NULL; iterator = iterator->next)
		printf("%d ",iterator->data);
	printf("\n");
}

/* Insert at Beginning */
struct Node *insertBegin(struct Node *head, int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("Memory allocation failed.\n");
		return head;
	}
	newNode->data = val;
	newNode->next = head;
	return newNode;
}

/* Insert at End */
struct Node *insertEnd(struct Node *head, int val) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	if(newNode == NULL) {
		printf("Memory allocation failed.\n");
		return head;
	}
	if(head == NULL)
		return newNode;
	struct Node* iterator = head;
	while(iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = newNode;
	return head;
}

/* Insert at Any Position */
struct Node *insertAtPosition(struct Node *head, int val, int pos) {
	struct Node *newNode =
	    (struct Node*)malloc(sizeof(struct Node));

	if(newNode == NULL) {
		printf("Memory allocation failed\n");
		return head;
	}

	newNode->data = val;
	newNode->next = NULL;
	
	if(pos <= 0) // Edge case
	    return head;

	/* Insert at beginning */
	if(pos == 1) {
		newNode->next = head;
		return newNode;
	}

	struct Node *iterator = head;

	for(int i = 1; i < pos - 1 && iterator != NULL; i++)
		iterator = iterator->next;

	if(iterator == NULL) { // Edge Case
		printf("Invalid Position.\n");
		free(newNode);
		return head;
	}

	newNode->next = iterator->next;
	iterator->next = newNode;

	return head;
}

/* Search Element */
int search(struct Node *head, int key) {
	struct Node *iterator;
	int pos = 1;

	if(head == NULL) {
		printf("List is Empty.\n");
		return -1;
	}

	for(iterator = head; iterator != NULL; iterator = iterator->next) {
		if(iterator->data == key)
			return pos;
		pos++;
	}

	return -1;
}

/* Delete at Beginning */
struct Node *deleteBegin(struct Node *head) {
	if(head == NULL) {
		printf("List is Empty.\n");
		return head;
	}

	struct Node* iterator = head;
	head = head->next;
	free(iterator);
	return head;
}

/* Delete at End */
struct Node *deleteEnd(struct Node *head) {

	if(head == NULL) {
		printf("List is Empty.\n");
		return NULL;
	}

	if(head->next == NULL) {
		free(head);
		return NULL;
	}

	struct Node *iterator = head;

	while(iterator->next->next != NULL)
		iterator = iterator->next;

	free(iterator->next);

	iterator->next = NULL;

	return head;
}

/* Delete at Any Position */
struct Node *deleteAtPosition(struct Node *head, int pos) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return NULL;
    }
    if(pos <= 0)
        return head;
    if(pos == 1) {
        struct Node* iterator = head;
        head = head->next;
        free(iterator);
        return head;
    }
    struct Node* iterator = head;
    for(int i = 1; i < pos - 1 && iterator->next != NULL; i++)
        iterator = iterator->next;
        
    if(iterator->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    
    struct Node* deleteNode = iterator->next;
    iterator->next = deleteNode->next;
    
    free(deleteNode);
    
    return head;
}

/* Main Function */
int main() {

	struct Node *head = NULL;

	head = create_list();

	int choice, val, pos;

	while(1) {

		printf("\n__Single Linked List Functions__\n");
		printf("Enter your choice :\n");
		printf("1. Insert at Begin\n");
		printf("2. Insert at End\n");
		printf("3. Insert at Position\n");
		printf("4. Delete at Begin\n");
		printf("5. Delete at End\n");
		printf("6. Delete at Position\n");
		printf("7. Search\n");
		printf("8. Display\n");
		printf("9. Exit\n");

		scanf("%d", &choice);

		switch(choice) {

		case 1:
			printf("Enter value : ");
			scanf("%d", &val);

			head = insertBegin(head, val);
			display(head);
			break;

		case 2:
			printf("Enter value : ");
			scanf("%d", &val);

			head = insertEnd(head, val);
			display(head);
			break;

		case 3:
			printf("Enter position : ");
			scanf("%d", &pos);

			printf("Enter value : ");
			scanf("%d", &val);

			head = insertAtPosition(head, val, pos);
			display(head);
			break;

		case 4:
			head = deleteBegin(head);
			display(head);
			break;

		case 5:
			head = deleteEnd(head);
			display(head);
			break;

		case 6:
			printf("Enter position to delete : ");
			scanf("%d", &pos);

			head = deleteAtPosition(head, pos);
			display(head);
			break;

		case 7:
			printf("Enter value to search : ");
			scanf("%d", &val);

			pos = search(head, val);

			if(pos == -1)
				printf("Element not found\n");
			else
				printf("Found at position %d\n", pos);

			break;

		case 8:
			display(head);
			break;

		case 9:
			printf("Exiting Program...\n");
			return 0;

		default:
			printf("Invalid Choice\n");
		}
	}

	return 0;
}