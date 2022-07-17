#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
}
int heap_get_capacity(heap* tmp){
    //TODO
}
int heap_get_size(heap* tmp){
    //TODO
}

int heap_insert(heap* tmp,int data){
    //TODO
}
int heap_get_min(heap* tmp){
    //TODO
}
void heap_remove(heap* tmp){
    //TODO
}

