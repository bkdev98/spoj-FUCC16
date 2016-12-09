#include <stdio.h>
#include <string.h>

int main() {
    char s[1000000], temp;
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
