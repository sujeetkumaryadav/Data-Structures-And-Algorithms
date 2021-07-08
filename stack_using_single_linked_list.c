#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *link;
};
struct Node *top=NULL;
void push(int ele);
void pop();
void display();
void main()
{
int ch,ele;
printf("Stack operations are:\n");
while(1)
{
printf("\n1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.Quit\n");

printf("Enter Your choice\n");
scanf("%d",&ch);

switch(ch)
{
case 1:
         {
           printf("Enter Element to push\n");
           scanf("%d",&ele);
           push(ele);
           break;
         }
case 2:pop();
           break;
case 3:display();
            break;
case 4:exit(1);
default: printf("Invalid Choice\n");
}
}
}
void push(int ele)
{
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
new->data=ele;
printf("Element pushed\n");
new->link=top;
top=new;
}
void pop()
{
if(top==NULL)
printf("Stack is empty");
else
{
struct Node *temp=top;
printf("Popped: %d\n",top->data);
top=top->link;
temp->link=NULL;
free(temp);
}
}
void display()
{
if(top==NULL)
         printf("stack is empty\n");
else
{
struct Node *node=top;
printf("stack Elements are: ");

while(node!=NULL)
{
printf("%4d",node->data);
node=node->link;
}
}
}
