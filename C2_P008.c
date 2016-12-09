#include <stdio.h>

int main(void) {
    int i, j, k, l, m, n, o, p;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        for (j = n - i; j >= 1; j--)
            printf(" ");
        for (l = 0; l <= i; l++)
            printf("%d", l);

        if (i > 0)
            for (p = i - 1; p >= 0; p--)
                  printf("%d", p);
        for (o = n - i; o >= 1; o--)
            printf(" ");
        printf("\n");
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf(" ");
        for (k = 0; k <= n - i; k++)
            printf("%d", k);
        for (l = n - 1 - i; l >= 0; l--)
            printf("%d", l);
        printf("\n");
    }

    return 0;
}
