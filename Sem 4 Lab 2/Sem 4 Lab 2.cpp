#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"



void main()
{
    
    
    //3 уровня
    //BinarySearchTree* MainTree = Init(4);//3 уровня
    //Insert(MainTree, 2);
    //Insert(MainTree, 6);

    //Insert(MainTree, 1);
    //Insert(MainTree, 3);
    //Insert(MainTree, 5);
    //Insert(MainTree, 7);
    
    //4 уровня
    BinarySearchTree* MainTree = Init(8);//4 уровня
    Insert(MainTree, 4);
    Insert(MainTree, 12);

    Insert(MainTree, 2);
    Insert(MainTree, 6);
    Insert(MainTree, 10);
    Insert(MainTree, 14);

    Insert(MainTree, 1);
    Insert(MainTree, 3);
    Insert(MainTree, 5);
    Insert(MainTree, 7);
    Insert(MainTree, 9);
    Insert(MainTree, 11);
    Insert(MainTree, 13);
    Insert(MainTree, 15);
    printf("Infix:\n");
    Traverse(MainTree,0);
    printf("\nPrefix:\n"); 
    Traverse(MainTree, 1);
    printf("\nPostfix:\n");
    Traverse(MainTree, 2);
    /*Remove(MainTree, 1);
    Remove(MainTree, 7);
    Remove(MainTree, 2);
    Remove(MainTree, 6);
    Remove(MainTree, 4);
    Remove(MainTree, 12);*/

    //BinarySearchTree* MainTree = Init(2);//4 уровня
    //Insert(MainTree, 1);
    //Insert(MainTree, 3);
    //Remove(MainTree, 2);

    //Вырожденное дерево
    /*BinarySearchTree* MainTree = Init(1);
    Insert(MainTree, 2);
    Insert(MainTree, 3);
    Insert(MainTree, 4);
    Insert(MainTree, 5);
    Insert(MainTree, 6);
    Insert(MainTree, 7);*/
    //Traverse(MainTree, 0);
    printf("Done");
}