#include <stdio.h>
#include <stdlib.h>

// AVL Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Height function
int height(struct Node *node) {
    if(node == NULL)
        return 0;

    return node->height;
}

// Maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create new node
struct Node* createNode(int data) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// Right Rotation
struct Node* rightRotate(struct Node* y) {

    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height =
        max(height(y->left), height(y->right)) + 1;

    x->height =
        max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation
struct Node* leftRotate(struct Node* x) {

    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height =
        max(height(x->left), height(x->right)) + 1;

    y->height =
        max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance Factor
int getBalance(struct Node* node) {

    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// AVL Insertion
struct Node* insert(struct Node* node, int key) {

    // Normal BST insertion
    if(node == NULL)
        return createNode(key);

    if(key < node->data)
        node->left = insert(node->left, key);

    else if(key > node->data)
        node->right = insert(node->right, key);

    else
        return node;

    // Update height
    node->height =
        1 + max(height(node->left),
                height(node->right));

    // Balance factor
    int balance = getBalance(node);

    // LEFT LEFT
    if(balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RIGHT RIGHT
    if(balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LEFT RIGHT
    if(balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RIGHT LEFT
    if(balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Minimum value node
struct Node* minValueNode(struct Node* node) {

    struct Node* current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

// AVL Deletion
struct Node* deleteNode(struct Node* root, int key) {

    // Normal BST deletion
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        // One child or no child
        if(root->left == NULL ||
           root->right == NULL) {

            struct Node* temp =
                root->left ? root->left : root->right;

            // No child
            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }

            free(temp);
        }

        else {

            // Two children
            struct Node* temp =
                minValueNode(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL)
        return root;

    // Update height
    root->height =
        1 + max(height(root->left),
                height(root->right));

    // Balance factor
    int balance = getBalance(root);

    // LEFT LEFT
    if(balance > 1 &&
       getBalance(root->left) >= 0)
        return rightRotate(root);

    // LEFT RIGHT
    if(balance > 1 &&
       getBalance(root->left) < 0) {

        root->left =
            leftRotate(root->left);

        return rightRotate(root);
    }

    // RIGHT RIGHT
    if(balance < -1 &&
       getBalance(root->right) <= 0)
        return leftRotate(root);

    // RIGHT LEFT
    if(balance < -1 &&
       getBalance(root->right) > 0) {

        root->right =
            rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {

    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {

    struct Node* root = NULL;

    // Insertions
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder after insertion:\n");
    inorder(root);

    // Deletion
    root = deleteNode(root, 40);

    printf("\n\nInorder after deletion:\n");
    inorder(root);

    return 0;
}