#include<stdio.h>
int main()
{
	int x[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\nenter element at x[%d][%d] : ",i,j);
			scanf("%d",&x[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",x[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
//#include <stdio.h>  
//void main ()  
//{  
//    int arr[3][3],i,j;   
//    for (i=0;i<3;i++)  
//    {  
//        for (j=0;j<3;j++)  
//        {  
//            printf("Enter a[%d][%d]: ",i,j);              
//            scanf("%d",&arr[i][j]);  
//        }  
//    }  
//    printf("\n printing the elements ....\n");   
//    for(i=0;i<3;i++)  
//    {  
//        printf("\n");  
//        for (j=0;j<3;j++)  
//        {  
//            printf("%d\t",arr[i][j]);  
//        }  
//    }  
//}  
