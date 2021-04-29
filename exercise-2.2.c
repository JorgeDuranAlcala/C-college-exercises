#include <stdio.h>

	void main() {
		int sal;
		printf("Ingrese su salario actual\n");
		scanf("%d", &sal);
		
		if(sal < 18000) {
			sal += (12 * sal) / 100;
		}
		else if(sal >= 18000 && sal <= 30000) {
		
			sal += (8 * sal) / 100;
		}
		
		else if(sal > 30000 && sal <= 50000) {
		
			sal += (7 * sal) / 100;
		}

		else if(sal > 50000 ) {
	
			sal += (6 * sal) / 100;
		}

		printf("Su salario despuues de su respectivo aumento es %d \n", sal);
	}
