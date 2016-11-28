#include <stdio.h>
void quicksort(int* a,int low,int high)
{
  int pivot;
  if(high>low)
    {
      pivot=partition(a,low,high);
      quicksort(a,low,pivot-1);
      quicksort(a,pivot+1,high);
    }
}
int partition(int *a,int low,int high)
{
  int piv=a[high];
  int i,j,tmp;
  i=low-1;
  for(j=low;j<high;j++)
    {
      if(a[j]<=piv)
	{
	  i++;
	  tmp=a[i]; a[i]=a[j]; a[j]=tmp;
	}
    }
  tmp=a[i+1]; a[i+1]=a[high]; a[high]=tmp;
  return i+1;
}
	  
      
int main()
{
  int n,i,j;
  scanf("%d",&n);
  int arr[100];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  quicksort(arr,0,n-1);
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}
