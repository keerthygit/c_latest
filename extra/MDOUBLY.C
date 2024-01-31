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
void revdisplay();
int n=0;
struct node
{
	int data;
	struct node *prev,*next;
}*head,*tail;
void main()
{
	int ch;
	clrscr();
	do
	{
		printf("Select\n1.Insert at first\n2.insert at position\n3.Insert at last\n4.Delete at first\n5.Delete at position\n6.Delete at last\n7.search\n8.Display\n9.Reverse Display\n10.Exit\n");
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
			case 9: revdisplay();
				break;
			default: exit(0);
		}
	}while(ch!=0);
	getch();
}

void insert_first()
{
	int data;
	struct node *newnode;
	printf("Enter the value to be inserted\n");
	scanf("%d",&data);
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	if(head->data==NULL)
	{
		head=malloc(sizeof(struct node));
		head=newnode;
		head->next=NULL;
		tail=head;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	n++;
	printf("Node Inserted\n");
}
void insert_last()
{
	int data;
	struct node *newnode;
	printf("Enter the value to be inserted\n");
	scanf("%d",&data);
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(head->data==NULL)
	{
		head=malloc(sizeof(struct node));
		head=newnode;
		head->prev=NULL;
		tail=head;
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
	n++;
	printf("Node Inserted\n");
}

void insert_pos()
{
	int pos,data,i;
	struct node *newnode,*curr,*prev;
	printf("Enter position to be inserted\n");
	scanf("%d",&pos);
	if(pos<1 || pos>n+1)
		printf("Invlaid Position\n");
	else if(pos==1)
		insert_first();
	else if(pos==n+1)
		insert_last();
	else
	{
		printf("Enter the value to be inserted\n");
		scanf("%d",&data);
		newnode=malloc(sizeof(struct node));
		newnode->data=data;
		curr=head;
		for(i=1;i<pos;++i)
		{
			prev=curr;
			curr=curr->next;
		}
		newnode->prev=prev;
		newnode->next=curr;
		prev->next=newnode;
		curr->prev=newnode;
		n++;
		printf("Node Inserted\n");
	}
}
void delete_first()
{
	struct node *temp;
	if(head->data==NULL)
		printf("List Empty\n");
	else if(head->next==NULL)
	{
		printf("%d Deleted\n",head->data);
		head=NULL;
		tail=NULL;
		free(head);
		n--;
	}
	else
	{
		printf("%d Deleted\n",head->data);
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		n--;
	}
}
void delete_last()
{
	struct node *temp;
	if(head->data==NULL)
		printf("List Empty\n");
	else if(head->next==NULL)
	{
		printf("%d Deleted\n",head->data);
		head=NULL;
		tail=NULL;
		free(head);
		n--;
	}
	else
	{
		printf("%d Deleted\n",tail->data);
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
		n--;
	}
}
void delete_pos()
{
	int pos,i;
	struct node *curr,*prev;
	printf("Enter position to be deleted\n");
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
		printf("%d Deleted\n",curr->data);
		prev->next=curr->next;
		curr->next->prev=prev;
		free(curr);
		n--;
	}
}
void search()
{
	int flag=0,value,pos=0;
	struct node *curr;
	if(head->data==NULL)
	{
		printf("List Empty\n");
		return;
	}
	printf("Enter value to be searche\n");
	scanf("%d",&value);
	curr=head;
	while(curr!=NULL)
	{
		pos++;
		if(curr->data==value)
		{
			printf("%d found at node %d\n",value,pos);
			flag=1;
			break;
		}
		curr=curr->next;
	}
	if(flag==0)
		printf("%d not found\n",value);
}
void display()
{
	struct node *curr;
	if(head->data==NULL)
	{
		printf("List Empty\n");
	}
	else
	{
		printf("List is\n\t");
		curr=head;
		while(curr!=NULL)
		{
			printf("%d ",curr->data);
			curr=curr->next;
		}
		printf("\n");
	}

}
void revdisplay()
{
	struct node *curr;
	if(tail->data==NULL)
	{
		printf("List Empty\n");
	}
	else
	{
		printf("List is\n\t");
		curr=tail;
		while(curr!=NULL)
		{
			printf("%d ",curr->data);
			curr=curr->prev;
		}
		printf("\n");
	}

}