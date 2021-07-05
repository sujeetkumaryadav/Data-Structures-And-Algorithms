#include<stdio.h>
#include<stdlib.h>
struct Emp
{
int data;
struct Emp *link;
};
struct Emp *root=NULL;
void append(struct Emp *new);
void length();
void display();
int main()
{
int ch;
while(1)
{
printf("\n1.append\n");
printf("2.length\n");
printf("3.display\n");
printf("4.quit\n");

printf("Enter Your choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1:
         {
           struct Emp *new;
            new=(struct Emp*)malloc(sizeof(struct Emp));
            printf("Enter data: ");
            scanf("%d",&new->data);
            append(new);
           break;
         }
case 2: length();
            break;
case 3: display();
            break;
case 4: exit(1);
default: printf("Invalid choice\n");
}
}
}
void append(struct Emp *new)
{
new->link=NULL;
if(root==NULL)
{
root=new;
}
else
{
struct Emp *ptr;
ptr=root;
while(ptr!=NULL)
{
ptr=ptr->link;
}
ptr->link=new;
}
}
void length()
{
int count=0;
struct Emp *node;
node=root;
while(node!=NULL)
{
count++;
node=node->link;
}
printf("\nLength : %d",count);
}
void display()
{
struct Emp *node=root;
printf("\nLinked List elements are: ");
if(node==NULL)
printf("\nEmpty List\n");
while(node!=NULL)
{
printf("%4d",node->data);
node=node->link;
}
}
