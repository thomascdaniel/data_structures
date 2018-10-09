#include<stdio.h>
#include<conio.h>

int main()
	{
   		int a[100], linear, c, n;
 
	   printf("Enter the number of elements in a\n");
   		scanf("%d",&n);
 
	   printf("Enter %d integer(s)\n", n);
 
   			for (c = 0; c < n; c++) /*How much number you want to print*/
      		scanf("%d", &a[c]);
 
		   printf("Enter the number to searched\n");
   			scanf("%d", &linear);
 
		   for (c = 0; c < n; c++)
   				{
      				if (a[c] == linear)     /* if the required element found */
      					{
         					printf("%d is present at location %d.\n", linear, c+1);
         					break;
      					}
   				}
   
   
	   	if (c == n)
    	  printf("%d is not present in a.\n", linear);
 
   return 0;
	}
