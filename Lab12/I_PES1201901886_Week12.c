#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    int i;
    int a=size;
    HashTable *htable=(HashTable*)malloc(sizeof(HashTable));
    htable->size=size;
    htable->table=(int*)malloc(sizeof(int)*size);
    for(i=0;i<a;i++)
    	htable->table[i]=-1;
    return htable;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int a;
    if(htable==NULL)
    	return;
    for(a=element%(htable->size);htable->table[a]!=0 && htable->table[a]!=-1;++a)
    	a=a%(htable->size);
    htable->table[a]=element;
}

int search(HashTable *htable, int element)
{
    //TODO
    int a;
    for(a=element%(htable->size);htable->table[a]!=-1;++a)
    {
    	if(htable->table[a]==element)
    		return 1;
    	a=a%(htable->size);
    }
    return 0;
}

void delete (HashTable *htable, int element)
{
    //TODO
    int a=element%(htable->size);
    if(htable->table[a]==element)
    	htable->table[a]=-1;
    else
    	return;
}


void destroy_table(HashTable *htable)
{
    //TODO
	free(htable->table);
	free(htable);
}

