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
        p->nxt = *root;
    }
    else
    {
        for(q=*root; q->nxt != *root; q=q->nxt);
        {
            q->nxt=p;
            p->nxt = *root;
        }
    }
}

void display(node *root)
{
    node *p;
    p=root;
    do
    {
        printf("%d \t",p->data);
        p=p->nxt;
    }
    while(p!=root);
}

void del(node **root, int ex)
{
    node *q, *c;
    if((*root)->data==ex)
    {
        for(c=*root; c->nxt!=*root;c=c->nxt);
        q=(*root);
        *root=q->nxt;
        c->nxt=*root;
        free(q);
    }
    else
    {
        for(c=*root, q=(*root)->nxt; q->nxt!=*root; c=c->nxt,q=q->nxt);
            if(q->data==ex)
            {
                c->nxt=*root;
                free(q);
            }
        for(c=*root, q=(*root)->nxt; q->nxt!=*root; c=c->nxt,q=q->nxt)
        {
        if(q->data==ex)
        {
            c->nxt=q->nxt;
            free(q);
            break;
        }
        }
                
            
        }
    }

void insert_b(node **root, int ex, int ne)
{
    node *p, *q, *c;
    p=(node*) malloc(sizeof(node));
    p->data=ne;
    for(c=*root,q=(*root)->nxt;q->nxt!=*root;c=c->nxt,q=q->nxt);
    c=c->nxt;
    if((*root)->data==ex)
    {
        q=*root;
        *root=p;
        p->nxt=q;
        c->nxt=p;
    }
    else
    {
        for(c=*root,q=(*root)->nxt;q->nxt!=*root;c=c->nxt,q=q->nxt);
        if(q->data==ex)
        {
            p->nxt=q;
            c->nxt=p;
            q->nxt=*root;
        }
        else
        {
            for(c=*root,q=(*root)->nxt;q->nxt!=*root;c=c->nxt,q=q->nxt)
            if(q->data==ex)
            {
                p->nxt=q;
                c->nxt=p;
                p->nxt->nxt=q->nxt;
            }
        }
    }
}

void ins_after(node **root, int ex, int ne)
{
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->data=ne;
    if((*root)->data==ex)
    {
        q=(*root)->nxt;
        (*root)->nxt=p;
        p->nxt=q;
    }
    else
    {
        for(q=*root; q->nxt!=*root; q=q->nxt);
        if(q->data==ex)
        {
            q->nxt=p;
            p->nxt=*root;
        }
        else
        {
            for(q=*root; q->nxt!=*root; q=q->nxt)
            {
                if(q->data==ex)
                {
                    p->nxt=q->nxt;
                    q->nxt=p;
                }
            }
        }
    }
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
        printf("\n 3. Insert Before\n");
        printf("\n 4. Insert After\n");
        printf("\n 5. Delete\n");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create(&root);
                    break;
            case 2: display(root);
                    break;
            case 3: printf("Enter number to be inserted: \n");
                    scanf("%d",&num);
                    int temp;
                    printf("Enter where to insert: \n");
                    scanf("%d",&temp);
                    insert_b(&root,temp,num);
                    break;
            case 4: printf("Enter value to insert: ");
                    scanf("%d",&num);
                    int pos;
                    printf("Enter where to insert: ");
                    scanf("%d",&pos);
                    ins_after(&root,pos,num);
                    break;
            case 5: printf("Enter Element to delete: ");
                    scanf("%d",&num);
                    del(&root,num);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Invalid command");
        }

    }
    while(1);
    return 0;
}