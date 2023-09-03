/*
Brayan Ivan Perez Ventura - 372781

Código creado: 02 de septiembre del 2023 / Código modificado: 03 de septiembre del 2023

Programa en C que lee 6 números y despliega el valor del número mayor.

PVBI_Act2_3_932
*/

#include <stdio.h>

int main(){
    int num[5];

    printf("Programa para el despligue del numero mayor de 6 numeros enteros\n");

    printf("Ingresa el valor del numero 1: ");
    scanf("%d", &num[0]);
    printf("Ingresa el valor del numero 2: ");
    scanf("%d", &num[1]);
    printf("Ingresa el valor del numero 3: ");
    scanf("%d", &num[2]);
    printf("Ingresa el valor del numero 4: ");
    scanf("%d", &num[3]);
    printf("Ingresa el valor del numero 5: ");
    scanf("%d", &num[4]);
    printf("Ingresa el valor del numero 6: ");
    scanf("%d", &num[5]);

    if (num[0] > num[1]){
        if (num[0] > num[2]){
            if (num[0] > num[3]){
                if (num[0] > num[4]){
                    if (num[0] > num[5]){
                        printf("El numero mayor es: %d",num[0]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            } else {
                if (num[3] > num[4]){
                    if (num[3] > num[5]){
                        printf("El numero mayor es: %d", num[3]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            }
        } else {
            if (num[2] > num[3]){
                if (num[2] > num[4]){
                    if (num[2]> num[5]){
                        printf("El numero mayor es: %d", num[2]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            } else {
                if (num[3] > num[4]){
                    if (num[3] > num[5]){
                        printf("El numero mayor es: %d", num[3]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            }
        }
    } else {
        if (num[1]>num[2]){
            if (num[1] > num[3]){
                if (num[1] > num[4]){
                    if (num[1] > num[5]){
                        printf("El numero mayor es: %d", num[1]);
                    } else {
                        printf("El número mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            } else {
                if (num[3] > num[4]){
                    if (num[3] > num[5]){
                        printf("El numero mayor es: %d", num[3]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            }
        } else {
            if (num[2] > num[3]){
                if (num[2] > num[4]){
                    if (num[2] > num[5]){
                        printf("El numero mayor es: %d", num[2]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            } else {
                if (num[3] > num[4]){
                    if (num[3] > num[5]){
                        printf("El numero mayor es: %d", num[3]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                } else {
                    if (num[4] > num[5]){
                        printf("El numero mayor es: %d", num[4]);
                    } else {
                        printf("El numero mayor es: %d", num[5]);
                    }
                }
            }
        }
    }
    return 0;
}