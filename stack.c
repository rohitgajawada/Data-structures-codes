#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
  int val;
  struct nodes* next;
} node;
typedef struct stacks
{
  node* headnode;
} stack;

void push(stack* stack1,int item)
{
  node* temp=(node *)malloc(sizeof(node));
  temp->val=item;
  temp->next=stack1->headnode;
  stack1->headnode=temp;
}
int pop(stack* stack1)
{
  node* temp=stack1->headnode;
  int data=temp->val;
  stack1->headnode=temp->next;
  free(temp);
  return data;
}
int top(stack* stack1)
{
  node* temp=stack1->headnode;
  return temp->val;
}

int main()
{
  int n,i,data;
  scanf("%d",&n);
  stack* stack1=(stack *)malloc(sizeof(stack));
  stack1->headnode=NULL;
  for(i=0;i<n;i++)
    {
      scanf("%d",&data);
      push(stack1,data);
    }
  for(i=0;i<n;i++)
    printf("%d ",pop(stack1));
  printf("\n");
  return 0;
}
	   

  
  
  
  
