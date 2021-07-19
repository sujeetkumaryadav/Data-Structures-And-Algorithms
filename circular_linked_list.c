#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
};
struct Node *start=NULL;
void insert();
void display();
int length();
void delete();
int main()
{
int ch;
while(1)
{
printf("\nCircular linked list operation:\n");

printf("'1.insert\n");
printf("2.display\n");
printf("3.length\n");
printf("4.delete\n");
printf("5.exit\n");

printf("enter your choice\n");
scanf("%d",&ch);

switch(ch)
{
case 1:   insert();
              break;
case 2:   display();
              break;
case 3:
         {
              int len=length();
               printf("Length: %d",len);
               break;
         }
case 4:   delete();
               break;
case 5:    exit(1);
               break;
default:  printf("Invalid choice\n");
}
}
}
void insert()
{
int ele;
printf("enter element to insert:\n");
scanf("%d",&ele);
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
new->data=ele;
if(start==NULL)
{
start=new;
new->next=start;
}
else
{
struct Node *temp=start;
while(temp->next!=start)
{
temp=temp->next;
}
new->next=temp->next;
temp->next=new;
}
}
void display()
{
struct Node *temp=start;
if(start==NULL)
         printf("List is empty\n");
else
{
while(temp->next!=start)
{
printf("%4d",temp->data);
temp=temp->next;
}
printf("%4d",temp->data);
}
}
int length()
{
int count=0;
struct Node *temp=start;
if(start==NULL)
         return 0;
else
{
while(temp->next!=start)
{
count++;
temp=temp->next;
}
return (count+1);
}
}
void delete()
{
int len,i=1,loc;
struct Node *p,*q;
printf("enter location\n");
scanf("%d",&loc);
len=length();
if(loc>len)
{
printf("Invalid location\n");
return;
}
if(loc==1)
{
p=start;
if(p->next==start)
{
p->next=NULL;
start=NULL;
free(p);
}
else
{
while(p->next!=start)
{
p=p->next;
}
q=start;
p->next=q->next;
start=q->next;
q->next=NULL;
free(q);
}
}
else
{
p=start;
while(i<loc-1)
{
p=p->next;
i++;
}
q=p->next;
p->next=q->next;
q->next=NULL;
free(q);
}
}
