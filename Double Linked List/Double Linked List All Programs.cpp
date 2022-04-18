#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}S;
S *head=NULL, *tail=NULL, *p,*q,*k;
void create();
void insBeg();
void insEnd();
void insAny();
void delBeg();
void delEnd();
void delAny();
void display();
int main()
{
    int opt;
    do{
        printf("Option 1 :create()\n");
        printf("Option 2 :insBeg()\n");
        printf("Option 3 :insEnd()\n");
        printf("Option 4 :insAny()\n");
        printf("Option 5 :delBeg()\n");
        printf("Option 6 :delEnd()\n");
        printf("Option 7 :delAny()\n");
        printf("Option 8 :display()\n");
        printf("Enter Option :\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1 : create();
            break;
            case 2 : insBeg();
            break;
            case 3 : insEnd();
            break;
            case 4 : insAny();
            break;
            case 5 : delBeg();
            break;
            case 6 : delEnd();
            break;
            case 7 : delAny();
            break;
            case 8 : display();
            break;
        }
    }while(opt>=1&&opt<=8);
}
void create()
{
    int x, n, i;
    printf("Enter no.of nodes :\n ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        p=(S*)malloc(sizeof(S));
        printf("Enter the data :\n ");
        scanf("%d", &x);
        p->data=x;
        p->prev=NULL;
        p->next=NULL;
        if(i==1)
            head=tail=p;
        else
        {
            tail->next=p;
            p->prev=tail;
            tail=p;
            tail->next=head;
            head->prev=tail;
        }
    }
}
void insBeg()
{
    int x;
    q=(S*)malloc(sizeof(S));
    printf("Enter the data :\n ");
    scanf("%d", &x);
    q->data=x;
    q->prev=NULL;
    q->next=NULL;
    q->next=head;
    head->prev=q;
    head=q;
    tail->next=head;
     head->prev=tail;
}
void insEnd()
{
    int x;
    q=(S*)malloc(sizeof(S));
    printf("Enter the data :\n");
    scanf("%d", &x);
    q->data=x;
    q->prev=NULL;
    q->next=NULL;
    tail->next=q;
    q->prev=tail;
    tail=q;
     tail->next=head;
     head->prev=tail;
   
}
void insAny()
{
    int x,i=1,pos;
    q=(S*)malloc(sizeof(S));
    printf("Enter the data :\n ");
    scanf("%d", &x);
    q->data=x;
    q->prev=NULL;
    q->next=NULL;
    scanf("%d", &pos);
    printf("Enter the position :\n ");
    p=head;
    while(i<pos)
    {
        k=p;
        p=p->next;
        i++;
    }
    k->next=q;
    q->prev=k;
    q->next=p;
}
void delBeg()
{
    if(head==NULL)
    printf("List is Empty\n");
    else
    {
       p=head;
       head=head->next;
        tail->next=head;
     head->prev=tail;;
       free(p);
    }
}
void delEnd()
{
    if(head==NULL)
    printf("List is Empty\n");
    else
    {
        p=head;
        while(p->next!=head)
        {
            k=p;
            p=p->next;
        }
        tail=k;
        tail->next=head;
     head->prev=tail;
        free(p);
    }
}
void delAny()
{
    int i=1,pos;
    if(head==NULL)
    printf("List is Empty\n");
    else
    {
        p=head;
        printf("Enter Position:-\n");
        scanf("%d",&pos);
        while(i<pos)
        {
            k=p;
            p=p->next;
            i++;
        }
        k->next=p->next;
        p->next->prev=k;
        free(p);
    }
}
void display()
{
    if(head==NULL)
    printf("List is Empty\n");
    else
    {  printf("%d->",head->data);
        for(p=head->next;p!=head;p=p->next)
        {
            printf("%d->",p->data);
        }
        printf("\n");
    }
   
}
