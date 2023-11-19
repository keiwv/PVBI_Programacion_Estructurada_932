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
    Tkey cellPhone;
} TWrkr;
//****** PROTOTYPE FUNCTIONS *******
int msge_menu();
void menu();

int addRegisters(TWrkr employee[], int position, int ordFlag);
int editRegister(TWrkr employee[], int position, int ordFlag);
int deleteEmployee(TWrkr employee[], int position, int ordFlag);
void searchEmployee(TWrkr employee[], int position, int ordFlag);
int ordRegister(TWrkr employee[], int position, int ordFlag);
void displayRegister(TWrkr employee[], int position);
//****** USEFUL FUNCTIONS *********
TWrkr getOneEmployee(TWrkr employee[], int position, int ordFlag);
int existElem(int employeesEnrollment[], int longi, Tkey num);
int binarySearch(int employeesEnrollment[], int left, int right, Tkey number);
void displayRegEmp(TWrkr employee);
void displayListEmp(TWrkr employee);
void getNumEnrollment(TWrkr employees[], int num1[], int position);
void getNumCell(TWrkr employees[], int num1[], int position);
int menuRegister(TWrkr employees[], int position, int index, int enrollments[], int ordFlag);
int menuEditRegister();

void bubbleSort(TWrkr employees[], int n);
void quicksort(TWrkr employees[], int low, int high);
int partition(TWrkr employees[], int low, int high);
void swap(TWrkr employees[], int i, int j);
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
            ordFlag = 0;
            break;
        case 2:
            ordFlag = editRegister(employee, position, ordFlag);
            break;
        case 3:
            deleteEmployee(employee, position, ordFlag);
            break;
        case 4:
            searchEmployee(employee, position, ordFlag);
            break;
        case 5:
            ordFlag = ordRegister(employee, position, ordFlag);
            break;
        case 6:
            displayRegister(employee, position);
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
            employee[position + i] = getOneEmployee(employee, position, ordFlag);
            displayListEmp(employee[i]);
        }
        position += GEN_REGISTERS;
    }
    else
    {
        printf("El registro no puede añadir %d de registros debido a que ha sobrepasado el limite.\n", GEN_REGISTERS);
    }
    return position;
}

int editRegister(TWrkr employee[], int position, int ordFlag)
{
    int index;
    Tkey num;
    int enrollment[position];

    getNumEnrollment(employee, enrollment, position);
    num = valid("Ingresa la matricula de la persona para editar el registro: ", 300000, 399999);
    if (ordFlag)
    {
        index = binarySearch(enrollment, 0, position, num);
    }
    else
    {
        index = existElem(enrollment, position, num);
    }

    if (index != -1)
    {
        if (employee[index].status)
        {
            ordFlag = menuRegister(employee, position, index, enrollment, ordFlag);
        }
        else
        {
            printf("El trabajador ha sido de baja con anterioridad\n");
        }
    }
    return ordFlag;
}

int deleteEmployee(TWrkr employee[], int position, int ordFlag)
{
    int index;
    int enrollment[position];
    Tkey num;
    getNumEnrollment(employee, enrollment, position);
    num = valid("Ingresa la matricula de la persona: ", 300000, 399999);
    if (ordFlag)
    {
        index = binarySearch(enrollment, 0, position, num);
    }
    else
    {
        index = existElem(enrollment, position, num);
    }

    if (index != -1)
    {
        if (employee[index].status != 0)
        {
            printf("\n------ ENCONTRADO --------\n");
            displayRegEmp(employee[index]);
            printf("--------------------------\n");
            if (valid("Deseas eliminar el registro (0.- No / 1.- Si): ", 0, 1))
            {
                employee[index].status = 0;

                printf("El trabajador ha sido dado de baja correctamente.\n");
                return 0;
            }
        }
        else
        {
            printf("El trabajador ya sido dado de baja con anterioridad.\n");
        }
    }
    else
    {
        printf("La enrollment ingresada no pertecene a ningun trabajador\n");
    }
    return ordFlag;
}

void searchEmployee(TWrkr employee[], int position, int ordFlag)
{
    int num[position];
    Tkey index;
    getNumEnrollment(employee, num, position);
    index = valid("Ingresa la matricula del trabajador a buscar: ", 300000, 399999);
    if (ordFlag)
    {
        index = binarySearch(num, 0, position, index);
    }
    else
    {
        index = existElem(num, position, index);
    }

    if (index != -1)
    {
        if (employee[index].status)
        {
            printf("------- ENCONTRADO ------\n");
            displayRegEmp(employee[index]);
            printf("-------------------------\n");
        }
        else
        {
            printf("El trabajador ha sido de baja con anterioridad.\n");
        }
    }
    else
    {
        printf("El trabajador con esa matricula no existe\n");
    }
}

int ordRegister(TWrkr employee[], int position, int ordFlag)
{
    if (!ordFlag)
    {
        if (!(position == 0))
        {
            if(position < 600)
            {
                bubbleSort(employee, position);
            }
            else
            {
                quicksort(employee, 0, position);
            }
            printf("Se han ordenado por matricula de menor a mayor\n");
            return 1;
        }
        else
        {
            printf("No hay nada en el vector.\n");
        }
    }
    else
    {
        printf("Ya esta ordenado.\n");
    }
    return ordFlag;
}

void displayRegister(TWrkr employee[], int position)
{
    int i;
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
    for (i = 0; i < position; i++)
    {
        displayListEmp(employee[i]);
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

int existElem(int employee[], int longi, Tkey num)
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

int binarySearch(int employee[], int left, int right, Tkey number)
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
    printf("Ap. Paterno: %s\n", employee.LastName1);
    printf("Ap. Materno: %s\n", employee.LastName2);
    printf("Sexo:        %s\n", employee.sex);
    printf("Edad:        %d\n", employee.age);
    printf("Posicion:    %s\n", employee.JobPstion);
    printf("Num. Cel:    646-%d\n", employee.cellPhone);
    printf("Lug. Nacim:  %s\n", employee.state);
}

void displayListEmp(TWrkr employee)
{
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
    printf("4.- Posicion de trabajo\n");
    printf("5.- Matricula\n");
    printf("0.- Salir\n");
    return valid("Selecciona una opcion: ", 0, 6);
}

int menuRegister(TWrkr employees[], int position, int index, int enrollments[], int ordFlag)
{
    int op;
    int cellPhone[position];
    getNumCell(employees, cellPhone, position);

    do
    {
        printf("\n----------- ENCONTRADO ----------\n");
        displayRegEmp(employees[index]);
        printf("---------------------------------\n");
        printf("MODIFICAR ALGUN CAMPO\n");
        op = menuEditRegister();
        system("CLS");
        switch (op)
        {
        case 1:
            employees[index].age = valid("Ingrese la edad correcta: ", 18, 40);
            break;
        case 2:
            displayStates(employees[index].state);
            break;
        case 3:
            do
            {
                employees[index].cellPhone = valid("Ingrese el numero de telefono: 646-", 1000000, 1999999);
            } while (existElem(cellPhone, position, employees[index].cellPhone) != -1);
            break;
        case 4:
            displayJobPositions(employees[index].JobPstion);
            break;
        case 5:
            do
            {
                employees[index].enrollment = valid("Ingrese la nueva matricula: ", 300000, 399999);
            } while (existElem(enrollments, position, employees[index].enrollment) != -1);
            ordFlag = 0;
            break;
        }
        if (op != 0)
        {
            system("PAUSE");
            system("CLS");
        }
    } while (op != 0);

    return ordFlag;
}

//******* ORDER FUNCTIONS ***********

void swap(TWrkr employees[], int i, int j)
{
    TWrkr temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;
}

int partition(TWrkr employees[], int low, int high)
{
    TWrkr pivot;
    pivot.enrollment = employees[high].enrollment;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (employees[j].enrollment <= pivot.enrollment)
        {
            i++;
            swap(employees, i, j);
        }
    }
    swap(employees, i + 1, high);
    return i + 1;
}

void quicksort(TWrkr employees[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(employees, low, high);

        quicksort(employees, low, pi - 1);
        quicksort(employees, pi + 1, high);
    }
}

void bubbleSort(TWrkr employees[], int n)
{
    int i, j;
    TWrkr temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (employees[j].enrollment < employees[i].enrollment)
            {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
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