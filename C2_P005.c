#include <stdio.h>
#include <math.h>

int main(void) {
    int n, dd = 0;
    scanf("%d", &n);
    while ((n % 10 == 0) && (n != 0))
        n /= 10;
    while (n != 0) {
        printf("%d", n % 10);
        n /= 10;
    }
    return 0;
}

/*

#include <stdio.h>
#include <string.h>

int main() {
    char s[100000], temp;
    int i, j;
    gets(s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
       temp = s[i];
       s[i] = s[j];
       s[j] = temp;
       i++;
       j--;
    }

    printf("%s", s);
    return(0);
}

*/
