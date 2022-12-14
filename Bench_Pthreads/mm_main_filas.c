/*************************************************
*Fecha: 09-agosto-2022
*Autor: Juan Pablo Barrios Suarez
*Materia: Parallel and Distribuited Computing
*Tema: Construcción Benchmark Multiplicación de matrices
*Tópico: Uso Pthreads para paralelismo
**************************************************/
#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>


/****
 * Función principal de la aplicación 
****/
int main(int argc, char **argv){
    double *matA, *matB, *matC;
    int N, Num_Hilos;
    //arg1.size = (int) atof(argv[1]);
    //arg1.Num_Hilos = (int) atof(argv[2]);
    N = (int) atof(argv[1]);
    Num_Hilos = (int) atof(argv[2]);
    //N = (int) atof(argv[1]); //Cantidad Filas/Columnas
    //Num_Hilos = (int) atof(argv[2]); // Cantidad de hilos
    int MAX_NUM_HILOS = omp_get_max_threads();
    if(!(Num_Hilos >0 && Num_Hilos <= MAX_NUM_HILOS) || N % Num_Hilos != 0){
        printf("\t¡Revise los datos de entrada!\n");
        printf("\t Los siguientes items pueden estar fallando:\n");
        printf("\t\t 1. No exceder el numero maximo de hilos que es %d:\n", MAX_NUM_HILOS);
        printf("\t\t 2. El número de hilos no puede ser negativo \n");
        printf("\t\t 3. El tamaño de la matriz no se puede dividir exactamente entre el número de hilos: \n");
        exit(0);
    }
    printf("\t-> Número de hilos máximo a usar en este ordenador: %d:\n", MAX_NUM_HILOS);
    /****
     * Declaración de matrices con apuntadores a memoria
    ****/

    matA = (double *)malloc(N*N*sizeof(double));
    matB = (double *)malloc(N*N*sizeof(double));
    matC = (double *)malloc(N*N*sizeof(double));

    //printf("\t-> Inicializacion con double:\n");
    inicializacion_mm_double(matA, matB, matC, N);
    impresion_mm_double(matA, N);
    impresion_mm_double(matB, N);
    

    /****
     * Inicio de toma de tiempo
     * Mulplticación de matrices
     * Fin de toma de tiempo 
    ****/

   // Se reserva la memoria para cada hilo
    punto_prueba_inicial();
    mm_F(matA, matB, matC, N, Num_Hilos);
    punto_prueba_final();

    
    
    impresion_mm_double(matC, N);
    //printf("\t-------------------------------------\n");
    
    free(matA);
    free(matB);
    free(matC);
    
    return 0;
}
