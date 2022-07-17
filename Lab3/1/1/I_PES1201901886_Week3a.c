#include "poly.h"
void insert_at_end(List *list, int data)
{
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

long long int evaluate(List *list, int x)
{
    //TODO
    Node *temp=(Node*)malloc(sizeof(Node));
    long long int power=1;
    long long int answer=0;
    int num=0;
    temp=list->head;
    while(temp!=NULL)
    {
        int count=0;
        while(count<num)
        {
            power*=x;
            count++;
        }
        answer=answer+(temp->data)*power;
        num++;
        power=1;
        temp=temp->link;
    }
    return answer;
}

