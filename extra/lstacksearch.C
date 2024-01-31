#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void push()
{
    int val;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value to be pushed:");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("inserted");
}

void pop()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("stack empty");
    }
    else
    {
        head=head->next;
        free(temp);
        printf("deleted");
    }
}

void display()
{
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("stack empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
 void search()
 
{
    int search;
    struct node *ptr;
    printf("enter elemnt to search:");
    scanf("%d",&search);
    ptr=head;
    if(ptr==NULL)
    {
        printf("elemnt not found");
    }
    while(ptr!=NULL)
    {
        if(search==ptr->data)
        {
            printf("elemnt present in stack");
            ptr=ptr->next;
            break;
        }
    
        else if(search!=ptr->data)
        {
            printf("elemnt not in stack");
            break;
        }
    }  
    
}
int main()
{
    int ch;
    while(ch!=5)
    {
        printf("\n1.push\n2.pop\n3.display\n4.search\n5.exit");
        printf("\n enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
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
}
