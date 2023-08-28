/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Algoritmo que lee 4 calificaciones, saca el promedio y en base a este, imprime si estás aprobado o reprobado

PVBI_Act1_1_932
*/

#include <stdio.h>


int main(){
    
    int cali_1, cali_2, cali_3, cali_4, promedio;

    printf("Inserte la calificacion de la primera materia: ");
    scanf("%d",&cali_1);
    printf("Inserte la calificacion de la segunda materia: ");
    scanf("%d",&cali_2);
    printf("Inserte la calificacion de la tercera materia: ");
    scanf("%d",&cali_3);
    printf("Inserte la calificacion de la cuarta materia: ");
    scanf("%d",&cali_4);

    promedio = (cali_1 + cali_2 + cali_3 + cali_4) / 4;
    if (promedio >= 60){
        printf("Aprobado");
    }
    if (promedio < 60){
        printf("Reprobado");
    }

    return 0;
}