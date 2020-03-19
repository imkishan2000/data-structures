#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *front,*rear;
void insert();
void delete();
void show();

void main()
{
	int choice;
	 printf("\n*********Main Menu*********\n"); 
	printf("\nEnter your choice:");
	printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit");
	while(choice!=4)
	{
		printf("\nEnter your choice: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
		
			case 2:
				delete();
				break;
		
			case 3:
				show();
				break;
		
			case 4:
				exit(0);
				
			default:
				printf("\nInvalid choice..");
				break;				
		}
	}
}

void insert()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Queue OverFlow");
	}
	else
	{
		printf("Enter element to enter: ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=NULL;
		if(rear==NULL)
		{
			front=ptr;
			rear=ptr;
		}
		else
		{
			rear->next=ptr;
			rear=rear->next;
		}
	}
}

void delete()
{
	struct node *ptr;
	if(front==NULL)
	{
		printf("Queue is empty");
	}
	else if(front==rear)
	{
		printf("\n%d is deleted",front->data);
		front=NULL;
		rear=NULL;
	}
	else
	{
		ptr=front;
		front=front->next;
		printf("\n%d is deleted",ptr->data);
		free(ptr);
	}
}

void show()
{
	struct node *ptr;
	if(front==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Printing Queue......\n");
		ptr=front;
		while(ptr->next!=NULL)
		{
			printf("%d  <<-- ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}
