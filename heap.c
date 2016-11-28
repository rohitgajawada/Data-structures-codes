#include <stdio.h>
#include <math.h>
void heapify(int* heap,int i,int ht,int n)
{
  int k=pow(2,ht);
  if(i>=k-1)
    return;
  int temp;
  int child1=2*i+1;
  int child2=2*i+2;
  if(heap[i]>heap[child1] && child1<n)
    {
      temp=heap[i]; heap[i]=heap[child1]; heap[child1]=temp;
      heapify(heap,child1,ht,n);
    }
  if(heap[i]>heap[child2] && child2<n)
    {
      temp=heap[i]; heap[i]=heap[child2]; heap[child2]=temp;
      heapify(heap,child2,ht,n);
    }
} 

void build(int* a,int* heap,int n)
{
  int i,j,k,ht,temp,paren,rem;
  ht=log2(n);
  k=pow(2,ht);
  for(j=0;j<=k-1,k-1+j<n;j++)
    heap[k-1+j]=a[j];
  while(k>0)
    {
      k=k/2;
      for(i=0;i<=k-1;i++)
	{
	  heap[k-1+i]=a[j++];
	  heapify(heap,k-1+i,ht,n);
	}
    }
}
void delete(int *heap,int n)
{
  int ht=log2(n);
  heap[0]=heap[n-1];
  heapify(heap,0,ht,n);
}
   
  
void insert(int *heap,int n,int val)
{
  heap[n-1]=val;
  int i=n-1,paren,temp;
  while(i>0)
    {
      if(i==0)
	break;
      paren=(i-1)/2;
      if(heap[paren]>heap[i])
	{
	  temp=heap[paren]; heap[paren]=heap[i]; heap[i]=temp;
	  i=paren;
	}
      else
	break;
    }
}     

int main()
{
  int n,i,a[100],heap[100],x,val;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  build(a,heap,n);
  while(1)
    {
      printf("Insert: 1; Delete: 2; Print Heap: 3\n");
      scanf("%d",&x);
      switch(x)
	{
	case 1:
	  scanf("%d",&val);
	  insert(heap,++n,val);
	  break;
	case 2:
	  delete(heap,n--);
	  break;
	case 3:
	  for(i=0;i<n;i++)
	    printf("%d ",heap[i]);
	  printf("\n");
	  break;
	}
    }
  return 0;
}
