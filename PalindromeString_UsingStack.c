#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define SIZE 3
char stack[SIZE];
int top=-1;
void push(char n)
{
    if(top==SIZE-1)
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        char v=stack[top];
        top--;
        return v;
    }
}

void show()
{
    int i;
    if(top==-1)
    printf("\nUnderflow!!");
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%c",stack[i]);
        }
    }
}

int main()
{
    char wd[10];
    printf("Enter a word: \n");
    scanf("%s",&wd);
    int flag=0,stat=1;
    char ch=wd[flag++];
    while(ch!=NULL)
    {
        push(ch);
        ch=wd[flag++];
    }
    flag=0;
    ch=wd[flag++];
    while(ch!=NULL)
    {
        char temp=pop();
        if(ch!=temp)
        stat=0;
        ch=wd[flag++];
    }
    if(stat==1)
    printf("GIVEN WORD IS PALINDROME !!!");
    else
    printf("GIVEN WORD IS NOT A PALINDROME!!!");
    return 0;   
}
