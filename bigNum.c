#include <stdio.h>
#include <string.h>

void numberToString (unsigned long int k, char (*str)[]) {
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
    //  printf("%s\n", *str);
}

void standardize (char (*str1)[], char (*str2)[]) {
    char st[1000];
    if (strlen(*str1) > strlen(*str2)) {
        for (int k = 1; k <= strlen(*str1) - strlen(*str2); k++) {
            strcat(st ,"0");
        }
        strcat(st, *str2);
        strcpy(*str2, st);
    } else {
        for (int k = 1; k <= strlen(*str2) - strlen(*str1); k++) {
            strcat(st ,"0");
        }
        strcat(st, *str1);
        strcpy(*str1, st);
    }
    //  printf("%s\n%s\n", *str1, *str2);
}

char *bigAddition (char str1[], char str2[]) {
    static char res[100000];
    int carry = 0, sum, index = 0;
    char digit[10] = "0123456789";
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        sum = ((str1)[i] - '0') + ((str2)[i] - '0') + carry;
        carry = sum / 10;
        res[index] = digit[sum % 10];
        index++;
    }
    index--;

    for (int i = 1; i <= index / 2 + 1; i++) {
        char tmp = res[i];
        res[i] = res[index - i];
        res[index - i] = tmp;
    }
    return res;
};

char *bigSubtraction (char str1[], char str2[]) {
    static char res[100000];
    int borrow = 0, s, index = 0;
    char digit[10] = "0123456789";
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        s = ((str1)[i] - '0') - ((str2)[i] - '0') - borrow;
        if (s < 0) {
            s += 10;
            borrow = 1;
        } else
            borrow = 0;
        res[index] = digit[s];
        index++;
    }
    index--;
    for (int i = 1; i <= index / 2 + 1; i++) {
        char tmp = res[i];
        res[i] = res[index - i];
        res[index - i] = tmp;
    }
    return res;
};

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
/*
void bigDivide1 (char str[], int n) {
    int res[1000], hold = 0, s = 0;

    for (int i = 0; i <= strlen(str) - 1; i++) {
        hold = hold * 10 + (str[i] + '0');
        s = hold / n;
        hold %= n;
        res[i] = s;
        printf("%d ", res[i]);
    };

}
*/
int main (void) {
    char str1[1000000], str2[1000000], st1[1000000], st2[1000000];
    unsigned long int i, j;
    scanf("%ld %ld", &i, &j);
    numberToString(i, &str1);
    numberToString(j, &str2);

    strcpy(st1, str1); strcpy(st2, str2);
    standardize(&st1, &st2);
    printf("(+): %s\n", bigAddition(st1, st2));
    printf("(-): %s\n", bigSubtraction(st1, st2));
    printf("(x): %s\n", bigMultiply(str1, str2));
    //  bigDivide1(str1, j);
    return 0;
}
