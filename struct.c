#include<stdio.h>
struct employee
{
	int id;
	float salary;
	int mobile;
};
int main()
{
	struct employee e1,e2,e3;
	printf ("\nEnter ids, salary & mobile no. of 3 employee\n"); 
	scanf ("%d %f %d", &e1.id, &e1.salary, &e1.mobile);  
	scanf ("%d %f %d", &e2.id, &e2.salary, &e2.mobile);  
	scanf ("%d %f %d", &e3.id, &e3.salary, &e3.mobile);  
	printf ("\n Entered Result ");  
	printf ("\n%d %f %d", e1.id, e1.salary, e1.mobile);  
	printf ("\n%d%f %d", e2.id, e2.salary, e2.mobile);  
	printf ("\n%d %f %d", e3.id, e3.salary, e3.mobile);  
}
