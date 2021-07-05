#include<stdio.h>
#include<stdlib.h>
struct Emp
{
char name[20];
int id;
float salary;
};
int main()
{
struct Emp *ptr;
ptr=(struct Emp*)malloc(sizeof(struct Emp));
printf("Enter Employee Details:\nName   Id   Salary\n");
scanf("%s%d%f",ptr->name,&ptr->id,&ptr->salary);
printf("Employee Details are:\n");
printf("Name: %s\nId: %d\nSalary: %.2f",(*ptr).name,ptr->id,ptr->salary);
return 0;
}
