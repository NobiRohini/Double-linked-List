#include<stdio.h>
#include<stdlib.h>   
void create();
void display();
void insert_begin();
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*start=NULL;
int main()      
{
        int choice;
        while(1){
                printf("\n*double LINKED LIST OPERATIONS:\n");
                printf("\n                MENU                             \n");
                printf("---------------------------------------\n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);


  switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                        	insert_begin();
                        	break;
                       
                        case 4:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void display()
{
	struct node*p;
	p=start;
	if(start==NULL)
	{
		printf("empty");
	}
	else
	{
	 for(p=start;p!=NULL;p=p->next)
	 {
	 	printf("%d",p->data);
	 }
	}
}

void create()
{
	   struct node *newnode,*ptr;
        newnode=(struct node *)malloc(sizeof(struct node));
    int ele;
    scanf("%d",&ele);
    newnode->data=ele;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(start==NULL)
        {
                start=newnode;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=newnode;
                newnode->prev=ptr;
        }
}
void insert_begin()
{
	   struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
    int ele;
    scanf("%d",&ele);
    newnode->data=ele;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(start==NULL)
        {
                start=newnode;
        }
        else
        {
                newnode->next=start;
                start->prev=newnode;
                start=newnode;
        }
}
