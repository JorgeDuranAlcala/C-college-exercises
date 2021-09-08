#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Returns true if s is a number else false
bool isNumber(char s[])
{

    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == false)
        {
            printf("%s", s[i]);
            return false;
        }
    }

    return true;
}

// Driver code
int main()
{
    // Saving the input in a string
    char str[] = "";
    printf("Enter an integer value \n");
    scanf("%s", &str);

    // Function returns 1 if all elements
    // are in range '0-9'
    if (isNumber(str))
        printf("Integer");

    // Function returns 0 if the input is
    // not an integer
    else
        printf("String");
}