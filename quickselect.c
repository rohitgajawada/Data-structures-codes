#include <stdio.h>
int select(int* a,int low,int high,int k)
{
  int pivot;
  if(high>low)
    {
      pivot=partition(a,low,high);
      if(pivot==k)
	return a[k];
      else if(k<pivot)
	return select(a,low,pivot-1,k);
      else
	return select(a,pivot+1,high,k);
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
  int n,i,j,k;
  scanf("%d%d",&n,&k);
  int arr[100];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("%d\n",select(arr,0,n-1,k));
  return 0;
}
