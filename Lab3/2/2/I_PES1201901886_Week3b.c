#include<stdlib.h>
#include"dll.h"
int count_nodes(List* dll)
{
	//TODO
	int count=0;
	Node *temp;
	temp=dll->head;
	if(temp==NULL)
		return 0;
	else
	{
		while(temp!=NULL)
		{
			count=count+1;
			temp=temp->next;
		}
	}
	return count;
}

void insert_front(List* dll, int data)
{
    //TODO
    Node *n= create_node(data);
	if((dll->head) == NULL)
        dll->head=n;
	else
	{
	    n->next = dll->head;
		(dll->head)->prev = n;
		dll->head=n;
	}
	dll->number_of_nodes++;
}


void dllist_delete_beginning(List* list)
{
    //TODO
     if(list->head != NULL)
    {
        Node *n= (Node*)malloc(sizeof(Node));
        n= list->head;
        list->head = n->next;
        n->next->prev = NULL;
        free(n);
        list->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos)
{
    //TODO
    if(dll->head != NULL && pos < dll->number_of_nodes && pos >= 0)
    {
        Node *n = (Node*)malloc(sizeof(Node));
        n= dll->head;

        int count= 0;
            while(n->next != NULL && count!= pos)
            {
                n= n->next;
                    count++;
            }
            n->prev->next = n->next;
            n->next->prev = n->prev;
        dll->number_of_nodes--;
        free(n);
    }
}

int search_list(List* dll,int key)
{
    //TODO
     if(dll->head == NULL)
    {
        return -1;
    }
    Node *n= (Node*)malloc(sizeof(Node));
    n= dll->head;
    int count=0;
    while(n!= NULL)
    {
        if(n->data == key){
            return count;
        }
        n=n->next;
        count++;
    }
    return -1;
}


void reverse_list(List* dll)
{
    //TODO
      Node *temp = NULL;
      Node *curr = dll->head;
     while (curr !=  NULL)
     {
       temp = curr->prev;
       curr->prev = curr->next;
       curr->next = temp;
       curr = curr->prev;
     }
     if(temp != NULL )
        dll->head = temp->prev;
}


