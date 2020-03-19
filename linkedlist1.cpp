#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert();   
void lastinsert();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
int main()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randominsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
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
void beginsert()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("Overflow");
	}
	else
	{	
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("node inserted");
	}
}

void lastinsert()
{
	struct node *ptr;
	struct node *pptr;
	pptr=head;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("overflow");
		
	}
	else
	{
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=NULL;
		while(pptr->next!=NULL)
		{
			pptr=pptr->next;
		}
		pptr->next=ptr;
		
	}
}
void randominsert()
{
	struct node *ptr;
	struct node *pptr;
	pptr=head;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr == NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter the data to be stored\n");
		scanf("%d",&item);
		ptr->data=item;
		printf("Enter the data after which new data is stored");
		scanf("%d",&item);
		while(pptr->data!=item)
		{
			pptr=pptr->next;
		}
		ptr->next=pptr->next;
		pptr->next=ptr;
		
		
	}
}

void begin_delete()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Underflow");
	}
	else
	{
		head=ptr->next;
		printf("deleted node is %d",ptr->data);
		free(ptr);
	}
}

void last_delete()
{
	struct node *ptr;
	struct node *pptr;
	ptr=head;
	pptr=ptr->next;
	if(pptr==NULL)
	{
		printf("Linked list is empty");
		head=NULL;
		free(ptr);
		return;
	}
	if(ptr==NULL)
	{
		printf("Underflow");
	}
	else
	{
		while(pptr->next!=NULL)
		{
			pptr=pptr->next;
			ptr=ptr->next;
		}
		ptr->next=NULL;
		printf("%d is deleted",pptr->data);
		free(pptr);
	}
}

void random_delete()
{
	struct node *ptr;
	struct node *pptr;
	int item;
	ptr=head;
	pptr=ptr->next;
	if(ptr==NULL)
	{
		printf("Underflow");
	}
	else
	{
		printf("Enter the node to be deleted");
		scanf("%d",&item);
		if(ptr->data==item)
		{
			begin_delete();
			return;
		}
		while(pptr->data!=item)
		{
			if(pptr->next==NULL)
			{
				printf("Invalid Deletion\n");
				printf("Please give valid data to delete");
				return;
			}
			pptr=pptr->next;
			ptr=ptr->next;
		}
		ptr->next=pptr->next;
		free(pptr);
	}
}

void search()
{
	struct node *ptr;
	ptr=head;
	int item,count=1;
	bool flag=false;
	if(ptr==NULL)
	{
		printf("List is Empty");
	}	
	else
	{
		printf("Enter the item to be searched\n");
		scanf("%d",&item);
		
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("item found at location %d",count);
				flag=true;
			}
			count++;
			ptr=ptr->next;
		}
		if(flag==false)
		{
			printf("Searched item is not in list");
		}
		
	}
}

void display()
{

    struct node *ptr;  
    ptr = head;  
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 
