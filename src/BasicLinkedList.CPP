#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct stud{
int roll_no;
struct stud* next;
}*start=NULL,*temp,*ptr;
//data is the roll_no while pos is the position where element is to be added
void add(int data,int pos)
{
temp=(struct stud*)malloc(sizeof(struct stud));
temp->roll_no=data;
temp->next=NULL;
//List is empty
if(start==NULL)
{
start=temp;
}
else
{
int i=1;
ptr=start;
while(i<pos&&ptr!=NULL)
{
ptr=ptr->next;
i++;
}
//Ptr reaches at end of linked list
if(ptr==NULL)
{
ptr->next=temp;
}
else
{
//Inserting in between
temp->next=ptr->next;
ptr->next=temp;
}
}

}
//Displaying the element
void display(int pos)
{
int i=0;
ptr=start;
while(i<pos&&ptr!=NULL)
{
ptr->next=ptr;
i++;
}
printf("Roll_no = %d",ptr->roll_no);
}
void display()
{
ptr=start;
while(ptr!=NULL)
{printf("%d",ptr->roll_no);
  if(ptr->next!=NULL)
  printf("->");
  ptr=ptr->next;
}
}

void main()
{
clrscr();
int i=0,n,da,cho;
printf("Enter the number of elements");
scanf("%d",&n);
while(i<n)
{
printf("\n Enter Data: ");
scanf("%d",&da);
add(da,i);
display();
i++;
printf("Want To Enter More Elements (y/n):");
scanf("%d",cho);
if(cho=='y'||cho=='Y')
n++;
}
getch();
}