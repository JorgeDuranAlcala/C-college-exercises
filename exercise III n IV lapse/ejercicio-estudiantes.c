#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**  
 * @author Jorge Luis Duran Alcala
 * @cedula 28.511.812
 * @carrera Ingenieria de sistemas D1
 * @Asignatura Lenguajes de Programacion I
 * @Profesora Ing. Wilmary Colmenarez
 **/

/* crear struct student */
/* 
    El struct estudiante va a tener la siguiente estructura
    - nombre
    - cedula
    - sexo
        - 1 representa masculino
        - 0 representa femenino
    - nota
        - entre 0 y 20
 */

typedef struct
{
    char nombre[50];
    char cedula[12];
    int sexo;
    int nota;
} Estudiante;

/* funcion que lee los datos de los estudiantes */
void readEstudiantesData(Estudiante *, int TAM);
/* funcion que imprime lista de alumnos aplazados */
void printAlumnosAplazados(Estudiante *, int TAM);
/* funcion que busca la persona con mayor nota */
Estudiante buscarPersonaConMayorNota(Estudiante *, int TAM);
/* Funcion que imprime los datos de la persona con mayor nota */
void printPersonaConMayorNota(Estudiante *, int TAM);
/* funcion que imprime porcentaje de cada sexo */
void printPorcentajeCadaSexo(Estudiante *, int TAM);
/* funcion que devuelve el porcentaje de notas */
float getPorcentajeDeNotas(Estudiante *, int TAM);
/* funcion que imprime el promedio de todos las notas */
void printPromedioNotas(Estudiante *, int TAM);

/* funciones de ayuda  */
/* la funcion printAllStudents aunque no esta en el enunciado del problema, yo la
   utilize con fines de probar que lo datos de los estudiantes fueran correctos */
void printAllStudents(Estudiante *, int TAM);
/* funcion que comprueba si el estudiante ya se ha registrada
    retorna 1 si esta registrado y 0 si no lo esta
*/
int buscarEstudianteById(Estudiante *, int TAM, char cedula[12]);

void main()
{
    int TAM;
    /* definir array de studiantes */
    Estudiante estudiantes[20];
    // preguntar al usuario el numero de estudiantes que hay
    do
    {
        printf("Ingrese el numero de estudiantes\n");
        scanf("%i", &TAM);
        fflush(stdin);
    } while (TAM > 50 || TAM < 1);

    /* 
        funcion que leera los datos de todos los estudiantes
     */
    system("cls");
    readEstudiantesData(estudiantes, TAM);
    printPersonaConMayorNota(estudiantes, TAM);
    printAlumnosAplazados(estudiantes, TAM);
    printPorcentajeCadaSexo(estudiantes, TAM);
    printPromedioNotas(estudiantes, TAM);
}

void readEstudiantesData(Estudiante estudiantes[], int TAM)
{
    int i = 0;
    for (int i = 0; i < TAM; i++)
    {
        system("cls");
        printf("Ingresar nombre del estudiante %i \n", i + 1);
        gets(estudiantes[i].nombre);
        fflush(stdin);

        system("cls");

        /* Ciclo que checkea que el sexo esta en un formato correcto 
           Caso contrario: imprime un mensaje de error
        */

        while (1)
        {
            printf("Ingresar sexo del estudiante %i, ingresa 1 para masculino, 0 para femenino \n", i + 1);
            scanf("%d", &estudiantes[i].sexo);
            fflush(stdin);
            if (estudiantes[i].sexo == 1 || estudiantes[i].sexo == 0)
                break;
            system("cls");
            printf("**Opcion no valida, ingrese 1 para masculino o 0 para femenino**\n");
        }

        system("cls");

        /*  Ciclo que checkea que el estudiante solo se pueda registrar una sola vez,
            todo esto basandoce en la cedula.
            Caso contrario: imprime un mensaje de error
        */

        while (1)
        {
            printf("Ingrese la cedula del estudiante %i \n", i + 1);
            gets(estudiantes[i].cedula);
            fflush(stdin);
            if (buscarEstudianteById(estudiantes, TAM, estudiantes[i].cedula) == 0)
            {
                break;
            }
            else
            {
                system("cls");
                printf("** Este estudiante ya ha sido registrado **\n");
            }
        }

        system("cls");

        /* Ciclo que checkea que la nota esta en un formato correcto 
            Caso contrario: imprime un mensaje de error
        */
        do
        {
            printf("Ingrese la nota del estudiante %i \n", i + 1);
            scanf("%i", &estudiantes[i].nota);
            fflush(stdin);

            if (estudiantes[i].nota < 0 || estudiantes[i].nota > 20)
            {
                system("cls");
                printf("**La nota del estudiante tiene que estar entre 0 y 20 puntos**\n");
            }

        } while (estudiantes[i].nota < 0 || estudiantes[i].nota > 20);
    }
}

// funcion que imprime los alumnos aplazados
void printAlumnosAplazados(Estudiante estudiantes[], int TAM)
{
    //int n = 1;
    //Estudiante estudiantesAplazados[n];
    int numero_de_aplazados = 0;
    printf("Lista alumnos aplazados: \n");
    for (int i = 0; i < TAM; i++)
    {

        if (estudiantes[i].nota < 10)
        {
            printf("    -Alumno %s aplazado con una nota de %i\n", estudiantes[i].nombre, estudiantes[i].nota);
            numero_de_aplazados++;
        }
    }

    if (numero_de_aplazados < 1)
    {
        printf("    -No hay alumnos aplazados");
    }
    printf("\n\n");
}

// funcion que imprime el porcentaje de mujeres y hombres
void printPorcentajeCadaSexo(Estudiante estudiantes[], int TAM)
{
    float num_mujeres = 0, num_hombres = 0, total_estudiantes = 0;
    float porcentaje_mujeres = 0.00, porcentaje_hombres = 0.00;
    for (int i = 0; i < TAM; i++)
    {

        switch (estudiantes[i].sexo)
        {
        case 1:
            num_hombres++;
            break;

        default:
            num_mujeres++;
            break;
        }

        total_estudiantes++;
    }

    porcentaje_mujeres = (num_mujeres / total_estudiantes) * 100;
    porcentaje_hombres = (num_hombres / total_estudiantes) * 100;

    printf("Porcentaje de estudiantes mujeres: %4.2f ", porcentaje_mujeres);
    printf("\n");
    printf("Porcentaje de estudiantes hombres: %4.2f ", porcentaje_hombres);
    printf("\n\n");
}

// funcion que imprime el promedio de todas las notas en pantalla
void printPromedioNotas(Estudiante estudiantes[], int TAM)
{
    float promedio_notas = getPorcentajeDeNotas(estudiantes, TAM);

    printf("Promedio de las notas: %4.2f", promedio_notas);
    printf("\n\n");
}

// funcion que calcula el promedio de todas las notas
float getPorcentajeDeNotas(Estudiante estudiantes[], int TAM)
{
    float promedio_notas = 0.00, total_notas = 0, cantidad_estudiantes = 0;
    for (int i = 0; i < TAM; i++)
    {
        total_notas += estudiantes[i].nota;
        cantidad_estudiantes++;
    }

    promedio_notas = total_notas / cantidad_estudiantes;

    return promedio_notas;
}

/* funcion que imprime todos los estudiantes
    ** utilizada para pruebas solamente **
 */
void printAllStudents(Estudiante estudiantes[], int TAM)
{
    system("cls");
    for (int i = 0; i < TAM; i++)
    {
        printf("Estudiante %i nombre: %s, ", i, estudiantes[i].nombre);
        switch (estudiantes[i].sexo)
        {
        case 1:
            printf("sexo: masculino, ");
            break;

        default:
            printf("sexo: femenino, ");
            break;
        }
        printf("cedula: %s, ", estudiantes[i].cedula);
        printf("nota: %i, ", estudiantes[i].nota);
        printf("\n\n");
    }
}
/* fucion que se encarga de buscar la mayor nota entre los estudiantes */
Estudiante buscarPersonaConMayorNota(Estudiante estudiantes[], int TAM)
{
    Estudiante estudiante_mayorNota;
    for (int i = 0; i < TAM; i++)
    {
        if (estudiantes[i].nota > estudiante_mayorNota.nota)
        {
            estudiante_mayorNota = estudiantes[i];
        }
    }

    return estudiante_mayorNota;
}
/* Funcion que imprime los datos de la persona con mayor nota */
void printPersonaConMayorNota(Estudiante estudiantes[], int TAM)
{
    Estudiante estudiante_mayorNota = buscarPersonaConMayorNota(estudiantes, TAM);
    printf("La persona con mayor nota fue: %s, Con una nota de %i\n\n", estudiante_mayorNota.nombre, estudiante_mayorNota.nota);
}

/* 
    funcion que detecta si el estudiante ya fue registrado
    basandoce en la cedula
 */
int buscarEstudianteById(Estudiante estudiantes[], int TAM, char cedula[12])
{
    int count = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (strstr(estudiantes[i].cedula, cedula))
        {
            count++;
        }
    }

    if (count >= 2)
        return 1;
    else
        return 0;
}