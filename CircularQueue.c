#include <stdio.h>
#include <stdlib.h>
#define size 5
int front=0,rear=0;
int queue[size];

void insert(int n)
{
    if ( ((rear == size)&&(front==0)) || (rear==front && front!=0))
    {
        printf("OverFlow !!\n");
    }
    else
    {
        if(rear<size)
        queue[rear++]=n;
        
        else if(rear==size && front !=0)
        {
            rear=0;
            queue[rear++]=n;
        }
        printf("\n%d",rear);
    }
}

void display()
{
    if(front<rear)
    {
        for(int i=front; i<rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else
    {
        
        for(int i=front; i<size; i++)
        {
            printf("%d ",queue[i]);
        }
        for(int i=0; i<rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void delete()
{
    if(front==0 && rear==0)
    printf("Queue UnderFlow \n");

    else
    {
        printf("Element deleted: %d\n",queue[front++]);
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        if(front==size)
        front=0;
    }
}

int main()
{
    printf("Enter 1 to insert, 2 to del, 3 to display, 4 to quit.");
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
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("\nInvalid Input!");
        }
    }
    return 0;   
}