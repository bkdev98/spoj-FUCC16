#include <stdio.h>

int main(void) {
    int n, count = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", count);
            ++count;
        }
        printf("\n");
    }
    return 0;
}
