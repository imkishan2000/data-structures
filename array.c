void main()
{
	int marks[6]={28,15,26,24,21,24};
	int i;
	float avg=0;
	for(i=0;i<6;i++)
	{
		avg=avg+marks[i];
	}
//	avg=avg/6;
	printf("%f",avg/6);
}
