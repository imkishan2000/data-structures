#include<stdio.h>  
#include<stdlib.h> 
#include<stdbool.h> 
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert ();   
void begin_delete();  
void last_delete();    
void display();  
void search();  
void main ()  
{  
    int choice =0;  
    while(choice != 7)   
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");  
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
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
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

void beginsert()
{
	struct node *ptr,*pptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("OverFlow");
		
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			pptr=head;
			while(pptr->next!=head)
			{
				pptr=pptr->next;
			}
			pptr->next=ptr;
			ptr->next=head;
			head=ptr;
			
		}
	}
}

void lastinsert ()
{
	struct node *ptr,*pptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("Enter the element to be stored: ");
		scanf("%d",&item);
		ptr->data=item;
		pptr=head;
		while(pptr->next!=head)
		{
			pptr=pptr->next;
		}
		pptr->next=ptr;
		ptr->next=head;
	}
}

void begin_delete()
{
	struct node *ptr,*pptr;
	ptr=head;
	if(head==NULL)
	{
		printf("No element to delete");
		return;
	}
	else if(ptr->next==head)
	{
		printf("%d is deleted",head->data);
		free(ptr);
		head=NULL;
		return;
	}
	else
	{
		pptr=head->next;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->next=pptr;
		head=pptr;
	}
}

void last_delete()
{
	struct node *ptr,*pptr;
	ptr=head;
	if(head==NULL)
	{
		printf("No element to delete");
		return;
	}
	else if(ptr->next==head)
	{
		printf("%d is deleted",ptr->data);
		head=NULL;
		free(ptr);
	}
	else
	{
		pptr=ptr->next;
		while(pptr->next!=head)
		{
			ptr=ptr->next;
			pptr=pptr->next;
		}
		ptr->next=head;
		printf("%d id deleted",pptr->data);
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
		
		while(ptr->next!=head)
		{
			if(ptr->data==item)
			{
				printf("item found at location %d\n",count);
				flag=true;
			}
			count++;
			ptr=ptr->next;
		}
		if(ptr->data==item)
		{
			printf("item found at location %d",count);
			flag=true;
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
	ptr=head;
	if(ptr==NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("printing values....\n");
		while(ptr->next!=head)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}
