#include "6b.h"
stack* stack_initialize(int size)
{
//TODO
	stack *s=(struct stack *)(malloc(sizeof(struct stack)));;
	s->arr=(int *)malloc(size*sizeof(int));
	s->top=-1;
	return s;
}

void stack_push(stack *ptr_stack, int key)
{
//TODO
	int TOP;
	ptr_stack->top +=1;
	TOP=ptr_stack->top;
	(ptr_stack->arr)[TOP]=key;
}

void stack_pop(stack *ptr_stack)
{
//TODO
	if(stack_is_empty(ptr_stack)==-1); // Do nothing
	else
		ptr_stack->arr[ptr_stack->top--];
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
	if(ptr_stack->top==-1)
		return 1;
	else
		return 0;
}

int stack_peek(stack *ptr_stack)
{
//TODO
	int TOP=ptr_stack->top;
	return (ptr_stack->arr)[TOP];
}

void stack_destroy(stack *ptr_stack)
{
//TODO
	free(ptr_stack->arr);
	free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
	int count=0;
	stack *new_stack;
	int size=0;
	while(source_infix[count]!='\0')
		count=count+1;
	size=count;	
	new_stack=stack_initialize(size);
	int i=0;
	int j=0;
	void bkt(char ch)
	{
		if(ch=='(')
			{
				stack_push(new_stack,ch);
				i+=1;
				while(source_infix[i]!=')')
				{
					ch=source_infix[i];
					if(ch=='(' || ch=='[' || ch=='{')
					{
						bkt(ch);
					}
					else if((ch=='+') || (ch=='-') || (ch=='*') || (ch=='/'))
					{
						stack_push(new_stack,ch);
						i=i+1;
					}
					else
					{
						target_postfix[j]=ch;
						j=j+1;
						i=i+1;
					}
				}
				i+=1;
				while(new_stack->arr[new_stack->top]!='(')
				{
					int y=stack_peek(new_stack);
					stack_pop(new_stack);
					target_postfix[j]=y;
					j=j+1;
				}
				stack_pop(new_stack);
			}
			else if(ch=='{')
			{
				stack_push(new_stack,ch);
				i=i+1;
				while(source_infix[i]!='}')
				{
					ch=source_infix[i];
					if(ch=='(' || ch=='[' || ch=='{')
					{
						bkt(ch);
					}
					else if((ch=='+') || (ch=='-') || (ch=='*') || (ch=='/'))
					{
						stack_push(new_stack,ch);
						i=i+1;
					}
					else
					{
						target_postfix[j]=ch;
						j=j+1;
						i=i+1;
					}
				}
				i=i+1;
				while(new_stack->arr[new_stack->top]!='{')
				{
					int y=stack_peek(new_stack);
					stack_pop(new_stack);
					target_postfix[j]=y;
					j=j+1;
				}
				stack_pop(new_stack);
			}
			else if(ch=='[')
			{
				stack_push(new_stack,ch);
				i=i+1;
				while(source_infix[i]!=']')
				{
					ch=source_infix[i];
					if(ch=='(' || ch=='[' || ch=='{')
					{
						bkt(ch);
					}
					else if((ch=='+') || (ch=='-') || (ch=='*') || (ch=='/'))
					{
						stack_push(new_stack,ch);
						i+=1;
					}
					else
					{
						target_postfix[j]=ch;
						j+=1;
						i+=1;
					}
				}
				i+=1;
				while(new_stack->arr[new_stack->top]!='[')
				{
					int y=stack_peek(new_stack);
					stack_pop(new_stack);
					target_postfix[j]=y;
					j+=1;
				}
				stack_pop(new_stack);
			}
	}
	while(source_infix[i]!='\0')
		{
		char c=source_infix[i];
		if(c=='(' || c=='[' || c=='{')
		{
			bkt(c);
		}
		else if((c=='+') || (c=='-') || (c=='*') || (c=='/'))
		{
			if(new_stack->top!=-1)
			{
				int z=new_stack->arr[new_stack->top];
				if(c=='*')
				{
					if(z=='/')
					{
					int y=stack_peek(new_stack);
					stack_pop(new_stack);
					target_postfix[j]=y;
					j+=1;
					}
					else
					{
						stack_push(new_stack,c);
						i+=1;
					}
				}
				else if(c=='/')
				{
					if(z=='*')
					{
					int y=stack_peek(new_stack);
					stack_pop(new_stack);
					target_postfix[j]=y;
					j+=1;
					}
					else
					{
						stack_push(new_stack,c);
						i+=1;
					}
				}
				else if(c=='+')
				{
					if(z=='*' || z=='/' || z=='-')
					{
						int y=stack_peek(new_stack);
						stack_pop(new_stack);
						target_postfix[j]=y;
						j+=1;
					}
					else
					{
						stack_push(new_stack,c);
						i+=1;
					}
				}
				else
				{
					if(z=='*' || z=='/' || z=='+')
					{
						int y=stack_peek(new_stack);
						stack_pop(new_stack);
						target_postfix[j]=y;
						j+=1;
					}
					else
					{
						stack_push(new_stack,c);
						i+=1;
					}
				}
			}
			else
			{
				stack_push(new_stack,c);
				i+=1;
			}
		}			
		else
		{
			target_postfix[j]=c;
			j+=1;
			i+=1;
		}
		}
		while(new_stack->top!=-1)
		{
			int y=stack_peek(new_stack);
			stack_pop(new_stack);
			target_postfix[j]=y;
			j+=1;
		}
}

