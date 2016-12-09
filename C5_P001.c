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
    gets(value);
    if ((int)value - value)
        return -1;
    else
}

int getNextChoice() {
    /* your code goes here */
    char numberArray[10] = "0123456789";
    int check, value;
    gets(string);
    for (int i = 0; i <= strlen(string) - 1; i++)
        if (strstr(numberArray, string[i]) == NULL) {
            check = -1;
            break;
        }
    if (check != 1) {
        sscanf(string, "%d", &value);
        switch (value) {
            case (1): return 1;
            case (2): return 2;
            case (3): return 3;
        }
    } else
        return -1;
    return 0;
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
