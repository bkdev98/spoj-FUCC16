#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n==1) printf("Sunday");
    if (n==2) printf("Monday");
    if (n==3) printf("Tuesday");
    if (n==4) printf("Wednesday");
    if (n==5) printf("Thursday");
    if (n==6) printf("Friday");
    if (n==7) printf("Saturday");
    if ((n<1)||(n>7)) printf("Error");
    return 0;
}
