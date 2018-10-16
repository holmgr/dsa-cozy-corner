
//binary search tree
//we have for n nodes contains  n+1 null values/pointers

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* root=NULL;

void insert()
{
struct node* parent,*temp,*curr;
temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
parent=root;
if(parent==NULL)
{
root=temp;
}
else
{
curr=root;
while(curr)
{
parent=curr;
if(curr->data<temp->data)
{curr=curr->left;}
else
curr=curr->right;
}
if(parent->data<temp->data)
parent->left=temp;
else
parent->right=temp;
}

}

void main()
{
int ch;
while(1)
{
printf("\n1.Insert \n2.Exit");
}

}