#include <stdio.h>
#include <stdlib.h>
int comp(const void* a,const void* b)
{
  return (*(int *)a > *(int *)b);
}
int main()
{
   int n=5;
   int values[] = { 88, 56, 100, 2, 25 };
   qsort(values,n,sizeof(int),comp);
   for(n=0;n<5;n++) 
     printf("%d ", values[n]);
   return(0);
}
