#include<stdio.h>

const char *f(const char **p) {
    auto q = (p + sizeof(char))[1];
    return q;
}

int main() {
    const char *str[] = {"Wish", "You", "Best", ":D"};

    printf("%s %s\n", f((str) - 2), f(str - 1));
    printf("%s %s %s %s\n", *str, (*(str + 1)), *((str + 1) + 1), *(str + 3));
}
