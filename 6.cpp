#include <stdio.h>
int main()
{
	int a;
	char *x;
	x = (char *)&a; // changing int* to char*
	a = 512;		// a will look like this:0000 0010 0000 0000
	//       x looks like an array like this:x[3] x[2] x[1] x[0]
	x[0] = 1; // now look like               0000 0010 0000 0001
	printf("%d\n", a);
	return 0;
}
