#include <stdio.h>
int board[100][100]={0};
void backtrack(int i,int m);
void insert(int i,int m);

int check(int i,int j,int m)
{
  int p,q,state=1;
  for(p=i,q=j;p>=0;p--)
    {
      if(board[p][q]==1)
	{
	  state=0;
	  return state;
	}
    }
  for(p=i,q=j;p>=0,q>=0;p--,q--)
    {
      if(board[p][q]==1)
	{
	  state=0;
	  return state;
	}
    }
  for(p=i,q=j;p>=0,q<m;p--,q++)
    {
      if(board[p][q]==1)
	{
	  state=0;
	  return state;
	}
    }
  return state;
}

void backtrack(int i,int m)
{
  if(i>=0)
    {
      int j,p,q,state=0;
      for(q=0;q<m;q++)
	{
	  if(board[i][q]==1)
	    {
	      j=q;
	      break;
	    }
	}
      board[i][j]=0;
      for(q=j+1;q<m;q++)
	{
	  if(check(i,q,m)==1)
	    {
	      state=1;
	      board[i][q]=1;
	      break;
	    }
	}
      if(state==0)
	backtrack(i-1,m);
      insert(i+1,m);
    }
}       	       

void insert(int i,int m)
{
  int j,state=0;
  for(j=0;j<m;j++)
    {
      if(check(i,j,m)==1)
	{
	  board[i][j]=1;
	  state=1;
	  break;
	}
    }
  if(state==0)
    {
      backtrack(i-1,m);
      //insert(i,m);
    }
}

int main()
{
  int n,m,i,j,k;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
    insert(i,m);
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
	printf("%d ",board[i][j]);
      printf("\n");
    }
  return 0;
}
  
