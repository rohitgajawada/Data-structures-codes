#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int val;
  struct node* next;
} node;
typedef struct queue
{
  node* head;
  node* tail;
} queue;
void enqueue(queue* q1,int data)
{
  node* temp=(node *)malloc(sizeof(node));
  temp->val=data;
  temp->next=NULL;
  if(q1->head==NULL)
    {
      q1->head=temp;
      q1->tail=temp;
    }
  else
    {
      node* ptr=q1->tail;
      ptr->next=temp;
      q1->tail=temp;
    }
}
int dequeue(queue* q1)
{
  int data;
  node* ptr=q1->head;
  data=ptr->val;
  q1->head=ptr->next;
  return data;
}     
node* insert(node* a,node* temp)
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
      a=temp;
      return a;
    }
}
void bfs(int v,node** list,queue* q1,int* state)
{
  int x;
  enqueue(q1,v);
  while(q1->head!=NULL)
    {
      v=dequeue(q1);
      if(state[v]==0)
	{
	  state[v]=1;
	  printf("%d ",v);
	}
      node* ptr=list[v];
      while(ptr!=NULL)
	{
	  x=ptr->val;
	  int tmpstate[100]={0};
	  if(state[x]==0 && tmpstate[x]==0)
	    {
	      tmpstate[x]=1;
	      enqueue(q1,x);
	    }
	  ptr=ptr->next;
	}
    }
}
      
int main()
{
  int n,m,i,j,a,b;
  int visit[100]={0};
  node* list[100];
  queue* q1;
  q1=(queue *)malloc(sizeof(queue));
  q1->head=NULL;
  q1->tail=NULL;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
    list[i]=NULL;
  for(i=0;i<m;i++)
    {
      scanf("%d%d",&a,&b);
      node* temp1=(node *)malloc(sizeof(node));
      node* temp2=(node *)malloc(sizeof(node));
      temp1->val=b;
      temp2->val=a;
      list[a]=insert(list[a],temp1);
      list[b]=insert(list[b],temp2);
    }
  bfs(0,list,q1,visit);
  printf("\n");
  return 0;
}
      
