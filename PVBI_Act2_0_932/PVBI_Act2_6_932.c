/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de Septiembre del 2023 / Código modificado: 03 de Septiembre del 2023

Programa en C que sirve para calcular el Total a pagar por consumo de agua, donde el dato
de entrada son los M3 de agua consumidos.
Se cobra de la siguiente manera:
De 0 a 4 M3 $50 sin importar cuanto se consumió.
5 a 15 M3 $8 x M3
16 a 50 M3 $10 x M3
51 en adelante $11 x M3 
Se desplegará subtotal, iva y total a pagar

PVBI_Act2_6_932
*/

#include <stdio.h>

int main(){
    float m3_consumidos, subtotal, total, ivatotal;

    float tasa_iva = 0.16;

    int m3_r1 = 4; //r1 significa el rango.
    int m3_r2 = 15;
    int m3_r3 = 50;

    int m3_pago1 = 50;
    int m3_pago2 = 8;
    int m3_pago3 = 10;
    int m3_pago4 = 11; 

    printf("Programa que calcula el total a pagar por consumo de agua\n");
    printf("Ingresa la cantidad de m3 consumidos: ");
    scanf("%f",&m3_consumidos);

    if (m3_consumidos > 0){
        if (m3_consumidos < m3_r1){

            subtotal = m3_pago1;
        } else {
            if (m3_consumidos < m3_r2){
                subtotal = m3_pago2 * m3_consumidos;

            } else {
                if (m3_consumidos < m3_r3){
                    subtotal = m3_pago3 * m3_consumidos;

                } else {
                    subtotal = m3_pago4 * m3_consumidos;  

                }
            }
        }

        ivatotal = subtotal * tasa_iva;
        total = subtotal + ivatotal;

        printf("Subtotal: %2.f\n", subtotal);
        printf("IVA: %.2f\n", ivatotal);
        printf("Total a pagar: %.2f\n", total);

    } else {
        printf("Introduce una cantidad correcta.");
    }
    return 0;
}