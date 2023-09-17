#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    printf("\n-----------------------------------CALCULADORA DE MEDIDAS Y TENDENCIA CENTRAL Y DE DISPERSION---------------------------------\n");
    printf("INSTRUCCIONES: Cuando aparezca '>' puedes teclear cualquiera de los siguientes comandos que se muestran en la siguiente tabla.\n");
    vercomandos();

    char opc[100]; //para guardar la opcion que ingresa el usuario
    float arreglo[100]; //para guardar los datos que ingresa el usuario en un arreglo inicializado en 100 por especificaciones 
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);//para guardar el tamaño del arreglo

    while (1)
    {                   
        printf("\n> "); 
        scanf("%s", opc);

        if (strcmp(opc, "ayuda") == 0)
        {
            vercomandos();
            printf("\n\n\n"); 
        }
        else if (strcmp(opc, "salir") == 0)
        {
            break; 
        }
        else if (strcmp(opc, "n") == 0)
        {

            printf("\nEl numero actual de elementos del arreglos es n = %d\n", tamaño);
            char opc2;
            printf("¿Deseas modificar n? (Y/N): ");
            scanf(" %c", &opc2);

            int num;

            if (opc2 == 'Y' || opc2 == 'y')
            {
                printf("Indica el nuevo tamaño del arreglo (max: 100): ");
                scanf("%d", &num);

                if (num > 100 || num < 0)
                {
                    printf("Excede el maximo.\n");
                    return 1; 
                }

                printf("Tu numero de elementos para el arreglo ha cambiado a n = %d\n", num);
                tamaño = num;
            }
        }
        else if (strcmp(opc, "datos") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {
                printf("Ingresa %d elementos para tu arreglo:\n", tamaño);
                for (int i = 0; i < tamaño; i++)
                {
                    printf("Dato [%d]: ", i); 
                    scanf("%f", &arreglo[i]);
                }
            }
        }
        else if (strcmp(opc, "cambiar") == 0)
        {

            int posicion;
            float nuevoValor;
            for (int i = 0; i < tamaño; i++)
            {
                printf("Posicion[%d]: %f \n", i, arreglo[i]);
            }
            printf("Ingresa la posición del dato que deseas cambiar: ");

            scanf("%d", &posicion);

            printf("Ingresa el nuevo valor para el dato: ");
            scanf("%f", &nuevoValor);

            cambiarDato(arreglo, tamaño, posicion, nuevoValor);
        }
        else if (strcmp(opc, "imprimir") == 0)
        {
            for (int i = 0; i < tamaño; i++)
            {
                printf("Dato[%d]: %.4f \n", i, arreglo[i]);
            }
        }
        else if (strcmp(opc, "media") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {
                float suma = 0;
                for (int i = 0; i < tamaño; i++)
                {
                    suma += arreglo[i];
                }
                float media = calcularMedia(arreglo, tamaño);
                printf("La media del arreglo es: %.4f\n", media);
            }
        }
        else if (strcmp(opc, "mediana") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {
                float mediana = calcularMediana(arreglo, tamaño);
                printf("La mediana del arreglo es: %.4f\n", mediana);
            }
        }

        else if (strcmp(opc, "moda") == 0)
        {
            float moda = calcularModa(arreglo, tamaño);
        }
        else if (strcmp(opc, "varianza") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {
                float varianza = calcularVarianza(arreglo, tamaño);
                printf("La varianza del arreglo es: %.4f\n", varianza);
            }
        }
        else if (strcmp(opc, "desvest") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {
                float desviacion_estandar = calcularDesviacionEstandar(arreglo, tamaño);
                printf("La desviacion estandar del arreglo es: %.4f\n", desviacion_estandar);
            }
        }
        else if (strcmp(opc, "cuartil_1") == 0)
        {

            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");
            }
            else
            {             
                ordenarArreglo(arreglo, tamaño);
                float c_uno = calcularCuartil1(arreglo, tamaño);
                printf("El cuartil 1 es: %.4f\n", c_uno);
            }
        }
        else if (strcmp(opc, "cuartil_3") == 0)
        {
            if (tamaño == 0)
            {
                printf("El numero de elementos del arreglo es 0\n");

            }
            else
            {
             
                ordenarArreglo(arreglo, tamaño);
                float c_tres = calcularCuartil3(arreglo, tamaño);
                printf("El cuartil 3 es: %.4f\n", c_tres);
            }
        }
        else if (strcmp(opc, "ric") == 0)
        {

            float ric = calcularRIC(arreglo, tamaño);
            printf("El rango intercuartilico del arreglo es de: %.4f\n", ric);
        }
        else if (strcmp(opc, "rango") == 0)
        {
            float rango = calcularRango(arreglo, tamaño);
            printf("El rango del arreglo es de: %.4f\n", rango);
        }
        else if (strcmp(opc, "todos") == 0)
        {
            float media = calcularMedia(arreglo, tamaño);
            float mediana = calcularMediana(arreglo, tamaño);
            float varianza = calcularVarianza(arreglo, tamaño);
            float desviacion_estandar = calcularDesviacionEstandar(arreglo, tamaño);
            float cuartil1 = calcularCuartil1(arreglo, tamaño);
            float cuartil3 = calcularCuartil3(arreglo, tamaño);
            float rango_intercuartil = calcularRIC(arreglo, tamaño);
            float rango = calcularRango(arreglo, tamaño);

            printf("--------------------------------------------\n");
            printf("|        MEDIDA         |       RESULTADO  |\n");
            printf("--------------------------------------------\n");
            printf("|         Media         |     %10.2f       |\n", media);
            printf("|        Mediana        |     %10.2f       |\n", mediana);
            printf("|          Moda         | ");
            calcularModa(arreglo, tamaño);
            printf("|\n");
            printf("|        Varianza       |     %10.2f       |\n", varianza);
            printf("|  Desviacion Estandar  |     %10.2f       |\n", desviacion_estandar);
            printf("|       Cuartil 1       |     %10.2f       |\n", cuartil1);
            printf("|       Cuartil 3       |     %10.2f       |\n", cuartil3);
            printf("|        Rango          |     %10.2f       |\n", rango);
            printf("| Rango Intercuartilico |     %10.2f       |\n", rango_intercuartil);
            printf("------.-------------------------------------\n");
        }
        else
        {
            printf("\nTu comando ingresado no tiene ninguna coincidencia. Ingresa 'ayuda' para ver los comandos disponibles.");
        }
    }

    return 0;
}
