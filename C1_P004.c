#include <stdio.h>

int main(void) {
    int w, h, a;
    scanf("%i %i %i", &w, &h, &a);
    int m = 1, n = 1;
    while (m*a < w)
        m++;
    while (n*a < h)
        n++;
    if ((1 <= w) && (1 <= h) && (1 <= a) && (a <= 100) && (w <= 100) && (h <= 100)) {
        printf("%i",m*n);
    } else
        printf("Error");
    return 0;
}
