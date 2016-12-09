#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hh,mm,hh1,mm1,a,b,c;
    scanf ("%d:%d\n",&hh,&mm);
    scanf ("%d:%d",&hh1,&mm1);
    if (0 > hh, hh1 > 23 || 0 > mm, mm1 > 59)
        return 0;
    else {
        if (hh > hh1 ||(hh == hh1 && mm > mm1)){
            hh1 = hh1 + 24;
            a = (hh1 * 60 + mm1)-( hh * 60 + mm);
            b =a  / 60;
            c = a % 60;
            printf ("%.2d:%.2d", b, c);
        }
        else {
            a = (hh1 * 60 + mm1)-(hh * 60 + mm);
            b = a / 60;
            c = a % 60;
            printf ("%.2d:%.2d",b,c);
        }
    }
    return 0;
}
