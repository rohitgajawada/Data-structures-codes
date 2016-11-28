#include <stdio.h>

void merge(int a[],int l,int r,int p,int q)
{
  int c[2000],k=0,x,y;
  int i=l,j=p;
  while(i<=r && j<=q)
    {
      if(a[i]<a[j])
	c[k++]=a[i++];
      else
	c[k++]=a[j++];
    }
  while(i<=r)
    c[k++]=a[i++];
  
  while(j<=q)
    c[k++]=a[j++];
  
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      a[y]=c[x];
    }   
}

void mergesort(int a[],int low,int high)
{
  if(low<high)
    {
      int mid=low+(high-low)/2;
      mergesort(a,low,mid);
      mergesort(a,mid+1,high);
      merge(a,low,mid,mid+1,high);
    }
}

int main()
{
  int n,i,j;
  int a[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  mergesort(a,0,n-1);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
  
