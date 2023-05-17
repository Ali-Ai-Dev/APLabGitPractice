#include <iostream>
#include<stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("%d\n", (*ptr2 - *ptr1));
    printf("%c%c", ((*ptr2 - *ptr1) / 10) + '0', ((*ptr2 - *ptr1) % 10) + '0');
//    std::cout << (*ptr2 - *ptr1);
    return 0;
}