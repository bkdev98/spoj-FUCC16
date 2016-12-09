
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char s[1000000];
    int res, isPalind, k = 0, j = 0;
    gets(s);

    for (int i = 0; i <= strlen(s); i++) {
        if ((s[i] == ' ') || (i == strlen(s))) {
            if (j > 0) {
                isPalind = 1;
                for (k = 0; k <= j/2; k++)
                    if (s[i - j + k] != s[i - 1 - k]) {
                        isPalind = 0;
                        break;
                    }
                if (isPalind == 1) res++;
                j = 0;
            }
        } else {
            j++;
        }
    }
    printf("%d", res);
}
