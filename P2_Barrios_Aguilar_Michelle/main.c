#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

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
        }
        else if (strcmp(opc, "moda") == 0)
        {
            // Salir del programa si el usuario ingresa "moda"
            printf("\nInstrucciones para el comando 'moda':\n");
        }
        else if (strcmp(opc, "varianza") == 0)
        {
            // Salir del programa si el usuario ingresa "varianza"
            printf("\nInstrucciones para el comando 'varianza':\n");
        }
        else if (strcmp(opc, "desvest") == 0)
        {
            // Salir del programa si el usuario ingresa "desvest"
            printf("\nInstrucciones para el comando 'desvest':\n");
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
}
