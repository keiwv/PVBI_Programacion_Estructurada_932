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

int addRegisters(TWrkr employee[], int position, int ordFlag);
void editRegister(TWrkr employee[], int position, int ordFlag);
//****** USEFUL FUNCTIONS *********
TWrkr getOneEmployee(TWrkr employee[], int position, int ordFlag);
int existElem(int employeesEnrollment[], int longi, int num);
int binarySearch(int employeesEnrollment[], int left, int right, int number);
void displayRegEmp(TWrkr employee);
void displayListEmp(TWrkr employee);
void getNumEnrollment(TWrkr employees[], int num1[], int position);
void getNumCell(TWrkr employees[], int num1[], int position);
TWrkr menuRegister(TWrkr employees[], int position);
int menuEditRegister();
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
    int ordFlag = 0;
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            position = addRegisters(employee, position, ordFlag);
            break;
        case 2:
            editRegister(employee, position, ordFlag);
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

int addRegisters(TWrkr employee[], int position, int ordFlag)
{
    int i;
    if (position + GEN_REGISTERS < MAX_REGISTERS)
    {

        for (i = 0; i < GEN_REGISTERS; i++)
        {
            employee[i] = getOneEmployee(employee, position, ordFlag);
            displayListEmp(employee[i]);
            position++;
        }
    }
    else
    {
        printf("El registro no puede añadir %d de registros debido a que ha sobrepasado el limite.\n", GEN_REGISTERS);
    }
    return position;
}

void editRegister(TWrkr employee[], int position, int ordFlag)
{
    int index;
    int num;
    int enrollement[position];

    getNumEnrollment(employee, enrollement, position);
    num = valid("Ingresa la matricula de la persona para editar el registro: ", 300000, 399999);
    if (ordFlag)
    {
        index = binarySearch(enrollement, 0, position, num);
    }
    else
    {
        index = existElem(enrollement, position, num);
    }

    if (index != -1)
    {
        printf("\n----------- ENCONTRADO ----------\n");
        displayRegEmp(employee[index]);
        printf("---------------------------------\n");
        printf("MODIFICAR ALGUN CAMPO\n");
        employee[index] = menuRegister(employee, position);
    }
}
// ************* USEFUL FUNCTIONS DEVELOPEMENT ********
TWrkr getOneEmployee(TWrkr employee[], int position, int ordFlag)
{
    TWrkr tempEmployee;
    int cellPhone[position];
    int enrollment[position];

    tempEmployee.age = numRandom(18, 50);
    int i;
    for (i = 0; i < position; i++)
    {
        cellPhone[i] = employee[i].cellPhone;
        enrollment[i] = employee[i].enrollment;
    }

    do
    {
        tempEmployee.cellPhone = numRandom(1000000, 1999999);
    } while (existElem(cellPhone, position, tempEmployee.cellPhone) != -1);

    if (ordFlag)
    {
        do
        {
            tempEmployee.enrollment = numRandom(300000, 399999);
        } while (binarySearch(enrollment, 0, position, tempEmployee.enrollment) != -1);
    }
    else
    {
        do
        {
            tempEmployee.enrollment = numRandom(300000, 399999);
        } while (existElem(enrollment, position, tempEmployee.enrollment) != -1);
    }

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

    LastName(tempEmployee.LastName1);
    LastName(tempEmployee.LastName2);
    getState(tempEmployee.state);
    getJobPositions(tempEmployee.JobPstion);
    tempEmployee.status = 1;

    return tempEmployee;
}

int existElem(int employee[], int longi, int num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (employee[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int employee[], int left, int right, int number)
{
    int medium;
    while (left <= right)
    {
        medium = left + (right - left) / 2;

        if (employee[medium] == number)
        {
            return medium;
        }

        if (employee[medium] < number)
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

void displayRegEmp(TWrkr employee)
{
    printf("Matricula:   %d\n", employee.enrollment);
    printf("Nombre:      %s\n", employee.name);
    printf("Ap. Paterno: %s", employee.LastName1);
    printf("Ap. Materno: %s\n", employee.LastName2);
    printf("Sexo:        %s\n", employee.sex);
    printf("Edad:        %d\n", employee.age);
    printf("Posicion:    %s\n", employee.JobPstion);
    printf("Num. Cel:    646%d\n", employee.cellPhone);
}

void displayListEmp(TWrkr employee)
{
    printf("%-10s %-12s %-15s %-20s %-15s %-10s %-30s %-20s %-5s %-10s\n",
           "Status",
           "Enrollment",
           "Name",
           "Last Name 1",
           "Last Name 2",
           "Sex",
           "Job Position",
           "State",
           "Age",
           "Cell Phone");

    printf("%-10d %-12d %-15s %-20s %-15s %-10s %-30s %-20s %-5d 646%-10d\n",
           employee.status,
           employee.enrollment,
           employee.name,
           employee.LastName1,
           employee.LastName2,
           employee.sex,
           employee.JobPstion,
           employee.state,
           employee.age,
           employee.cellPhone);
}

void getNumEnrollment(TWrkr employees[], int num1[], int position)
{
    int i;
    for (i = 0; i < position; i++)
    {
        num1[i] = employees[i].enrollment;
    }
}

void getNumCell(TWrkr employees[], int num1[], int position)
{
    int i;
    for (i = 0; i < position; i++)
    {
        num1[i] = employees[i].cellPhone;
    }
}

int menuEditRegister()
{
    printf("1.- Edad\n");
    printf("2.- Lugar de nacimiento\n");
    printf("3.- Num. Cel\n");
    printf("4.- Sexo\n");
    printf("5.- Posicion de trabajo\n");
    printf("6.- Matricula\n");
    printf("0.- Salir\n");
    return valid("Selecciona una opcion: ", 0, 6);
}

TWrkr menuRegister(TWrkr employees[], int position)
{
    int op;
    int cellPhone[position];
    int enrollments[position];
    TWrkr employee;
    getNumCell(employees, cellPhone, position);
    getNumEnrollment(employees, enrollments, position);

    do
    {
        op = menuEditRegister();
        system("CLS");
        switch (op)
        {
        case 1:
            employee.age = valid("Ingrese la edad correcta: ", 18, 40);
            break;
        case 2:
            displayStates(employee.state);
            break;
        case 3:
            do
            {
                employee.cellPhone = valid("Ingrese el numero de telefono: 646-", 1000000, 1999999);
            } while (existElem(cellPhone, position, employee.cellPhone) != -1);
            break;
        }
        if (op != 0)
        {
            system("PAUSE");
        }
    } while (op != 0);

    return employee;
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