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

    /*while (temp->left!=NULL&&temp->right!=NULL) {
        if (value < temp->val) temp = temp->left;
        else temp = temp->right;
    }*/
    /*if (temp->left==NULL) printf("temp->left == NULL\n");
    if (temp->right == NULL) printf("temp->right == NULL\n");*/

    for (; temp->val != value;) {
        if (value < temp->val) temp = temp->left;
        else temp = temp->right;

        if (temp == NULL) break;
    }



    /*if (temp == NULL) {
        printf("temp == NULL\n");
    }*/

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
   /* for (; (temp->left != NULL && temp->right != NULL);) {
        
        if (value < temp->val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        
    }*/

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
    /*if (value < temp->val) {
        temp->left = node;
    }
    else {
        temp->right = node;
    }*/
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
    static int pos = 0; //Если 0 - предыдущий шаг был пройден влево, 1 - вправо
    if (toDelete == NULL) return;
    else {
        if (value < toDelete->val) { //Идет по левому поддереву
            previousNod = toDelete;
            pos = 0;
            Remove(toDelete->left, value);
        }
        else if (value > toDelete->val) { //Идет по левому поддереву
            previousNod = toDelete;
            pos = 1;
            Remove(toDelete->right, value);
        }
        else { //Рассматривает текущий элемент
            if (toDelete->left == NULL && toDelete->right == NULL) { 
                if (pos == 0) previousNod->left = NULL;
                else previousNod->right = NULL;

                free(toDelete);
            }
                
            else if ((toDelete->left == NULL) || (toDelete->right == NULL)) {
                if (toDelete->left == NULL) {
                    /*toDelete->val = toDelete->right->val;
                    toDelete->left = toDelete->right->left;
                    toDelete->right = toDelete->right->right;*/
                    if (pos == 0) previousNod->left = toDelete->right;
                    else previousNod->right = toDelete->right;

                    free(toDelete);
                }
                else {
                    /*toDelete->val = toDelete->left->val;
                    toDelete->right = toDelete->left->right;
                    toDelete->left = toDelete->left->left;*/
                    if (pos == 0) previousNod->left = toDelete->left;
                    else previousNod->right = toDelete->left;

                    free(toDelete);
                }
            }
            else {
                /*if (toDelete->right->left == NULL) {
                    if (previousNod != NULL) 
                    {
                        if (pos == 0) {
                            previousNod->left = toDelete->right;
                        }
                        else {
                            previousNod->right = toDelete->right;
                        }
                        free(toDelete);

                    }
                    else {
                        BinarySearchTree* temp = toDelete->right;
                        previousNod = toDelete;

                        for (; temp->left != NULL;  temp = temp->left) previousNod = temp;

                        previousNod->left = NULL;

                        temp->left = toDelete->left;
                        temp->right = toDelete->right;

                        free(toDelete);
                    }
                }*/
                /*if (previousNod != NULL) {

                }
                else {
                    toDelete->right->left = toDelete->left;
                    free(toDelete);
                }*/
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