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
  printf("%d ",v);
  state[v]=1;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      int z=ptr->val;
      if(state[z]==0)
	printdfs(z,list,state);
      ptr=ptr->next;
    } 
}
int main()
{
  int n,m,i,j,a,b;
  scanf("%d%d",&n,&m);
  Node* list[100]={NULL};
  int state[100]={0};
  Node* temp2=NULL;
  for(i=0;i<m;i++)
    {
      scanf("%d%d",&a,&b);
      temp2=(Node *)malloc(sizeof(Node));
      temp2->val=b;
      list[a]=insert(list[a],temp2);
    }
  printf("dfs of %d\n",1);
  printdfs(1,list,state);
  printf("\n");
  return 0;
}

