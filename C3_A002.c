#include <stdio.h>

int sumOfDigit(int a) {
    int b = 0;
    while (a != 0) {
        b += a % 10;
        a /= 10;
    }
    return b;
}

int main(void) {
    int a[1000000], n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
        printf("%d ", sumOfDigit(a[i]));
    return 0;
}
