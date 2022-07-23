/*A C program to convert infix expression to post expression*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(char c);
char pop();
int prec(char c);//if operator check precendency with stack of top
char stack[35];
int top=-1;
void main()
{
	char in[35],post[35],ch;
	int i,j;
	printf("enter infix expression");
	gets(in);
	for(i=0,j=0;i<strlen(in);i++)
	{
		if(isdigit(in[i])||isalpha(in[i]))
		post[j++]=in[i];
		else if(in[i]=='(')
		push(in[i]);
		else if(in[i]==')')
		{
			while((ch=pop())!='(')
			post[j++]=ch;
		}
		else
		{
			while(prec(in[i])<=prec(stack[top]))
			{
			if((in[i]=='^')&&(stack[top]=='^'))
			break;
			else
				post[j++]=pop();
			}
			push(in[i]);
		}
	}
	while(top!=-1)//until the stack is empty
	{
		post[j++]=pop();
		post[j]='\0';
		printf("post fix expression is:%s",post);
	}
}
void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	return(stack[top--]);
}
int prec(char c)
{
	switch(c)
	{
		case '^':return 3;
		case '*':
	    case '/':return 2;
	    case '+':
	    case '-':return 1;
	    default:return 0;
	}
}