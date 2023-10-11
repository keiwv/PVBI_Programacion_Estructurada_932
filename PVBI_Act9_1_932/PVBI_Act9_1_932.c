/*

*/

//**** LIBRARIES ****
#include "Frijoles.h"

//*******************
typedef struct _Person
{
    char name[50];
    char lastName1[30];
    char lastName2[30];
    char birthDay[6];
    int sex;
    int state;
    char curp[18];
} Tperson;

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void askNames();
void askLastName1();
void askLastName2();
void askBirthDay();
int askSex();
int askState();
void printCURP();

//**** MAIN FUNCTIONS ****
int main()
{
    menu();
    return 0;
}
//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu(Tperson *person)
{
    int op;
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            askNames(&person);
            break;
        case 2:
            askLastName1(&person);
            break;
        case 3:
            askLastName2();
            break;
        case 4:
            askBirthDay();
            break;
        case 5:
            askSex();
            break;
        case 6:
            askState();
            break;
        case 7:
            printCURP();
            break;
        }
    } while (op != 0);
}
//***********
int msge_menu()
{
    int op;
    system("CLS");
    printArr("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printArr("1.- Ingresar Nombre\n");
    printArr("2.- Ingresar Apellido Paterno\n");
    printArr("3.- Ingresa Apellido Materno\n");
    printArr("4.- Ingresa el Dia de Nacimiento\n");
    printArr("5.- Seleccionar sexo\n");
    printArr("6.- Selecciona Estado\n");
    printArr("7.- Imprimir CURP\n");
    printArr("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 7);
}

//**********
void askNames(Tperson *person)
{
    printArr("Por favor, ingresa tu(s) nombre(s): ");
    fflush(stdin);
    gets(person->name);
}

void askLastName1(Tperson *person)
{
}
void askLastName2()
{
}
void askBirthDay()
{
}
int askSex()
{
}
int askState()
{
}
void printCURP()
{
}