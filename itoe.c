/*==============================================================
| Write a succinct program to convert any integer from 1-999 into the English word (in lower case)
| Usage: ./intToEnglish (then enter integer)
| Description of parameters:
|  input: input given by user
|  quit: whether the user wants to quit
|  twty: number presentation between 1 and 20
|  hundred: hundred presentation
|  decades: ten multipler presentation
----------------------------------------------------------------
*/
#include <stdio.h>

int main(void)
{
        int input, quit = 0;
        char twty[21][16] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
        char hundreds[10][16] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};
        char decades[10][16] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        // while user does not want to quit
        while (!quit)
        {
                // Print menu
                printf("Please enter a value (1-999, 0 to quit): ");
                if (scanf("%d", &input) == 1)
                {
                        // Quit
                        if (input == 0)
                        {
                                quit = 1;
                        }
                        else if (input > 0 && input < 1000)
                        {
                                printf("You entered the number ");
                                // Print hundreds
                                if (input / 100 > 0)
                                {
                                        printf("%s and ", hundreds[input / 100]);
                                        input = input % 100;
                                }
                                // Handle number between 1 and 20
                                if (input < 21)
                                {
                                        printf("%s\n", twty[input]);
                                }
                                // Print decades
                                else
                                {
                                        printf("%s", decades[input / 10]);
                                        input = input % 10;
                                        // If last digit is not 0, print "-"
                                        if (input > 0)
                                        {
                                                printf("-");
                                        }
                                        // Print last digit
                                        printf("%s\n", twty[input]);
                                }
                        }
                        else
                        {
                                // Ask retry if input is not in range
                                printf("Value is not between 1 and 999.\n");
                        }
                }
                else
                {
                        // Catch invalid input
                        while (getchar() != '\n')
                                ;
                        printf("Invalid input.\n");
                }
        }
        return 0;
}
