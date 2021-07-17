#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *prev;
struct Node *next;
};
struct Node *start=NULL;
void createList();
void display();
void length();
int main()
{
createList();
display();
length();
}
void createList()
{
while(1)
{
struct Node *new,*last;
new=(struct Node *)malloc(sizeof(struct Node));
printf("\nEnter new Node data: ");
scanf("%d",&new->data);
if(start==NULL)
{
start=new;
new->prev=NULL;
new->next=NULL;
last=new;
}
else
{
last->next=new;
new->prev=last;
last=new;
}
printf("Do you want to continue:(y/n) ");
if(getche()=='n')
{
last->next=NULL;
break;
}
}
}
void display()
{
struct Node *temp=start;
if(temp==NULL)
         printf("List is empty:\n");
else
{
printf("\nLinked List elements are: \n");
while(temp)
{
printf("%4d",temp->data);
temp=temp->next;
}
}
}
void length()
{
struct Node *temp=start;
int count=0;
if(temp==NULL)
         printf("List is empty");
else
{
while(temp)
{
count++;
temp=temp->next;
}
printf("\nLength : %d",count);
}
}
