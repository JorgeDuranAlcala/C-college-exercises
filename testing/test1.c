#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char cedula[10];
} Person;

int findByCedula(Person *, int n, char ced[10]);

void main()
{
    Person personas[2];
    char ce[12];
    int verdadero = 0, falso = 0;

    printf("cedula porfavor\n");
    gets(personas[0].cedula);
    printf("su cedula es: ");
    puts(personas[0].cedula);
    printf("\n\n");

    personas[1].cedula = "28.555";

    printf("Desea buscar una persona por su cedula (Y | N)\n");
    char c = getchar();
    fflush(stdin);

    if (toupper(c) == 'Y')
    {

        char cedula_target[12];
        do
        {
            printf("Ingrese cedula de la persona que quiere buscar\n");
            gets(cedula_target);
            fflush(stdin);
            if (findByCedula(personas, sizeof personas / sizeof personas[0], cedula_target))
            {
                printf("la persona que busca fue encontrada \n");
            }
            else
            {
                printf("No se encontro siga buscando \n");
            }
        } while (findByCedula(personas, sizeof personas / sizeof personas[0], cedula_target) == 0);
    }

    /*  
    //char *c1 = "Mexico city is the best", *ca0;
    //ca0 = strstr(c1, "car");
    //ca0 = strstr(personas[0].cedula, "28.511.812");
    printf("buscar por cedula\n");
    scanf("%s", &ce);

    findByCedula(personas, sizeof personas / sizeof personas[0], ce); 
    */

    /*  double nm = 3, nw = 64, np = nm + nw;
    float pcw = (nm / np) * 100;
    printf("The percent of woman %4.2f", pcw); */
}

int findByCedula(Person persons[], int n, char ced[10])
{
    //char *c;
    for (int i = 0; i < n; i++)
    {
        if (strstr(persons[i].cedula, ced))
        {
            return 1;
        }
    }
    return 0;
}