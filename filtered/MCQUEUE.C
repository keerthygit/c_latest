#include <stdio.h>
#include <conio.h>
void enqueue();
void dequeue();
void display();
int n,front=-1,rear=-1,queue[10];
void main()
{
	int ch;
	clrscr();
	printf("Enter size of the queue\n");
	scanf("%d",&n);
	do
	{
		printf("Select\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			default: exit();

		}
	}while(ch!=0);
	getch();
}

void enqueue()
{
	int data;
	if(front==(rear+1)%n)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		printf("Enter value\n");
		scanf("%d",&data);

		if(front==-1 && rear==-1)
		{
			front++;
			rear++;
		}
		else
		{
			rear=(rear+1)%n;
		}
		queue[rear]=data;
		printf("%d Inserted\n",data);
	}
}
void dequeue()
{
	if((front==-1 && rear==-1)||(front>rear))
	{
		printf("Queue Empty\n");
	}
	else if(front==rear)
	{
		printf("%d Deleted\n",queue[rear]);
		queue[front]=NULL;
		front=-1;
		rear=-1;
	}
	else
	{
		printf("%d Deleted\n",queue[front]);
		queue[front]=NULL;
		front=(front+1)%n;
	}

}
void display()
{
	int i;
	for(i=0;i<n;++i)
	{
		if(queue[i]==NULL)
			printf("- ");
		else
			printf("%d ",queue[i]);
	}
	printf("\n");
}