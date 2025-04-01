// Program in C to show stack operations using a single liked list.

#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *nxt;   
}node;

void push(node **root)
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
    if(p==NULL)
    printf("Stack is empty\n");
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->nxt;
    }
    
}

void pop(node **root)
{
    node *q, *c;
    if(*root==NULL)
    {
        printf("Stack UnderFlow !!\n");
    }
    else if((*root)->nxt==NULL)
    {
        printf("Element Popped: %d\n",(*root)->data);
        *root=NULL;
    }
    else
    {
        for(c=*root, q=(*root)->nxt; q->nxt!=NULL; c=c->nxt,q=q->nxt);
        c->nxt=NULL;
        printf("Element Popped: %d\n",q->data);
        free(q);
    }
}

int main()
{
    node *root=NULL;
    int ch,num,pos;
    do
    {
        printf("\n 0. Exit\n");
        printf("\n 1. Push\n");
        printf("\n 2. Display\n");
        printf("\n 3. Pop\n");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(&root);
                    break;
            case 2: display(root);
                    break;
            case 3: pop(&root);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Invalid command");
        }

    }
    while(1);
    return 0;
}