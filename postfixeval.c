/*A C program for evaluation of postfix expression*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void push(int c);
int pop();
int stack[15],top=-1;
void main()
{
    char p[35];
    int i,j,a,b,c,n,t[32];
    printf("enter postfix expression");
    gets(p);
    for(i=0;i<strlen(p);i++)
    {
        j=0;
        if(p[i]==' ')
        continue;
        else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='^')
        {
            a=pop();
            b=pop();
            switch(p[i])
            {
                case '+':c=b+a;;
                         break;
                case '-':c=b-a;
                         break;
                case '*':c=b*a;
                         break;
                case '/':c=b/a;
                         break;
                case '^':c=pow(b,a);
                         break;
            }
            push(c);
        }
        else
        {
            while(p[i]!=' ')
            {
                t[j++]=p[i++];
            }
            t[j]='\0';
            n=atoi(t);
            push(n);
        }
    }
    printf("result=%d",stack[top]);
}
void push(int c)
{
    stack[++top]=c;
}
int pop()
{
    return (stack[top--]);
}