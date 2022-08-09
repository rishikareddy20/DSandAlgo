/*A C Program to implement basic circular linked list operations*/
#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
struct node
{
	int data;
	struct node *link;
}*ptr,*new,*header=NULL,*ptr1,*last;
int i,ch,pos,item,f1=0;
void main()
{
	while(1)
	{
		printf("MENU\n1.insertion\n2.deletion\n3.display\n4.exit");
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
			default:printf("entered invalid choice");
		}
	}
}
void insertion()
{
	ptr=header;
	new=malloc(sizeof(struct node));
	printf("enter item to be inserted");
	scanf("%d",&item);
	new->data=item;
	if(header==NULL)
	{
		new->link=new;
		header=new;
	}
	else
	{
	    last=header;
		printf("MENU:\n1.begin\n2.at any position\n3.end");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
			while(last->link!=header)
			last=last->link;
			last->link=new;
			new->link=header;
			header=new;
		}
		if(ch==2)
		{
			printf("enter position");
			scanf("%d",&pos);
			for(i=1;i<pos-1;i++)
			ptr=ptr->link;
			new->link=ptr->link;
			ptr->link=new;
		}
		if(ch==3)
		{
		   while(last->link!=header)
		   last=last->link;
		   last->link=new;
		   new->link=header;	
		}
	}
}
void deletion()
{
	ptr=last=header;
	if(header==NULL)
	printf("the list is empty");
	else if(header->link==header)
	{
		printf("the deleted item is:%d",header->data);
		header=NULL;
	}
	else
	{
		printf("MENU:\n1.begin\n2.at any position\n3.end");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("the deleted item=%d",ptr->data);
			header=ptr->link;
			while(last->link!=header)
			last=last->link;
			last->link=header;
			free(ptr);
    	}
    	if(ch==2)
    	{
    		printf("enter position");
    		scanf("%d",&pos);
    		for(i=1;i<pos;i++)
    		{
			 ptr1=ptr;
    		ptr=ptr->link;  
        	}
    		printf("the deleted item=%d",ptr->data);
    		ptr1->link=ptr->link;
    		free(ptr);
		}
		if(ch==3)
		{
		    while(ptr->link!=header)
		    {
		    ptr1=ptr;
		    ptr=ptr->link;
		    }
		    printf("the deleted item=%d",ptr->data);
		    ptr1->link=header;
		    free(ptr);
		}
	}
}
void display()
{
	if(header==NULL)
	printf("the list is empty");
	else
	{
		printf("the elements in the list are:");
		for(ptr=header;ptr!=NULL;ptr=ptr->link)
		{
		printf("%d",ptr->data);
		if(ptr->link==header)
		break;
    	      }
	}
}