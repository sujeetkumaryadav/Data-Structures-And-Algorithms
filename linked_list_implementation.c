#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *link;
};
void main()
{
struct Node *ptr,*root=NULL,*temp;
while(1)
{
ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\nEnter data: ");
scanf("%d",&ptr->data);
if(root==NULL)
{
root=ptr;
temp=ptr;
}
else
{
temp->link=ptr;
temp=ptr;
}
printf("Do you want to another node(y/n): ");
if(getche()=='n')
{
temp->link=NULL;
temp=root;
break;
}
}
if(temp==NULL)
         printf("Empty list:\n");
printf("\n");
while(temp!=NULL)
{
printf("%4d",temp->data);
temp=temp->link;
}
}
