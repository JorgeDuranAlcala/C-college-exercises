#include <stdio.h>
#define ACTUAL_YEAR 2021

int calculate_age(int year);

//int ACTUAL_YEAR = 2021;

int main(void)
{
    int day, month, year, age;
    char x[100];

    printf("Enter your birthdate like so XX, XX, XXXX\n");

    scanf("%d, %d, %d", &day, &month, &year);

    age = calculate_age(year);

    printf("This is your age: %i\n", age);

    printf("Press any key");
    scanf("%s", &x);
    printf("Key you just pressed %s", x);

    return 0;
}

int calculate_age(int year)
{
    return ACTUAL_YEAR - year;
}
