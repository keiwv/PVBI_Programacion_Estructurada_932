/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de Septiembre del 2023 / Código modificado: 03 de Septiembre del 2023

Algoritmo que despliega el total de una llamada telefónica donde se pide como datos
de entrada los minutos y el tipo de llamada.
Se cobra de la siguiente manera: 

** Llamada local $3.00 sin límite de tiempo
** Llamada nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional
** Llamada internacional $9.00 por los 2 primeros minutos y $4.00 por minuto adicional.


PVBI_Act2_5_932
*/


#include <stdio.h>

int main() {
    int opcion, minutos, minutos_extra;
    float iva, total, subtotal, total_extra;
    
    float costo_llamada_local = 3.00;
    int limite_minutos_nacional = 3;
    float costo_llamada_nacional_inicial = 7.00;
    float costo_llamada_nacional_extra = 2.00;
    int limite_minutos_internacional = 2;
    float costo_llamada_internacional_inicial = 9.00;
    float costo_llamada_internacional_extra = 4.00;
    float tasa_iva = 0.16;

    printf("Precio total de una llamada telefónica\n");
    printf("Ingresa la cantidad de minutos hechos: ");
    scanf("%d", &minutos);
    printf("Cual es tu tipo de llamada?\n");
    printf("1.- Llamada local\n");
    printf("2.- Llamada nacional\n");
    printf("3.- Llamada internacional\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("----- Llamada local -----\n");
        subtotal = costo_llamada_local;

    } else if (opcion == 2) {
        printf("----- Llamada nacional -----\n");
        if (minutos <= limite_minutos_nacional) {
            subtotal = costo_llamada_nacional_inicial;

        } else {
            minutos_extra = minutos - limite_minutos_nacional;
            total_extra = costo_llamada_nacional_extra * minutos_extra;
            subtotal = costo_llamada_nacional_inicial + total_extra;

        }
    } else if (opcion == 3) {
        printf("----- Llamada internacional -----\n");
        if (minutos <= limite_minutos_internacional) {
            subtotal = costo_llamada_internacional_inicial;

        } else {
            minutos_extra = minutos - limite_minutos_internacional;
            total_extra = costo_llamada_internacional_extra * minutos_extra;
            subtotal = costo_llamada_internacional_inicial + total_extra;

        }
    } else {
        printf("Opción no válida\n");
        return 1; // Salir del programa con un código de error
    }

    iva = subtotal * tasa_iva;
    total = iva + subtotal;

    printf("El subtotal de tu llamada es: %.2f\n", subtotal);
    printf("El IVA de tu llamada: %.2f\n", iva);
    printf("El total seria: %.2f\n", total);

    return 0;
}
