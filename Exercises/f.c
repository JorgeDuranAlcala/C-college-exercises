#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
        int flight_id;
        int numero_de_pasajeros;
        float costo_boleto;
        int condiciones_salida;
} Flight;

typedef struct
{
        int aeroLinea_id;
        char name[100];
        Flight *flights;
        int numero_vuelos_diarios;
} aeroLinea;

void print_flights_data(Flight *F, size_t n)
{
        int i = 0, total = 0;
        float monto_total;
        float multa;
        //printf("id: %d\n n: %ld \n", F[0].flight_id, n);
        while (i < n)
        {
                // monto_total += F[i].costo_boleto;
                if (F[i].condiciones_salida == 0)
                {
                        monto_total += ((F[i].costo_boleto) * 5) / 100;
                        total++;
                }
                printf("flight's ID: %d\n", F[i].flight_id);
                printf("flight's numero de pasajeros: %d\n", F[i].numero_de_pasajeros);
                printf("flight's costo del boleto: %f\n", F[i].costo_boleto);
                i++;
        }
        printf("total vuelos atrasados: %d\n", total);
}

void print_total_de_vuelos_retrasados(Flight *F, size_t n)
{
        int i = 0, total;
        while (i < n)
        {
                if (F[i].condiciones_salida == 0)
                {
                        total++;
                }
                i++;
        }
        printf("Total de vuelos retrasados %d\n", total);
}

void iterar_aerolineas(aeroLinea *a, size_t num)
{
        int total = 0;
        for (int i = 0; i < num; i++)
        {
                printf("aeroline's name: %s\n Aerolinea ID: %d\n", a[i].name, a[i].aeroLinea_id);
                printf("\n");
                //print_flights_data(a[i].flights, a[i].numero_vuelos_diarios );
                int j = 0;
                float monto_total;
                while (j < a[i].numero_vuelos_diarios)
                {
                        if (a[i].flights[j].condiciones_salida == 0)
                        {
                                monto_total += ((a[i].flights[j].costo_boleto) * 5) / 100;
                                total++;
                        }
                }
                // print_total_de_vuelos_retrasados(a[i].flights, a[i].numero_vuelos_diarios);
        }
}

int main(void)
{
        char nombre_aerolinea[100];
        int numero_de_aerolineas, numero_de_vuelos_diarios, numero_de_vuelo, numero_de_pasajeros;
        int condiciones_de_salida;
        float costo_del_boleto;

        printf("Numero de aerolineas\n");
        scanf("%d", &numero_de_aerolineas);
        aeroLinea aerolineas[numero_de_aerolineas];
        //printf("n %d\n", numero_de_aerolineas);
        int i = 0;
        while (1)
        {
                //printf("n de aero: %d\n", numero_de_aerolineas);
                if (numero_de_aerolineas == 0)
                        break;
                aeroLinea aero_linea = {i + 1};
                printf("nombre aerolinea %d\n", i + 1);
                scanf("%s", nombre_aerolinea);
                strcpy(aero_linea.name, nombre_aerolinea);

                printf("numero de vuelos diarios de la aerolinea %d \n", i + 1);
                scanf("%d", &numero_de_vuelos_diarios);
                aero_linea.flights = (Flight *)calloc(numero_de_vuelos_diarios, sizeof(Flight));

                aero_linea.numero_vuelos_diarios = numero_de_vuelos_diarios;

                int j = 0;

                if (aero_linea.flights == NULL)
                {
                        printf("Memory not allocated.\n");
                        exit(0);
                }
                else
                {
                        while (1)
                        {
                                if (numero_de_vuelos_diarios == 0)
                                        break;
                                //printf("i: %d, j: %d\n", i, j);
                                Flight flight;

                                printf("numero de pasajeros del vuelo %d \n", j + 1);
                                scanf("%d", &numero_de_pasajeros);
                                printf("Costo del boleto del vuelo %d \n", j + 1);
                                scanf("%f", &costo_del_boleto);
                                printf("Condiciones de vuelo 1 para 'a tiempo' y 0 para 'retrasado del vuelo %d'\n", j + 1);
                                scanf("%d", &condiciones_de_salida);
                                printf("\n");
                                system("cls");

                                flight.flight_id = j + 1;
                                flight.numero_de_pasajeros = numero_de_pasajeros;
                                flight.costo_boleto = costo_del_boleto;
                                flight.numero_de_pasajeros = numero_de_pasajeros;
                                flight.condiciones_salida = condiciones_de_salida;

                                aero_linea.flights[j] = flight;

                                numero_de_vuelos_diarios--;
                                j++;
                        }
                }

                aerolineas[i] = aero_linea;
                numero_de_aerolineas--;
                i++;
        }

        size_t num = sizeof(aerolineas) / sizeof(aerolineas[0]);
        int max = 0;
        int min;
        float monto_total_de_multas;
        char *nombre_aerolinea_con_mas_retrasos;
        char *nombre_aerolinea_con_menos_retrasos;
        nombre_aerolinea_con_mas_retrasos = "";
        nombre_aerolinea_con_menos_retrasos = "";
        for (int i = 0; i < num; i++)
        {
                printf("\n");
                printf("aeroline's name: %s\n Aerolinea ID: %d\n", aerolineas[i].name, aerolineas[i].aeroLinea_id);
                printf("\n");
                int j = 0;
                float monto_total;
                int total = 0;
                while (j < aerolineas[i].numero_vuelos_diarios)
                {
                        if (aerolineas[i].flights[j].condiciones_salida == 0)
                        {
                                monto_total += ((aerolineas[i].flights[j].costo_boleto * aerolineas[i].flights[j].numero_de_pasajeros) * 5) / 100;
                                total++;
                        }
                        j++;
                }
                int x = 0;
                while (x < aerolineas[i].numero_vuelos_diarios)
                {

                        if (total > max)
                        {
                                max = total;
                                nombre_aerolinea_con_mas_retrasos = aerolineas[i].name;
                        }
                        x++;
                }
                int z = 0;
                while (z < aerolineas[i].numero_vuelos_diarios)
                {
                        if (total < min)
                        {
                                min = total;
                                nombre_aerolinea_con_menos_retrasos = aerolineas[i].name;
                        }
                        z++;
                }
                printf("Monto Total a cancelar por multas aplicadas %f\n", monto_total);
                monto_total_de_multas += monto_total;
                printf("Total de vuelos retrasados %d\n", total);
                printf("\n");
        }

        printf("\n");

        printf("maximo de vuelos retrasados %d aerolinea: %s\n", max, nombre_aerolinea_con_mas_retrasos);
        printf("minimo de vuelos retrasados %d aerolinea: %s\n", min, nombre_aerolinea_con_menos_retrasos);
        printf("Monto total recaudado por multas %f \n", monto_total_de_multas);

        return 0;
}
