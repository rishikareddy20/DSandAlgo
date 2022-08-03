#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
void search();
struct node//node creation
{
	int data;
	struct node *link;
}*header=NULL,*ptr,*ptr1,*new;
int ch,f1,item,key,pos,i;
void main()
{
	while(1)
	{
		printf("MENU:\n1.insertion\n2.deletion\n3.display\n4.search\n5.exit\n");
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
	new=malloc(sizeof(struct node));
	ptr=header;
	printf("enter item");
	scanf("%d",&item);
	new->data=item;
	if(header==NULL)
	{
		new->link=NULL;
		header=new;
	}
	else
	{
		printf("MENU:\n1.begin\n2.at any position\n3.end\n");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
		  new->link=ptr;
		  header=new;
		}
		if(ch==2)
		{
			printf("enter position");
			scanf("%d",&pos);
			for(i=1;i<(pos-1);i++)
			ptr=ptr->link;
			new->link=ptr->link;
			ptr->link=new;
		}
		if(ch==3)
		{
			while(ptr->link!=NULL)
			ptr=ptr->link;
			ptr->link=new;
			new->link=NULL;
		}
	}
}
void deletion()
{
	ptr=header;
	if(header==NULL)
	printf("the list is empty");
	else if(header->link==NULL)
	{
		printf("the deleted item is:%d",header->data);
		header=NULL;
		free(header);
	}
	else
	{
		printf("MENU:\n1.begin\n2.at any position\n3.end\n");
		printf("enter your choice");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("the deleted item is :%d",ptr->data);
			header=ptr->link;
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
			printf("deleted item is:%d",ptr->data);
			ptr1->link=ptr->link;
			free(ptr);
		}
		if(ch==3)
		{
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			printf("deleted item is=%d",ptr->data);
			ptr1->link=NULL;
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
		printf("%d",ptr->data);
	}
}
void search()
{
      int f1=0;
	if(header==NULL)
	printf("there are no elements in the list");
  else
  {
  printf("enter key");
  scanf("%d",&key);
  for(ptr=header;ptr!=NULL;ptr=ptr->link)
  {
  	if(ptr->data==key)
  {
  	f1=1;
  	break;
  }
  }
  if(f1==1)
  printf("search is successfull");
  else
  printf("search is  not successfull");
}
}