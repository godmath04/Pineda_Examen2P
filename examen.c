/*
Cada semestre, a la materia de Programación se inscriben una cantidad constante de 23 alumnos. El semestre está dividido en 3 progresos. Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes cálculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificación durante el semestre
*/

/* CONSIDERACIONES PERSONALES ---  LA GENERACION DE NOTAS SERA ALEATORIA
LA NOTA SERA SOBRE 0- 100 PUNTOS Y CADA ALUMNO TEDRÁ 5 NOTAS PARA LUEGO OBTENER SU PROMEDIO*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creo una matriz 3D para que la profundidad indique el progreso, la fila los alumnos y la columna las notas
void notasProgreso(int progreso, int alumnos, int notas, int MatrizCalificaciones[progreso][alumnos][notas])
{
    for (int k = 0; k < progreso; k++)
    {
        printf("***PROGRESO %d:\n", k + 1);

        for (int i = 0; i < alumnos; i++)
        {
            printf("Alumno %d:\t", i + 1);
            for (int j = 0; j < notas; j++)
            {
                MatrizCalificaciones[k][i][j] = rand() % 11;
                printf("%6d\t|", MatrizCalificaciones[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void PromedioCalificaciones(int progreso, int alumnos, int notas, int MatrizCalificaciones[progreso][alumnos][notas])
{

    notasProgreso(progreso, alumnos, notas, MatrizCalificaciones);
    // SUMA DE NOTAS POR CADA PROGRESO
    for (int k = 0; k < progreso; k++)
    {
        printf("***PROGRESO %d:\n", k + 1);

        for (int i = 0; i < alumnos; i++)
        {
            int suma = 0;
            for (int j = 0; j < notas; j++)
            {

                suma = suma + MatrizCalificaciones[k][i][j];
            }
            float promedio = (float )suma / notas;

            printf("Alumno: %d\t su promedio es: %f\n", i + 1, promedio);
            printf("\n");
        };
    }
}

int main(int argc, char const *argv[])
{

    printf("***** NOTAS DE LA CARRERA DE ING.*****\n");
    int alumnos = 3, progreso = 1, notas = 5;
    int MatrizNotas[progreso][alumnos][notas];
    PromedioCalificaciones(progreso, alumnos, notas, MatrizNotas);

    return 0;
}
