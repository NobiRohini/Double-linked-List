void insert at specific position()
{
	struct node*newnode,*ptr;
	int elements,position,i;
	printf("\n enter elements to be inserted");
	scanf("%d",&elements);
	printf("\n enter position after which node is to be inserted");
	scanf("%d",&position);
	newnode=(struct node*)malloc(size of (struct node));
	newnode->data=elements;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(start==NULL);
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		for(i=1;i<position;i++)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next->prev=newnode;
		newnode->prev=ptr;
		ptr->next=newnode;
	}
}
