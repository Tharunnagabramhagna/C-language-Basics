/* Implementation of Circular Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* create_ll() {
	int n,val;
	printf("Enter number of elements needed : ");
	scanf("%d",&n);
	if(n <= 0)
		return NULL;

	struct Node* head = NULL;
	struct Node* curr = NULL;

	for(int i = 0; i < n; i++) {
		printf("Enter a value : ");
		scanf("%d",&val);
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		if(newNode == NULL) {
			printf("Memory allocation failed.\n");
			return head;
		}
		newNode->data = val;

		if(head == NULL) {
			head = curr = newNode;
			newNode->next = head;
		}
		else {
			curr->next = newNode;
			newNode->next = head;
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

	struct Node* temp = head;
	do {
		printf("%d -> ",temp->data);
		temp = temp->next;
	} while(temp != head);
    printf("(back to head)\n");
}

int search(struct Node* head, int key) {
	if(head == NULL) {
		printf("List is Empty.\n");
		return -1;
	}
	int pos = 1;
	struct Node* temp = head;

	do {
		if(temp->data == key)
			return pos;
		temp = temp->next;
		pos++;
	} while(temp != head);

	return -1;
}

struct Node* insertBegin(struct Node* head, int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("Memory allocation failed.\n");
		return head;
	}

	newNode->data = val;

	if(head == NULL) {
		head = newNode;
		newNode->next = head;
	} else {
		struct Node* temp = head;
		while(temp->next != head)
			temp = temp->next;
		newNode->next = head;
		temp->next = newNode;
		head = newNode;
	}
	return head;
}

struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = val;
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

struct Node* insertAtPos(struct Node* head, int val, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = val;
    if(pos <= 0)
        return head;
    struct Node* temp = head;
    if(pos == 1) {
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            while(temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        return head;
    }
    for(int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
        
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteBegin(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return head;
    }
    
    if(head->next == head) { // Single Node exists
        free(head);
        return NULL;
    }
    
    struct Node* delNode = head;
    struct Node* temp = head;
    
    while(temp->next != head)
        temp = temp->next;
        
    head = head->next;
    temp->next = head;
    
    free(delNode);
    
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty.\n");
        return head;
    }
    
    if(head->next == head) { // Single Node exists
        free(head);
        return NULL;
    }
    
    struct Node* temp = head;
    
    while(temp->next->next != head)
        temp = temp->next;
        
    struct Node* delNode = temp->next;
    temp->next = head;
    free(delNode);
    
    return head;
}

struct Node* deleteAtPos(struct Node* head, int pos) {
    if(pos <= 0)
        return head;
        
    struct Node* temp = head;
    if(pos == 1) {
        if(head->next == head) {
            free(head);
            return NULL;
        }
        struct Node* delNode = head;
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        free(delNode);
        return head;
    }
    
    for(int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
        
    struct Node* delNode = temp->next;
    
    if(delNode == head) { // If only head exists
        printf("Invalid Position.\n");
        return head;
    }
    
    temp->next = delNode->next;
    free(delNode);
    
    return head;
}

int main() {
    struct Node* head = NULL;
    head = create_ll();
    int val,pos;
    while(1) {
        int choice;
        printf("\n--Circular Linked List Operations--\n");
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
		scanf("%d",&choice);
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

			head = insertAtPos(head, val, pos);
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

			head = deleteAtPos(head, pos);
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
