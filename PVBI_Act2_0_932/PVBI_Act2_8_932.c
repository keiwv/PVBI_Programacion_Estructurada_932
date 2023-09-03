/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de Septiembre del 2023 / Código modificado: 03 de Septiembre del 2023

Juego llamado "Chinchampú (Papel, piedra, tijera)" para 1 jugador contra la computadora utilizando condiciones anidadas.

PVBI_Act2_8_932
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jugador, computadora;
    
    printf("Juguemos a Piedra, Papel, Tijera!\n");
    printf("Elige una opción:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    printf("Tu elección: ");
    scanf("%d", &jugador);
    
    // Inicializar la generación de números aleatorios
    srand(time(NULL));
    
    // Generar la elección aleatoria de la computadora (1 para Piedra, 2 para Papel, 3 para Tijera)
    computadora = rand() % 3 + 1;
    
    if (jugador == 1) {
        if (computadora == 1) {
            printf("Empate, ambos eligieron piedra (1).\n");
        } else {
            if (computadora == 2) {
                printf("La computadora gana, papel (2) cubre piedra (1).\n");
            } else {
                printf("Ganaste, piedra (1) aplasta tijera (3).\n");
            }
        }
    } else {
        if (jugador == 2) {
            if (computadora == 1) {
                printf("Ganaste, papel (2) cubre piedra (1).\n");
            } else {
                if (computadora == 2) {
                    printf("Empate, ambos eligieron papel (2).\n");
                } else {
                    printf("La computadora gana, tijera (3) corta papel (2).\n");
                }
            }
        } else {
            if (jugador == 3) {
                if (computadora == 1) {
                    printf("La computadora gana, piedra (1) aplasta tijera (3).\n");
                } else {
                    if (computadora == 2) {
                        printf("Ganaste, tijera (3) corta papel (2).\n");
                    } else {
                        printf("Empate, ambos eligieron tijera (3).\n");
                    }
                }
            } else {
                printf("Selección inválida. Por favor, elige 1, 2 o 3.\n");
            }
        }
    }
    
    return 0;
}
