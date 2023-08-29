/*
Brayan Ivan Perez Ventura - 372781

Código creado: 27 de agosto del 2023 / Código modificado: 27 de agosto del 2023

Algoritmo que calcula el salario semanal de un trabajador en función de las horas trabajadas y el salario por hora ingresados por el usuario
Este imprime los datos relevantes incluyendo el salario por hora, las horas trabajadas, el salario normal, extra y triple, así como el salario total.


PVBI_Act1_10_932
*/

#include <stdio.h>


int main(){
    int hrs_trabajo, hrs_extras;
    float salario, total_salario, salario_extra, salario_normal, salario_triple;

    printf("Introduce la cantidad de horas trabajadas durante la semana: ");
    scanf("%d", &hrs_trabajo);
    printf("Introduce el salario por hora del trabajador: ");
    scanf("%f",&salario);
    
    if (hrs_trabajo <= 40){

        total_salario = hrs_trabajo * salario;
        salario_normal = total_salario; //Al ser igual o menor a 40 horas, el salario normal no cambia y es igual al salario total.

        printf("El salario por hora es: %.1f", salario);
        printf("\nHoras trabajadas: %d", hrs_trabajo);
        printf("\nSalario normal es: %.1f", salario_normal);
        printf("\nSalario extra: 0"); //Este siempre será 0 porque las horas son menores a 40, por lo tanto, no hay horas extras.
        printf("\nSalario total: %.1f", total_salario);

    } else {
        if (hrs_trabajo <= 49){

            hrs_extras = hrs_trabajo - 40;
            salario_extra = (salario * 2) * hrs_extras;
            salario_normal = salario * 40;
            total_salario = salario_extra + salario_normal;

            printf("El salario por hora es: %.1f", salario);
            printf("\nHoras trabajadas: %d", hrs_trabajo);
            printf("\nSalario normal es: %.1f", salario_normal);
            printf("\nSalario extra: %.1f", salario_extra); 
            printf("\nSalario total: %.1f", total_salario);
        } else {

            hrs_extras = hrs_trabajo - 49;
            salario_extra = (salario * 2) * 9;
            salario_triple = (salario * 3) * hrs_extras;
            salario_normal = salario * 40;
            total_salario = salario_extra + salario_normal + salario_triple;

            printf("El salario por hora es: %.1f", salario);
            printf("\nHoras trabajadas: %d", hrs_trabajo);
            printf("\nSalario normal es: %.1f", salario_normal);
            printf("\nSalario extra: %.1f", salario_extra); 
            printf("\nSalario total: %.1f", total_salario); 
        }
    }
    return 0;

}