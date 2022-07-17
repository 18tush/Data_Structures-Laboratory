#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO
}

void tree_insert(Tree *tree, int data)
{
    //TODO
}

Node *inorder_predecessor(Node *ptr)
{
   //TODO
}

Node *inorder_successor(Node *ptr)
{
   //TODO
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
