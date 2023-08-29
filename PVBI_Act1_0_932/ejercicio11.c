/*
Brayan Ivan Perez Ventura - 372781

Código creado: 27 de agosto del 2023 / Código modificado: 27 de agosto del 2023

Algoritmo que despliega el total de una llamada telefónica donde se pide como datos
de entrada los minutos y el tipo de llamada.
Se cobra de la siguiente manera: 

** Llamada local $3.00 sin límite de tiempo
** Llamada nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional
** Llamada internacional $9.00 por los 2 primeros minutos y $4.00 por minuto adicional.


PVBI_Act1_11_932
*/

#include <stdio.h>

int main(){
    int opcion,minutos, minutos_extra;
    float iva, total, subtotal, total_extra;
    printf("Precio total de una llamada telefonica\n");
    printf("Ingresa la cantidad de minutos hechos: ");
    scanf("%d",&minutos);
    printf("Cual es tu tipo de llamada?\n");
    printf("1.- Llamada local\n");
    printf("2.- Llamada nacional\n");
    printf("3.- Llamada internacional\n");
    printf("Selecciona tu opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1){

        printf("----- Llamada local -----\n");
        iva = 3 * 0.16;
        subtotal = 3;
        total = iva + subtotal;
        printf("El subtotal de tu llamada es: %.2f", subtotal);
        printf("\nEl IVA de tu llamada: %.2f",iva);
        printf("\nEl total seria: %.2f\n", total);

    } else {
        if (opcion == 2){
            if (minutos <= 3){

                printf("----- Llamada nacional -----\n");
                subtotal = 7;
                iva = subtotal * 0.16;
                total = iva + subtotal;
                printf("El subtotal de tu llamada es: %.2f", subtotal);
                printf("\nEl IVA de tu llamada: %.2f",iva);
                printf("\nEl total seria: %.2f\n", total);

            } else {

                printf("----- Llamada nacional -----\n");
                minutos_extra = minutos - 3;
                total_extra = 2*minutos_extra;
                subtotal = 7 + total_extra;
                iva = subtotal * 0.16;
                total = iva + subtotal;
                printf("El subtotal de tu llamada es: %.2f", subtotal);
                printf("\nEl IVA de tu llamada: %.2f",iva);
                printf("\nEl total seria: %.2f\n", total);
            }

        } else {
            if (minutos <= 2){
                printf("----- Llamada internacional -----\n");
                subtotal = 7;
                iva = subtotal * 0.16;
                total = iva + subtotal;
                printf("El subtotal de tu llamada es: %.2f", subtotal);
                printf("\nEl IVA de tu llamada: %.2f",iva);
                printf("\nEl total seria: %.2f\n", total);
            } else {
                printf("----- Llamada internacional -----\n");
                minutos_extra = minutos - 2;
                total_extra = 4*minutos_extra;
                subtotal = 9 + total_extra;
                iva = subtotal * 0.16;
                total = iva + subtotal;
                printf("El subtotal de tu llamada es: %.2f", subtotal);
                printf("\nEl IVA de tu llamada: %.2f",iva);
                printf("\nEl total seria: %.2f\n", total);
            }
        }
    }
    printf("\n");
    return 0;
}