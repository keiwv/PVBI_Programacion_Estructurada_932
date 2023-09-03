/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de septiembre del 2023 / Código modificado: 03 de septiembre del 2023

Algoritmo que calcula el salario semanal de un trabajador en función de las horas trabajadas y el salario por hora ingresados por el usuario
Este imprime los datos relevantes incluyendo el salario por hora, las horas trabajadas, el salario normal, extra y triple, así como el salario total.


PVBI_Act2_4_932
*/

#include <stdio.h>

int main() {
    int hrs_trabajo, hrs_extras;
    float salario, total_salario, salario_extra, salario_normal, salario_triple;
    float factor_salario_doble = 2;
    float factor_salario_triple = 3;
    int horas_normales = 40;
    int horas_dobles_1 = 49;
    int horas_dobles_2 = 9;

    printf("Introduce la cantidad de horas trabajadas durante la semana: ");
    scanf("%d", &hrs_trabajo);
    printf("Introduce el salario por hora del trabajador: ");
    scanf("%f", &salario);

    if (hrs_trabajo <= horas_normales) {
        total_salario = hrs_trabajo * salario;
        salario_normal = total_salario;
        salario_extra = 0;

    } else {
        if (hrs_trabajo <= horas_dobles_1) {

            hrs_extras = hrs_trabajo - horas_normales;
            salario_extra = (salario * factor_salario_doble) * hrs_extras;
            salario_normal = salario * (hrs_trabajo - horas_dobles_2);
            total_salario = salario_extra + salario_normal;

        } else {

            hrs_extras = hrs_trabajo - horas_dobles_1;
            salario_extra = (salario * factor_salario_doble) * horas_dobles_2;
            salario_triple = (salario * factor_salario_triple) * hrs_extras;
            salario_normal = salario * (hrs_trabajo - (hrs_extras + horas_dobles_2));
            total_salario = salario_extra + salario_normal + salario_triple;

        }
    }

    printf("El salario por hora es: %.1f\n", salario);
    printf("Horas trabajadas: %d\n", hrs_trabajo);
    printf("Salario normal es: %.1f\n", salario_normal);
    printf("Salario extra: %.1f\n", salario_extra);
    printf("Salario total: %.1f\n", total_salario);

    return 0;
}
