/*
Brayan Ivan Perez Ventura - 372781

Código creado: 27 de agosto del 2023 / Código modificado: 27 de agosto del 2023

Algoritmo que lee 3 y desplegará el número del medio con su valor correspondiente

PVBI_Act1_8_932
*/

#include <stdio.h>

int main(){
    float num1, num2, num3;

    printf("Programa para saber el numero menor de 3 numeros\n");
    printf("Introduce el valor del primer numero: ");
    scanf("%f",&num1);
    printf("Introduce el valor del segundo numero: ");
    scanf("%f",&num2);
    printf("Introduce el valor del tercer numero: ");
    scanf("%f",&num3);

    if (num1 <= num2) {
        if (num2 <= num3) {
            printf("El numero del medio es: %.2f", num2);
        } else {
            if (num1 <= num3) {
                printf("El numero del medio es: %.2f", num3);
            } else {
                printf("El numero del medio es: %.2f", num1);
            }
        }
    } else {
        if (num1 <= num3) {
            printf("El numero del medio es: %.2f", num1);
        } else {
            if (num2 <= num3) {
                printf("El numero del medio es: %.2f", num3);
            } else {
                printf("El numero del medio es: %.2f", num2);
            }
        }
    }
}