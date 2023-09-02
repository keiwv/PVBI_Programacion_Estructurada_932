/*
Brayan Ivan Perez Ventura - 372781

Código creado: 22 de agosto del 2023 / Código modificado: 26 de agosto del 2023

Programa que use un menú para realizar conversiones de unidades de medida, donde el usuarioo selecciona
una opción y realizará la opción según sea su selección del menú
El cual está conformado por: 1.- cm a pulgadas, 2.- cm a pies, 3.- km a millas, 4.- pulgadas a cm
5.- pies a cm, 6.- millas a km.


PVBI_Act2_2_932
*/

#include <stdio.h>

int main(){
    int opcion = 0;
    float unidad = 0;
    float resultado = 0;

    printf("Menu para realizar conversiones de unidades\n");
    printf("1.- Cm a Pulgadas\n");
    printf("2.- Cm a Pies\n");
    printf("3.-  Km a Millas\n");
    printf("4.- Pulgadas a Cm\n");
    printf("5.- Pies a Cm\n");
    printf("6.- Millas a Km\n");
    printf("Ingresa tu opcion: ");
    scanf("%d",&opcion);

    printf("Ingrese la medida a convertir: ");
    scanf("%f",&unidad);

    if (opcion == 1){
        //cm a pulgadas
        resultado = unidad * 0.393701;

    } else {
        if (opcion == 2){
            //Cm a Pies
            resultado = unidad * 0.0328084;

        } else {
            if (opcion == 3){
                //km a millas
                resultado = unidad * 0.621371;

            } else {
                if (opcion == 4){
                    //pulgadas a cm
                    resultado = unidad * 2.54;

                } else {
                    //Pies a cm
                    if (opcion == 5){
                        resultado = unidad * 30.48;

                    } else {
                        //Milas a km
                        resultado = unidad * 1.60934;

                    }
                }
            }
        }
    }
    printf("El resultado es: %.2f",resultado);
}