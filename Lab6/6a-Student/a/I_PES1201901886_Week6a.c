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
	ptr_List->head=NULL;
	ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data)
{
//TODO
	Node *new_node;
	new_node=create_Node(data,ptr_List->head);
	if(ptr_List->head==NULL)
	{
		 ptr_List->head=new_node;
		 ptr_List->number_of_Nodes=ptr_List->number_of_Nodes+1;
	}
	new_node->link=ptr_List->head;
	ptr_List->head=new_node;
	ptr_List->number_of_Nodes=ptr_List->number_of_Nodes+1;
}

const int Node_get_data(Node *Node_ptr)
{
	//TODO
	if(Node_ptr==NULL)
		return 0;
	else
		return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	//TODO
	Node *del=(Node*)malloc(sizeof(Node));
	if(ptr_List->head==NULL);	// Do nothing
	else
	{
		del=ptr_List->head;
		ptr_List->head=del->link;
		free(del);
	}
	ptr_List->number_of_Nodes=ptr_List->number_of_Nodes-1;
}

void List_destroy(List* ptr_List)
{
	//TODO
	Node* trav=(Node*)malloc(sizeof(Node));
	Node* del=(Node*)malloc(sizeof(Node));
	trav=ptr_List->head;
	del=NULL;
	while(trav!=NULL)
	{
		del=trav;
		trav=trav->link;
		free(del);
	}
	free(ptr_List);
}


void stack_initialize(Stack *ptr_stack)
{
	// TODO
	ptr_stack->ptr_List=(List*)malloc(sizeof(List));
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
		return 1;
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
    int ans=0,var1,var2;
    int i=0,r;
    List a;
    Stack new_stack;
    (&new_stack)->ptr_List=&a;
    stack_initialize(&new_stack);
    while(expression[i]!='\0')
    {
    	if(expression[i]>='0' && expression[i]<='9')
    		stack_push(&new_stack,expression[i]-'0');
    	else if(expression[i]=='-' || expression[i]=='+' || expression[i]=='/' || expression[i]=='*')
    	{
    		if(stack_is_empty(&new_stack))
    			return 0;
    		else
    		{
    			var1=stack_peek(&new_stack);
    			stack_pop(&new_stack);
    			var2=stack_peek(&new_stack);
    			stack_pop(&new_stack);

    			switch(expression[i])
    			{
    				case '+': r = var1+var2;
    						stack_push(&new_stack,r);
				          	break;
					case '-': r = var2-var1;
							stack_push(&new_stack,r);
				          	break;
					case '*': r = var1*var2;
							stack_push(&new_stack,r);
				          	break;
					case '/': r = var2/var1;
							stack_push(&new_stack,r);
				          	break;
				}
    		}
    	}
    	i++;
    }
    ans=stack_peek(&new_stack);
    return ans;
}

