#include<stdio.h>
int summition(int a[]);
void main()
{
	int arr[6]={4,5,6,7,8,90};
	int sum=summition(arr);
	printf("%d",sum);
}
int summition(int a[])
{
	int i;
	int sum=0;
	for(i=0;i<6;i++)
	{
		sum=sum+a[i];
	}
	return(sum);
}
