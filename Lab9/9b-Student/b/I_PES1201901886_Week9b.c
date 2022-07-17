#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
    free(tmp);
}
int heap_get_capacity(heap* tmp){
    //TODO
    return tmp->capacity;
}
int heap_get_size(heap* tmp){
    //TODO
    return tmp->size;
}

int heap_insert(heap* tmp,int data){
    //TODO
    int a=tmp->size;
    if(a<tmp->capacity)
    {
        tmp->elements[a]=data;
        tmp->size=tmp->size+1;
        return 1;
    }
    else
        return 0;
}
int heap_get_min(heap* tmp){
    //TODO
    int min=tmp->elements[0];
    int x=0;
    while(x<tmp->size)
    {
        if(tmp->elements[x]<min)
        {
            min=tmp->elements[x];
        }
        x=x+1;
    }
    return min;
}
void heap_remove(heap* tmp){
    //TODO
    int x=0;
    int i;
    int a=tmp->size;
    int min=heap_get_min(tmp);
    while(x<a)
    {
        if(tmp->elements[x]==min)
            break;                  // Come out of the loop
        x=x+1;
    }
    i=x;
    while(i<a)
    {
        tmp->elements[i]=tmp->elements[i+1];
        i=i+1;
    }
    tmp->size=tmp->size-1;
}