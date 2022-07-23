/*A C program to implement basic circular queue operations*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insertion();//to insert element in to the list
void deletion();//to delete the element from the list
void display();//to display the all elements in the list
int cqueue[SIZE],front=-1,rear=-1,item;
void main()
{
	int ch;
	while(1)
	{
		printf("MENU:\n1.insertion\n2.deletion\n3.display\n4.exit");
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
		    case 4:exit(0);
		           break;
		    default:printf("entered invalid input");
		}
	}
}
void insertion()
{
	if(front==(rear+1)%SIZE)//queue full condition
	printf("queue is full");
	else
	{
		printf("enter item");
		scanf("%d",&item);
		rear=(rear+1)%SIZE;
		cqueue[rear]=item;
		if(front==-1)
		front++;
	}
}
void deletion()
{
	if(front==-1)//queue empty condition
	printf("queue is empty");
	else
	{
		printf("deleted element =%d",cqueue[front]);
		if(front==rear)
		front=rear=-1;
		else
		front=(front+1)%SIZE;
	}
}
void display()
{
	int i;
	if(front==-1)
	printf("queue is empty");
	else
	{
		printf("the elements in the queue are:");
		for(i=front;i!=rear;i=(i+1)%SIZE)
		printf("%d",cqueue[i]);
		printf("%d",cqueue[i]);
	}
}