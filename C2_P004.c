#include <stdio.h>
#include <math.h>

//  Chia De Tri

double calc(int a, int k)
{
    if(k == 1) {
        return a;
    } else {
        double temp = calc(a, k/2);
        if(k % 2 == 0)
            return temp * temp;
        else
            return temp * temp * a;
    }
}

int main(void) {
    int a, k;
    scanf("%d %d", &a, &k);
    printf("%.0lf", pow(a, k));
    return 0;
}
