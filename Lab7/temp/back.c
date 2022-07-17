#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node *new=(node *)malloc(sizeof(node));
	new=link;
	new->id=id;
	new->time=time;
	new->link=NULL;
	return new;
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
	int a;
	a=node_ptr->id;
	return a;
}

const int node_get_time(node *node_ptr)
{
//TODO
	int t;
	t=node_ptr->time;
	return t;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO
	node *new=(node *)malloc(sizeof(node));
	new=create_node(id,time,new);
	if(ptr_list->number_of_nodes==0)
	{
		ptr_list->head=new;
		ptr_list->tail=new;
	}
	else
	{
		ptr_list->tail->link=new;
		ptr_list->tail=new;
	}
	(ptr_list->number_of_nodes)++;
}

void list_delete_front(List *ptr_list)
{
//TODO
	node *temp=(node *)malloc(sizeof(node));
	if(ptr_list->number_of_nodes==0);	//do nothing
	else if(ptr_list->number_of_nodes==1)
	{
		temp=ptr_list->head;
		ptr_list->head=NULL;
		ptr_list->tail=NULL;
		free(temp);
	}
	else
	{
		temp=ptr_list->head;
		ptr_list->head=temp->link;
		free(temp);
	}
	(ptr_list->number_of_nodes)--;
}

void list_destroy(List *ptr_list)
{
//TODO
	node *temp=(node *)malloc(sizeof(node));
	node *del=(node *)malloc(sizeof(node));
	temp=ptr_list->head;
	while(ptr_list->head!=NULL && ptr_list->tail!=NULL)
	{
		del=temp;
		free(del);
		temp=temp->link;
	}
	free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
//TODO
	queue_list->ptr_list=(List *)malloc(sizeof(List));
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
	if(!queue_is_empty(ptr))
		list_delete_front(ptr->ptr_list);
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
	if(ptr->ptr_list->number_of_nodes==0)
		printf("Empty Queue\n");
	else
		printf("%d %d\n",node_get_id(ptr->ptr_list->head),node_get_time(ptr->ptr_list->head));
}

void queue_destroy(Queue *ptr)
{
//TODO
	list_destroy(ptr->ptr_list);
	free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO
	int gone=0,id=0;
	node *temp=(node *)malloc(sizeof(node));
	node *n=(node *)malloc(sizeof(node));
	if(queue_is_empty(ptr_queue))
		printf("Empty Queue\n");
	else
	{
		temp=ptr_queue->ptr_list->head;
		n=NULL;
		while(temp!=NULL && gone<=t)
		{
			id=node_get_id(temp);
			gone=gone+node_get_time(temp);
			n=temp;
			temp=temp->link;
			if(gone<t)
				queue_dequeue(ptr_queue);
		}
		if(queue_is_empty(ptr_queue))
		{
			printf("Empty Queue\n");
			return n->id;
		}
		printf("%d\n",n->id);
	}
	return n->id;
}
