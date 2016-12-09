#include <stdio.h>

int main(void) {
    int a,b,c,max,min;
    scanf("%d%d%d", &a,&b,&c);
    max=a; min=a;
    if (b>max) {
        max = b;
    };
    if (c>max) {
        max = c;
    };
    if (b<min) {
        min = b;
    };
    if (c<min) {
        min = c;
    };
    printf("%d\n%d", max, min);
    return 0;
}
