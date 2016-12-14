#include <stdio.h>
#include <string.h>

char s[10];

long long decc(int base){
    unsigned int dec = 0;
    for(int i = (strlen(s) - 1), j = 1; i > -1; i--, j = j * base){
        if(s[i] > 47 && s[i] < 58)
            dec = (s[i] - 48) * j + dec;
        // else if (s[i] > 64 && s[i] < 71)
        //     dec = (s[i] - 55) * j + dec;
        else if (s[i] > 96 && s[i] < 103)
            dec = (s[i] - 87) * j + dec;
    }
    return dec;
}

void output(long long gt, int y){
    char base16[16] ="0123456789abcdef";
    int number[100], index=0;

    if(gt == 0){
        printf("0");
        return;
    }
    while (gt != 0){
        number[index] = gt % y;
	gt = gt / y;
	++index;
    }
    --index;
    for(  ; index > -1; index--)
	printf("%c", base16[number[index]]);
}

int main(){
    int x, y, base;
    long long gt, arr[] = {0,2,8,10,16};

    scanf("%d%d\n", &x, &y);
    gets(s);
    base = arr[x];
    gt = decc(base);
    base = arr[y];
    output(gt, base);
    return 0;
}
