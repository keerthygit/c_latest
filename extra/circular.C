#include<stdio.h>
#include<stdlib.h>
#define n 5
int i,rear=-1,front=-1,item;
int queue[n];

void insert()
{
if(rear==n-1)
{ 
printf("overflow");
}
else
{
printf("enter elemnt to insert:");
scanf("%d",&item);
rear=(rear+1)%n;
queue[rear]=item;
printf("inserted");
}
if(front==-1)
{
front=0;
}
}

void delete()
{
if(front==-1)
{
printf("underflow");
}
else
{
printf("elemrnt deleted is %d",queue[front]);
if(front==rear)
{
front=rear=-1;
}
else
{
front=(front+1)%n;
}
}
}

void display()
{
if(front==-1)
{
printf("queue empty");
}
else if(front<rear)
{
for(i=front;i<=rear;i++)
{
printf("%d ",queue[i]);
}
}
}

void search()
{
int search;
int temp= front;
int flag=0;
printf("search element:");
scanf("%d",&search);
if(front==-1)
{
printf("empty");
}
else
{
while(temp<=rear)
{
if(search==queue[temp])
{
    flag=1;
    break;
}
temp=(temp+1)%n;
}
if(flag==1)
{
    printf("elemnt found");
}
else
{
    printf("elemnt not found");
}
}
}

int main()
{
int ch;
while(ch!=5)
{
printf("\n1.insert\n2.delete\n3.display\n4.search\n5.exit");
printf("\nenter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
search();
break;
case 5:
exit(0);
break;
default:
printf("invalid input");
}
}
return 0;
}