#include <stdio.h>
#include <stdlib.h>

float cantidad_vitams, peso, altura;
int cantidad_fem, cantidad_masc, mayor_peso_masc, mayor_peso_fem, sexo;
float calcular_promedio_vitaminas(float cantidad_vitams, int cantidad_estudiantes);
void print_cantidad_estudiantes();
void administrar_vitams();
void obtener_sexo();
void obtener_altura();
void obtener_peso();
int i = 1;

int main()
{
    while (i <= 3)
    {
        obtener_sexo();
        obtener_altura();
        obtener_peso();
        administrar_vitams();

        i++;
    }
    printf("El promedio de vitaminas es %.2f\n", calcular_promedio_vitaminas(cantidad_vitams, cantidad_fem + cantidad_masc));
    print_cantidad_estudiantes();

    return 0;
}

void obtener_sexo()
{
    while (1)
    {
        printf("Ingrese sexo del estudiante numero %i - presione 1 para masculino, 0 para femenino?\n", i);
        scanf("%d", &sexo);

        if (sexo == 1 || sexo == 0)
            break;
        printf("Ingrese una de las 2 opciones de arriba\n");
    }

    system("cls");
}
void obtener_altura()
{
    while (1)
    {
        printf("Ingrese altura del estudiante %i expresada en metros?\n", i);
        scanf("%f", &altura);

        if (altura > 0.00)
            break;
        printf("Ingrese una altura valida\n");
    }

    system("cls");
}

void obtener_peso()
{

    while (1)
    {
        printf("Ingrese peso del estudiante numero %i expresado en kilogramos?\n", i);
        scanf("%f", &peso);

        if (peso > 0.00)
            break;
        printf("Ingrese una altura valida\n");
    }

    system("cls");
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
        if (peso > mayor_peso_masc)
            mayor_peso_masc = peso;
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
        cantidad_fem++;
        if (peso > mayor_peso_fem)
            mayor_peso_fem = peso;
        break;
    }
}

void print_cantidad_estudiantes()
{
    printf("Cantidad de estudiantes femeninas %i\n", cantidad_fem);
    printf("El mayor peso femenino fue de %ikg\n", mayor_peso_fem);
    printf("Cantidad de estudiantes masculinos %i\n", cantidad_masc);
    printf("El mayor peso masculino fue de %ikg\n", mayor_peso_masc);
}

float calcular_promedio_vitaminas(float cantidad_vitams, int cantidad_estudiantes)
{
    return cantidad_vitams / cantidad_estudiantes;
}