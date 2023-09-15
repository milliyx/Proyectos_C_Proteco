#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include <math.h>

// Función para ordenar un arreglo en orden ascendente (utilizando el algoritmo de burbuja)
void ordenarArreglo(float arreglo[], int tamaño)
{
    for (int i = 0; i < tamaño - 1; i++)
    {
        for (int j = 0; j < tamaño - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                // Intercambiar los elementos si están en el orden incorrecto
                float temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}
// Función para calcular la moda de un arreglo
void calcularModa(float arreglo[], int tamaño)
{
    int frecuencias[tamaño]; // Arreglo para almacenar las frecuencias
    for (int i = 0; i < tamaño; i++)
    {
        frecuencias[i] = 0; // Inicializar todas las frecuencias a 0
    }

    // Calcular las frecuencias de cada valor
    for (int i = 0; i < tamaño; i++)
    {
        int frecuenciaActual = 1; // Inicializar la frecuencia actual a 1
        for (int j = i + 1; j < tamaño; j++)
        {
            if (arreglo[i] == arreglo[j])
            {
                frecuenciaActual++; // Incrementar la frecuencia si se encuentra un valor igual
            }
        }
        frecuencias[i] = frecuenciaActual;
    }

    // Encontrar el valor o valores con la frecuencia máxima
    int maxFrecuencia = 0;
    for (int i = 0; i < tamaño; i++)
    {
        if (frecuencias[i] > maxFrecuencia)
        {
            maxFrecuencia = frecuencias[i];
        }
    }

    // Imprimir los valores que tienen la frecuencia máxima (la moda)
    printf("La moda del arreglo es/son:\n");
    for (int i = 0; i < tamaño; i++)
    {
        if (frecuencias[i] == maxFrecuencia)
        {
            printf("%.2f ", arreglo[i]);
        }
    }
    printf("\n");
}
/// @brief
/// @return
int main()
{
    printf("INSTRUCCIONES: Cuando aparezca '>' puedes teclear cualquiera de los siguientes comandos que se muestran en la siguiente tabla.\n");
    vercomandos();

    char opc[100];
    float arreglo[100];
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    // int n = 1; // Tamaño inicial del arreglo (inicialmente 1)

    while (1)
    {                   // Bucle infinito para aceptar múltiples comandos
        printf("\n> "); // Muestra el símbolo ">" para indicar que el usuario debe ingresar un comando
        scanf("%s", opc);

        if (strcmp(opc, "ayuda") == 0)
        {
            vercomandos();
            printf("\n\n\n"); // Coloca aquí las instrucciones específicas
        }
        else if (strcmp(opc, "salir") == 0)
        {
            break; // Termina el bucle
        }
        else if (strcmp(opc, "n") == 0)
        {

            // Mostrar el tamaño actual del arreglo
            printf("\nEl tamaño actual del arreglo es: %d\n", tamaño);
            char opc2;
            printf("¿Deseas cambiar la cantidad de datos? (Y/N): ");
            scanf(" %c", &opc2);

            int num;

            if (opc2 == 'Y' || opc2 == 'y')
            {
                printf("Ingrese el nuevo tamaño del arreglo (máximo 100): ");
                scanf("%d", &num);

                if (num > 100 || num < 0)
                {
                    printf("Tamaño de arreglo no válido.\n");
                    return 1; // Salir del programa con error
                }

                printf("El nuevo tamaño del arreglo es: %d\n", num);
                tamaño = num;
            }
        }
        else if (strcmp(opc, "datos") == 0)
        {
            // Salir del programa si el usuario ingresa "datos"

            printf("Ingrese %d elementos del arreglo:\n", tamaño);
            for (int i = 0; i < tamaño; i++)
            {
                printf("Dato [%d]: ", i); // Imprimir la posición del dato
                scanf("%f", &arreglo[i]);
            }
        }
        else if (strcmp(opc, "cambiar") == 0)
        {
            // Salir del programa si el usuario ingresa "cambiar"
            printf("\nInstrucciones para el comando 'cambiar':\n");
        }
        else if (strcmp(opc, "imprimir") == 0)
        {
            // Salir del programa si el usuario ingresa "imprimir"
            printf("Los nuevos elementos del arreglo son:\n");
            for (int i = 0; i < tamaño; i++)
            {
                printf("Dato[%d]: %f \n", i, arreglo[i]);
            }
        }
        else if (strcmp(opc, "media") == 0)
        {
            // Salir del programa si el usuario ingresa "media"
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                float suma = 0;
                for (int i = 0; i < tamaño; i++)
                {
                    suma += arreglo[i];
                }
                float media = suma / tamaño;
                printf("La media de los datos en el arreglo es: %.2f\n", media);
            }
        }
        else if (strcmp(opc, "mediana") == 0)
        {
            // Salir del programa si el usuario ingresa "mediana"
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                // Ordenar el arreglo en orden ascendente
                ordenarArreglo(arreglo, tamaño);

                float mediana;
                if (tamaño % 2 == 0)
                {
                    // Si la cantidad de datos es par, calcular el promedio de los dos valores centrales
                    int indice1 = tamaño / 2 - 1;
                    int indice2 = tamaño / 2;
                    mediana = (arreglo[indice1] + arreglo[indice2]) / 2.0;
                }
                else
                {
                    // Si la cantidad de datos es impar, el valor central es la mediana
                    int indice = tamaño / 2;
                    mediana = arreglo[indice];
                }

                printf("La mediana de los datos en el arreglo es: %.2f\n", mediana);
            }
        }
        else if (strcmp(opc, "moda") == 0)
        {
            // Salir del programa si el usuario ingresa "moda"
            printf("\nInstrucciones para el comando 'moda':\n");
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                calcularModa(arreglo, tamaño);
            }
        }
        else if (strcmp(opc, "varianza") == 0)
        {
            // Salir del programa si el usuario ingresa "varianza"
            printf("\nInstrucciones para el comando 'varianza':\n");
            // Calcular la suma de cuadrados de las diferencias (SSD)
            float ssd = 0;
            for (int i = 0; i < tamaño; i++)
            {
                float diferencia = arreglo[i] - media;
                ssd += diferencia * diferencia;
            }

            // Calcular la varianza
            float varianza = ssd / (tamaño - 1);

            printf("La varianza es: %.2f\n", varianza);
        }
        else if (strcmp(opc, "desvest") == 0)
        {
            // Salir del programa si el usuario ingresa "desvest"
            float desviacion_estandar = sqrt(varianza);

            printf("La desviación estándar es: %.2f\n", desviación_estandar);
        }
        else if (strcmp(opc, "cuartil_1") == 0)
        {
            // Salir del programa si el usuario ingresa "cuartil_1"
            printf("\nInstrucciones para el comando 'cuartil_1':\n");
        }
        else if (strcmp(opc, "cuartil_3") == 0)
        {
            // Salir del programa si el usuario ingresa "cuartil_3"
            printf("\nInstrucciones para el comando 'cuartil_3':\n");
        }
        else if (strcmp(opc, "ric") == 0)
        {
            // Salir del programa si el usuario ingresa "ric"
            printf("\nInstrucciones para el comando 'ric':\n");
        }
        else if (strcmp(opc, "rango") == 0)
        {
            // Salir del programa si el usuario ingresa "rango"
            printf("\nInstrucciones para el comando 'rango':\n");
        }
        else if (strcmp(opc, "todos") == 0)
        {
            // Salir del programa si el usuario ingresa "todos"
            printf("\nInstrucciones para el comando 'todos':\n");
            break; // Termina el bucle
        }
        else
        {
            printf("\nComando no reconocido. Ingrese 'ayuda' para ver los comandos disponibles.");
        }
    }

    return 0;