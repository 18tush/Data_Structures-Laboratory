#include"dll.h"
int count_nodes(List* dl1)
{
	int a;
	a=0;
	Node *temp;
	temp=dl1->head;
	if(dl1->head==NULL) 
		return 0;
	else
	{
		
		while(temp!=NULL)
		{
			a=a+1;
			temp=temp->next;
		}
	}
	return (a);
	
}

void insert_front(List* dl1, int data)
{
    Node* node= create_node (data);
	if((dl1->head) == NULL) dl1->head=node;
	else
	{
	    node->next = dl1->head;
		(dl1->head)->prev = node;
		dl1->head=node;
	}
	dl1->number_of_nodes++;
}

void enddel(List *dl1)
{   
	Node* new;
	Node* temp;
	if(dl1==NULL)printf("EMPTY");
	else if((dl1->head)->next==NULL)
	{
		temp=dl1->head;
		dl1->head=NULL;
		free(temp);
	}
	else
	{
		temp=dl1->head;
		while(temp->next!=NULL)
			temp=temp->next;
		(temp->prev)->next=NULL;
		free(temp);
	}
	
  
}







void dllist_delete_beginning(List* list)
{
    Node *temp;
  	if(list->head == NULL) printf("EMPTY");
	else {
		   temp=list->head;
		   if((list->head)->next==NULL)
		   { list->head=NULL;
	         free(temp);
	       }
		   else {
			  list->head=(list->head)->next;
		      (list->head)->prev=NULL;
		      free(temp);
		   }
		   list->number_of_nodes--;
	     }
		
}


void position_delete(List* dl1, int pos)
{
    Node *temp;
    int i,length;
	length=count_nodes(dl1);
    if(pos == 0)
    {
        dllist_delete_beginning(dl1);
    }
    else if(pos==length-1)
    {
        enddel(dl1);
		dl1->number_of_nodes--;
    }
    else if(pos>0 || pos<length-1)
    {
        temp=dl1->head;
		int c1=0;
		while(temp!=NULL)
		{
			if(c1==pos)
			{
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				free(temp);
				break;
			}
			else
			{
				temp=temp->next;
				c1=c1+1;
			}
		}
		dl1->number_of_nodes--;
	}
    
    else
    {
        
    }
	
}

int search_list(List* dl1,int key)
{
     Node *temp;
	 temp=dl1->head;
	 int c,i,flag;
	 c=0;
	 if(dl1->head==NULL)
		 return -1;
	 else  
    {    
        while (temp!=NULL)  
        {  
            if(temp->data == key)  
            {  
                return i; 
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            temp = temp -> next;  
        }  
        if(flag==1)  
        {  
            return -1;  
        }  
    } 
}    
void reverse_list(List* dl1)
{
      Node *temp = NULL;   
      Node *current = dl1->head; 
       
     
       
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     
        
     if(temp != NULL ) 
        dl1->head = temp->prev; 
}


