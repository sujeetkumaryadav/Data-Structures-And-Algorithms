#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *link;
};
struct Node *front=NULL,*rear=NULL;
void insert(int);
void delete();
void display();
int main()
{
int ch,ele;
printf("Queue Operations:\n");
while(1)
{
printf("\n1.insert\n");
printf("2.delete\n");
printf("3.display\n");
printf("4.Quit\n");

printf("Enter Your Choice: ");
scanf("%d",&ch);

switch(ch)
{
case 1:
         {
         printf("enter Element to insert: ");
         scanf("%d",&ele);
         insert(ele);
         break;
         }
case 2: delete();
            break;
case 3: display();
            break;
case 4:  exit(1);
default: printf("Invalid choice\n");
}
}
}
void insert(int ele)
{
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
new->data=ele;
new->link=NULL;
if(rear==NULL)
{
front=rear=new;
}
else
{
   rear->link=new;
    rear=new;
}
}
void delete()
{
if(front==NULL)
         printf("List is Empty:\n");
else
{
struct Node *temp=front;
printf("Deleted: %d\n",front->data);
front=front->link;
temp->link=NULL;
free(temp);
}
if(front==NULL)
         rear=front;
}
void display()
{
struct Node *node=front;
if(front==NULL)
         printf("List is empty:\n");
else
{
while(node)
{
printf("%4d",node->data);
node=node->link;
}
}
}

