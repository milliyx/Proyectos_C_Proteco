#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // para tolower() que convierte una letra a minúscula
#include "contador.h"

// esta funcion recibe una cadena, la convierte toda a minusculas y le quita puntos (.), comas (,) y letras 's'
void limpiar_palabra(char *palabra)
{
    // Convertir la palabra a minúsculas con tolower()
    for (int i = 0; palabra[i]; i++)
    {
        palabra[i] = tolower(palabra[i]);
    }
    // se obtiene la longitud de la palabra
    int longitud = strlen(palabra);

    // elimina puntos (.)
    for (int i = 0; i < longitud; i++)
    {
        if (palabra[i] == '.')
        {
            for (int j = i; j < longitud; j++)
            {
                palabra[j] = palabra[j + 1];
            }
            longitud--;
            i--;
        }
    }

    // eliminar comas (,)
    for (int i = 0; i < longitud; i++)
    {
        if (palabra[i] == ',')
        {
            for (int j = i; j < longitud; j++)
            {
                palabra[j] = palabra[j + 1];
            }
            longitud--;
            i--;
        }
    }

    // eliminar 's' al final de la palabra
    if (longitud > 0 && palabra[longitud - 1] == 's')
    {
        palabra[longitud - 1] = '\0';
    }
}
// recibe una palabra y un arreglo de estructuras de tipo Nodo y regresa el arreglo de estructuras actualizado
Nodo *contar_palabra(const char *palabra, Nodo *palabras)
{
    int indice = buscar_palabra(palabra, palabras);

    if (indice != -1)
    {
        // si la palabra ya existe en el arreglo, incrementar la frecuencia
        palabras[indice].frecuencia++;
    }
    else
    {
        // si la palabra no existe en el arreglo, agregarla
        int numPalabras = 0;
        if (palabras != NULL)
        {
            while (palabras[numPalabras].frecuencia > 0)
            {
                numPalabras++;
            }
        }
        // se crea un nuevo nodo para guardar la nueva palabra
        Nodo nueva_palabra;
        // se copia la palabra al nuevo nodo mediante strcpy()
        strcpy(nueva_palabra.palabra, palabra);
        nueva_palabra.frecuencia = 1;

        // aignar memoria para un nuevo arreglo de palabras
        Nodo *nuevo_arreglo = (Nodo *)malloc((numPalabras + 2) * sizeof(Nodo));
        // se verifica que se haya asignado memoria correctamente, sino mandar mensaje de error y terminar el programa

        if (nuevo_arreglo == NULL)
        {
            printf("error en la asignación de memoria.\n");
            exit(1);
        }

        // copia las palabras del arreglo actual al nuevo arreglo
        for (int i = 0; i < numPalabras; i++)
        {
            nuevo_arreglo[i] = palabras[i];
        }

        // agrega la nueva palabra al nuevo arreglo
        nuevo_arreglo[numPalabras] = nueva_palabra;

        // agregar un nodo adicional vacío al final del nuevo arreglo
        nuevo_arreglo[numPalabras + 1].frecuencia = 0;

        // libera la memoria del arreglo antiguo
        free(palabras);

        // devuelve el nuevo arreglo
        palabras = nuevo_arreglo;
    }

    return palabras;
}

// recibe una palabra y un arreglo de estructuras de tipo Nodo y regresa el indice de la palabra en el arreglo de estructuras
int buscar_palabra(const char *palabra, Nodo *palabras)
{
    if (palabras == NULL)
    {
        return -1; // el arreglo está vacío, no se encuentra la palabra
    }

    for (int i = 0; palabras[i].frecuencia > 0; i++)
    {
        if (strcmp(palabras[i].palabra, palabra) == 0)
        {
            return i; // la palabra se encontró en el arreglo
        }
    }

    return -1; // la palabra no se encontró en el arreglo
}

// recibe un arreglo de estructuras de tipo Nodo y lo regresa ordenado de mayor a menor frecuencia
Nodo *ordenar_palabras(Nodo *palabras)
{
    if (palabras == NULL)
    {
        return NULL; // el arreglo está vacío, no hay nada que ordenar
    }

    int numPalabras = 0;
    // se obtiene el numero de palabras en el arreglo
    while (palabras[numPalabras].frecuencia > 0)
    {
        numPalabras++;
    }

    for (int i = 0; i < numPalabras - 1; i++)
    {
        for (int j = 0; j < numPalabras - i - 1; j++)
        {
            if (palabras[j].frecuencia < palabras[j + 1].frecuencia)
            {
                // Intercambiar las palabras si están en el orden incorrecto
                Nodo temp = palabras[j];
                palabras[j] = palabras[j + 1];
                palabras[j + 1] = temp;
            }
        }
    }

    return palabras;
}
// recibe un arreglo de estructuras de tipo Nodo y un archivo y guarda las palabras en el archivo
void guardar_palabras(const Nodo *palabras, FILE *frecuencias)
{
    if (palabras == NULL || frecuencias == NULL)
    {
        printf("argumentos invalidos\n");
        return;
    }

    fprintf(frecuencias, "Palabra            Frecuencia\n");
    // se imprimen las palabras y su frecuencia en el archivo
    int i = 0;
    while (palabras[i].frecuencia > 0)
    {
        fprintf(frecuencias, "%s                %10d\n", palabras[i].palabra, palabras[i].frecuencia);
        i++;
    }

    printf("tus palabras han sido guardadas en archivo de frencuencias\n");
}
