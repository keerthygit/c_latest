#include <stdio.h>
#include <conio.h>
int queue[10],front=-1,rear=-1,n;
void enqueue();
void dequeue();
void display();
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
	int num,i;
	if(rear==n-1)
		printf("Queue Overflow\n");
	else
	{
		printf("Enter node to be inserted\n");
		scanf("%d",&num);
		if(front==-1 && rear==-1)
		{
			front++;
			rear++;
			queue[rear]=num;
			printf("%d inserted\n",num);
		}
		else
		{
			rear++;
			queue[rear]=num;
			printf("%d inserted\n",num);
		}

	}
}
void dequeue()
{
	if((front==-1 && rear==-1)||(front>rear))
		printf("Queue Underflow\n");
	else
	{
		printf("%d Deleted\n",queue[front]);
		queue[front]=' ';
		front++;
	}


}
void display()
{
	int i;
	if((front==-1 && rear==-1)||(front>rear))
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is \n\t");
		for(i=0;i<n;++i)
		{
			if(queue[i]==' '|| queue[i]==0)
			{
				printf("- ");
			}
			else
			{
				printf("%d ",queue[i]);
			}
		}
		printf("\n");
	}
}