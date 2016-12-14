#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b) {
    long long temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    long long n;
    long long a[100000], b[100000];
    long long hcf;
    long long lcm;
    scanf("%lld", &n);
    for (long long i = 0; i <= n - 1; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
    }
    for (long long i = 0; i <= n - 1; i++) {
        hcf = gcd(a[i], b[i]);
        lcm = (a[i] * b[i]) / hcf;
        printf("%lld %lld\n", hcf, lcm);
    }
    return 0;
}
