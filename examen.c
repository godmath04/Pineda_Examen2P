/*
Cada semestre, a la materia de Programación se inscriben una cantidad constante de 23 alumnos. El semestre está dividido en 3 progresos. Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes cálculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificación durante el semestre
*/

/* CONSIDERACIONES PERSONALES ---  LA GENERACION DE NOTAS SERA ALEATORIA
LA NOTA SERA SOBRE 0- 10 PUNTOS Y CADA ALUMNO TEDRÁ 5 NOTAS PARA LUEGO OBTENER SU PROMEDIO*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creo una matriz 3D para que la profundidad indique el progreso, la fila los alumnos y la columna las notas
// GENERO LAS NOTAS ALEATORIAMENTE
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


// FUNCION PROMEDIO Y APROVECHO PARA OBTENER EL ALUMNO CON LA MAYOR NOTA
void PromedioCalificaciones(int progreso, int alumnos, int notas, int MatrizCalificaciones[progreso][alumnos][notas])
{
    // SUMA DE NOTAS POR CADA PROGRESO Y ALUMNO CON LA MEJOR NOTA
    // ARREGLO PARA UBICAR LA MEJOR NOTA
    int mejorAlumno = -1,i;
    float mejorNota = -1.00;

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
            float promedio = (float)suma / notas;

            printf("Alumno: %d\t su promedio es: %f\n", i + 1, promedio);
            printf("\n");

            // VERIFICACIÓN DE LA MEJOR NOTA
            if (promedio > mejorNota)
            {
                mejorNota = promedio;
                mejorAlumno = i+1;
            }
            
        }
        printf("El alumno con la mejora es %d y tiene nota  %f\n",mejorAlumno, mejorNota);
    }
}

// FUNCION PARA OBBTENER EL PROMEDIO DE FORMA GRUPAL
void promedioGrupo(int progreso, int alumnos, int notas, int MatrizCalificaciones[progreso][alumnos][notas])
{
    int sumafilas = 0, sumacolumnas = 0;

    for (int k = 0; k < progreso; k++)
    {
        printf("***PROGRESO %d:\n", k + 1);
        sumacolumnas = 0;
        for (int i = 0; i < alumnos; i++)
        {
            sumafilas = 0;
            for (int j = 0; j < notas; j++)
            {

                sumafilas = sumafilas + MatrizCalificaciones[k][i][j];
            }
            sumacolumnas = sumacolumnas + sumafilas;
        }
        float promediocurso = (float)sumacolumnas / (alumnos * notas);
        printf("En el Progreso %d\t el promedio del curso es: %f\n", k + 1, promediocurso);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{

    printf("***** NOTAS DE LA CARRERA DE ING.*****\n");
    const int alumnos = 23, progreso = 3, notas = 5;
    int MatrizNotas[progreso][alumnos][notas];
    
    notasProgreso(progreso, alumnos, notas, MatrizNotas);
    printf("\n");
    PromedioCalificaciones(progreso, alumnos, notas, MatrizNotas);
    printf("\n");
    promedioGrupo(progreso, alumnos, notas, MatrizNotas);
    return 0;
}
