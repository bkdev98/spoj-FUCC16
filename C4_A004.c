#include <stdio.h>

int convertedNumber[64], index = 0;

char baseDigits[16] =
{'0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

//  Converter from Dec to Others

void convertDecToBin(numberToConvert, int index) {
    while (numberToConvert != 0) {
        convertedNumber[index] = numberToConvert % 2;
        numberToConvert = numberToConvert / 2;
        ++index;
    }

}

void convertDecToOct(numberToConvert, int index) {
    while (numberToConvert != 0) {
        convertedNumber[index] = numberToConvert % 8;
        numberToConvert = numberToConvert / 8;
        ++index;
    }

}

void convertDecToHex(numberToConvert, int index) {
    while (numberToConvert != 0) {
        convertedNumber[index] = numberToConvert % 16;
        numberToConvert = numberToConvert / 16;
        ++index;
    }

}

//  Converter from Others to Dec

int decOfBin(numberToConvert, int index) {
    int j = 0, tmp, sumOfBin, multipVariable;
    while (numberToConvert != 0) {
        tmp = numberToConvert % 10;
        for (int k = 0; k <= j; k++)
            multipVariable *= multipVariable;
        sumOfBin += tmp * multipVariable;
        j++;
    };
    return sumOfBin;
}

//  Main Process

int main(void)
{
    int x, y, numberToConvert;

    scanf("%d %d", &x, &y);

    //  Converter from Dec to Others

    if (x == 3) {
        scanf("%d", numberToConvert);

        switch(y) {
            case (1):
                    convertDecToBin(numberToConvert, int index);
            case (2):
                    convertDecToOct(numberToConvert, int index);
            case (4):
                    convertDecToHex(numberToConvert, int index);
        };

        --index;

        for(  ; index>=0; index--) {
            printf("%c", baseDigits[convertedNumber[index]]);
        }
    }

    //  Converter from Bin to Others
    if (x == 1) {
        scanf("%d", numberToConvert);

        switch(y) {
            case (2):
                  convertDecToOct(decOfBin(numberToConvert, int index));
                  --index;

                  for ( ; index >= 0; index--) {
                      printf("%c", baseDigits[convertedNumber[index]]);
                  }
            case (3):
                  printf("%d", decOfBin(numberToConvert, int index));
        };

    }

}

int main(void) {
    scanf("%d", &index);
    printf("%d", index);
}
