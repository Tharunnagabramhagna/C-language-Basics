// Binary Tree Creation and Traversals
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    // Base Case
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    // Base Case
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    // Base Case
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    struct Node* root = createNode(1);
    
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Inorder Traversal of Binary Tree : ");
    inorder(root);

    printf("\nPreorder Traversal of Binary Tree : ");
    preorder(root);
    
    printf("\nPostorder Traversal of Binary Tree : ");
    postorder(root);

    return 0;
}