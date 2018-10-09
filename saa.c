#include<stdio.h>
int main()
{
	int d,i,n,temp,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		d=i;
		while(d>0 && a[d]<a[d-1])
		{
			temp=a[d];
			a[d]=a[d-1];
			a[d-1]=temp;
			d--;
		}
	}
		for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}
