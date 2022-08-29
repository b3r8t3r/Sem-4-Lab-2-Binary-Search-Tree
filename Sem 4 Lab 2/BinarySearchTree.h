#pragma once
#include <malloc.h>

typedef struct Nod BinarySearchTree;

struct Nod {
    int val;
    BinarySearchTree* left;
    BinarySearchTree* right;
};

BinarySearchTree* Init(int value) {
    BinarySearchTree* tree;
    tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));

    tree->val = value;
    tree->left = tree->right = NULL;
    return (tree);
}

BinarySearchTree* Search(BinarySearchTree* tree, int value) {
    BinarySearchTree* temp = tree;

    for (; temp->val != value;) {
        if (value < temp->val) temp = temp->left;
        else temp = temp->right;

        if (temp == NULL) break;
    }

    return temp;
}

BinarySearchTree* Min(BinarySearchTree* tree) {
    BinarySearchTree* min = tree;
    
    if (min!=NULL)
        for (; min->left != NULL; min = min->left);
    
    return min;
}

BinarySearchTree* Insert(BinarySearchTree* tree, int value) {
    BinarySearchTree* temp = tree, * node = Init(value);
    BinarySearchTree* previousNod = NULL;
    int pos = 0;

    for (; (temp != NULL);) {

        if (value < temp->val) {
            previousNod = temp;
            temp = temp->left;
            pos = 0;

        }
        else {
            previousNod = temp;
            temp = temp->right;
            pos = 1;
        }
    }
    if (pos == 0) {
        previousNod->left = node;
    }
    else {
        previousNod->right = node;
    }

    return tree;
}

void Remove(BinarySearchTree* tree, int value) {
    BinarySearchTree* toDelete = tree;
    static BinarySearchTree* previousNod = NULL;
    static int pos = 0; 
    if (toDelete == NULL) return;
    else {
        if (value < toDelete->val) { 
            previousNod = toDelete;
            pos = 0;
            Remove(toDelete->left, value);
        }
        else if (value > toDelete->val) { 
            previousNod = toDelete;
            pos = 1;
            Remove(toDelete->right, value);
        }
        else { 
            if (toDelete->left == NULL && toDelete->right == NULL) { 
                if (pos == 0) previousNod->left = NULL;
                else previousNod->right = NULL;

                free(toDelete);
            }
                
            else if ((toDelete->left == NULL) || (toDelete->right == NULL)) {
                if (toDelete->left == NULL) {
                    if (pos == 0) previousNod->left = toDelete->right;
                    else previousNod->right = toDelete->right;

                    free(toDelete);
                }
                else {
                    if (pos == 0) previousNod->left = toDelete->left;
                    else previousNod->right = toDelete->left;

                    free(toDelete);
                }
            }
            else {
                BinarySearchTree* min = Min(toDelete->right);
                toDelete->val = min->val;
                free(min);
            }
        }
    }
    previousNod = NULL;
    pos = 0;
}

void Traverse(BinarySearchTree* tree, int type) {
    if (tree != NULL) {
        if (type == 0) {
            Traverse(tree->left, 0);
            printf("%d ", tree->val);
            Traverse(tree->right, 0);
        }
        if (type == 1) {
            printf("%d ", tree->val);
            Traverse(tree->left, 1);
            Traverse(tree->right, 1);
        }
        if (type == 2) {
            
            Traverse(tree->left, 2);
            Traverse(tree->right, 2);
            printf("%d ", tree->val);
        }
    }
    return;    
}