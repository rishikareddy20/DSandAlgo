/*A C program to implement basic queue operations*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void enqueue();//inserting an item in to the list
void dequeue();//deleting an item from the list
void display();//used to display all the elements in the list
int queue[SIZE],front=-1,rear=-1,item;
void main()
{
    int ch;
    while(1)
    {
        printf("MENU\n1.insertion\n2.deletion\n3.display\n4.exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("entered invalid choice");
        }
    }
}
void enqueue()//insertions allways takes place from rear 
{
    if(rear==SIZE-1)//queue full condition
    printf("queue is full");
    else
    {
      printf("enter item");
      scanf("%d",&item);
      rear++;
      queue[rear]=item;
      if(front==-1)
      front++;
    }
}
void dequeue()//deletions always takes place from front 
{
    if(front==-1||front>rear)//queue empty condition
     printf("queue is empty");
     else
     {
         printf("the deleted item is=%d",queue[front]);
         front++;
     }
}
void display()
{
    int i;
    if(front==-1||front>rear)
    printf("the queue is empty");
    else
    {
        printf("the elements in the list are:");
        for(i=front;i<=rear;i++)
        printf("%d",queue[i]);
    }
}