#include<stdio.h>
#include<stdlib.h>
struct Emp
{
int data;
struct Emp *link;
};
struct Emp *root=NULL;
void createList();
void display();
int main()
{
createList();
display();
}
void createList()
{
while(1)
{
struct Emp *new,*temp;
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
printf("Do you want to continue(y/n)");
if(getche()=='n')
{
temp->link=NULL;
break;
}
}
}
void display()
{
if(root==NULL)
printf("Empty List\n");
else
{
struct Emp *node=root;
printf("\nLinked list  Elements are: \n");
while(node)
{

printf("%4d",node->data);
node=node->link;
}
}
}
