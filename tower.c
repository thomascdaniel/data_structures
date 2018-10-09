#include<stdio.h>
#include<math.h>
void tower(int,char,char,char);
int main()
{
	int num;
	printf("Enter number of disk\t");
	scanf("%d",&num);
	tower(num,'A','B','C');
	int a=(pow(2,num)-1);
		printf("\nTotal Number of steps is %d",a);
	
	getch();

	
}
void tower(int n, char a, char b, char c)
{ 
	
	if(n==1)
	{
	printf("\nDisk move from %c to %c",a,c);
	return ;	
	}
	
	
	tower(n-1,a,c,b); //recurssive function
	printf("\nDisk move form %c to %c",a,c);
	tower(n-1,b,a,c); //recurssive function
	
	
}
