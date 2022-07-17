#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	//TODO
	struct Node *new=malloc(sizeof(struct Node));
    new->link=NULL;
    new->data=data;
	if(list->head==NULL)
    {
        list->head=new;
    }
    else
    {
        struct Node *tempo= list->head;
        while(tempo->link!=NULL)
        {
            tempo=tempo->link;
        }
        tempo->link=new;
    }
    list->number_of_nodes++;
}

void list_delete_front(List* list) {
	//TODO
    if(list->head!=NULL)
    {
        struct Node *del=list->head;
        list->head=(del->link);
        list->number_of_nodes--;
    }
}

void list_insert_at (List *list, int data, int position)
{
	//TODO
    if(position==0)
    {
        struct Node *new=malloc(sizeof(struct Node));
        new->data=data;
        new->link=(list->head);
        list->head=new;
        list->number_of_nodes+=1;
    }
    else if(position<=list->number_of_nodes && position>0)
    {
        struct Node *new=malloc(sizeof(struct Node));
        new->data=data;
        struct Node *temp=list->head;
        for(int i=0;i<=position;i++)
        {
            if(i==position-1)
            {
                new->link=(temp->link);
                temp->link=new;
                list->number_of_nodes+=1;
            }
            temp=temp->link;
        }
    }
}

void list_reverse(List* list)
{
 	//TODO
    struct Node *pre=NULL;
    struct Node *cur= list->head;
    struct Node *next=NULL;
    while(cur!=NULL)
    {
        next=cur->link;
        cur->link=pre;
        pre=cur;
        cur=next;
    }
    list->head=pre;
}



