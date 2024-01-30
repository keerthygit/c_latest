#include<stdio.h>
#include<conio.h>


void unionab(int a[10],int b[10]);
int  find(int a[10],int b[10]);

void main()
{

   int a[10]={1,2,3,4,5};
   int b[10]={6,7,8,9};
   int parent;
   clrscr();

   unionab(a,b);
   parent=find(a,b);

   if(parent==a[0])
       printf("parent found in set a \n root=%d",parent);
   else if(parent==b[0])
       printf("parent found in set b \n root=%d",parent);
   else
       printf("parent not found");

  getch();

 }

 void unionab(int a[10],int b[10])
 {

      int i,j,k,uni[10];

      i=0;

      //setA

      for(j=0;j<5;j++)
      {
	uni[i]=a[j];
	i++;
      }


      //setB

      for(k=0;k<4;k++)
      {

	uni[i]=b[k];
	i++;
      }

      //printunion

      printf("\n set a-");

      for(i=0;i<5;i++)
      {
	printf("\t %d",a[i]);
      }

      printf("\nset b-");

      for(i=0;i<4;i++)
      {
	printf("\t%d",b[i]);
      }

     printf("\n union of a and b:\n\n");

     for(i=0;i<9;i++)
     {
       printf("\t %d",uni[i]);
     }

  }


  //find

  int find(int a[10],int b[10])
  {

     int parent, num,i;

     printf("\n enter num to be searched");
     scanf("%d",&num);

     for(i=0;i<5;i++)
     {
	if(a[i]==num)
	  {
	     parent=a[0];
	  }
     }

     for(i=0;i<5;i++)
     {

       if(b[i]==num)
       {
	  parent=b[0];
       }

    }

    return parent;

 }


