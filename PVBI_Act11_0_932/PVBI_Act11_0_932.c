/*

*/

//***** LIBRARIES *****
#include "Frijoles.h"

//***** STRUCTURES ******
typedef struct _Data
{
    char name[50];
    char lastName1[30];
    char LastName2[30];
    int year;
    int month;
    int day;
} Tdate;

typedef struct _stdnt
{
    int status;
    int matricula;
    Tdate personalData;
    int age;
    int sex;
} Tstdnt;

//***** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

void menuAdd();
int msge_menuAdd();

//***** MAIN FUNCTION *****
int main()
{
    menu();
    return 0;
}
//***** PROTOTYPE FUNCTIONS DEVELOPMENT *****
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
            menuAdd();
            break;
        }
    } while (op != 0);
    printf("Saliendo del programa");
}

int msge_menu()
{
    printf("1.- Agregar\n");
    printf("2.- Eliminar registro\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Imprimir\n");
    printf("6.- Archivo de texto\n");
    printf("0.- Salir\n");

    return valid("Por favor, selecciona una opcion: ", 0, 6);
}

void menuAdd()
{
    int op;
    do
    {
        op = msge_menuAdd();
        switch (op)
        {
        case 1:
            printf("Aniadir manual");
            break;
        case 2:
            printf("Automatico");
            break;
        }
    } while (op != 3);
    printf("Regresando al menu principal\n");
}

int msge_menuAdd()
{
    printf("1.- Manual (1)\n");
    printf("2.- Automatico (100)\n");
    printf("3.- Regresar al inicio\n");

    return valid("Selecciona una opcion: ", 1, 3);
}