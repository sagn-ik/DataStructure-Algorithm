// Program in C to implement sorting operation in a single liked list.

#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *nxt;

}node;

void create(node **root)
{
    node *p, *q;
    p=(node *)malloc(sizeof(node));
    printf("Enter value:\t");
    scanf("%d", &p->data);
    p->nxt = NULL;
    if(*root == NULL)
    {
        *root =p;
    }
    else
    {
        for(q=*root; q->nxt != NULL; q=q->nxt);
        {
            q->nxt=p;
        }
    }
}

void display(node *root)
{
    node *p;
    p=root;
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->nxt;
    }
}

void sort(node *root)
{
    node *p=root;
    node *q;
    int temp;
    while(p!=NULL)
    {
        q=p->nxt;
        while(q!=NULL)
        {
            if((p->data)>(q->data))
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->nxt;
        }
        p=p->nxt;
    }
    display(root);
}


int main()
{
    node *root=NULL;
    int ch,num,pos;
    do
    {
        printf("\n 0. Exit\n");
        printf("\n 1. Create\n");
        printf("\n 2. Display\n");
        printf("\n 3. Sort\n");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create(&root);
                    break;
            case 2: display(root);
                    break;
            case 3: sort(root);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Invalid command");
        }

    }
    while(1);
    return 0;
}