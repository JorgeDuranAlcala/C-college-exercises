#include <stdio.h>

void main(void) {

	int N, numero_de_personas = 1, edad, SEX;
	float promedio_peso = 0.00, promedio_alt = 0.00, ALT, PES;
	
	printf("How many people?\n");
	scanf("%d", &N);

	while(N >= 1) {

		printf("how tall are you?\n");
		scanf("%f", &ALT);

		printf("how much do you weigh?\n");
		scanf("%f", &PES);
		
		printf("how old are you?\n");
		scanf("%d", &edad);

		 if(edad >= 18 ) {
                        promedio_peso += PES;
                        promedio_alt += ALT;

                        numero_de_personas++;
                };

		   while(1) {
                        printf("what's your gender?, 1 for male, 0 for female\n");
                        scanf("%d", &SEX); 
			if(SEX == 1 || SEX == 0) break;
                        printf("%d is not valid number, choose either 1 or 0, please\n", SEX);
                   }

		

		N--;
	}

	promedio_peso /= numero_de_personas;
	promedio_alt /= numero_de_personas;

	printf("average of weight %4.2f \n", promedio_peso);
	printf("average of height %4.2f \n", promedio_alt);
}
