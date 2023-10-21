/*

*/

//**** LIBRARIES ****
#include "Frijoles.h"
#include <wchar.h>
#include <string.h>
#include <locale.h>
//*******************

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void askNames(wchar_t name[]);
void askLastName1(wchar_t LastName1[]);
void askLastName2(wchar_t LastName2[]);
int askSex();
int askState();
void printCURP(wchar_t name[], wchar_t LastName1[], wchar_t LastName2[], int day, int month, int year, int sex, int state);
void printBirthday(int day, int month, int year); 
//**** MAIN FUNCTIONS ****
int main()
{
    setlocale(LC_ALL, "");
    menu();
    return 0;
}
//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu()
{
    int op;
    wchar_t name[50], LastName1[30], LastName2[30];
    int day, month, year;
    int sex;
    int state;
    do
    {
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            askNames(name);
            break;
            case 2:
                askLastName1(LastName1);
                break;
            case 3:
                askLastName2(LastName2);
                break;
            case 4:
                day = valid("Ingresa el dia de tu nacimiento: ", 1, 31);
                month = valid("Ingresa el mes de tu nacimiento: ", 1, 12);
                year = valid("Ingresa el anio de tu nacimiento: ", 1894, 2023);
                year = year % 100;
                printf("Se han guardado correctamente la fecha de nacimiento.\n");
                break;
            case 5:
                sex = askSex();
                break;
            case 6:
                state = askState();
                break;
            case 7:
                printCURP(name, LastName1, LastName2, day, month, year, sex, state);
                break;
        }
        system("PAUSE");
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
    return op;
}

//**********
void askNames(wchar_t name[])
{
    int size = 50;
    do
    {
        printArr("Por favor, ingresa tu(s) nombre(s): ");
        ask(name, size);
    } while (alfaSpace(name) != 1);
}

void askLastName1(wchar_t LastName1[])
{
    int size = 50;
    do
    {
        printArr("Por favor, ingresa el apellido paterno: ");
        ask(LastName1, size);
    } while (alfaSpace(LastName1) != 1);
}
void askLastName2(wchar_t LastName2[])
{
    int size = 50;
    do
    {
        printArr("Por favor, ingresa el apellido materno: ");
        ask(LastName2, size);
    } while (alfaSpace(LastName2) != 1);
}

int askSex()
{
    int sex;
    printf("0.- Mujer\t 1.- Hombre\n");
    sex = valid("Introduce el sexo del estudiante: ", 0, 1);
    return sex;
}
int askState()
{
    return valid("Introduce el estado: ", 1, 32);
}

void printCURP(wchar_t name[], wchar_t LastName1[], wchar_t LastName2[], int day, int month, int year, int sex, int state)
{
    int temp;
    wchar_t tempArray[3];
    temp = vowels(LastName1);
    tempArray[0] = LastName1[0];
    tempArray[1] = LastName1[temp];
    tempArray[2] = LastName2[0];
    tempArray[3] = name[0];
    printf("%ls", tempArray);
    printBirthday(day, month, year);
    printf("\n");
    system("PAUSE");
}

//***************************
void printBirthday(int day, int month, int year)
{
    if (year <= 9)
    {
        printf("0%d", year);
    }
    else
    {
        printf("%d", year);
    }

    if (month <= 9)
    {
        printf("0%d", month);
    }
    else
    {
        printf("%d", month);
    }

    if (day <= 9)
    {
        printf("0%d", day);
    }
    else
    {
        printf("%d", day);
    }
}
