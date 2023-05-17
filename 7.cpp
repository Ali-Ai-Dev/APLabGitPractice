#include <stdio.h>
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int *p = arr;		  // p=arr[0]
	++*p;				  // arr[0]++ -> arr[0]=2
	p += 2;				  // p=arr[2]
	printf("%d\n", *p);	  // 3
	printf("%d", arr[0]); // 2
	return 0;
}