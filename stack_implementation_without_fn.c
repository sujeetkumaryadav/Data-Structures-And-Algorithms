#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE],top=-1;
int main()
{
int ch,ele;
printf("Stack operations:\n");
while(1)
{
printf("\n1.push\n");
printf("2.pop\n");
printf("3.peek\n");
printf("4.display\n");
printf("5.Quit\n");
printf("Enter Your choice\n");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter Element to push:\n");
scanf("%d",&ele);
}
switch(ch)
{
case 1: if(top==SIZE-1)
             printf("Stack is full\n");
             else
             {
               ++top;
               stack[top]=ele;
               printf("Element pushed\n");
             }
             break;
case 2: if(top==-1)
            printf("Stack is empty\n");
            else
            {
             printf("Popped element is: %d",stack[top]);
             --top;
            }
            break;
case 3: if(top==-1)
            printf("Stack is empty\n");
            else
                  printf("Peek element : %d",stack[top]);
            break;
case 4: if(top==-1)
             printf("Stack is empty\n");
             else
             {
              int i;
              for(i=top;i>=0;i--)
                  printf("%3d",stack[i]);
             }
             break;
case 5: exit(1);
default: printf("Invalid choice\n");
}
}

}
