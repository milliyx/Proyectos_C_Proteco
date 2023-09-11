#include <stdio.h>

int main(){

    //declaraciòn de variables de tipo real
    float num1, num2;
    float sum, res, mult, div;

    //pedir al usuario
    printf("Ingresa el primer numero: \n");
    scanf("%f", &num1);
    printf("Ingresa el segundo numero: \n");
    scanf("%f", &num2);
    //impresiòn de los numeros ingresados
    printf("Sus numeros ingresados fueron: %.4f y %.4f\n\n", num1, num2);
    //operaciones aritméticas
    sum = num1 + num2;
    res = num1 - num2;
    mult = num1 * num2;
    div = num1/num2;
    //impresión de tabla con formato y resultados correspondientes
    printf("\n\t|       OPERACIÓN       |       RESULTADO       |\t");   
    printf("\n\t------------------------------- -------- --------\t");
    printf("\n\t|        SUMA           |      %-9.4f        |\t",sum);
    printf("\n\t|        RESTA          |      %-9.4f        |\t",res);
    printf("\n\t|    MULTIPLICACION     |      %-9.4f        |\t",mult);
    printf("\n\t|      DIVISION         |      %-9.4f        |\t",div);

    return 0;
}