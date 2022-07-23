/*A C program for implementation of stack operations*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insertion();//for adding an item to a list
void deletion();//for removing an item from a list
void display();//to obtain the all items in the list
void isfull();//to check whether the stack is full or not
void isempty();//to check whether the stack is empty or not
int stack[35],top=-1,item;
void main()
{
    int ch;
    while(1)
    {
        printf("MENU:\n1.insertion\n2.deletion\n3.display\n4.isfull\n5.isempty\n6.exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertion();
                   break;
            case 2:deletion();
                    break;
            case 3:display();
                    break;
            case 4:isfull();
                    break;
            case 5:isempty();
                    break;
            case 6:exit(0);
            default:printf("entered invalid choice");
        }
    }
}
void insertion()
{
    if(top==SIZE-1)//stack full condition
    printf("stack is full");
    else
    {
      printf("enter item");
      scanf("%d",&item);
      top++;
      stack[top]=item;
    }
}
void deletion()
{
    if(top==-1)//stack empty condition
    printf("stack is empty");
    else
    {
        printf("the deleted item is=%d",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top==-1)
    printf("the stack is empty");
    else
    {
      printf("the elements in the stack are:");
      for(i=top;i>=0;i--)
        printf("%d",stack[i]);
    }
}
void isfull()
{
    if(top==SIZE-1)
    printf("the stack is full");
    else
    printf("the stack is not full");
}
void isempty()
{
    if(top==-1)
    printf("the stack is empty");
    else
    printf("the stack is not empty");
}