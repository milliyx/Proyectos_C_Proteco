#include <stdio.h>
#include <stdlib.h>
#include "contador.h"

// se definen los parametros pasandose como argumentos en la terminal para ser leidos
// int numArgumentos es el numero de argumentos que se pasan en la terminal
// char *argumentos[] es el arreglo de argumentos que se pasan en la terminal
int main(int numArgumentos, char *argumentos[])
{
    // verifica que se pasen los argumentos necesarios para que el programa funcione
    if (numArgumentos != 3)
    {
        printf("Uso: %s archEntrada archSalida\n", argumentos[0]);
        return 1;
    }

    // obtiene los nombres de archivo de los argumentos que represenatan el archivo de entrada y el archivo de salida
    char *nombreArchEntrada = argumentos[1];
    char *nombreArchSalida = argumentos[2];

    // abre los archivos de entrada y salida para su lectura y escritura respectivamente
    FILE *archivoEntrada = fopen(nombreArchEntrada, "r");
    FILE *archivoSalida = fopen(nombreArchSalida, "w");

    // verifica que los archivos se hayan abierto correctamente y si no, termina el programa
    if (archivoEntrada == NULL || archivoSalida == NULL)
    {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    if (archivoSalida == NULL)
    {
        printf("Error al abrir el archivo de salida.\n");
        fclose(archivoEntrada); // Cerrar el archivo de entrada antes de salir
        return 1;
    }

    // se crea un arreglo de estructuras de tipo Nodo para guardar las palabras y su frecuencia
    Nodo *palabras = NULL;
    int numPalabras = 0;
    char palabra[30];

    // se lee el archivo de entrada y se guardan las palabras en el arreglo de estructuras
    // procesa el archivo de entrada palabra por palabra
    // fscanf regresa 1 si se pudo leer una palabra y 0 si no se pudo leer una palabra

    while (fscanf(archivoEntrada, "%s", palabra) == 1)
    {
        // se limpia la palabra de puntos, comas y letras 's' si se encuentra en plural
        limpiar_palabra(palabra);
        // se busca la palabra en el arreglo de estructuras
        int indice = buscar_palabra(palabra, palabras);
        // si la palabra ya existe en el arreglo, se incrementa su frecuencia
        if (indice != -1)
        {
            palabras[indice].frecuencia++;
        }
        else
        {
            palabras = contar_palabra(palabra, palabras);
            numPalabras++;
        }
    }
    // se ordenan las palabras de mayor a menor frecuencia
    palabras = ordenar_palabras(palabras);
    // se guardan las palabras en el archivo de salida
    guardar_palabras(palabras, archivoSalida);
    // se cierran los archivos y se libera la memoria
    fclose(archivoEntrada);
    fclose(archivoSalida);
    free(palabras);

    return 0;
}
