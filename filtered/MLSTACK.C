#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct node
{
	int data;
	struct node *next;
}*top;
void main()
{
	int ch;
	clrscr();
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
			default: exit(0);
		}

	}while(ch!=0);
	getch();
}
//insert first
void push()
{
	int num;
	struct node *newnode;
	printf("Enter value to be inserted\n");
	scanf("%d",&num);
	if(top==NULL)
	{
		top=malloc(sizeof(struct node));
		top->data=num;
		top->next=NULL;
		printf("Node Inserted\n");
	}
	else
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=num;
		newnode->next=top;
		top=newnode;
		printf("Node Inserted\n");
	}
}
//delete first
void pop()
{
	struct node *temp;
	if(top->data==NULL)
		printf("Stack Empty\n");
	else
	{
		temp=top;
		top=top->next;
		printf("%d Node deleted\n",temp->data);
		free(temp);
	}
}

void display()
{
	struct node *curr;
	if(top->data==NULL)
	{
		printf("Stack Empty\n");
	}
	else
	{
		printf("The stack is\n");
		curr=top;
		while(curr!=NULL)
		{
			printf("%d\n",curr->data);
			curr=curr->next;
		}
		printf("\n");
	}
}