#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;                     //--*ptr1=arr[0];
    int *ptr2 = arr + 5;                 //--*ptr2=arr[0+5];
    printf("%d\n", (*ptr2 - *ptr1));     // 60-10
    printf("%c", (char)(*ptr2 - *ptr1)); // 50 is equal to '2' charchtor in ASCI code
    return 0;
}