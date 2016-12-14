#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getValidBase() {
    /* your code goes here */
    char s[1000];
    int length;
    gets(s);
    for (length = 0; s[length] != '\0'; length++);
    if (length == 1) {
        if (s[0] >= 50 && s[0] <= 57)
            return (s[0] - '0');
        if (s[0] == 48 || s[0] == 49)
            return 0;
        return -1;
    } else if (length > 1) {
        if (s[0] == 45) {
            for (int i = 1; i <= length - 1; i++)
                if (s[i] <= 47 || s[i] >= 58)
                    return -1;
            return 0;
        } else if (length == 2 && s[0] == 49 && s[1] >= 48 && s[1] <= 54)
            return ((s[0] - '0') * 10 + (s[1] - '0'));
        else
            for (int i = 0; i <= length - 1; i++)
                if (s[i] <= 47 || s[i] >= 58)
                    return -1;
            return 0;
    }
    return -1;
}

int isContinue() {
    /* your code goes here */
    char s[100];
    int length;
    gets(s);
    for (length = 0; s[length] != '\0'; length++);
    if (length != 1)
        return -1;
    else if (s[0] == 78 || s[0] == 110)
        return 0;
    else if (s[0] == 89 || s[0] == 121)
        return 1;
    return -1;
}

void convert(int in, int ou, char number[]) {
    /* your code goes here */
    long long dec;
    long long length;
    //  Convert to DEC
    for (length = 0; number[length] != '\0'; length++);

    for (long long i = (length - 1), j = 1; i > -1; i--, j = j * in){
        if(number[i] > 47 && number[i] < 58)
            dec = (number[i] - 48) * j + dec;
        else if (number[i] > 64 && number[i] < 71)
            dec = (number[i] - 55) * j + dec;
    }
    //  Convert to OTHERS
    char base16[16] ="0123456789ABCDEF";
    long long res[1000], index = 0;

    if (dec == 0) {
        printf("0");
        return;
    } while (dec != 0) {
        res[index] = dec % ou;
      	dec = dec / ou;
      	++index;
    }
    --index;
    for(  ; index > -1; index--)
        printf("%c", base16[res[index]]);
}

int isValueinBase(char number[], int base) {
    /* your code goes here */
    long long length;

    for (length = 0; number[length] != '\0'; length++);

    for (long long i = 0; i <= length - 1; i++)
        if (number[i] < 48 || ((number[i] > (57 - 10 + base)) && number[i] < 65) || number[i] > 65 + base - 11)
            return 0;
    return 1;
}

int readBase() {
    int base;
    do {
        base = getValidBase();
        if (base == -1)
            printf("Your input must be an integer number in [2, 16]! Please input again!\n");
        else
            if (base == 0)
                printf("Your input must be in [2, 16]! Please input again!\n");
    }
    while (base <= 0);
    return base;
}

int main()
{
    int isStop = 0; // stop flag
    int in, ou, kt;
    char s[123];
    do {
        printf("*****************************************************************\n");
        printf("*       Welcome you to Base Converter!                          *\n");
        printf("*****************************************************************\n");
        printf("* To use this app you must follow those steps:                  *\n");
        printf("*    Step 1. Enter input base (2 - 16).                         *\n");
        printf("*    Step 2. Enter value in input base.                         *\n");
        printf("*    Step 3. Enter output base (2 - 16).                        *\n");
        printf("*****************************************************************\n");
        // input base
        printf("Enter input base:\n");
        in = readBase();
        // value
        printf("Enter value to convert:\n");
        do {
            fflush(stdin);
            gets(s);
            kt = isValueinBase(s, in);
            if (kt == 0) {
                printf("Your input is not number in base %d. Please input again!\n", in);
            }
        }
        while (kt == 0);
        // output base
        printf("Enter output base:\n");
        ou = readBase();
        // Convert and display
        printf("Value in base %d:\n", ou);
        convert(in, ou, s);
        printf("\n");
        // ask if continue
        printf("Do you want to continue (Y/N)?\n");
        do {
            kt = isContinue();
            if (kt == -1) {
                printf("Your request is not valid, please input 'Y' or 'N'.\n");
            }
            else
                if (kt == 0) isStop = 1;
        }
        while (kt == -1);
        // stop
        if (isStop)
            printf("Bye bye...");
    } while (isStop == 0);

    return 0;
}
