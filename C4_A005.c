#include <stdio.h>
#include <math.h>

int isPrime(int a) {
    if (a < 2)
        return 0;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            return 0;
    return 1;
}

int main(void) {
    int n, a, count = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++) {
        scanf("%d", &a);
        if (isPrime(a) == 1)
            ++count;
    }
    printf("%d", count);
    return 0;
}
