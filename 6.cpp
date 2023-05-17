#include<stdio.h>

int main() {
    int a;
    char *x;
    x = (char *) &a;
    a = 512;
    x[1] = 2;
    printf("%d\n", a);
    return 0;
}
