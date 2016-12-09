#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c, d;
    scanf("%f %f %f", &a, &b, &c);
    d = b*b - 4*a*c;
    if (d < 0)
        printf("0");
    else if (d == 0) {
        printf("1\n");
        if (-b/(2*a) != 0)
            printf("%.3f", -b/(2*a));
        else printf("0.000");
    } else {
        printf("2\n");
        if ((-b-sqrt(d))/(2*a) < (-b+sqrt(d))/(2*a)) {
            if ((-b-sqrt(d))/(2*a) != 0)
                printf("%.3f ", (-b-sqrt(d))/(2*a));
            else printf("0.000");
            if ((-b+sqrt(d))/(2*a) != 0)
                printf("%.3f", (-b+sqrt(d))/(2*a));
            else printf("0.000");
        } else {
            if ((-b+sqrt(d))/(2*a) != 0)
                printf("%.3f ", (-b+sqrt(d))/(2*a));
            else printf("0.000");
            if ((-b-sqrt(d))/(2*a) != 0)
                printf("%.3f", (-b-sqrt(d))/(2*a));
            else printf("0.000");
        }

    }
    return 0;
}
