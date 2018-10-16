//Queue implementations using static array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define CAPACITY 5
//# -> PREPROCESSOR DIRECTIVE
int queue[CAPACITY];
int front=0;
int rear=0;

void insert()
{
if(rear==CAPACITY)
{
printf("\nThe queue is already full");
}
else
{
int ele;
printf("\nEnter data:");
scanf("%d",&ele);
queue[rear]=ele;
rear++;
}

}

void display()
{

if(front==rear)
{
printf("\nThe queue is empty");
}
else
{
int i=0;
while(i<rear)
{
printf(" %d ",queue[i]);
i++;
}
}

}

void del()
{
if(front==rear)
printf("\nQueue is empty");
else
{
printf("\nThe deleted element is:%d",queue[front]);
int i=0;
while(i<rear-1)
{
queue[i]=queue[i+1];
i++;
}
rear--;
}

}

void main()
{
int ch;
clrscr();
while(1)
{
printf("\n1.Add \n2.Display \n3.Deletion\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
       printf("\n");
       break;
case 2:display();
       printf("\n");
       break;
case 3:del();
       printf("\n");
       break;
case 4:exit(1);
       break;
default:printf("\nWrong Choice!");
}

}
}