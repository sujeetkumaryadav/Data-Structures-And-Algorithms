#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=0,rear=0;
int isFull();
void insert(int);
void delete();
int isEmpty();
void display();
int main()
{
int ch,ele;
while(1)
{
printf("Queue operations:....\n");
printf("1.insert\n");
printf("2.Delete\n");
printf("3.display\n");
printf("4.Quit\n");

printf("Enter Your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:  printf("Enter Element to insert: ");
             scanf("%d",&ele);
             insert(ele);
             break;
case 2: delete();
            break;
case 3: display();
            break;
case 4: exit(1);
default: printf("Invalid choice\n");
}
}
}
void insert(int ele)
{
if(isFull())
         printf("Queue is overflow\n");
else{
         queue[rear]=ele;
          ++rear;
          printf("inserted successfully...\n");
}
}
int isFull()
{
if(rear==SIZE)
         return 1;
else
         return 0;
}
void delete()
{
if(isEmpty())
{
printf("Queue is under flow\n");
}
else
{
int i;
printf("Deleted : %d\n",queue[front]);
for(i=front;i<rear-1;i++)
{
queue[i]=queue[i+1];
}
--rear;
}
}
int isEmpty()
{
if(front==rear)
         return 1;
else
         return 0;
}
void display()
{
if(isEmpty())
         printf("Queue is underflow\n");
else{
         int i;
         printf("Queue Elements are: ");
         for(int i=front;i<rear;i++)
                  printf("%4d",queue[i]);
                  printf("\n");
}
}
