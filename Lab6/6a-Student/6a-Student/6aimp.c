#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO	
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
}

void List_delete_front(List* ptr_List)
{
	//TODO
}

void List_destroy(List* ptr_List) 
{
	//TODO
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
}

int postfix_eval(const char* expression) 
{
    // TODO
}
