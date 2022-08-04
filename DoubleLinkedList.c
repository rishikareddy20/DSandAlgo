/* A C program for basic double linked list operations*/
#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
void search();
struct node//node creation
{
	struct node *prev;
	int data;
	struct node *next;
}*ptr2,*ptr,*ptr1,*header=NULL,*new;
int i,item,pos,ch,key,f1;
void main()
{
	while(1)
	{
		printf("MENU:\n1.insertion\n2.deletion\n3.display\n4.search\n5.exit");
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
			case 4:search();
					break;
			case 5:exit(0);
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
		new->prev=NULL;
		new->next=NULL;
		header=new;
	}
	else
	{
		printf("select place");
		printf("MENU:\n1.begin\n2.at any position\n3.end");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
			new->prev=NULL;
			new->next=ptr;
			ptr->prev=new;
			header=new;
		}
		if(ch==2)
		{
			printf("enter position");
			scanf("%d",&pos);
			for(i=1;i<pos-1;i++)
			ptr=ptr->next;
			ptr1=ptr->next;
			new->prev=ptr;
			new->next=ptr1;
			ptr->next=new;
			ptr1->prev=new;
		}
		if(ch==3)
		{
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=new;
			new->prev=ptr;
			new->next=NULL;
		}
	}
}
void deletion()
{
	if(header==NULL)
	printf("the list is empty");
   else if(header->next==NULL)
	{
		printf("the deleted item=%d",header->data);
		free(header);
		header=NULL;
	}
	else
	{
	      ptr=header;
		printf("MENU:\n1.begin\n2.at any position\n3.end");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
			ptr1=ptr->next;
			printf("the deleted item is=%d",ptr->data);
			ptr1->prev=NULL;
			header=ptr1;
			free(ptr);
		}
		if(ch==2)
		{
			printf("enter position");
			scanf("%d",&pos);
			for(i=1;i<pos;i++)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr2=ptr->next;
			printf("the deleted item=%d",ptr->data);
		     ptr1->next=ptr2;
		     ptr2->prev=ptr1;
		     free(ptr);
		}
		if(ch==3)
		{
			while(ptr->next!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			printf("the deleted item=%d",ptr->data);
			ptr1->next=NULL;
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
	printf("the list in forward direction is:");
	for(ptr=header;ptr!=NULL;ptr=ptr->next)
     {
	 printf("%d",ptr->data);
	 ptr1=ptr;
     }
     printf("the list in reverse direction is:");
     for(;ptr1!=NULL;ptr1=ptr1->prev)
     printf("%d",ptr1->data);
    }
}
void search()
{
    int f1=0;
	printf("enter key");
	scanf("%d",&key);
	for(ptr=header;ptr!=NULL;ptr=ptr->next)
	{
		if(key==ptr->data)
		{
		f1=1;
		break;
		}
	}
	if(f1==1)
	printf("the search is succesful");
	else
	printf("the search is not successful");
}