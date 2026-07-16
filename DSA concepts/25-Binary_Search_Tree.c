/* Binary Search Tree */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* createBST(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* getIS(struct Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node* insert(struct Node* root, int val) {
    if(root == NULL)
        return createBST(val);
    if(val < root->data)
        root->left = insert(root->left,val);
    else if (val > root->data)
        root->right = insert(root->right,val);
    return root;
}

struct Node* deleteNode(struct Node* root, int val) {
    if(root == NULL)
        return root;
    if(val < root->data)
        root->left = deleteNode(root->left,val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else { // val == root->data
        // 0 children case
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // 1 child case
        else if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } 
        // 2 childs case    
        struct Node* temp = getIS(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return search(root->left,key);
    return search(root->right,key);
}

void inorder(struct Node* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    
    printf("Inorder Traversal : ");
    inorder(root);
    
    int key = 40;
    if(search(root,key))
        printf("\n%d found in BST.\n",key);
    else
        printf("%d not found in BST.",key);
        
    root = deleteNode(root,50);
    printf("\nInorder after deleting 50 : \n");
    inorder(root);
    printf("\n");
    
    return 0;
}