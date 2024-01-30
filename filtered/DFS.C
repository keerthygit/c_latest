#include<stdio.h>
#include<stdlib.h>

int i,j,n,v,item,vertex,top=0,s[10],visited[10],a[10][10];
void push(int v);
int pop();


void push(int v)
{
  top++;
  s[top]=v;
}

int pop()
{
  v=s[top];
  top--;
  return v;
}

int main()
{
   clrscr();
  printf("enter no of vertices:");

  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
   visited[i]=0;
  }

  printf("enter matrix:\n");

  for(i=1;i<=n;i++)
  {

     for(j=1;j<=n;j++)
     {
	   printf("adj[%d][%d]:",i,j);
	   scanf("%d",&a[i][j]);
	   printf("\n");
     }
  }
  printf("enter starting vertex:");
  scanf("%d",&vertex);

  push(vertex);

  printf("traversal of vertices:\n");

  while(top>0)
  {
    item=pop();

    if(!visited[item])
    {

      visited[item]=1;
      printf("%d\t",item);
    }

    for(j=1;j<=n;j++)
    {
      if(a[item][j]==1 && visited[j]==0)
     {
      push(j);
     }

    }

  }
  getch();
  return 0;
 }