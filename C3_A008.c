#include <stdio.h>

int main(void) {
    int m, n, a[1000][1000], b[1000][1000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n - 1; i++)
        for (int j = 0; j <= m - 1; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i <= n - 1; i++)
        for (int j = 0; j <= m - 1; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= m - 1; j++)
            printf("%d ", a[i][j] + b[i][j]);
        printf("\n");
    }
}
