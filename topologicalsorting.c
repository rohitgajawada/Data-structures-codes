#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
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
void printdfs(int v,Node** list,int *state)
{
  state[v]=1;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      int x=ptr->val;
      printf("%d ",x);	  
      if(state[x]==0)
	printdfs(x,list,state);
      ptr=ptr->next;
    }
}   
int dfs(int v,Node** list,int *state,int* tmp,int k)
{
  state[v]=1;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      int z=ptr->val;
      if(state[z]==0)
	k=dfs(z,list,state,tmp,k);
      ptr=ptr->next;
    }
  tmp[k++]=v;
  return k;
}
int main()
{
  int n,m,i,j,a,b;
  int sort[10000]={0};
  int tmp[100000]={0};
  scanf("%d%d",&n,&m);
  Node* list[100];
  int state[100]={0};
  for(i=0;i<100;i++)
    list[i]=NULL;;
  Node* temp2=NULL;
  for(i=0;i<m;i++)
    {
      scanf("%d%d",&a,&b);
      temp2=(Node *)malloc(sizeof(Node));
      temp2->val=b;
      list[a]=insert(list[a],temp2);
    }
  int k=0;
  for(i=1;i<=n;i++)
    {
      if(state[i]==0)
	{
	  //printf("doing dfs of %d\n",i);
	  k=dfs(i,list,state,tmp,k);
	}
    }
  for(i=n-1;i>=0;i--)
    printf("%d ",tmp[i]);
  printf("\n");
  return 0;
}
  
