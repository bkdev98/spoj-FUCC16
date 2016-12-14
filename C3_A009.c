#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* receiveInput( char *s ){
    scanf("%1000000s",s);
    return s;
}

int main() {
    char st[1000000];
    receiveInput(st);
    long long i, j = 0;
    long long sum = 0;
    st[strlen(st)] = ' ';
    st[strlen(st) + 1] = '\0';
    for (i = 0; i <= strlen(st); i++) {
        if (st[i] > 47 && st[i] < 58)
            j++;
        else if (j > 0) {
            sum += (( j * (j + 1)) / 2);
            j = 0;
        }
    }
    printf("%lld", sum);
    return 0;
}
