#include<stdio.h>


int main()
{

    int a[10],i,n,m,c=0,f,l,mid;

    printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the elements in ascending order: ");
    for(i=0;i<n;i++)
	{
         scanf("%d",&a[i]);
    }

    printf("Enter the number to be search: ");
    scanf("%d",&m);

    f=0,l=n-1;
    while(f<=l)
	{
         mid=(f+l)/2;
         if(m==a[mid]) /* for getting the middle value*/
		 {
             c=1; /* Count for the elements*/
             break;
         }
         else if(m<a[mid]) /*Searching Key is less than the mid element*/
		 {
             l=mid-1;
         }
         else
             f=mid+1;
    }
    if(c==0)
         printf("The number is not found.");
    else
         printf("The number is found.");

    return 0;
}
