#include <stdio.h>

int main(void) {
    int h, w, s, max = 1;
    int i = 1, j = 1;
    scanf("%d %d %d", &h , &w, &s);
    if (s == 0)
        printf("0");
    else {
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                if ((i * j <= s) && (i * j > max)) {
                    max = i * j;
                } else if (i * j > s) {
                    break;
                }
            }
        };
        printf("%d", max);
    };
    return 0;
}
