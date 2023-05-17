#include <stdio.h>
int main()
{
	int a;
	char *x;
	x = (char *)&a;
	a = 512;
	x[0] = 1;
	printf("%d\n", a);
	return 0;
}

// this code, sum's two numbers (a & x) binarical. for example 1000000000 (512) + 1 (1) = 1000000001 (513)

// output : 513