#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    int n;
    int a[100000], b[100000];
    int lcm, hcf;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i <= n - 1; i++) {
        hcf = gcd(a[i], b[i]);
        lcm = (a[i] * b[i]) / hcf;
        printf("%d %d\n", hcf, lcm);
    }
    return 0;
}
