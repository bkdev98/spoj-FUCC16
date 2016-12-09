#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000000];
    gets(s);
    int count = 0, max = 0, num = 0, same = 1, i = 0;
    for (i = 0; i <= strlen(s); i++) {
        if ((s[i] == ' ') || (i == strlen(s))) {
            if (count > 0) {
                if (max <= count) {
                    if (max == count) {
                        same++;
                    } else {
                        same = 1;
                    };
                    max = count;
                };
                count = 0;
                num++;
            }
        } else {
            count++;
        }
    };
    if (num == 0) same = 0;
    printf("%d\n%d\n%d\n", num, max, same);
}
