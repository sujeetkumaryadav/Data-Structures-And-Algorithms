#include<stdio.h>
#include<stdlib.h>
int *queue,*front,*rear,size,curr;
void createQueue();
void insert(int ele);
void delete();
void display();
int main()
{
int ch,ele;
createQueue();
printf("Queue operations:\n");
while(1)
{
printf("1.insert\n");
printf("2.delete\n");
printf("3.display\n");
printf("4.Quit\n");

printf("Enter You choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1: printf("Enter element to insert\n");
            scanf("%d",&ele);
            insert(ele);
            break;
case 2: delete();
            break;
case 3: display();
           break;
case 4: exit(1);
default:
            printf("Invalid choice\n");
}
}
}
void createQueue()
{
printf("Enter initial size: ");
scanf("%d",&size);
curr=size;
queue=(int*)calloc(size,sizeof(int));
if(queue==NULL)
         printf("Queue creation failed\n");
else
{
         printf("Queue created successfully\n");
         front=rear=queue;
}
}
void insert(int ele)
{
if(front+curr==rear)
{
curr++;
queue=(int*)realloc(queue,curr*sizeof(int));
if(queue==NULL)
{
         printf("Size not increases\n");
}
else
{
*rear=ele;
rear++;
printf("Element inserted\n");
}
}
else{
*rear=ele;
printf("Element inserted....\n");
rear++;
}
}
void delete()
{
if(front ==rear)
         printf("Queue is empty\n");
else{
         int *i;
         printf("Deleted: %d\n", *front);
         for(i=front;i<rear-1;i++)
         {
         *i=*(i+1);
         }
         rear--;
if(curr>size)
{
--curr;
queue=(int*)realloc(queue,curr*sizeof(int));
}
}
}
void display()
{
if(front==rear)
         printf("Queue is empty\n");
else{
int *i;
printf("Queue elements are: ");
for(i=front;i<rear;i++)
         printf("%4d",*i);
         printf("\n");
}
}
