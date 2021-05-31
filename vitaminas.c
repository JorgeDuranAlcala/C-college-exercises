#include <stdio.h>
#include <stdlib.h>

float cantidad_vitams, peso, altura;
int cantidad_fem, cantidad_masc, mayor_peso, sexo;
float calcular_promedio_vitaminas(float cantidad_vitams, int cantidad_estudiantes);
void print_cantidad_estudiantes();
void administrar_vitams();

int main()
{
    while (1)
    {
        printf("Ingrese 1 para masculino, 0 para femenino?\n");
        scanf("%d", &sexo);

        if (sexo == 1 || sexo == 0)
            break;
    }

    system("cls");

    while (1)
    {
        printf("Ingrese altura expresada en metros?\n");
        scanf("%f", &altura);

        if (altura > 0.00)
            break;
        printf("Ingrese una altura valida\n");
    }

    system("cls");

    while (1)
    {
        printf("Ingrese peso del estudiante expresado en kilogramos?\n");
        scanf("%f", &peso);

        if (peso > 0.00)
            break;
        printf("Ingrese una altura valida\n");
    }

    system("cls");

    administrar_vitams();
    printf("El promedio de vitaminas es %.2f", calcular_promedio_vitaminas(cantidad_vitams, cantidad_fem + cantidad_masc));
    print_cantidad_estudiantes();

    return 0;
}

void administrar_vitams()
{
    switch (sexo)
    {
    case 1:
        if (altura > 1.60 && peso >= 70)
        {
            cantidad_vitams += (altura * 0.2) + (peso * 0.8);
        }
        else
        {
            cantidad_vitams += (altura * 0.3) + (peso * 0.7);
        }
        cantidad_masc++;
        break;
    default:
        if (altura > 1.50 && peso >= 50)
        {
            cantidad_vitams += (altura * 0.25) + (peso * 0.7);
        }
        else
        {
            cantidad_vitams += (altura * 0.35) + (peso * 0.65);
        }
        break;
        cantidad_fem++;
    }
}

void print_cantidad_estudiantes()
{
    printf("Cantidad de estudiantes femeninas %i", cantidad_fem);
    printf("Cantidad de estudiantes masculinos %i", cantidad_masc);
}

float calcular_promedio_vitaminas(float cantidad_vitams, int cantidad_estudiantes)
{
    return cantidad_vitams / cantidad_estudiantes;
}