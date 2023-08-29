/*
Brayan Ivan Perez Ventura - 372781

Código creado: 27 de agosto del 2023 / Código modificado: 27 de agosto del 2023

Algoritmo que lee 3 y despliega los 3 números ordenados ascendentemente

PVBI_Act1_9_932
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

    if (num1 <= num2){
        if (num1 <= num3){
            if (num2 <= num3){
                printf("%.2f, %.2f, %.2f", num1, num2, num3);
            } else {
                printf("%.2f, %.2f, %.2f", num1, num3, num2);
            }
        } else {
            printf("%.2f, %.2f, %.2f", num3, num1, num2);
        }
    } else {
        if (num2 <= num3){
            if (num3 <= num1){
                printf("%.2f, %.2f, %.2f", num2, num3, num1);
            } else {
                printf("%.2f, %.2f, %.2f", num2, num1, num3);
            }
        } else {
            printf("%.2f, %.2f, %.2f", num3, num2, num1);
        }
    }
    return 0;
}