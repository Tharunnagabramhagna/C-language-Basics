#include <stdio.h>
#include <stdlib.h>

/* Structure */
struct dNode {
    int data;
    struct dNode *prev, *next;
};

/* Create */
struct dNode* create_ddlist() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0) return NULL;

    struct dNode *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);

        struct dNode* newNode = (struct dNode*)malloc(sizeof(struct dNode));
        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }

        newNode->data = val;
        newNode->prev = newNode->next = NULL;

        if(head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

/* Display */
void display(struct dNode *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct dNode *temp;
    for(temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

/* Insert Begin */
struct dNode* insertBegin(struct dNode* head, int val) {
    struct dNode* newNode = (struct dNode*)malloc(sizeof(struct dNode));
    if(newNode == NULL) return head;

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    return newNode;
}

/* Insert End */
struct dNode* insertEnd(struct dNode* head, int val) {
    struct dNode* newNode = (struct dNode*)malloc(sizeof(struct dNode));
    if(newNode == NULL) return head;

    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct dNode* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Insert AT Position (independent) */
struct dNode* insertAtPos(struct dNode* head, int val, int pos) {
    if(pos <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* newNode = (struct dNode*)malloc(sizeof(struct dNode));
    if(newNode == NULL) return head;

    newNode->data = val;
    newNode->prev = newNode->next = NULL;

    if(pos == 1) {
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct dNode* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position\n");
        free(newNode);
        return head;
    }

    if(temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

/* Insert AFTER Position (independent) */
struct dNode* insertAfterPos(struct dNode* head, int val, int pos) {
    if(pos <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* temp = head;
    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* newNode = (struct dNode*)malloc(sizeof(struct dNode));
    if(newNode == NULL) return head;

    newNode->data = val;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

/* Delete Begin */
struct dNode* deleteBegin(struct dNode* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct dNode* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
    return head;
}

/* Delete End */
struct dNode* deleteEnd(struct dNode* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct dNode* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    return head;
}

/* Delete AT Position (independent) */
struct dNode* deleteAtPos(struct dNode* head, int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* temp = head;

    // Case 1: Delete the head node (Position 1)
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    // Traverse to the exact node at the given position
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    // Position is out of bounds
    if (temp == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    // Case 2: Delete the last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
    } 
    // Case 3: Delete a middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}


/* Delete AFTER Position (independent) */
struct dNode* deleteAfterPos(struct dNode* head, int pos) {
    if(head == NULL || pos <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* temp = head;

    // move to position 'pos'
    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    struct dNode* del = temp->next;  // node to delete

    /* Case 1: deleting last node */
    if(del->next == NULL) {
        del->prev->next = NULL;
        free(del);
        return head;
    }

    /* Case 2: deleting middle node */
    del->prev->next = del->next;
    del->next->prev = del->prev;

    free(del);
    return head;
}

/* Search */
int search(struct dNode *head, int key) {
    if(head == NULL) {
        printf("Linked List is empty.\n");
        return -1;
    }
    int pos = 1;
    struct dNode *temp;
    for(temp = head; temp != NULL; temp = temp->next) {
        if(temp->data == key)
            return pos;
        pos++;
    }
    return -1;
}

/* Main */
int main() {
    struct dNode *head = create_ddlist();
    int choice, val, pos;

    while(1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1.Insert Begin\n2.Insert End\n3.Insert AtPos\n4.Insert AfterPos\n");
        printf("5.Delete Begin\n6.Delete End\n7.Delete AtPos\n8.Delete AfterPos\n");
        printf("9.Search\n10.Display\n11.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            scanf("%d", &val);
            head = insertBegin(head, val);
            break;

        case 2:
            scanf("%d", &val);
            head = insertEnd(head, val);
            break;

        case 3:
            scanf("%d %d", &val, &pos);
            head = insertAtPos(head, val, pos);
            break;

        case 4:
            scanf("%d %d", &val, &pos);
            head = insertAfterPos(head, val, pos);
            break;

        case 5:
            head = deleteBegin(head);
            break;

        case 6:
            head = deleteEnd(head);
            break;

        case 7:
            scanf("%d", &pos);
            head = deleteAtPos(head, pos);
            break;

        case 8:
            scanf("%d", &pos);
            head = deleteAfterPos(head, pos);
            break;

        case 9:
            scanf("%d", &val);
            pos = search(head, val);
            if(pos == -1)
                printf("Not found\n");
            else
                printf("Found at position %d\n", pos);
            break;

        case 10:
            display(head);
            break;

        case 11:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}