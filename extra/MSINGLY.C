#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_first();
void insert_pos();
void insert_last();
void delete_first();
void delete_pos();
void delete_last();
void search();
void display();
int n=0;
struct node
{
	int data;
	struct node *next;
}*head;
void main()
{
	int ch;
	clrscr();
	do
	{
		printf("Select\n1.Insert at first\n2.insert at position\n3.Insert at last\n4.Delete at first\n5.Delete at position\n6.Delete at last\n7.search\n8.Display\n9.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_first();
				break;
			case 2: insert_pos();
				break;
			case 3: insert_last();
				break;
			case 4: delete_first();
				break;
			case 5: delete_pos();
				break;
			case 6: delete_last();
				break;
			case 7: search();
				break;
			case 8: display();
				break;
			default: exit(0);
		}
	}while(ch!=0);
	getch();
}
void insert_first()
{
	struct node *newnode;
	int data;
	printf("Enter the node value\n");
	scanf("%d",&data);
	if(head==NULL)
	{
		head=malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
	}
	else
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=head;
		head=newnode;

	}
	n++;
	printf("%d inserted\n",data);
}
void insert_last()
{
	struct node *curr;
	struct node *newnode;
	int data;
	printf("Enter the node value\n");
	scanf("%d",&data);
	if(head==NULL)
	{
		head=malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
	}
	else
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=NULL;
		curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=newnode;

	}
	n++;
	printf("%d inserted\n",data);

}
void insert_pos()
{
	int pos,data,i;
	struct node *newnode,*curr;
	printf("Enter the position at which node to be inserted\n");
	scanf("%d",&pos);
	if(pos<1 || pos>n+1)
		printf("Invalid Position\n");
	else if(pos==1)
		insert_first();
	else if(pos==n+1)
		insert_last();
	else
	{
		printf("Enter the node value\n");
		scanf("%d",&data);
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		curr=head;
		for(i=1;i<pos-1;++i)
			curr=curr->next;
		newnode->next=curr->next;
		curr->next=newnode;
		printf("Node Inserted\n");
		n++;
	}
}
void delete_first()
{
	if(head->data==NULL)
		printf("List Empty\n");
	else if(head->next==NULL)
	{
		printf("The node deleted is %d\n",head->data);
		n--;
		head=NULL;
	}
	else
	{
		printf("The node deleted is %d\n",head->data);
		n--;
		head=head->next;
	}
}

void delete_last()
{
	struct node *curr,*prev;
	if(head->data==NULL)
		printf("List Empty\n");
	else if(head->next==NULL)
	{
		printf("The node deleted is %d\n",head->data);
		n--;
		head=NULL;
	}
	else
	{
		curr=head;
		while(curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
		}
		printf("The node deleted is %d\n",curr->data);
		n--;
		prev->next=NULL;
	}
}
void delete_pos()
{
	int pos,data,i;
	struct node *prev,*curr;
	printf("Enter the position at which node to be deleted\n");
	scanf("%d",&pos);
	if(pos<1 || pos>n)
		printf("Invalid Position\n");
	else if(pos==1)
		delete_first();
	else if(pos==n)
		delete_last();
	else
	{
		curr=head;
		for(i=1;i<pos;++i)
		{
			prev=curr;
			curr=curr->next;
		}
		printf("The node deleted is %d\n",curr->data);
		n--;
		prev->next=curr->next;

	}
}
void search()
{
	int num,flag,count;
	struct node *curr;
	printf("Enter the number to be searched\n");
	scanf("%d",&num);
	curr=head;
	flag=0;
	count=0;
	while(curr->data!=NULL)
	{
		count++;
		if(curr->data==num)
		{
			flag=1;
			break;
		}
		curr=curr->next;
	}
	if(flag==0)
		printf("%d not found\n",num);
	else
	{
		printf("%d found at node %d\n",num,count);
	}
}

void display()
{
	struct node *curr;
	if(head->data==NULL)
		printf("List Empty\n");
	else
	{
		curr=head;
		while(curr->data!=NULL)
		{
			printf("%d  ",curr->data);
			curr=curr->next;
		}
		printf("\n");
	}
}