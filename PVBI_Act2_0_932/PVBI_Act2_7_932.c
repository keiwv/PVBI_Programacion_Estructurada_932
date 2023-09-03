/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de Septiembre del 2023 / Código modificado: 03 de Septiembre del 2023

Algoritmo para calcular el promedio final de la materia, donde la calificación menor de los exámenes
se anula y el promedio se calcula en base a 4 exámenes.

PVBI_Act2_7_932
*/

#include <stdio.h>

int main(){

    int cali_exam[4];
    float promedio;

    printf("Ingresa el valor de la primera calificaion del examen: ");
    scanf("%d", &cali_exam[0]);
    printf("Ingresa el valor de la segunda calificaion del examen: ");
    scanf("%d", &cali_exam[1]);
    printf("Ingresa el valor de la tercera calificaion del examen: ");
    scanf("%d", &cali_exam[2]);
    printf("Ingresa el valor de la cuarta calificaion del examen: ");
    scanf("%d", &cali_exam[3]);

    if (cali_exam[0] < cali_exam[1]){
        if (cali_exam[0] < cali_exam[2]){
            if (cali_exam[0] < cali_exam[3]){
                cali_exam[0] = 0;
            } else{
                cali_exam[3] = 0;
            }
        } else {
            if (cali_exam[2] < cali_exam[3]){
                cali_exam[2] = 0;
            } else {
                cali_exam[3] = 0;
            }
        }
    } else {
        if (cali_exam[1] < cali_exam[2]){
            if (cali_exam[1] < cali_exam[3]){
                cali_exam[1] = 0;
            } else {
                cali_exam[3] = 0;
            }
        } else {
            if (cali_exam[2] < cali_exam[3]){
                cali_exam[2] = 0;
            } else {
                cali_exam[3] = 0;
            }
        }
    }
    promedio = (cali_exam[0] + cali_exam[1] + cali_exam[2] + cali_exam[3]) / 3;
    printf("El promedio final es: %.2f", promedio);

    return 0;
}