#include <stdio.h>
void isort(int* a,int n)
{
  int i,j,k;
  for(i=1;i<n;i++)
    {
      k=a[i];
      for(j=i-1;j>=0 && a[j]>k;j--)
	{
	  a[j+1]=a[j];
	}
      a[j+1]=k;
    }
}
  
int main()
{
  int n,i,j;
  scanf("%d",&n);
  int arr[100];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  isort(arr,n);
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}
