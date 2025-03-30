#include <stdio.h>
#include <stdlib.h>
#define size 5
int front=0,rear=0;
int queue[size];

void insert(int n)
{
    if(rear == size)
    {
        printf("OverFlow !!\n");
    }
    else
    {
        queue[rear++]=n;
    }
}

void del()
{
    if(rear == 0)
    printf("UnderFlow !!\n");
    else
    {
        int v=queue[front++];
        printf("Removed %d\n",v);
        if(front == rear)
        {
            front=0;
            rear=0;
        }
    }
}

void show()
{
    int i;
    if(rear==0)
    printf("\nUnderflow!!");
    else
    {
        for(i=front;i<rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}

int main()
{
    printf("Enter 1 to insert, 2 to del, 3 to display, 5 to quit.");
    int ch;
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter value to insert: ");
                    int n;
                    scanf("%d",&n);
                    insert(n);
                    break;
            case 2: del();
                    break;
            case 3: show();
                    break;
            case 4: exit(0);
            default:printf("\nInvalid Input!");
        }
    }
    return 0;   
}