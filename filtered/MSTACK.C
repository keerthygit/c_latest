#include <stdio.h>
#include <conio.h>
int top=-1,stack[10],n;
void push();
void pop();
void display();
void main()
{
	int ch;
	clrscr();
	printf("Enter size of the stack\n");
	scanf("%d",&n);
	do
	{
		printf("Select\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default: exit();
		}

	}while(ch!=0);
	getch();
}

void push()
{
	int num,i;
	if(top==n-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		printf("Enter the value to be inserted\n");
		scanf("%d",&num);
		top++;
		stack[top]=num;
		printf("%d inserted\n",num);
	}

}
void pop()
{
	if(top<0)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d Deleted\n",stack[top]);
		top--;
	}
}

void display()
{
	int i;
	if(top<0)
		printf("Stack Empty\n");
	else
	{
		printf("Stack is\n");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}