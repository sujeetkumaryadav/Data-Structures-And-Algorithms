#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *prev;
struct Node *next;
};
struct Node *start=NULL;
void append();
void display();
int length();
void addFirst();
void addAfter();
void removeFirst();
void removeAfter();
void swap();
void search();
int main()
{
int ch,ele,len;
while(1)
{
printf("\nDoubly Linked list operation:\n");
printf("\n1.append\n");
printf("2.display\n");
printf("3.length\n");
printf("4.addFirst\n");
printf("5.addAfter\n");
printf("6.removeFirst\n");
printf("7.removeAfter\n");
printf("8.swap\n");
printf("9.search\n");
printf("10.exit\n");

printf("Enter Your Choice\n");
scanf("%d",&ch);
 switch(ch)
 {
case 1: append();
            break;
case 2:  display();
             break;
case 3:
         {
           len=length();
            printf("length: %d",len);
            break;
         }
case 4: addFirst();
            break;
case 5: addAfter();
            break;
case 6: removeFirst();
            break;
case 7: removeAfter();
            break;
case 8: swap();
            break;
case 9: search();
            break;
case 10: exit(1);
default: printf("Invalid choice:\n");
}
}
return 0;
}
void append()
{
struct Node *new,*temp=start;
new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter node data:");
scanf("%d",&new->data);
new->prev=NULL;
new->next=NULL;
if(start==NULL)
{
start=new;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=new;
new->prev=temp;
}
}
void display()
{
struct Node *temp=start;
if(temp==NULL)
         printf("List is Empty\n");
else
{
printf("Elements are: ");
while(temp)
{
printf("%4d",temp->data);
temp=temp->next;
}
}
}
int length()
{
int count=0;
struct Node *temp=start;
while(temp)
{
count++;
temp=temp->next;
}
return count;
}
void addFirst()
{
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter new data: ");
scanf("%d",&new->data);
 new->prev=NULL;
 new->next=start;
 if(start==NULL)
 {
  start=new;
 }
 else
 {
start->prev=new;
start=new;
 }
}
void addAfter()
{
struct Node *new,*temp;
int i=1,loc,len;
printf("\nEnter location:");
scanf("%d",&loc);
len=length();
if(loc>len)
{
printf("Invalid location:\n ");
return;
}
temp=start;
new=(struct Node *)malloc(sizeof(struct Node));
printf("Enter Node data: ");
scanf("%d",&new->data);
while(i<loc)
{
temp=temp->next;
i++;
}
new->next=temp->next;
if(temp->next)
{
temp->next->prev=new;
}
new->prev=temp;
temp->next=new;
}
void removeFirst()
{
struct Node *temp=start;
if(start==NULL)
{
printf("List is empty\n");
return;
}
start=temp->next;
if(temp->next)
         start->prev=NULL;
temp->next=NULL;
free(temp);
}
void removeAfter()
{
int i=1,loc,len;
struct Node *p,*q;
printf("Enter location:");
scanf("%d",&loc);
len=length();
if(loc>len)
{
printf("Invalid location\n");
return;
}
p=start;
while(i<loc)
{
p=p->next;
i++;
}
q=p->next;
p->next=q->next;
if(q->next)
{
q->next->prev=p;
}
q->prev=NULL;
q->next=NULL;
free(q);
}
void swap()
{
struct Node *p,*q;
int i=1,len,j=1,loc1,loc2,temp;
len=length();
printf("Enter Loc1 and Loc2");
scanf("%d%d",&loc1,&loc2);
if(loc1>len || loc2>len)
{
printf("Invalid location\n");
return;
}
p=start;
while(i<loc1)
{
p=p->next;
i++;
}
q=start;
while(j<loc2)
{
q=q->next;
j++;
}
temp=p->data;
p->data=q->data;
q->data=temp;
}
void search()
{
int ele,f=0;
printf("Enter element to search\n");
scanf("%d",&ele);
if(start==NULL)
{
printf("List is Empty\n");
return;
}
struct Node *temp;
temp=start;
while(temp->next!=NULL)
{
if(temp->data==ele)
{
f=1;
break;
}
temp=temp->next;
}
if(f==1)
printf("Element is found:\n");
else
         printf("Element is not found\n");
}
