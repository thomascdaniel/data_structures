#include<stdio.h>
#include<conio.h>

 
int main()
{
   int array_point[100], n, c, d, position, swap;
 
   printf("Enter number of elements\n");
   scanf("%d", &n);
 
   printf("Enter %d integers\n", n);
 
   for ( c = 0 ; c < n ; c++ )
      scanf("%d", &array_point[c]);
 
   for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ ) // d is the element which is storing the new value 
      {
         if ( array_point[position] > array_point[d] )
            position = d;
      }
      if ( position != c )
      {
         swap = array_point[c];
         array_point[c] = array_point[position];
         array_point[position] = swap;
      }
   }
 
   printf("Sorted list in ascending order:\n");
 
   for ( c = 0 ; c < n ; c++ )
      printf("%d\n", array_point[c]);
 
   return 0;
}
