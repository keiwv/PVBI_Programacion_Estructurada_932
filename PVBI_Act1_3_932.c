/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Algoritmo que lee 4 calificaciones, saca el promedio e imprime tu promedio y una leyendo si aprobó o reprobó

PVBI_Act1_3_932
*/

#include <stdio.h>


int main(){
    
    int calificacion[3], promedio;

    printf("Inserte la calificacion de la primera materia: ");
    scanf("%d",&calificacion[0]);
    printf("\nInserte la calificacion de la segunda materia: ");
    scanf("%d",&calificacion[1]);
    printf("\nInserte la calificacion de la tercera materia: ");
    scanf("%d",&calificacion[2]);
    printf("\nInserte la calificacion de la cuarta materia: ");
    scanf("%d",&calificacion[3]);

    promedio = (calificacion[0] + calificacion[1] + calificacion[2] + calificacion [3]) / 4;
   
    if (promedio >= 60 ){
        printf("Tu promedio es %d y estas APROBADO", promedio);
    } else {
        printf("Tu promedio es %d y estas REPROBADO", promedio);
    }

    return 0;
}