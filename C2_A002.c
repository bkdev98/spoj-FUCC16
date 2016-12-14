#include <stdio.h>
#include <string.h>

void numberToString (int k, char (*str)[]) {
    int index = 0;
    char digit[10] = "0123456789";
    while (k != 0) {
        (*str)[index] = digit[k % 10];
        k /= 10;
        index++;
    };
    index--;
    char ch;
    for (int i = 0; i <= index / 2; i++) {
        ch = (*str)[i];
        (*str)[i] = (*str)[index - i];
        (*str)[index - i] = ch;
    }
    (*str)[index + 1] = '\0';
    // printf("%s\n", *str);
}
void standardize (char (*str1)[], char (*str2)[]) {
    char st[1000];
    if (strlen(*str1) > strlen(*str2)) {
        for (int k = 1; k <= strlen(*str1) - strlen(*str2); k++) {
            strcat(st ,"0");
        }
        strcat(st, *str2);
        strcpy(*str2, st);
    } else if (strlen(*str1) < strlen(*str2)){
        for (int k = 1; k <= strlen(*str2) - strlen(*str1); k++) {
            strcat(st ,"0");
        }
        strcat(st, *str1);
        strcpy(*str1, st);
    }
    //  printf("%s\n%s\n", *str1, *str2);
}

char *bigMultiply (char str1[], char str2[]) {
    int res[strlen(str1) + strlen(str2)];
    static char s[100000];
    char digit[10] = "0123456789";
    for (int i = 0; i <= strlen(str1) + strlen(str2); i++)
        res[i] = 0;
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        for( int j = strlen(str2) - 1; j >= 0; j--)
          res[i + 1 + j] += ((str1)[i] - '0') * ((str2)[j] - '0');
    }
    for (int i = strlen(str1) + strlen(str2); i >= 0 ; i--) {
        if(res[i] > 9) {
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
    }
    for (int i = 1; i <= strlen(str1) + strlen(str2) - 1; i++ ) {
        s[i - 1] = digit[res[i]];
    }
    return s;
}

int comparison (char st1[], char st2[]) {
    char s1[1000], s2[1000];
    strcpy(s1, st1);
    strcpy(s2, st2);
    standardize(&s1, &s2);
    printf("s1: %s, s2: %s\n", s1, s2);
    for (int index = 0; index <= strlen(s1); index++) {
        if ((s1[index] + '0') > (s2[index] + '0'))
            return -1;
        else if ((s1[index] + '0') > (s2[index] + '0'))
            return 1;
    };
    return 0;
}

// char st[10000000];
// st[strlen(s)] = ' ';
//  sum += ((d*(d+1))/2);
int main(void) {
    int h, w, s, max = 1;
    int i = 1, j = 1;
    char stMul[1000], stS[1000], st1[1000], st2[1000], stMax[1000];
    for (i = 0; i <= strlen(stMax) - 1; i++)
        stMax[i] = '0';
    scanf("%d %d %d", &h , &w, &s);
    numberToString(s, &stS);
    if (s == 0)
        printf("0");
    else {
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                //  Convert
                numberToString(i, &st1);
                numberToString(j, &st2);

                strcpy(stMul, bigMultiply(st1, st2));

                //  standardize(&stMul, &stMax, &stS);
                printf("stMul: %s, stMax: %s, stS: %s\n", stMul, stMax, stS);
                if (((comparison(stMul, stS)) >= 0) && ((comparison(stMul, stMax)) == -1)) {
                    strcpy(stMax, stMul);
                } else if (comparison(stMul, stS) == -1)
                    break;
            }
        };
        printf("%s", stMax);
    };
    return 0;
}
