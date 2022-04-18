#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *link;
}s;
s *head=NULL,*tail=NULL,*p;

void create()
{
s*q;
int n,i;
printf("enter number of nodes to be created");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if(head==NULL)
{
p=(s*)malloc(sizeof(s));
printf("enter the data");
scanf("%d",&p->data);
head=p;
tail=p;
p->link=NULL;
}
else
{
 p=(s*)malloc(sizeof(s));
 printf("enter the data");
 scanf("%d",&p->data);
 tail->link=p;
 p->link=NULL;
 tail=p;
}
}
}
void display()
{
for(p=head;p!=NULL;p=p->link)
{
printf("%d\n",p->data);
}
}
void insbeg()
{
p=(s*)malloc(sizeof(s));
printf("enter the data");
scanf("%d",&p->data);
p->link=head;
head=p;
}
void insend()
{
p=(s*)malloc(sizeof(s));
printf("enter the data");
scanf("%d",&p->data);
tail->link=p;
p->link=NULL;
tail=p;
}
void inspos()
{
int x,i;
printf("enter the position to be inserted");
scanf("%d",&x);
s *k,*q;
p=head;
for(i=1;i<x-1;i++)
{
p=p->link;
if(k==NULL)
{
break;
}
}
if(k==NULL)
{
printf("invalid entry");
}
else
{
q=(s*)malloc(sizeof(s));
printf("enter the data");
scanf("%d",&q->data);
   q->link=p->link;
   p->link=q;
}
}
void delbeg()
{
p=head;
head=head->link;
free(p);
}
void delend()
{
for(p=head;p->link!=tail;p=p->link)
{}
tail=p;
p=p->link;
tail->link=NULL;
free(p);
}
void delpos()
{
s *q;
int i,x;
printf("enter position");
scanf("%d",&x);
p=head;
{
for(i=1;i<x-1;i++)
{
p=p->link;
if(p==NULL)
{
break;
}
}
if(p==NULL)
{
printf("invalid pos");
}
else
{
q=p->link;
p->link=q->link;
free(q);
}
}
}
void rev()
{
s *q,*r;
p=head;
q=p->link;
r=q->link;
while(tail->link==0)
{
q->link=p;
p=q;
q=r;
printf("b\n");
if(r!=tail)
r=r->link;
printf("a\n");
}

head->link=NULL;
p=tail;
tail=head;
head=p;
}

 int main()
{
int n;
while(1)
{
	printf("1.create\n 2.insbeg\n 3.insend\n 4.inspos\n 5.delbeg\n 6.delend\n 7.delpos\n 8.display\n 9.exit \n");
       scanf("%d",&n);
         switch(n)
          {
            case 1:

create();
break;
   
   case 2:
    
   insbeg();
   break;
   
case 3:

   insend();
break;
   
case 4:

   inspos();
break;
   
case 5:

   delbeg();
break;
   
case 6:

   delend();
break;  
   
case 7:

   delpos();
break;
   
case 8:

   display();
break;
   
   case 9:
    
   exit(0);
   break;
   
   case 10:
   
    rev();
break;

default:

   printf("invalid entry");

}
}
}
