#include<stdio.h>

int u[10]= {1,2,3,4,5,6,7,8,9,10};
void display(int *arr)
{
 int *ar=arr,i;

  for(i=0;i<10;i++)
  {
  if(*ar==1)

      printf("%d \t ",u[i]);
      ar++;
  }
}

int main()
{

 int universal[10]={1,1,1,1,1,1,1,1,1,1};
 int a[10]={1,1,1,0,0,0,1,0,0,1};
 int b[10]={1,0,0,1,0,0,1,1,1,0};
 int i,uni[10],inter[10],diffab[10],diffba[10];
 clrscr();

 printf("\n\t universal set is:\t");
 display(universal);
 printf("\n\t set a is:\t");
 display(a);
 printf("\n\t set b is :\t");
 display(b);

 printf("\n\t\t union of a and b is:\n");
 for(i=0;i<10;i++)
 uni[i]=a[i]||b[i];
 display(uni);

 printf("\n\t\t intersection of a and b is:\n");
 for(i=0;i<10;i++)
 inter[i]=a[i]&&b[i];
 display(inter);


 printf("\n\t\t diff of a and b:\n");
 for(i=0;i<10;i++)
 diffab[i]=a[i]-b[i];
 display(diffab);

 printf("\n\t\t diff of b and a:\n");
 for(i=0;i<10;i++)
 diffba[i]=b[i]-a[i];
 display(diffba);

 getch();
 return 0;
}





