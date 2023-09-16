#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Prototipos de funciones
void vercomandos();
void calcularModa(float arreglo[], int tamaño);
float calcularVarianza(float arreglo[], int tamaño);
float calcularDesviacionEstandar(float arreglo[], int tamaño);
float calcularCuartil1(float arreglo[], int tamaño);
float calcularCuartil3(float arreglo[], int tamaño);

void vercomandos()
{
    printf("\n\t|   COMANDO   |                  FUNCION                                          |\t");
    printf("\n\t|---------------------------------------------------------------------------------|\t");
    printf("\n\t|    ayuda    | Imprime nuevamente la tabla de ayuda.                             |\t");
    printf("\n\t|    salir    | Termina el programa.                                              |\t");
    printf("\n\t|      n      | Cambiar la cantidad de datos (por defec, n=100).                  |\t");
    printf("\n\t|    datos    | Cambiar todos los datos con los que usted desea trabajar.         |\t");
    printf("\n\t|   cambiar   | Cambiar un dato en la posicion especifica.                       |\t");
    printf("\n\t|   imprimir  | Imprimir los datos ordenados con los que se trabajan actualmente. |\t");
    printf("\n\t|    media    | Calcular la media aritmetica del conjunto de datos                |\t");
    printf("\n\t|   mediana   | Calcular la mediana del conjunto de datos.                        |\t");
    printf("\n\t|     moda    | Calcular la moda del conjunto de datos.                           |\t");
    printf("\n\t|   varianza  | Calcular la varianza del conjunto de datos.                       |\t");
    printf("\n\t|   desvest   | Calcular la desviacion estandar del conjunto de datos.            |\t");
    printf("\n\t|  cuartil_1  | Calcular el primer cuartil del conjunto de datos.                 |\t");
    printf("\n\t|  cuartil_3  | Calcular el tercer cuartil del conjunto de datos.                 |\t");
    printf("\n\t|     ric     | Calcular el rango intercuartilado del conjunto de datos.          |\t");
    printf("\n\t|    rango    | Calcular el rango del conjunto de datos.                          |\t");
    printf("\n\t|    todos    | Calcular todas las medidas del sobre el conjunto de datos.        |\t");
}
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
// Función para calcular la varianza de un arreglo
float calcularVarianza(float arreglo[], int tamaño)
{
    // Calcular la media de los datos
    float suma = 0;
    for (int i = 0; i < tamaño; i++)
    {
        suma += arreglo[i];
    }
    float media = suma / tamaño;

    // Calcular la suma de cuadrados de las diferencias (SSD)
    float ssd = 0;
    for (int i = 0; i < tamaño; i++)
    {
        float diferencia = arreglo[i] - media;
        ssd += diferencia * diferencia;
    }

    // Calcular la varianza
    float varianza = ssd / (tamaño - 1);

    return varianza;
}
// Calculo de desviacion estandar
float calcularDesviacionEstandar(float arreglo[], int tamaño)
{
    // Calcular la varianza
    float suma = 0;
    for (int i = 0; i < tamaño; i++)
    {
        suma += arreglo[i];
    }
    float media = suma / tamaño;

    float ssd = 0;
    for (int i = 0; i < tamaño; i++)
    {
        float diferencia = arreglo[i] - media;
        ssd += diferencia * diferencia;
    }

    float varianza = ssd / (tamaño - 1);

    // Calcular la desviación estándar (raíz cuadrada de la varianza)
    float desviacion_estandar = sqrt(varianza);

    return desviacion_estandar;
}
// Funcion para calcular el cuartil 1
float calcularCuartil1(float arreglo[], int tamaño)
{
    // Asegúrate de que los datos estén ordenados en orden ascendente
    // (puedes usar la función de ordenamiento que ya tienes)

    // Calcular el índice del cuartil 1
    float indice = 0.25 * (tamaño + 1);

    // Si el índice no es un número entero, interpola entre los valores cercanos
    if (indice != (int)indice)
    {
        int i = (int)indice;
        float fraccion = indice - i;
        return arreglo[i - 1] + fraccion * (arreglo[i] - arreglo[i - 1]);
    }
    else
    {
        int i = (int)indice;
        return arreglo[i - 1];
    }
}
// Función para calcular el cuartil 3 (Q3) de un arreglo ordenado
float calcularCuartil3(float arreglo[], int tamaño)
{
    // Asegúrate de que los datos estén ordenados en orden ascendente
    // (puedes usar la función de ordenamiento que ya tienes)

    // Calcular el índice del cuartil 3
    float indice = 0.75 * (tamaño + 1);

    // Si el índice no es un número entero, interpola entre los valores cercanos
    if (indice != (int)indice)
    {
        int i = (int)indice;
        float fraccion = indice - i;
        return arreglo[i - 1] + fraccion * (arreglo[i] - arreglo[i - 1]);
    }
    else
    {
        int i = (int)indice;
        return arreglo[i - 1];
    }
}
// Función para encontrar el valor máximo en un arreglo
float encontrarMaximo(float arreglo[], int tamaño)
{
    float maximo = arreglo[0]; // Suponemos que el primer elemento es el máximo inicialmente

    for (int i = 1; i < tamaño; i++)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i]; // Actualizamos el máximo si encontramos un valor mayor
        }
    }

    return maximo;
}

// Función para encontrar el valor mínimo en un arreglo
float encontrarMinimo(float arreglo[], int tamaño)
{
    float minimo = arreglo[0]; // Suponemos que el primer elemento es el mínimo inicialmente

    for (int i = 1; i < tamaño; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i]; // Actualizamos el mínimo si encontramos un valor menor
        }
    }

    return minimo;
}

/*int cambiar_n(int i);
void llenar(float datos[], int n);
void imprimir(float datos[], int n);
float media(float datos[], int n);
float mediana(float datos[], int n);
float moda(float datos[], int n);
float rango(float datos[], int n);
float varianza(float datos[], int n);
float des_estandar(float datos[], int n);
float cuartil_1(float datos[], int n);
float cuartil_3(float datos[], int n);
float rango_intercuartil(float datos[], int n);
void todo(float datos[], int n);
*/
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
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Cambie el tamaño primero.\n");
            }
            else
            {
                // Pedir al usuario que ingrese los datos en el nuevo arreglo
                printf("Ingrese %d elementos del arreglo:\n", tamaño);
                for (int i = 0; i < tamaño; i++)
                {
                    printf("Dato [%d]: ", i); // Imprimir la posición del dato
                    scanf("%f", &arreglo[i]);
                }
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
                ordenarArreglo(arreglo, tamaño);
                float mediana;
                if (tamaño % 2 == 0)
                {
                    mediana = (arreglo[tamaño / 2] + arreglo[(tamaño / 2) - 1]) / 2;
                }
                else
                {
                    mediana = arreglo[tamaño / 2];
                }
                printf("La mediana de los datos en el arreglo es: %.2f\n", mediana);
            }
        }

        else if (strcmp(opc, "moda") == 0)
        {
            // Salir del programa si el usuario ingresa "moda"
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
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                float varianza = calcularVarianza(arreglo, tamaño);
                printf("La varianza es: %.2f\n", varianza);
            }
        }
        else if (strcmp(opc, "desvest") == 0)
        {
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                float desviacion_estandar = calcularDesviacionEstandar(arreglo, tamaño);
                printf("La desviación estándar es: %.2f\n", desviacion_estandar);
            }
        }
        else if (strcmp(opc, "cuartil_1") == 0)
        {

            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                // Asegurarse de que el arreglo esté ordenado (puedes llamar a tu función de ordenamiento aquí)
                // Luego, calcular el cuartil 1
                ordenarArreglo(arreglo, tamaño);

                float q1 = calcularCuartil1(arreglo, tamaño);

                printf("El pimer cuartil es: %.2f\n", q1);
            }
        }
        else if (strcmp(opc, "cuartil_3") == 0)
        {
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                // Asegurarse de que el arreglo esté ordenado (puedes llamar a tu función de ordenamiento aquí)
                // Luego, calcular el cuartil 3
                ordenarArreglo(arreglo, tamaño);
                float q3 = calcularCuartil3(arreglo, tamaño);
                printf("El tercer cuartil es: %.2f\n", q3);            
                }
        }
        else if (strcmp(opc, "ric") == 0)
        {
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                // Asegurarse de que el arreglo esté ordenado (puedes llamar a tus funciones de ordenamiento aquí)
                // Luego, calcular el cuartil 1 (Q1) y el cuartil 3 (Q3)
                float q1 = calcularCuartil1(arreglo, tamaño);
                float q3 = calcularCuartil3(arreglo, tamaño);

                // Calcular el rango intercuartílico (IQR)
                float iqr = q3 - q1;

                printf("El rango intercuartílico (IQR) es: %.2f\n", iqr);
            }
        }
        else if (strcmp(opc, "rango") == 0)
        {
            if (tamaño == 0)
            {
                printf("El tamaño del arreglo es 0. Ingrese datos primero.\n");
            }
            else
            {
                // Llamamos a las funciones para encontrar el máximo y el mínimo
                float maximo = encontrarMaximo(arreglo, tamaño);
                float minimo = encontrarMinimo(arreglo, tamaño);

                // Calculamos el rango como la diferencia entre el máximo y el mínimo
                float rango = maximo - minimo;

                printf("El rango de los datos en el arreglo es: %.2f\n", rango);
            }
        }
        else if (strcmp(opc, "todos") == 0)
        {
            break;
        }
        else
        {
            printf("\nComando no reconocido. Ingrese 'ayuda' para ver los comandos disponibles.");
        }
    }

    return 0;
}