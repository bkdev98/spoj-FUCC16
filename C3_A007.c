#include <stdio.h>

void convertDecToBin(numberToConvert) {
    int convertedNumber[64], index = 0;
    while (numberToConvert != 0)
    {
        convertedNumber[index] = numberToConvert % 2;
        numberToConvert = numberToConvert / 2;
        ++index;
    }

    --index;

    for(  ; index>=0; index--) {
        printf("%d", convertedNumber[index]);
    }

    printf(" ");
}

void convertDecToOct(numberToConvert) {
    int convertedNumber[64], index = 0;
    while (numberToConvert != 0)
    {
        convertedNumber[index] = numberToConvert % 8;
        numberToConvert = numberToConvert / 8;
        ++index;
    }

    --index;

    for(  ; index>=0; index--) {
        printf("%d", convertedNumber[index]);
    }

    printf(" ");
}

void convertDecToHex(numberToConvert) {
    int convertedNumber[64], index = 0;

    char baseDigits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    while (numberToConvert != 0)
    {
        convertedNumber[index] = numberToConvert % 16;
        numberToConvert = numberToConvert / 16;
        ++index;
    }

    --index;

    for(  ; index>=0; index--) {
        printf("%c", baseDigits[convertedNumber[index]]);
    }
}

int main(void)
{

    int n, numberToConvert;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
         scanf("%d", &numberToConvert);
         convertDecToBin(numberToConvert);
         convertDecToOct(numberToConvert);
         convertDecToHex(numberToConvert);
         printf("\n");
    }
}
