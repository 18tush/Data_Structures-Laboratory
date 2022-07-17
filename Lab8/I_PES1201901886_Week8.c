#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    //TODO
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
	Node *new=(Node *)(malloc(sizeof(Node)));
	Node *temp;
	int a=1;
	new->right=NULL;
	new->left=NULL;
	new->data=data;
	if(tree->root==NULL)
		tree->root=new;
	else
	{
		temp=tree->root;
		while(a)
		{
			if(data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=new;
					a=0;
				}
				else
					temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=new;
					a=0;
				}
				else
					temp=temp->right;
			}
		}
	}
}

void tree_delete(Tree *tree, int element)
{
   // TODO : Delete elements from BST
	Node *par,*temp,*child,*insc;
	par=NULL;child=NULL;
	temp=tree->root;

	while(temp!=NULL && temp->data!=element)
	{
		par=temp;
		if(element<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}

	if(temp==NULL);	//Do nothing(since element doesnot exist)
	else if(temp->left==NULL)
		child=temp->right;
	else if(temp->right==NULL)
		child=temp->left;
	else
	{
		insc=temp->right;
		while(insc->left!=NULL)
			insc=insc->left;

		insc->left=temp->left;
		child=temp->right;
	}

	if(par==NULL)
		tree->root=child;
	else if(temp=par->left)
		par->left=child;
	else if(temp=par->right)
		par->right=child;
		free(temp);
}

void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder
	if(r!=NULL)
	{
		tree_inorder(r->left);	
		printf("%d ",r->data);
		tree_inorder(r->right);
	}
}

void tree_preorder(Node *r)
{
    //TODO :  use printf to print preorder
    if(r!=NULL)
	{
		printf("%d ",r->data);	
		tree_preorder(r->left);
		tree_preorder(r->right);
	}
}

void tree_postorder(Node *r)
{
    //TODO :  use printf to print postorder
    if(r!=NULL)
	{
		tree_postorder(r->left);	
		tree_postorder(r->right);
		printf("%d ",r->data);
	}
}

void postorder(Tree *t)
{
   //TODO
	tree_postorder(t->root);
	printf("\n");
}

void preorder(Tree *t)
{
     //TODO
	tree_preorder(t->root);
	printf("\n");
}

void inorder(Tree *t)
{
  //TODO
	tree_inorder(t->root);
	printf("\n");
}

void destroy(Node *r)
{
  //TODO
	free(r);
}

void tree_destroy(Tree *t)
{
//TODO
	destroy(t->root);
	free(t);
}

