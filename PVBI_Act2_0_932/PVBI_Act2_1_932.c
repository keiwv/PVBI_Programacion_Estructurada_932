/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Programa que utiliza un menú para realizar 4 operaciones básicas, donde el usuario introduce
2 números enteros y realizará la operación según sea su selección del menú.
El menú estará compuesto por: 1.- Suma 2.- Resta 3.- Multiplicación 4.- División

PVBI_Act2_1_932
*/

#include <stdio.h>

int main(){
    //Declaración de variables
    int num1, num2, opcion;

    //Despliegue del menú
    printf("Programa para realizar 4 operaciones basicas\n");
    printf("Elige tu opcion\n");
    printf("1.- Suma\n");
    printf("2.- Resta\n");
    printf("3.- Multiplicacion\n");
    printf("4.- Division\n");
    scanf("%d",&opcion);

    //Entrada de números
    printf("Ingresa el primer valor entero: ");
    scanf("%d",&num1);
    printf("Introduce el segundo valor entero: ");
    scanf("%d",&num2);


    if (opcion == 1)
    {
        printf("El resultado de la suma es: %d",(num1+num2));
    } 
    else
    {
        if (opcion == 2)
        {
            printf("El resultado de la resta es: %d",(num1-num2));
        } 
        else
        {
            if (opcion == 3)
            {
                printf("El resultado de la multiplicacion es: %d",(num1-num2));
            }
            else
            {
                if (num2 != 0)
                {
                    printf("El resultado de la division: %d",(num1/num2));
                }
                else
                {
                    printf("La operacion no puede hacerse porque el denominador no puede ser 0");
                }
            }
        }
    } 
}