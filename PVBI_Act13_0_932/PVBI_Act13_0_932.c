/*

*/

//***** LIBRARIES ***********
#include "dataFunctions.h"

//****** CONSTANTS *********
const int MAX_REGISTERS = 5000;
const int GEN_REGISTERS = 100;

//****** STRUCTURES **********

typedef int Tkey;
typedef struct _Wrkr
{
    int status;
    Tkey enrollment;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPstion[30];
    char state[30];
    int age;
    int cellPhone;
} TWrkr;
//****** PROTOTYPE FUNCTIONS *******
int msge_menu();
void menu();

void addRegisters(TWrkr employee[], int position);

//****** USEFUL FUNCTIONS *********
TWrkr getOneEmployee(TWrkr employee[], int position);
int existElem(int employeesEnrollment[], int longi, int num);
int binarySearch(int employeesEnrollment[], int left, int right, int number);
int getNumSort(int num[], int position, int ri, int rs);

//****** MAIN FUNCTION ************
int main()
{
    srand(time(NULL));
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
    TWrkr employee[MAX_REGISTERS];
    int position = 0;
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            addRegisters(employee, position);
            break;

        default:
            break;
        }
    } while (op != 0);
}

void addRegisters(TWrkr employee[], int position)
{
    int i;
    int 
    if (position + GEN_REGISTERS < MAX_REGISTERS)
    {

        for (i = 0; i < GEN_REGISTERS; i++)
        {
            employee[i] = getOneEmployee(employee, position);
        }
    }
    else
    {
        printf("El registro no puede añadir %d de registros debido a que ha sobrepasado el limite.\n", GEN_REGISTERS);
    }
}

// ************* USEFUL FUNCTIONS DEVELOPEMENT ********
TWrkr getOneEmployee(int num[], int position)
{
    TWrkr tempEmployee;

    tempEmployee.age = numRandom(18, 70);

    tempEmployee.cellPhone = getNumSort(employee->cellPhone, position, 1000000, 1999999);
    tempEmployee.enrollment = getNumSort(employee->enrollment, position, 1000000, 1999999);

    if (numRandom(0, 1))
    {
        nameMen(tempEmployee.name);
        strcpy(tempEmployee.sex, "HOMBRE");
    }
    else
    {
        nameWomen(tempEmployee.name);
        strcpy(tempEmployee.sex, "MUJER");
    }

    return tempEmployee;
}

int existElem(int employeesEnrollment[], int longi, int num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (employeesEnrollment == num)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int employeesEnrollment[], int left, int right, int number)
{
    int medium;
    while (left <= right)
    {
        medium = left + (right - left) / 2;

        if (employeesEnrollment == number)
        {
            return medium;
        }

        if (employeesEnrollment < number)
        {
            left = medium + 1;
        }
        else
        {
            right = medium - 1;
        }
    }

    return -1;
}

int getNumSort(int num[], int position, int ri, int rs)
{
    int number;
    if (position > 300)
    {
        do
        {
            number = numRandom(ri, rs);
        } while (binarySearch(num, 0, position, number) != -1);
    }
    else
    {
        do
        {
            number = numRandom(ri, rs);
        } while (existElem(num, position, number) != -1);
    }
    return number;
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