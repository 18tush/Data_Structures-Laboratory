#include "6b.h"
stack* stack_initialize(int size)
{
//TODO
    stack *a;
    a=(stack *)malloc(sizeof(stack));
    a->arr=(int *)malloc(size);
    *(a->arr)='(';
    a->top=1;
    return a;
    
    
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO 
    int p=ptr_stack->top;
    *(ptr_stack->arr+p)=key;
   ptr_stack->top=ptr_stack->top+1;
}

void stack_pop(stack *ptr_stack)
{
//TODO
    int *q=(int *)malloc(sizeof(int));
    q=(ptr_stack->arr+ptr_stack->top);
    //printf("\n%c\n",*q);
    ptr_stack->top=ptr_stack->top-1;
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
    if(ptr_stack->top==1)
        return 0;
    else
        return 1;
}

int stack_peek(stack *ptr_stack) 
{
//TODO
    int t=ptr_stack->top;
    return *(ptr_stack->arr+t-1);
}

void stack_destroy(stack *ptr_stack) 
{
//TODO
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
    int i=0,j=0;
    stack *p;
   
    int t=4*strlen(source_infix);
    p=stack_initialize(t);
    
    while(*(source_infix+i)!='\0')
    {
        if(*(source_infix+i)=='(' || *(source_infix+i)=='[' || *(source_infix+i)=='{')
        {
            stack_push(p,*(source_infix+i));
        }
        else if(*(source_infix+i)=='/' || *(source_infix+i)=='*')
        {
            
            
            if(stack_peek(p)=='/' || stack_peek(p)=='*')
            {
            
                *(target_postfix+j)=stack_peek(p);
                stack_pop(p);
                j++;
                
                
                
                
                
                
                stack_push(p,*(source_infix+i));
             
            }
            else
            {
            stack_push(p,*(source_infix+i));
            }
            
            
        }
        else if(*(source_infix+i)=='+' || *(source_infix+i)=='-')
        {
            if(stack_peek(p)=='+' || stack_peek(p)=='-')
            {
                *(target_postfix+j)=stack_peek(p);
                j++;
                stack_pop(p);
                stack_push(p,*(source_infix+i));
            }
            else if(stack_peek(p)=='*' || stack_peek(p)=='/')
            {
                *(target_postfix+j)=stack_peek(p);
                j++;
                stack_pop(p);
                if(stack_peek(p)=='+' || stack_peek(p)=='-')
                {
                    *(target_postfix+j)=stack_peek(p);
                    j++;
                    stack_pop(p);
                } 
                 stack_push(p,*(source_infix+i));
            }
            else
            {
                stack_push(p,*(source_infix+i));
            }
        }
        else if(*(source_infix+i)==')' )
        {
           
            while(stack_peek(p)!='(')
            {
                *(target_postfix+j)=stack_peek(p);
                stack_pop(p);
                j++;
            }
            stack_pop(p);
        }
        else if(*(source_infix+i)==']' )
        {
           
            while(stack_peek(p)!='[')
            {
                *(target_postfix+j)=stack_peek(p);
                stack_pop(p);
                j++;
            }
            stack_pop(p);
        }
        else if(*(source_infix+i)=='}' )
        {
           
            while(stack_peek(p)!='{')
            {
                *(target_postfix+j)=stack_peek(p);
                stack_pop(p);
                j++;
            }
            stack_pop(p);
        }
       
        
        else
        {
            *(target_postfix + j)=*(source_infix+i);
            j++;
        }
        
      i++;   
    }
    while(stack_is_empty(p))
    {
        *(target_postfix+j)=stack_peek(p);
        stack_pop(p);
        j++;
    }
    *(target_postfix+j)='\0';
    stack_destroy(p);
  
   
        
   
}
