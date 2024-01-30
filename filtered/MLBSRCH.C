#include <stdio.h>
#include <conio.h>
void lin_search(int a[10]);
void bin_search(int a[10]);
int n;
void main()
{
	int i,a[10],ch,value;
	clrscr();
	printf("Enter array size\n");
	scanf("%d",&n);
	printf("Enter Array elements\n");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	do
	{
		printf("Select\n1.Linear Search\n2.Binary Search\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: lin_search(a);
				break;
			case 2: bin_search(a);
				break;
			default: exit();
		}
	}while(ch!=0);
	getch();
}

void lin_search(int a[10])
{
	int flag=0,j,i,value;
	printf("Array is \n\t");
	for(i=0;i<n;++i)
		printf("%d ",a[i]);
	printf("\n");
	printf("Enter the number to be serached\n");
	scanf("%d",&value);
	for(i=0;i<n;++i)
	{
		if(a[i]==value)
		{
			printf("%d found at position %d\n",value,i+1);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("%d not found\n",value);
}

void bin_search(int a[10])
{
	int flag=0,i,j,temp,low,high,mid,value;
	//sort array
	for(i=0;i<n-1;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Array is \n\t");
	for(i=0;i<n;++i)
		printf("%d ",a[i]);
	printf("\n");
	printf("Enter the number to be serached\n");
	scanf("%d",&value);
	low=0;
	high=n-1;
	for(i=0;i<=n-1;++i)
	{
		mid=(low+high)/2;
		if(a[mid]==value)
		{
			printf("%d found at position %d\n",value,mid+1);
			flag=1;
			break;
		}
		else if(value<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(flag==0)
		printf("%d not found\n",value);
}