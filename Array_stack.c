#include <stdio.h>   
int stack[100],i,j,choice=0,n=0,top=-1;  
void push();  
void pop();  
void show();  
void main ()  
{  
      
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n);  
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
	if(top==n-1)
	{
		printf("StackOverflow\n");
	}
	else
	{
		int item;
		printf("Enter element to push");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
}

void pop()
{
	if(top<0)
	{
		printf("StackUnnderflow......\n");
	}
	else
	{
		printf("popped element: %d\n",stack[top]);
		top--;
	}
}
void show()
{
	if(top<0)
	{
		printf("stack is empty........\n");
	}
	else
	{
		printf("printing stack.....\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
