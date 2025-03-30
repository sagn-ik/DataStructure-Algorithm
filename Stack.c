#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int n)
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

void pop()
{
    if(top==-1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        int v=stack[top];
        top--;
        printf("\n Deleted Value: %d\n",v);
    }
}

void peek()
{
    if(top==-1)
    printf("\nUnderflow");
    else
    {
        int n = stack[top];
        printf("\nPeek: %d\n",n);
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
            printf("\n%d",stack[i]);
        }
    }
}
int main()
{
    printf("Enter 1 to push, 2 to pop, 3 to display, 4 to peek, 5 to quit.");
    int ch;
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter value to push: ");
                    int n;
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: peek();
                    break;
            case 5: exit(0);
            default:printf("\nInvalid Input!");
        }
    }
    return 0;   
}