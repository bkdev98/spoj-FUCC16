#include <stdio.h>

int main(void) {
    int s, a, b, c, res = 0;
    scanf("%d %d %d %d", &s, &a, &b, &c);
    while ((a > 0) && (s - 1 >= 0)) {
        s -= 1;
        --a;
        ++res;
    }
    while ((b > 0) && (s - 2 >= 0)) {
        s -= 2;
        --b;
        ++res;
    }
    while ((c > 0) && (s - 5 >= 0)) {
        s -= 5;
        --c;
        ++res;
    }
    printf("%d ", res);
    return 0;
}
