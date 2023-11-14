/*

*/

//***** LIBRARIES ***********
#include "dataFunctions.h"
//****** STRUCTURES **********

//****** PROTOTYPE FUNCTIONS *******
int msge_menu();
void menu();

//****** MAIN FUNCTION ************
int main()
{
    menu();
    return 0;
}
//****** PROTOTYPE DEVELOPMENT FUNCTIONS *******
int msge_menu()
{
    printf("------ M E N U --------\n");
    printf("[1] Agregar 100 registros\n");
    printf("[2] Editar registro\n");
    printf("[3] Eliminar registro\n");
    printf("[4] Buscar\n");
    printf("[5] Ordenar\n");
    printf("[6] Imprimir\n");
    printf("[7] Generar archivo de texto\n");    
    printf("[8] Mostrar archivo de texto\n");
    printf("[9] Crear archivo binario\n");
    printf("[10] Cargar archivo binario\n");
    printf("[11] Mostrar borrados\n");
    printf("[0] Salir\n");
    return valid("Selecciona una opcion: ", 0, 11);
}

void menu()
{
    int op;
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    } while (op != 0);
}





/*
  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ 
 ( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )
  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <
  /\_/\                                                   /\_/\ 
 ( o.o )                                                 ( o.o )
  > ^ <      ____    _             _                      > ^ <
  /\_/\     / __ \  | | __   ___  (_) __      __ __   __  /\_/\ 
 ( o.o )   / / _` | | |/ /  / _ \ | | \ \ /\ / / \ \ / / ( o.o )
  > ^ <   | | (_| | |   <  |  __/ | |  \ V  V /   \ V /   > ^ <
  /\_/\    \ \__,_| |_|\_\  \___| |_|   \_/\_/     \_/    /\_/\ 
 ( o.o )    \____/ ___   _____   _   _   _   _   ____    ( o.o )
  > ^ <    / ___| |_ _| |_   _| | | | | | | | | | __ )    > ^ <
  /\_/\   | |  _   | |    | |   | |_| | | | | | |  _ \    /\_/\ 
 ( o.o )  | |_| |  | |    | |   |  _  | | |_| | | |_) |  ( o.o )
  > ^ <    \____| |___|   |_|   |_| |_|  \___/  |____/    > ^ <
  /\_/\                                                   /\_/\ 
 ( o.o )                                                 ( o.o )
  > ^ <                                                   > ^ <
  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ 
 ( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )
  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < */