// Program in C to show various operations in a Double liked list.
// Demonstating following functions: Create, Delete, Display, Insert After and Insert Delete.

#include <stdlib.h>
#include <stdio.h>
typedef struct Node   // self referential structure
{
    int data;
    struct Node *nxt;   // address of the next node
    struct Node *prev;  //address of previous node

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
        p->prev= NULL;
        *root =p;        
    }
    else
    {
        for(q=*root; q->nxt != NULL; q=q->nxt);
        {
            p->prev=q;
            q->nxt=p;

        }
    }
}

void display(node *root)
{
    node *p;
    p=root;
    if(p==NULL)
    printf("List is empty\n");
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->nxt;
    }
    
}

void insert_b(node **root, int ex, int ne)
{
    node *p, *q, *c;
    p=(node*) malloc(sizeof(node));
    p->data=ne;
    if((*root)->data==ex)
    {
        q=*root;
        q->prev=p;
        p->prev = NULL;
        *root=p;
        p->nxt=q;
    }
    else
    {
        for(c=*root,q=(*root)->nxt;q->nxt!=NULL;c=c->nxt,q=q->nxt);
        if(q->data==ex)
        {
            p->nxt=q;
            p->prev=c;
            c->nxt=p;
            q->prev=p;
            q->nxt=NULL;
        }
        else
        {
            for(c=*root,q=(*root)->nxt;q->nxt!=NULL;c=c->nxt,q=q->nxt)
            if(q->data==ex)
            {
                p->nxt=q;
                p->prev=c;
                c->nxt=p;
                q->prev=p;
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
        p->prev=(*root);
        q->prev=p;
    }
    else
    {
        for(q=*root; q->nxt!=NULL; q=q->nxt);
        if(q->data==ex)
        {
            q->nxt=p;
            p->prev=q;
            p->nxt=NULL;
        }
        else
        {
            for(q=*root; q->nxt!=NULL; q=q->nxt)
            {
                if(q->data==ex)
                {
                    p->nxt=q->nxt;
                    p->prev=q;
                    q->nxt=p;
                }
            }
        }
    }
}

void del(node **root, int ex)
{
    node *q, *c;
    if((*root)->data==ex)
    {
        q=(*root)->nxt;
        q->prev = NULL;
        free(*root);
        *root=q;
    }
    else
    {
        for(c=*root, q=(*root)->nxt; q->nxt!=NULL; c=c->nxt,q=q->nxt);
        if(q->data==ex)
        {
            c->nxt=NULL;
            free(q);
        }
        else
        {
            for(c=*root, q=(*root)->nxt; q->nxt!=NULL; c=c->nxt,q=q->nxt)
            if(q->data==ex)
            {
                c->nxt=q->nxt;
                q->nxt->prev=c;
                free(q);
                break;
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
            case 3: printf("Enter value to insert: ");
                    scanf("%d",&num);
                    printf("Enter where to insert: ");
                    scanf("%d",&pos);
                    insert_b(&root,pos,num);
                    break;
            case 4: printf("Enter value to insert: ");
                    scanf("%d",&num);
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
