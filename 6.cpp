#include<stdio.h>
int main()
{
	int a;
	a = 512;
	char* x;
	x = (char*)&a;
	x[0] = 1;
	printf("%d\n", a);
	return 0;
}