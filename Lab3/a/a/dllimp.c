#include"dll.h"
#include<stdlib.h>
int count_nodes(List* dll)
{

	return dll->number_of_nodes;
	
}

void insert_front(List* dll, int data)
{
    struct Node *temp=malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(dll->head==NULL)
    {
        dll->head=temp;
        temp->prev=dll->tail;
        
    }
    else
    {
       Node *p=malloc(sizeof(Node));
       Node *q=malloc(sizeof(Node));
       q=p->prev;
       p=dll->head;
       dll->head=temp;
       temp->next=p;
       q=temp;
       temp->prev=dll->tail;
       
        
    }
    dll->number_of_nodes=dll->number_of_nodes + 1;
}


void dllist_delete_beginning(List* list)
{
    if(list->head==NULL)
    {
        
    }
    else
    {
        struct Node *p=malloc(sizeof(Node));
        
        p=list->head;
        list->head=p->next;
        list->tail=p->next->prev;
        free(p);
        list->number_of_nodes=list->number_of_nodes - 1;
        
    }
}

void position_delete(List* dll, int pos)
{
     struct Node *p,*q;
     p=dll->head;
     q=p;
     int i=1;
     if(pos==1)
     {
        
        dll->head=p->next;
        dll->tail=p->next->prev;
        free(p);
        dll->number_of_nodes=dll->number_of_nodes - 1;
     }
    else if(pos==dll->number_of_nodes)
    {
        struct Node *a;
        
        while(q->next!=NULL)
        {   
            a=q;
            q=q->next;
        }
        a->next=NULL;
        free(q);
        dll->number_of_nodes=dll->number_of_nodes - 1;
        
        
        //dll->number_of_nodes=dll->number_of_nodes - 1;
        
    }
    else
    {
        struct Node *a;
        while(i<pos)
        {
            a=p;
            p=p->next;
            i++;
        }
        a->next=p->next;
        p->next->prev=a->prev;
        free(p);
        dll->number_of_nodes=dll->number_of_nodes - 1;
    }
        
     
     
}

int search_list(List* dll,int key)
{
    struct Node *p=malloc(sizeof(Node));
    p=dll->head;
    int i=1;
    while(p!=NULL)
    {
        if(key==p->data)
            return i;
        i++;
        p=p->next;
        
    }
    return -1;
}


void reverse_list(List* dll)
{
    
    
   
    
}


