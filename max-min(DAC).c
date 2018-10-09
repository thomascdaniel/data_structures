#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],n,max,min,i;
	printf("Enter the size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("\nEnter element[%d]:",i+1);
			scanf("%d",&a[i]);
		}
	max=min=a[0];	
	for(i=0;i<n;i++)
		{
		   if(a[i]<min)
			{
			  min=a[i];
			}
			if(a[i]>max)
				{
					max=a[i];	
				}
		}
		printf("\n The min value is:%d",min);
		printf("\n The max value is:%d",max);
}
