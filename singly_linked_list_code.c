#include<stdio.h>
#include<stdlib.h>
struct Emp
{
int data;
struct Emp *link;
};
struct Emp *root=NULL;
//void createList();
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
int ch;
printf("\nSingly linked list operations:\n");
while(1)
{
//printf("\n1.createList\n");
printf("\n2.append\n");
printf("3.length\n");
printf("4.addFirst\n");
printf("5.addAfter\n");
printf("6.removeFirst\n");
printf("7.removeAfter\n");
printf("8.display\n");
printf("9.swap\n");
printf("10.search\n");
printf("11.Quit\n");

printf("Enter your choice: ");
scanf("%d",&ch);

switch(ch)
{
/*case 1: createList();
            break;
*/
case 2: append();
            break;
case 3: {
             int len;
            len=length();
            printf("Length: %d",len);
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
case 8: display();
            break;
case 9:  swap();
             break;
case 10: search();
              break;
case 11: exit(1);
default:  printf("Invalid choice\n");
}
}
return 0;
}
/*
void createList()
{
struct Emp *temp,*new;
new=(struct Emp*)malloc(sizeof(struct Emp));
printf("\nEnter data: ");
scanf("%d",&new->data);
if(root==NULL)
{
root=new;
temp=new;
}
else
{
temp->link=new;
temp=new;
}
}
*/
void append()
{
struct Emp *temp;
temp=(struct Emp*)malloc(sizeof(struct Emp));
printf("Enter data: ");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct Emp *p=root;
while(p->link!=NULL)
{
p=p->link;
}
p->link=temp;
}
}
void display()
{
struct Emp *p;
printf("Linked List Elements are: ");
if(root==NULL)
         printf("Empty List\n");
else
{
p=root;
while(p!=NULL)
{
printf("%4d",p->data);
p=p->link;
}
}
}
int length()
{
int count=0;
if(root==NULL)
{
return 0;
}
else
{
struct Emp *p=root;
while(p!=NULL)
{
count++;
p=p->link;
}
return count;
}
}
void addFirst()
{
struct Emp *new;
new=(struct Emp*)malloc(sizeof(struct Emp));
printf("Enter Data: ");
scanf("%d",&new->data);
new->link=root;
root=new;
}
void addAfter()
{
int len,loc,i=1;
struct Emp *new;
printf("Enter location: ");
scanf("%d",&loc);
new=(struct Emp *)malloc(sizeof(struct Emp));
printf("Enter data: ");
scanf("%d",&new->data);
len=length();
if(loc>len)
{
printf("Invalid locaton:\n");
}
else
{
struct Emp *p=root;
while(i<loc)
{
p=p->link;
i++;
}
new->link=p->link;
p->link=new;
}
}
void removeFirst()
{
if(root==NULL)
{
printf("Empty List\n");
return;
}
   struct Emp *temp=root;
   root=temp->link;
   temp->link=NULL;
   free(temp);
}
void removeAfter()
{
int loc,i=1,len;
printf("Enter location: ");
scanf("%d",&loc);
len=length();
if(loc>=len)
{
printf("Invalid location:");
}
else
{
struct Emp *p=root,*temp;
while(i<loc)
{
p=p->link;
i++;
}
temp=p->link;
p->link=temp->link;
temp->link=NULL;
free(temp);
}
}
void swap()
{
int loc1,loc2,i=1,j=1,len,temp;
printf("Enter location: ");
scanf("%d%d",&loc1,&loc2);
len=length();
if(loc1>len || loc2>len)
         printf("Invalid location\n");
else
{
struct Emp *p=root,*q=root;
while(i<loc1)
{
p=p->link;
i++;
}
while(j<loc2)
{
q=q->link;
j++;
}
temp=p->data;
p->data=q->data;
q->data=temp;
}
}
void search()
{
int ele,found=0;
printf("enter Element to search: ");
scanf("%d",&ele);
if(root==NULL)
         printf("Empty List: ");
else
{
struct Emp *p=root;
while(p!=NULL)
{
if(p->data==ele)
{
found=1;
break;
}
  p=p->link;
}
if(found==1)
         printf("Element Found: \n");
else
         printf("Element is not found:\n ");
}
}
