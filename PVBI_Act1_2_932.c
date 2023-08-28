/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Algoritmo que lee un número entero, y despliega si el número es “PAR” o “IMPAR”

PVBI_Act1_2_932
*/

#include <stdio.h>

int main() {
    int num;

    printf("Introduce un valor entero: ");
    scanf("%d",&num);

    if (num % 2 == 0){
        printf("El numero es par");
    }

    if (num % 2 != 0){
        printf("El numero es impar");
    } 

    return 0;
}