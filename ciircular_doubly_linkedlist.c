#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void deletion_beginning();  
void deletion_last();  
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
        printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search\n6.Show\n7.Exit\n");  
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
            deletion_beginning();  
            break;  
            case 4:  
            deletion_last();  
            break;  
            case 5:  
            search();  
            break;  
            case 6:  
            display();  
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  

void insertion_beginning()
{
	struct node *ptr,*pptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter the element to store: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
					ptr->prev=ptr;
					ptr->next=ptr;
					head=ptr;
					return;
		}	
		else
		{
			pptr=head;
			while(pptr->next!=head)
			{
				pptr=pptr->next;
			}
			pptr->next=ptr;
			ptr->prev=pptr;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
	}
	
}

void insertion_last()
{
	insertion_beginning();
	head=head->next;
}

void deletion_beginning()
{
	struct node *ptr,*pptr;
	if(head==NULL)
	{
		printf("Sorry! List is empty no element to delete......");
	}
	else if(head->next==head)
	{
		printf("%d is deleted",head->data);
		free(head);
		head=NULL;
	}
	else
	{
		ptr=head->next;
		pptr=head->prev;
		ptr->prev=pptr;
		pptr->next=ptr;
		printf("%d is deleted",head->data);
		free(head);
		head=ptr;	
	}
	
}

void deletion_last()
{
	struct node *ptr,*pptr;
	if(head==NULL)
	{
		printf("Sorry! List is empty no element to delete......");	
	}
	else if(head->next==head)
	{
		printf("%d is deleted",head->data);
		free(head);
		head=NULL;
	}
	else
	{
		ptr=head->prev;
		pptr=ptr->prev;
		pptr->next=head;
		head->prev=pptr;
		printf("%d is deleted",ptr->data);
		free(ptr);
	}
}

void search()
{
	struct node *ptr;
	int item,count=1,flag=0;
	ptr=head;
	if(head==NULL)
	{
		printf("Sorry! List is empty......");
		return;
	}
	printf("Enter the element to search: ");
	scanf("%d",&item);
	while(ptr->next!=head)
	{
		if(ptr->data==item)
		{
			printf("position of searched element is %d\n",count);
			flag=1;
		}
		ptr=ptr->next;
		count++;
	}
	if(ptr->data==item)
		{
			printf("position of searched element is %d\n",count);
			flag=1;
		}
	if(!flag)
	{
		printf("Soory! searched element is not in list......");
	}
	
}

void display()
{
	struct node* ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Circular Doubly LinkList is Empty.....");
	}
	else
	{
		printf("Printing list elements.......\n");
		while(ptr->next!=head)
		{
			printf("%d --> ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}
