#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j;
    int count = 0;
    char s[1000000];

    gets(s);

    for (i = 0; i <= strlen(s) - 1; i++) {
        for (j = i; j <= strlen(s) - 1; j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                ++count;
            } else {
                break;
            }
        }
    }

    printf("%d", count);
    return 0;
}
