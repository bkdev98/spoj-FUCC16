#include <stdio.h>

double maxSubArraySum(int a[], int n) {
    double maxSoFar = 0, maxEndingHere = 0;

    for (int i = 0; i < n; i++)
    {
        maxEndingHere = maxEndingHere + a[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main(void) {
    int n, a[100000];
    scanf("%d", &n);
    for (int index = 0; index <= n - 1; index++)
        scanf("%d", &a[index]);
    printf("%.0lf", maxSubArraySum(a, n));
    return(0);
}
