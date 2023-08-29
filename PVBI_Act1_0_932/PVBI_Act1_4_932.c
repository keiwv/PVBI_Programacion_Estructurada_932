/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Algoritmo que despliega un menú, en el cual el usuario debe elegir su sexo, según el que elija
imprimirá una leyenda, si es hombre: "HOLA, ERES HOMBRE" y si es mujer "HOLA, ERES MUJER"

PVBI_Act1_4_932
*/

#include <stdio.h>

int main (){
    int sexo;

    printf("Cual es tu sexo?\n");
    printf("1.- Hombre\n");
    printf("2.- Mujer\n");
    printf("Selecciona el numero: ");
    scanf("%d", &sexo);

    if (sexo == 1) {
        printf("HOLA, ERES HOMBRE");
    } else {
        printf("HOLA, ERES MUJER");
    }
    return 0;
}