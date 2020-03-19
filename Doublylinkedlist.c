#include<stdio.h>  
#include<stdlib.h>  
#include<stdbool.h>
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
                    insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
} 
void insertion_beginning()
{
	struct node *ptr;
	int item;
	ptr=head;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("OverFlow Condition");
	}
	else
	{
		printf("Enter the data to stored : ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->prev=NULL;
		ptr->next=head;
		head=ptr;
		
	}
}

void insertion_last()
{
	struct node *ptr,*pptr;
	int item;
	pptr=head;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter the data to stored : ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=NULL;
		while(pptr->next!=NULL)
		{
			pptr=pptr->next;
		}
		ptr->prev=pptr;
		pptr->next=ptr;
	}
}

void insertion_specified()
{
	struct node *ptr,*pptr,*rptr;
	int item;
	pptr=head;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Overflow");
	}
	else
	{
		
		printf("Enter the element after you want to insert new node\n");
		scanf("%d",&item);
		while(pptr->data!=item)
		{
			if(pptr->next==NULL)
			{
				printf("No node after you want to store");
				return;
			}
			pptr=pptr->next;
		}
		rptr=pptr->next;
		rptr->prev=ptr;
		pptr->next=ptr;
		ptr->prev=pptr;
		ptr->next=rptr;
		printf("Enter the element to store");
		scanf("%d",&item);
		ptr->data=item;
		
	}
}
void deletion_beginning()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	else if(head->next==NULL)
	{
		printf("%d is deleted",head->data);
		free(head);
		head=NULL;
		return;
	}
	ptr=head->next;
	ptr->prev=NULL;
	printf("%d is deleted",head->data);
	free(head);
	head=ptr;
	
}

void deletion_last()
{
	struct node *ptr,*pptr;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	else if(head->next==NULL)
	{
		printf("%d is deleted",head->data);
		free(head);
		head=NULL;
		return;
	}
	pptr=head->next;
	ptr=head;
	while(pptr->next!=NULL)
	{
		pptr=pptr->next;
		ptr=ptr->next;
	}
	ptr->next=NULL;
	printf("%d is deleted",pptr->data);
	free(pptr);
}
void deletion_specified()
{
	struct node *pptr,*ptr,*fptr;
	int item;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	else if(head->next==NULL)
	{
		printf("Enter the element to be deleted");
		scanf("%d",&item);
		if(item!=head->data)
		{
			printf("Entered element is not in list");
			return;
		}
		printf("%d is deleted",head->data);
		free(head);
		head=NULL;
		return;
	}
	pptr=head;
	ptr=head->next;
	if(ptr->next==NULL)
	{
		printf("Enter the element to be deleted");
		scanf("%d",&item);
		if(item!=pptr->data && item!=ptr->data)
		{
			printf("Entered element is not in list");
			return;
		}
		if(item==pptr->data)
		{
			ptr->prev=NULL;
			head=ptr;
			printf("%d is deleted",pptr->data);
			free(pptr);
			return;
		}
		else if(item==ptr->data)
		{
			pptr->next=NULL;
			printf("%d is deleted",ptr->data);
			free(ptr);
			return;
		}
	}
	fptr=ptr->next;
	printf("Enter the element to be deleted");
	scanf("%d",&item);
	if(pptr->data==item)
	{
		ptr->prev=NULL;
		head=ptr;
		printf("%d is deleted",pptr->data);
		free(pptr);
		return;
	}
	while(ptr->data!=item)
	{
		if(fptr->next==NULL && fptr->data==item)
		{
			ptr->next=NULL;
			printf("%d is deleted",fptr->data);
			free(fptr);
			return;
		}
		if(fptr->next==NULL)
		{
			printf("Invalid input");
			return;
		}
		fptr=fptr->next;
		ptr=ptr->next;
		pptr=pptr->next;
	}
	pptr->next=fptr;
	fptr->prev=pptr;
	printf("%d is deleted",ptr->data);
	free(ptr);
}
void search()
{
	struct node *ptr;
	int item,count=1;
	bool flag=false;
	ptr=head;
	printf("Enter the element to search");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		
		if(ptr->data==item)
		{
			printf("element is at position %d",count);
			flag=true;
		}
		count++;
		ptr=ptr->next;
	}
	if(!flag)
	{
		printf("Invalid element");
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		printf("Printing elements of DoublyLinked List:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
