﻿#include <stdio.h>
const char *f(const char **p)
{
	auto q = (p + sizeof(char))[1]; // q = p+2
	return q;
}
int main()
{
	const char *str[] = {"Wish", "You", "Best", ":D"};
	printf("%c%c ", *f(str), *(f(str) + 1)); // Be
	printf("%c%c%c%c\n", **str, *(*(str + 1) + 1), *((str + 2)[-1] + 1), **&*(&str[-1] + 1));
	//-----------------str[0][0]----str[1][1]--------str[2-1][1]--------**&*(&str)->**str
}
