#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
  int val;
  struct nodes* next;
} node;

typedef struct queues
{
  node* headnode;
  node* tailnode;
} queue;

void enqueue(queue* q1,int item)
{
  node* temp=(node *)malloc(sizeof(node));
  node* p1;
  temp->val=item;
  if(q1->headnode==NULL)
    {
      q1->headnode=temp;
      q1->tailnode=temp;
    }
  else
    {
      p1=q1->tailnode;
      p1->next=temp;
      temp->next=NULL;
      q1->tailnode=temp;
    }      
}
int dequeue(queue* q1)
{
  node* temp=q1->headnode;
  int data=temp->val;
  q1->headnode=temp->next;
  return data;
}
int top(queue* q1)
{
  node* temp=q1->headnode;
  return temp->val;
}

int main()
{
  int n,i,data;
  scanf("%d",&n);
  queue* q1=(queue *)malloc(sizeof(queue));
  q1->headnode=NULL;
  q1->size=0;
  for(i=0;i<n;i++)
    {
      scanf("%d",&data);
      enqueue(q1,data);
    }
  printf("size is %d\n",size(q1));
  for(i=0;i<n;i++)
    printf("%d ",dequeue(q1));
  printf("\n");
}
