/*
Brayan Ivan Perez Ventura - 372781

Código creado: 03 de Septiembre del 2023 / Código modificado: 03 de Septiembre del 2023

Juego llamado "Chinchampú (Papel, piedra, tijera)" para 1 jugador contra la computadora utilizando selección múltiple.

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
    
    switch (jugador) {
        case 1:
            switch (computadora) {
                case 1:
                    printf("Empate, ambos eligieron Piedra (1).\n");
                    break;
                case 2:
                    printf("La computadora gana, Papel (2) cubre Piedra (1).\n");
                    break;
                case 3:
                    printf("Ganaste, Piedra (1) aplasta Tijera (3).\n");
                    break;
                default:
                    printf("Selección de la computadora no válida.\n");
                    break;
            }
            break;
        case 2:
            switch (computadora) {
                case 1:
                    printf("Ganaste, Papel (2) cubre Piedra (1).\n");
                    break;
                case 2:
                    printf("Empate, ambos eligieron Papel (2).\n");
                    break;
                case 3:
                    printf("La computadora gana, Tijera (3) corta Papel (2).\n");
                    break;
                default:
                    printf("Selección de la computadora no válida.\n");
                    break;
            }
            break;
        case 3:
            switch (computadora) {
                case 1:
                    printf("La computadora gana, Piedra (1) aplasta Tijera (3).\n");
                    break;
                case 2:
                    printf("Ganaste, Tijera (3) corta Papel (2).\n");
                    break;
                case 3:
                    printf("Empate, ambos eligieron Tijera (3).\n");
                    break;
                default:
                    printf("Selección de la computadora no válida.\n");
                    break;
            }
            break;
        default:
            printf("Selección inválida. Por favor, elige 1, 2 o 3.\n");
            break;
    }
    
    return 0;
}
