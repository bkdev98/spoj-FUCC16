#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float areaOfCircle(int radius)
{
   /* your code goes here */
   return (3.14 * radius * radius);
}

int areaOfRectangle(int l, int w)
{
    /* your code goes here */
    return (l * w);
}

int getNextInt() {
    /* your code goes here */
    int length;
    char s[10000];
    int value = 0;
    gets(s);
    for (length = 0; s[length] != '\0'; ++length);
    if (s[0] == '-') {
        for (int i = 1; i <= length - 1; i++)
            if (s[i] <= 47 || s[i] >= 58)
                return -1;
        return 0;
    } else {
        for (int i = 0; i <= length - 1; i++) {
            if (s[i] <= 47 || s[i] >= 58)
                return -1;
            value = value * 10 + (s[i] - '0');
        };
        if (value - 0 == 0)
            return 0;
        else return value;
    }
    return -1;
}


int getNextChoice() {
    /* your code goes here */
    char s[10000];
    int length;
    gets(s);
    for (length = 0; s[length] != '\0'; ++length);
    if (length == 1) {
        if (s[0] >= 58 && s[0] <= 47)
            return -1;
        if (s[0] <= 51 && s[0] >= 49)
            return (s[0] - '0');
        if (s[0] == 48 || (s[0] >= 52 && s[0] <= 57))
            return 0;
    } else if (length > 1){
        if (s[0] == '-') {
            for (int i = 1; i <= length - 1; i++) {
                //  printf("%d", s[i]);
                if (s[i] >= 58 || s[i] <= 47)
                    return -1;
            };
            return 0;
        } else {
            for (int i = 0; i <= length - 1; i++) {
                //  printf("%d", s[i]);
                if (s[i] >= 58 || s[i] <= 47)
                    return -1;
            };
            return 0;
        }
    };
    return -1;
}

float readIntUntilTrue() {
    float value;
    do {
        value = getNextInt();
        if (value == -1)
            printf("Your input is not integer number!\n");
        if (value == 0)
            printf("Your input must be positive number!\n");
    }
    while (value <= 0);
    return value;
}

int main()
{
    int isStop = 0; // stop flag
    do {
        printf("**************************************************\n");
        printf("*       Welcome you to Math Application!         *\n");
        printf("**************************************************\n");
        printf("*    1. Calculate area of circle.                *\n");
        printf("*    2. Calculate area of rectangle.             *\n");
        printf("*    3. Exit.                                    *\n");
        printf("************ Please choose the option ************\n");

        int choice;
        int radius, res, width, length;
        // get menu choice
        do {
            choice = getNextChoice();
            if (choice == -1)
                printf("Your choice is not integer number! Please input again!\n");
            if (choice == 0)
                printf("Your choice must be 1, 2 or 3!\n");
        }
        while (choice <= 0);

        switch (choice)
        {
            case 1:
                printf("Please input the radius of the circle:\n");
                radius = readIntUntilTrue();
                printf("The area is: %.2f\n", areaOfCircle(radius));
                break;
            case 2:
                printf("Please input the length of rectangle:\n");
                length = readIntUntilTrue();
                printf("Please input the width of the rectangle:\n");
                width = readIntUntilTrue();
                printf("The area is: %d\n", areaOfRectangle(length, width));
                break;
            case 3:
                printf("Bye bye!");
                isStop = 1;
                break;
        }
    } while (isStop == 0);

    return 0;
}
