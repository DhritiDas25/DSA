/*1. Create a binary tree using an array/linked List.*/
/*This program is done uaing linked lists*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create() {
    int x;
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    
    if(x == -1) return NULL;
    
    newNode->data = x;
    printf("Enter left child of %d:\n", x);
    newNode->left = create();
    printf("Enter right child of %d:\n", x);
    newNode->right = create();
    
    return newNode;
}

int main() {
    struct Node *root;
    printf("Constructing the Binary Tree:\n");
    root = create();
    
    if(root == NULL) printf("Tree is empty.\n");
    else printf("\nBinary Tree Created Successfully.\n");
    
    return 0;
}