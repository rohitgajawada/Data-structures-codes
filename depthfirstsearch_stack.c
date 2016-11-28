#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
typedef struct stacks
{
  Node* headnode;
} stack;

void push(stack* stack1,long long int item)
{
  Node* temp=(Node *)malloc(sizeof(Node));
  temp->val=item;
  temp->next=stack1->headnode;
  stack1->headnode=temp;
}
long long int pop(stack* stack1)
{
  Node* temp=stack1->headnode;
  long long int data=temp->val;
  stack1->headnode=temp->next;
  free(temp);
  return data;
}
Node* insert(Node* a, Node* temp)
{
  if(a==NULL)
    {
      a=temp;
      temp->next=NULL;
      return a;
    }
  else
    {
      temp->next=a;
      return temp;
    }
}
void dfs(long long int v,Node** list,stack* stack1,int* state)
{
  long long int z;
  push(stack1,v);
  while(stack1->headnode!=NULL)
    {
      v=pop(stack1);
      if(state[v]==0)
	{
	  state[v]=1;
	  printf("%lld ",v);
	}
      Node* ptr=list[v];
      while(ptr!=NULL)
	{
	  long long int tmpstate[100]={0};
	  z=ptr->val;
	  if(state[z]==0 && tmpstate[z]==0)
	    {
	      tmpstate[z]=1;
	      push(stack1,z);
	    }
	  ptr=ptr->next;
	}
    }
}
	  
  
int main()
{
  int n,m,i,j,a,b;
  scanf("%d%d",&n,&m);
  Node* list[100];
  stack* stack1;
  stack1=(stack *)malloc(sizeof(stack));
  stack1->headnode=NULL;
  int state[100]={0};
  for(i=0;i<100;i++)
    list[i]=NULL;
  Node* temp1=NULL;
  Node* temp2=NULL;
  for(i=0;i<m;i++)
    {
      scanf("%d%d",&a,&b);
      temp1=(Node *)malloc(sizeof(Node));
      temp1->val=a;
      temp2=(Node *)malloc(sizeof(Node));
      temp2->val=b;
      list[a]=insert(list[a],temp2);
      list[b]=insert(list[b],temp1);
    }
  printf("dfs of %d\n",1);
  dfs(1,list,stack1,state);
  printf("\n");
  return 0;
}

