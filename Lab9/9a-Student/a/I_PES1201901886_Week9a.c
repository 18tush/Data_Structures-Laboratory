#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
    Node *s[len];
    char ch;
    int i=0;
    int count=0;
    while(*(a+i)!='\0')
    {
    	ch=*(a+i);
    	Node *new=(struct Node *)(malloc(sizeof(struct Node)));
    	new->left=NULL;
    	new->right=NULL;
    	new->data=ch;

    	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    	{
    		if(count!=0)
    		{
    			count=count-1;
    			new->right=s[count];
    			count=count-1;
    			new->left=s[count];
    			s[count]=new;
    			count=count+1;
    		}
    		else
    			return NULL;
    	}
    	else
    	{
    		s[count]=new;
    		count=count+1;
    	}
    	i=i+1;
    }
    return s[0];
}


void inorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
	if(root!=NULL)
	{
		inorder(root->left);
 		printf("%c",root->data);
 		inorder(root->right);
	}
}

void preorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
	if(root!=NULL)
	{
		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->data);
	}
}

void freeTree(Node *root)
{
	root->left=NULL;
	root->right=NULL;
	root->prev=NULL;
	free(root);
}


