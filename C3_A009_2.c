#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// LIBRA string
void balanceChainLength(char (*str1)[], char (*str2)[]){
    char s[1000];
    int g = strlen(str1), h = strlen(str2);
    if(g == h) return;
    if(g < h){
        for(int i = 0; i < h - g; i++)
            strcat(s, "0");
        strcat(s, *str1);
        strcpy(*str1, s);
    }
    else{
        for(int i = 0; i < g - h; i++)
            strcat(s, "0");
        strcat(s, *str2);
        strcpy(*str2, s);
    }
}
//==============================================================================
char * sum2(char strNumber_A[], char strNumber_B[]){
    int arr[100], tmp = 0, next = 0, indexx;
    static char str[1000];
    char digit[10] = "0123456789";
    int g = strlen(strNumber_A);

    for (int i = g - 1; i > -1 ; i--){
        tmp = (strNumber_A[i] - '0') + (strNumber_B[i] - '0') + tmp;
        if (tmp > 9){
            arr[next] = tmp % 10;
            next++;
            tmp = tmp / 10;
        }
        else{
            arr[next] = tmp;
            next++;
            tmp = 0;
        }
    }
    next--;
    for(indexx = 0; next > -1 ;indexx++, next--){
        str[indexx] = digit[arr[next]];
    }
    str[indexx] = '\0';
    return str;
}
//==============================================================================
char * multiplication(char strNumber_A[], char strNumber_B[]){
    int g = strlen(strNumber_A), h = strlen(strNumber_B);
    int res[strlen(strNumber_A) + strlen(strNumber_B)], index = 0;
    static char str[1000];
    char digit[10] = "0123456789";

    for(int i = strlen(strNumber_A) + strlen(strNumber_B) ; i >= 0 ; i--) res[i] = 0;
    for(int i = strlen(strNumber_A) - 1; i >=0; i--){
        for(int j = strlen(strNumber_B) - 1; j >=0; j--)
            res[i+j+1] = res[i+j+1] + (strNumber_A[i] - '0') * (strNumber_B[j] - '0');
    }
    for(int i = strlen(strNumber_A) + strlen(strNumber_B) ; i >= 0; i--)
        if(res[i] > 9){
            res[i-1] = res[i-1] + res[i]/10;
            res[i] = res[i] % 10;
        }
    int indexx = 0;
    for(indexx = 0; indexx < strlen(strNumber_A) + strlen(strNumber_B) - 1; indexx++){
        str[indexx] = digit[res[indexx+1]];
    }
    str[indexx] = '\0';
    return str;
}
//==============================================================================
char * compute(int number){
    int mid, last;
    char strMid[100], strLast[100];
    static char str[1000];

    if(number % 2 == 0){
        mid = number / 2;
        last = number + 1;
    }
    else {
         mid = number / 2 + 1;
        last = number;
    }
    numberToString(mid, &strMid);
    numberToString(last, &strLast);

    strcpy(str, multiplication(strMid, strLast));
    return str;
}
//==============================================================================
// int change into char
void numberToString (int k, char (*str)[]) {
    int index = 0;
    char digit[10] = "0123456789";
    while (k != 0) {
        (*str)[index] = digit[k % 10];
        k /= 10;
        index++;
    };
    index--;
    char tmp;
    for (int i = 0; i <= index / 2; i++) {
        tmp = (*str)[i];
        (*str)[i] = (*str)[index - i];
        (*str)[index - i] = tmp;
    }
    (*str)[index + 1] = '\0';
}
//==============================================================================
char * compute2(int number){
    static char str[100];
    if(number % 2 == 0)
        number = (number / 2) * (number + 1);
    else
         number = (number / 2 + 1) * number;
    numberToString(number, &str);
    return str;
}
//==============================================================================
int main(){
    char s[1000000];
    int count = 0, i;
    char sum[1000] = "0";
    char tmpAdd[1000], tmpSum[1000];
    scanf("%s", &s);
    for(i = 0; i < strlen(s) + 1; i++){
        if(s[i] > 47 && s[i] < 58)
            count++;
        else{
            if (count < 1000){
                strcpy(tmpAdd, compute2(count));
                strcpy(tmpSum, sum);
                balanceChainLength(&tmpAdd, &tmpSum);
                strcpy(sum, sum2(tmpAdd, tmpSum));
                count = 0;
            }
            else{
                strcpy(tmpAdd, compute(count));
                strcpy(tmpSum, sum);
                balanceChainLength(&tmpAdd, &tmpSum);
                strcpy(sum, sum2(tmpAdd, tmpSum));
                count = 0;
            }
        }
    }
    printf("%s", sum);
    return 0;
}
