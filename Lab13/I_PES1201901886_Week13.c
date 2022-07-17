#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
  {
    //TODO
    struct trienode *t=(struct trienode*)malloc(sizeof(struct trienode));
    for(int i=0;i<26;i++)
      t->child[i]=NULL;
    t->endofword=0;
    return t;
  }

  void insert(struct trienode *root, char *key)
  {
     //TODO
    struct trienode *c=root;
    int idx;
   for(int i=0;key[i]!='\0';i++)
   {
     idx=key[i]-'a';
     if(c->child[idx]==NULL)
        c->child[idx]=getnode();
      c=c->child[idx];
    }
    c->endofword=1;
  }

void display(struct trienode *curr)
  {
      //TODO:
     //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output
    int i,j;
    for(i=0;i<26;i++)
    {
      if(curr->child[i]!=NULL)
      {
        word[length++]=i+97;
        if(curr->child[i]->endofword==1)
        {
          printnewline();
          for(j=0;j<length;j++)
             printfun(word[j]);
        }
       display(curr->child[i]);
      }
    }
    length=length-1;
    return;
 }

  int search(struct trienode * root,char *key)
  {
  //TODO
    struct trienode *c=root;
    int idx;
    for(int i=0;key[i]!='\0';i++)
    {
      idx=key[i]-'a';
      if(c->child[idx]==NULL)
        return 0;
      c=c->child[idx];
    }
    if(c->endofword==1)
      return 1;
    return 0;
  }


 void delete_trie(struct trienode *root,char *key)
  {
    //TODO
    int i,j,idx,z;
    struct trienode* c=root;
    z=1;

    for(i=0;key[i]!='\0';i++)
    {
      idx=key[i]-'a';
      if(c->child[idx]==NULL)
         return;
      c=c->child[idx];
    }
      c->endofword=0;
      return;
  }

  int check(struct trienode *x)
  {
    //TODO
    int count=0;
    for(int i=0;i<26;i++)
      if(x->child[i]!=NULL)
        count=count+1;
    return count;
 }

  void push(struct trienode *x,int k)
  {
    //TODO
    top=top+1;
    s[top].m=x;
    s[top].index=k;
  }

  struct stack pop()
  {
    //TODO
    struct stack del;
    del=s[top--];
    return del;
  }