#include <stdio.h>

int main(void) {
    int a,b;
    scanf("%d %d", &a, &b);
    int t = a;
    a = b;
    b = t;
    printf("%d %d", a, b);
    return 0;
}
