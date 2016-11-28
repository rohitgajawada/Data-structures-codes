#include <stdio.h>
#include <stdlib.h>
#define M 1000000007
#define long long int ll
long long int fastmod(long long int a,long long int b)
{
  long long int twomods[100]={0};
  long long int x;
  for(x=0;x<64;x++)
    twomods[x]=0;
  twomods[0]=a%M;
  long long int i=1,t=0;
  long long int q=b,sum=1,count=0;
  while(i<=63)
    {
      twomods[i]=((twomods[i-1])*(twomods[i-1]))%M;
      i++;
    }
  while(q>0)
    {
      t=q%2;
      if(t==1)
	sum=((sum%M)*((twomods[count])%M))%M;
      count++;
      q/=2;
    }
  return sum%M;
}

int main()
{
  printf("%lld\n",fastmod(231,M-2));
  return 0;
}

