#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top=-1;
int stack[SIZE];
void push();
void pop();
void peek();
void display();
int isEmpty();
int isFull();
int main()
{
int ch;
printf("Stack operations:\n");
while(1)
{
printf("1.push\n");
printf("2.pop\n");
printf("3.peek\n");
printf("4.display\n");
printf("5.Quit\n\n");
printf("Enter Your Choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
            break;
case 2: pop();
            break;
case 3: peek();
            break;
case 4: display();
            break;
case 5: exit(1);
            break;
default:
         printf("Invalid choice:\n");
}
}
return 0;
}
void push()
{
if(isFull())
{
printf("Stack is Full\n");
}
else
{
   int ele;
printf("Enter Element to push: ");
scanf("%d",&ele);
   ++top;
   stack[top]=ele;
   printf("Element pushed sucessfully\n");
}
}
void pop()
{
if(isEmpty())
{
printf("Stack is Empty\n");
}
else{
         printf("Popped Elements: %d\n",stack[top]);
         --top;
}
}
void peek()
{
if(isEmpty())
{
printf("Stack is empty\n");
}
else{
printf("Peek element: %d\n",stack[top]);
}
}
void display()
{
if(isEmpty())
{
printf("\nStack is empty\n");
}
else{
int i;
for(i=top;i>=0;i--)
{
         printf("%3d",stack[i]);
}
printf("\n");
}
}
int isEmpty()
{
if(top==-1)
         return 1;
else
         return 0;
}
int isFull()
{
if(top==SIZE-1)
         return 1;
else return 0;
}
