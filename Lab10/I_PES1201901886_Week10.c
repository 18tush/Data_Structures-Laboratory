#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO
    tree->root=(struct node *)malloc(sizeof(struct node));
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    //TODO
    Node *temp,*iter;
    temp=(struct node *)malloc(sizeof(struct node));
    iter=tree->root;

    temp->data=data;
    temp->rightThread=1;
    temp->leftThread=1;
    temp->right=NULL;
    temp->left=NULL;

    if(iter==NULL)
        tree->root=temp;
    while(iter!=NULL)
    {
        if(data<iter->data)
        {
            if(iter->leftThread==0)
            {
                iter=iter->left;
            }
            else
                break;
        }

        else
        {
            if(iter->rightThread==0)
            {
                iter=iter->right;
            }
            else
                break;
        }
    }

    if(iter!=NULL)
    {
        if(data<iter->data)
        {
            temp->left=iter->left;
            temp->right=iter;
            iter->leftThread=0;
            iter->left=temp;
        }
        else
        {
            temp->right=iter->right;
            temp->left=iter;
            iter->rightThread=0;
            iter->right=temp;
        }
    }

}

Node *inorder_predecessor(Node *ptr)
{
   //TODO
    if(ptr->leftThread==1)
        return ptr->left;
    else
    {
        ptr=ptr->left;
        while(ptr->rightThread!=1)
            ptr=ptr->right;
    }
    return ptr;
}

Node *inorder_successor(Node *ptr)
{
   //TODO
    if(ptr->rightThread==1)
        return ptr->right;
    else
    {
        ptr=ptr->right;
        while(ptr->leftThread!=1)
            ptr=ptr->left;
    }
    return ptr;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        Node *temp=tree->root;
        while(temp->leftThread!=1)
            temp=temp->left;
        while(temp!=NULL)
        {
            printfun(temp->data);
            temp=inorder_successor(temp);
        }
    }
    nextline();
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        Node *temp=tree->root;
        while(temp->rightThread!=1)
            temp=temp->right;
        while(temp!=NULL)
        {
            printfun(temp->data);
            temp=inorder_predecessor(temp);
        }
    }
    nextline();
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void destroy(Node *r)
{
    //TODO
    Node *temp=(struct node *)malloc(sizeof(struct node));
    Node *del=(struct node *)malloc(sizeof(struct node));
    temp=r;
    if(temp==NULL); // do nothing
    else
    {
        while(temp->leftThread!=1)
            temp=temp->left;
        while(temp!=NULL)
        {
            del=temp;
            temp=inorder_successor(temp);
            free(del);
        }
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
