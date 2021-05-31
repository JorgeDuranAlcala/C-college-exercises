#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
  int flight_id;
  int numero_de_pasajeros;
  float costo_boleto;
  int condiciones_salida;
} Flight;

typedef struct {
  int aeroLinea_id;
  char name[100];
  Flight flights[];
} aeroLinea;

void print_aerolinea_data(aeroLinea *A) {
   printf("aerolines's name: %s", A->name);
}

void iterar_aerolineas(aeroLinea *a, size_t num) {
  
   for(int i = 0; i < num; i++) {
   	printf("aeroline's name: %s\n", a[i].name);
   }
}

int main(void) {
   char nombre_aerolinea[100];
   int numero_de_aerolineas, numero_de_vuelos_diarios, numero_de_vuelo, numero_de_pasajeros;
   int condiciones_de_salida;
   float costo_del_boleto; 
   aeroLinea aerolineas[] = {};

   printf("Numero de aerolineas\n");
   scanf("%d", &numero_de_aerolineas);
   //printf("n %d\n", numero_de_aerolineas);
   int i = 0;
   while(1) {
	 printf("n de aero: %d\n", numero_de_aerolineas);
	if(numero_de_aerolineas == 0) break;
	aeroLinea aero_linea = {i + 1};
   	printf("nombre aerolinea\n");
	scanf("%s", nombre_aerolinea);
	strcpy(aero_linea.name, nombre_aerolinea);
	

	printf("numero de vuelos diarios \n");
	scanf("%d", &numero_de_vuelos_diarios);
	int j = 0;
	while(1) {
	   if(numero_de_vuelos_diarios == 0) break;
	  //printf("i: %d, j: %d\n", i, j);
	 Flight flight = {j + 1};
	   
	 printf("numero de pasajeros \n");
         scanf("%d", &numero_de_pasajeros);
	 printf("Costo del boleto \n");
         scanf("%f", &costo_del_boleto);
	 printf("Condiciones de vuelo 1 para 'a tiempo' y 0 para 'retrasado'\n");
         scanf("%d", &condiciones_de_salida);

	 flight.numero_de_pasajeros = numero_de_pasajeros;
	 flight.costo_boleto = costo_del_boleto;
	 flight.numero_de_pasajeros = numero_de_pasajeros;
	 flight.condiciones_salida = condiciones_de_salida;
	 
	 aero_linea.flights[j] = flight;

	 numero_de_vuelos_diarios--;
	 j++;	 
	}

	aerolineas[i] = aero_linea;
	numero_de_aerolineas--;
	i++;
   }


   //iterar_aerolineas(aerolineas, sizeof(aerolineas) / sizeof(*aerolineas));

  for(i = 0; i < sizeof(aerolineas)/sizeof(aerolineas[0]); i++) {	
    printf(" Name %d \n" , i);
  }

   return 0;
   /*Flight flights[] = {{"turkey", 1}, {"spain", 2}, {"france", 3} };
   aeroLinea avior = {1, "Avior"};
   for(int i = 0; i < 3; i++) {
   	avior.flights[i] = flights[i];
   }
//   avior.flights = flights;
   print_struct_al(&avior); */
}


