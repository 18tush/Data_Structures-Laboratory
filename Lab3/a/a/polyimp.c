#include "poly.h"
#include<stdio.h>

void insert_at_end(List *list, int data) 
{
	struct Node *p;
	p=malloc(sizeof(Node));
	struct Node *q;
	q=list->head;
	p->data=data;
	p->link=NULL;
	if(list->head==NULL)
	{
	    list->head=p;
	}
	else
	{
	    while(q->link!=NULL)
	    {
	        q=q->link;
	    }
	    q->link=p;
	}
	list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{
    int i=0,k,l=0;
    struct Node *p;
    p=list->head;
  
   while(p!=NULL)
   {
        if(l==0)
            k=1;
        else
        {
            k=k*x;
        }
        
        i=i+(p->data)*k;
        l++;
        p=p->link;
   }
   return i;
}
