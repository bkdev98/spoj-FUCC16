#include <stdio.h>

int main(void) {
    int a[1000000], n, i, max, secondMax, min, secondMin;
    scanf("%d", &n);
    max = 0;
    min = 1000000001;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) {
            secondMax = max;
            max = a[i];
        } else if (a[i] > secondMax)
            secondMax = a[i];
        if (a[i] < min) {
            secondMin = min;
            min = a[i];
        } else if (a[i] < secondMin)
            secondMin = a[i];
    }

    printf("%d %d", secondMax, secondMin);
}
