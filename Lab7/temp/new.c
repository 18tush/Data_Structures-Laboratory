#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
    node *temp=(node *)malloc(sizeof(node));
    temp->link=NULL;
    temp->id=id;
    temp->time=time;
    return temp;
}
void list_initialize(List *ptr_list)
{
//TODO
    ptr_list->head=NULL;
    ptr_list->tail=NULL;
    ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
//TODO	
   return (node_ptr->id);
}

const int node_get_time(node *node_ptr)
{
//TODO		
    return (node_ptr->time);
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
    node *p,*q,*t;
    p=create_node(id,time,q);
    if(ptr_list->head==NULL)
    {
        ptr_list->head=p;
        ptr_list->tail=p;
    }
    else
    {
       ptr_list->tail->link=p;
       ptr_list->tail=p;
       ptr_list->tail->link=NULL;
    }
    ptr_list->number_of_nodes=ptr_list->number_of_nodes+1;
}

void list_delete_front(List *ptr_list)
{
//TODO	
    node *p;
    if(ptr_list->number_of_nodes==0)
    {
    
    }
    else if(ptr_list->number_of_nodes==1)
    {
        p=ptr_list->head;
        ptr_list->head=NULL;
        ptr_list->tail=NULL;
        free(p);
        ptr_list->number_of_nodes=ptr_list->number_of_nodes-1;
        
    }
    else
    {
        p=ptr_list->head;
        ptr_list->head=p->link;
        free(p);
        ptr_list->number_of_nodes=ptr_list->number_of_nodes-1;
    }
}

void list_destroy(List *ptr_list)
{
//TODO	
    while(ptr_list->number_of_nodes!=0)
    {
        list_delete_front(ptr_list);
    }
}

void queue_initialize(Queue *queue_list)
{
//TODO	
    list_initialize(queue_list->ptr_list);
	}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
   list_insert_rear(ptr->ptr_list,id,time);
}
    
void queue_dequeue(Queue *ptr)
{
//TODO		
    //printf("%d\n",ptr->ptr_list->head->data);
    if(queue_is_empty(ptr)==1)
    {
        
    }
    else
    {
        list_delete_front(ptr->ptr_list);
    }
}

int queue_is_empty(Queue *ptr)
{
//TODO	
    if(ptr->ptr_list->number_of_nodes==0)
        return 1;
    else 
        return 0;	
}

void queue_peek(Queue *ptr)
{
//TODO	
   // printf("%d\n",ptr->ptr_list->head->id);
   if(ptr->ptr_list->number_of_nodes!=0)
        printf("%d %d\n",node_get_id(ptr->ptr_list->head),node_get_time(ptr->ptr_list->head));
   else
        printf("EMPTY QUEUE\n");
    	
}

void queue_destroy(Queue *ptr)
{
//TODO	
    list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO		
    node *temp,*current;
    int tim=0;
    
    while(tim<=t && ptr_queue->ptr_list->number_of_nodes!=0)
    {
        
        temp=ptr_queue->ptr_list->head;
        tim=tim+temp->time;
        if(tim<=t)
            queue_dequeue(ptr_queue);
        
        
        
    }
    current=ptr_queue->ptr_list->head;
    if(ptr_queue->ptr_list->number_of_nodes==0)
        printf("EMPTY QUEUE\n");
    else
        printf("%d\n",current->id);
}