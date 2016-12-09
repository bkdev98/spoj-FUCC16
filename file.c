/*
Lam viec voi file

FILE *f = fopen("<tenfile>", "<cachsudung>");
                student.txt   Mo ra de doc: r
                              Mo ra de ghi: w
                              Mo ra ghi tiep: a

if (f != NULL)

fscanf(f, "%d%s", &n, &s);
fprintf(f, "%d%s", n, s);

DONG FILE:
fclose(f);
*/

#include <stdio.h>

int main(void) {
    int n;
    char s[1000];
    gets(s);
    FILE *f = fopen(s, "r");
    if (f != NULL) {
        fscanf(f, "%d", &n);
        printf("%d", n);
    } else
        printf("Ban muon mua tivi? :(\n");
    fclose(f);
}
