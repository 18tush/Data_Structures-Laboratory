#include "6a.h"
#include<stdlib.h>
#include<stdio.h>
static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO	
    ptr_List->head=NULL;
    ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
    struct node* p;
	p=create_Node(data,ptr_List->head);
	ptr_List->head=p;
	(ptr_List->number_of_Nodes)++;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	//TODO
	struct node *q=(struct node *)(malloc(sizeof(struct node)));
	q=ptr_List->head;
	ptr_List->head=q->link;
	free(q);
	(ptr_List->number_of_Nodes)--;
}

void List_destroy(List* ptr_List) 
{
	//TODO
	Node* p = (Node*)malloc(sizeof(Node));
    Node* q = (Node*)malloc(sizeof(Node));
    p = ptr_List->head;
    q = NULL;
    for(int i = 0; i < ptr_List->number_of_Nodes; i++)
    {
        q = p;
        p = p->link;
        free(q);
    }
    free(ptr_List);
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
	ptr_stack -> ptr_List = malloc(sizeof(struct list));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
	List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
	if(ptr_stack->ptr_List->number_of_Nodes == 0)
	{
        return 1;
    }
    else
    	return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
	return Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
	List_destroy(ptr_stack->ptr_List);
 	free(ptr_stack);
}

int postfix_eval(const char* expression) 
{
    // TODO
    int i=0,p;
    Stack post_fix;
    stack_initialize(&post_fix);
    
    while(*(expression+i)!='\0')
    {
        
        if((*(expression+i)>=48) && (*(expression+i)<=57))
        {
            stack_push(&post_fix,*(expression+i));
        }
        else if(*(expression+i)==43)
        {
            int j,k;
            if(stack_is_empty(&post_fix))
                return 0;
            j=stack_peek(&post_fix);

            if(j>=48 && j<=57)
                j=j-48;
            stack_pop(&post_fix);
            
            if(stack_is_empty(&post_fix))
                return 0;
            k=stack_peek(&post_fix);
            if(k>=48 && k<=57)
                k=k-48;
            stack_pop(&post_fix);
            p=j+k;
            stack_push(&post_fix,j+k);
        
        }
        else if(*(expression+i)==45)
        {
            int j,k;
            if(stack_is_empty(&post_fix))
                return 0;
            j=stack_peek(&post_fix);
            if(j>=48 && j<=57)
            j=j-48;
            stack_pop(&post_fix);
            
            if(stack_is_empty(&post_fix))
                return 0;
            
            k=stack_peek(&post_fix);
            if(k>=48 && k<=57)
            k=k-48;
            stack_pop(&post_fix);
            p=k-j;
            stack_push(&post_fix,k-j);
        
        }
        else if(*(expression+i)==42)
        {
            int j,k;
            if(stack_is_empty(&post_fix))
                return 0;
            j=stack_peek(&post_fix);
            if(j>=48 && j<=57)
                j=j-48;
            stack_pop(&post_fix);
            if(stack_is_empty(&post_fix))
                return 0;
            k=stack_peek(&post_fix);
            if(k>=48 && k<=57)
                k=k-48;
            stack_pop(&post_fix);
            p=j*k;
            stack_push(&post_fix,j*k);
        
        }
        else if(*(expression+i)==47)
        {
            int j,k;
            if(stack_is_empty(&post_fix))
                return 0;
            j=stack_peek(&post_fix);
            if(j>=48 && j<=57)
            j=j-48;
            stack_pop(&post_fix);
            if(stack_is_empty(&post_fix))
                return 0;
            k=stack_peek(&post_fix);
            if(k>=48 && k<=57)
            k=k-48;
            stack_pop(&post_fix);
            p=k/j;
            stack_push(&post_fix,k/j);
        
        }
        
        i++;
    }
    if(stack_is_empty(&post_fix))
        (stack_destroy(&post_fix));
    
        
   
    return p;
    
}
