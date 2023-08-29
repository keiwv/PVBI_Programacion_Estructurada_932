/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Algoritmo que lee 3 calificaciones, saca el promedio y según el promedio, se estarán evaluando en un rango de promedio con if anidados (Anidado por el verdadero). 

PVBI_Act1_5_932
*/

#include <stdio.h>

int main(){
    //Declaracion de variables 
    int cali_1, cali_2, cali_3, promedio;
    
    //Introducción de calificaciones
    printf("Inserte la calificacion de la primera materia: ");
    scanf("%d",&cali_1);
    printf("Inserte la calificacion de la segunda materia: ");
    scanf("%d",&cali_2);
    printf("Inserte la calificacion de la tercera materia: ");
    scanf("%d",&cali_3);

    //Obtención del promedio
    promedio = (cali_1 + cali_2 + cali_3) / 3;

    //Comparación utilizando if anidados para obtener su situación actual
    if (promedio < 30){
        printf("Repetir");
    } else {
        if (promedio >= 30){
            if (promedio < 60){
                printf("Extraordinario");
            } else {
                if (promedio >= 60){
                    if (promedio < 70){
                        printf("Suficiente");
                    } else {
                        if (promedio >= 70){
                            if (promedio < 80){
                                printf("Regular");
                            } else {
                                if (promedio >= 80){
                                    if (promedio < 90){
                                        printf("Bien");
                                    } else {
                                        if (promedio >= 90){
                                            if (promedio < 98){
                                                printf("Muy bien");
                                            } else {
                                                if (promedio >= 98){
                                                    if (promedio <= 100){
                                                        printf("Excelente");
                                                    } else {
                                                        if (promedio > 100){
                                                            printf("Error en promedio");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } 
            }
        }
    }
    
    return 0;

}