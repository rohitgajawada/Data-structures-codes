#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int val;
  struct node* left;
  struct node* right;
} node;
node* insert(node* root,int data)
{
  if(root==NULL)
    {
      node* temp=(node *)malloc(sizeof(node));
      temp->val=data;
      temp->left=NULL;
      temp->right=NULL;
      return temp;
    }
  if(data < root->val)
    root->left=insert(root->left,data);
  else
    root->right=insert(root->right,data);
  return root;
}
void search(node* root,int data)
{
  if(root==NULL)
    {
      printf("Does not exist\n");
      return;
    }
  if(root->val==data)
    {
      printf("Exists\n");
      return;
    }
  if(data < root->val)
    search(root->left,data);
  else if(data > root->val)
   search(root->right,data);
}
void inorder(node* root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d ",root->val);
  inorder(root->right);
}
node* findmax(node* root)
{
  if(root->right!=NULL)
    return findmax(root->right);
  else
    return root;
}

node* delete(node* root,int data)
{
  if(data < root->val)
    root->left=delete(root->left,data);
  else if(data > root->val)
    root->right=delete(root->right,data);
  else
    {
      if(root->left==NULL)
	{
	  return root->right;
	}
      else if(root->right==NULL)
	{
	  return root->left;
	}
      else if(root->left!=NULL && root->right!=NULL)
	{
	  node* temp=findmax(root->left);
	  root->val=temp->val;
	  root->left=delete(root->left,temp->val);
	  free(temp);
	  return root;
	}
    }
}   

int main()
{
  int x,v;
  node* root=NULL;
  while(1)
    {
      printf("Insert: 1; Search: 2; Delete: 3; Inorder: 4\n");
      scanf("%d",&x);
      switch (x)
	{
	case 1:
	  scanf("%d",&v);
	  root=insert(root,v);
	  break;
	case 2:
	  scanf("%d",&v);
	  search(root,v);
	  break;
	case 3:
	  scanf("%d",&v);
	  root=delete(root,v);
	  break;
	case 4:
	  inorder(root);
	  printf("\n");
	  break;
	}
    }
  return 0;
}
