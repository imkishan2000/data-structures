#include <stdio.h> 
#include<stdlib.h>  
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void push();  
void pop();  
void show();  
void main ()  
{  

	int choice;  
    printf("*********Stack operations using array*********");  
  
printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
}

void push()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("StackOverFlow\n");
	}
	else
	{
		printf("Enter the data to push: ");
		scanf("%d",&item);
		ptr->data=item;
//		if(head==NULL)
//		{
//			ptr->next=NULL;
//			head=ptr;
//			return;
//			
//		}
//		else
//		{
//			ptr->next=head;
//			head=ptr;
//		}
		ptr->next=head;
		head=ptr;
	}
	
	
}

void pop()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("StackUnderFlow\n");
	}
	else
	{
		ptr=head;
		printf("%d is popped\n",ptr->data);
		head=head->next;
		free(ptr);
		
	}
}

void show()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("Stack is Empty");
	}
	else
	{
		printf("printing values of stack.........\n");
		ptr=head;
		while(ptr->next!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
}
