#include<stdio.h>
#include<stdlib.h>
int *stack,*top,min,curr;
void push();
int pop();
int peek();
void dispaly();
void createStack();
int main()
{
int ch,ele;
createStack();
while(1)
{
printf("\nStack opeartions:\n");
printf("\n1.push\n");
printf("2.pop\n");
printf("3.peek\n");
printf("4.display\n");
printf("5.quit\n");
printf("Enter Your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:  printf("Enter element to push: ");
             scanf("%d",&ele);
             push(ele);
             break;
case 2: ele=pop();
            if(ele==-1)
                  printf("Stack is empty\n");
            else
                  printf("Popped element is: %d",ele);
            break;
case 3: ele=peek();
             if(ele==-1)
                  printf("Stack is empty\n");
             else
                  printf("Peek element is: %d",ele);
            break;
case 4: display();
            break;
case 5:exit(1);
default:
           printf("Invalid choice\n");
}
}
}

void createStack()
{
printf("Enter Initial size: ");
scanf("%d",&min);
curr=min;
stack=(int*)calloc(min,sizeof(int));
if(stack==NULL)
         printf("Stack creation failed\n");
else{
top=stack;
printf("Stack created sucessfully\n");
}
}
void push(int ele)
{
if(top==stack+curr)
{
++curr;
stack=(int*)realloc(stack,curr*sizeof(int));
if(stack==NULL)
         printf("unable to increase the size\n");
else
{
*top=ele;
++top;
printf("Element pushed\n");
}
}
else
{
*top=ele;
++top;
printf("Element pushed..\n");
}
}
int pop()
{
if(stack==top)
return -1;
else
{
--top;
int ele=*top;
return ele;
}
}
int peek()
{
if(stack==top)
         return -1;
else
{    int *ele=--top;
              top++;
      return *ele;
}
}
void display()
{
         if(stack==top)
                  printf("Stack is empty\n");
         else{
         int *i;
         printf("Stacks Elements are: ");
         for(i=top-1;i>=stack;i--)
           printf("%4d",*i);
         }
}
