#include <stdio.h>
#include <math.h>

int main(void) {
    int h, w, s;
    unsigned long long max = 0;
    scanf("%d %d %d", &h , &w, &s);

    int i = h, j = w;

    while (i >= 1 && j >= 1) {
        unsigned long long mul = i * j;
        if (mul <= s) {
            max = mul;
            break;
        };
        if (i > j)
            i = i - 1;
        else
            j = j - 1;
    };

    printf("%llu", max);
    return 0;
}
