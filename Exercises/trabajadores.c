#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

float calcular_pago(int horas, int tarifa_por_hora);
void obtener_horas_trabajadas();
void obtener_tarifa();
void obtener_cedula();
void obtener_nombre();
char cedula[10], nombre[100];
int horas_trabajadas, tarifa_por_hora, numero_empleados_sin_horas_extras;
float pago_total;

void main(void)
{
    while (1)
    {

        obtener_nombre();
        obtener_cedula();
        obtener_horas_trabajadas();
        obtener_tarifa();
        float pago = calcular_pago(horas_trabajadas, tarifa_por_hora);
        pago_total += pago;
        system("cls");
        printf("Monto a pagar al empleado %s es de %.2f\n", nombre, pago);

        int condition;
        printf("1 para continuar, 0 para terminar el programa\n");
        scanf("%i", &condition);
        if (condition == 0)
        {
            system("cls");
            printf("monto total a pagar por la empresa: %.2f\n", pago_total);
            printf("Numero de empleados sin horas extras: %i\n", numero_empleados_sin_horas_extras);
            break;
        }
        system("cls");
    }
}

void obtener_cedula()
{
    while (1)
    {
        printf("Ingrese la cedula del empleado %s \n", nombre);
        scanf("%s", &cedula);
        if (strlen(cedula) <= 10)
            break;
        system("cls");
        printf("Ingrese una cedula valida\n");
        // 40.555.044
    }
}
void obtener_nombre()
{
    printf("Ingrese el nombre del empleado \n");
    scanf("%s", &nombre);
}

void obtener_tarifa()
{
    while (1)
    {
        printf("Ingrese tarifa a pagar por hora al empleado %s\n", nombre);
        scanf("%i", &tarifa_por_hora);
        if (tarifa_por_hora > 0)
            break;
        system("cls");
        printf("Ingrese un numero valido\n");
    }
}

void obtener_horas_trabajadas()
{
    while (1)
    {
        printf("Ingrese numero de horas trabajadas del empleado %s\n", nombre);
        scanf("%i", &horas_trabajadas);
        if (horas_trabajadas > 0)
            break;
        system("cls");
        printf("Ingrese un numero de horas valido\n");
    }
}

float calcular_pago(int horas, int tarifa_por_hora)
{
    int prima_por_hogar = 250000;
    float monto = (horas * tarifa_por_hora) + prima_por_hogar;
    float descuento_seguro_social = (monto * 0.05);
    float descuento_caja_ahorro = (monto * 0.1);
    if (horas > 40)
    {
        monto += monto * 0.5;
    }
    else
    {
        numero_empleados_sin_horas_extras++;
    }
    monto -= descuento_seguro_social + descuento_caja_ahorro;
    return monto;
}
