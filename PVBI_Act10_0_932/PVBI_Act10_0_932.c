/*
Brayan Ivan Perez Ventura - 372781

Created code: October 10th 2023 / Modified code: Octuber 15th 2023

DESCRIPTION
In this program, we will implemented a program where it will be working with structures as if we're working with Data.
This program will be filling registers with the next data: Student school enrollment, status (active or inactive)
Two last name, Name, age and sex. We will be ordering from lowest to highest depending on the school enrollment.
User will be able:
    1.- Fill 10 Registers with random information (already declared)
    2.- Add a new student. Fill the information manually
    3.- Delete Student. It will be able to set student status inactive with the school enrollment.
    4.- Search student. It will be able to find a student by their school enrollment. The program will be able to take the best option to find the student depending if it's ordered or not.
    5.- Order by School Enrollment. Using modified bubble sort, the program will order the students by the school enrollment. From the lowest to the highest.
    6.- Display Active Users. The program will display the active students.
    0.- Leave. Leave from the progra.

#NOTE -- THE MAXIMUN OF REGISTERS ARE 500, IT CAN BE MODIFIED IF YOU CHANGE THE CONSTANT VALUE OF "STDNTSIZE".
#NOTE 2 -- LIBRARY "Frijoles.h" IS NECESSARY FOR THIS CODE.

PVBI_Act10_1_932
*/


#include "Frijoles.h"
#include <time.h>
#include <string.h>
#include <stdio.h>


typedef struct _stdnt
{
    int status;
    int matricula;
    char LastName1[30];
    char Lastname2[30];
    char name[50];
    int age;
    int sex;
} Tstdnt;

#define STDNTSIZE 500 


void menu();
int msge_menu();


void fillReg(Tstdnt studentArray[], int position);
Tstdnt newStdnt(Tstdnt studentArray[], int position);
void deleteStdnt(Tstdnt studentArray[], int position);
void searchStdnt(Tstdnt studentArray[], int position, int flag);
void bubbleSort(Tstdnt studentArray[], int n);
void displayRegActive(Tstdnt studentArray[], int position);


Tstdnt genDataReg(Tstdnt studentArray[], int position);
void displayReg(Tstdnt studentArray[], int position);
int existElem(Tstdnt studentArray[], int longi, int num);
void displayOneStdnt(Tstdnt studentArray, int position);
int binarySearch(Tstdnt studentArray[], int left, int right, int number);


void nameMen(char tempName[]);
void nameWomen(char tempName[]);
void LastName(char tempLastName[]);


int main()
{
    srand(time(NULL));
    menu();
    return 0;
}


void menu()
{
    int op, position; 
    int flag;
    flag = 1; 
    position = 0;
    Tstdnt studentArray[STDNTSIZE];
    do
    {
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            if (position + 10 >= STDNTSIZE)
            {
                printf("Has llegado a la maxima cantidad de registros permitidos\n");
            }
            else
            {
                fillReg(studentArray, position);
                position += 10;
                flag = 0;
                printf("\t\t\t10 registros creados correctamente!\n");
            }
            system("PAUSE");
            break;
        case 2:
            if (position + 1 >= STDNTSIZE)
            {
                printf("Has llegado a la maxima cantidad de registros permitidos\n");
            }
            else
            {
                studentArray[position] = newStdnt(studentArray, position);
                flag = 0;
                position += 1;
            }
            system("PAUSE");
            break;
        case 3:
            deleteStdnt(studentArray, position);
            flag = 0;
            system("PAUSE");
            break;
        case 4:
            searchStdnt(studentArray, position, flag);
            system("PAUSE");
            break;
        case 5:
            if (flag == 0)
            {
                bubbleSort(studentArray, position);
                flag = 1;
                printf("Los registros han sido ordenados correctamente por matricula de menor a mayor\n");
            }
            else
            {
                printf("Los registros ya han sido ordenados con anterioridad.\n");
            }
            system("PAUSE");
            break;
        case 6:
            displayRegActive(studentArray, position);
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Saliendo del programa\n");
}

int msge_menu()
{
    int op;
    system("CLS");
    printArr("MANEJO Y CONTROL DE ESTUDIANTES\n");
    printArr("1.- Agregar 10 registros automatico\n");
    printArr("2.- Agregar manual\n");
    printArr("3.- Eliminar registro\n");
    printArr("4.- Buscar\n");
    printArr("5.- Ordenar\n");
    printArr("6.- Imprimir\n");
    printArr("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 6);
    return op;
}


void fillReg(Tstdnt studentArray[], int position)
{
    int i;
    for (i = position; i < position + 10; i++)
    {
        studentArray[i] = genDataReg(studentArray, position);
    }
    displayReg(studentArray, position + 10);
}

Tstdnt newStdnt(Tstdnt studentArray[], int position)
{
    Tstdnt tempStudentArray;

    char tempSentence[30];

    tempStudentArray.status = 1;

    do
    {
        tempStudentArray.matricula = valid("Por favor, introduce la matricula del estudiante: ", 300000, 399999); 
    } while (existElem(studentArray, position, tempStudentArray.matricula) != -1);                                

    do 
    {
        printf("Por favor, introduce el apellido paterno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(tempStudentArray.LastName1, tempSentence); 

    do 
    {
        printf("Por favor, introduce el apellido materno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(tempStudentArray.Lastname2, tempSentence); 

    do 
    {
        printf("Por favor, introduce el nombre del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(tempStudentArray.name, tempSentence);
   
    tempStudentArray.age = valid("Introduce la edad del estudiante: ", 18, 40);
   
    printf("0.- Mujer\t 1.- Hombre\n");
    tempStudentArray.sex = valid("Introduce el sexo del estudiante: ", 0, 1);

    printf("\n\tINFORMACION DEL ESTUDIANTE AGREGADO RECIENTEMENTE\n");
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
    displayOneStdnt(tempStudentArray, position);

    return tempStudentArray;
}

void deleteStdnt(Tstdnt studentArray[], int position)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea eliminar: ", 300000, 399999);
    index = existElem(studentArray, position, num);
    if (index != -1)
    {
        if (studentArray[index].status != 0) 
        {
            studentArray[index].status = 0;
            printf("El estudiante ha sido dado de baja correctamente.\n");
        }
        else 
        {
            printf("El estudiante ya estaba dado de baja con anterioridad.\n");
        }
    }
    else 
    {
        printf("La matricula ingresada no pertecene a ningun estudiante\n");
    }
}

void searchStdnt(Tstdnt studentArray[], int position, int flag)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea buscar: ", 300000, 399999);
    if (flag == 0) 
    {
        index = existElem(studentArray, position, num);
    }
    else // if so
    {
        index = binarySearch(studentArray, 0, position - 1, num);
    }
    if (index != -1) 
    {
        printf("El estudiante ha sido encontrado con exito\n");
        printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
        displayOneStdnt(studentArray[index], index);
    }
    else
    {
        printf("El estudiante no ha sido encontrado\n");
    }
}

void bubbleSort(Tstdnt studentArray[], int n)
{
    int i, j;
    Tstdnt temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (studentArray[j].matricula < studentArray[i].matricula)
            {
                temp = studentArray[i];
                studentArray[i] = studentArray[j];
                studentArray[j] = temp;
            }
        }
    }
}

void displayRegActive(Tstdnt studentArray[], int position)
{
    int i;
    printf("DESPLEGANDO LISTA DE ALUMNOS ACTIVOS ACTUALMENTE\n");
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
    for (i = 0; i < position; i++)
    {
        if (studentArray[i].status == 1)
        {
            displayOneStdnt(studentArray[i], i);
        }
    }
}


Tstdnt genDataReg(Tstdnt studentArray[], int position)
{
    Tstdnt tempStudentArray;

    char tempName[50];


    LastName(tempName);
    strcpy(tempStudentArray.LastName1, tempName);


    LastName(tempName);
    strcpy(tempStudentArray.Lastname2, tempName);


    tempStudentArray.status = 1;


    do
    {
        tempStudentArray.matricula = numRandom(300000, 399999);
    } while (existElem(studentArray, position, tempStudentArray.matricula) != -1);


    if (numRandom(0, 1) == 1)
    {
        nameMen(tempName);
        strcpy(tempStudentArray.name, tempName);
        tempStudentArray.sex = 1; 
    }
    else
    {
        nameWomen(tempName);
        strcpy(tempStudentArray.name, tempName);
        tempStudentArray.sex = 0; 
    }


    tempStudentArray.age = numRandom(18, 40);

    return tempStudentArray;
}

void displayReg(Tstdnt studentArray[], int position)
{
    int i;
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");

    for (i = 0; i < position; i++)
    {
        printf("| %-3d | %-10d | %-6d | %-12s | %-12s | %-12s | %-4d |", i + 1, 
        studentArray[i].matricula, studentArray[i].status, studentArray[i].LastName1, studentArray[i].Lastname2, studentArray[i].name, studentArray[i].age);
        if (studentArray[i].sex == 0)
        {
            printf("  M   |\n");
        }

        else
        {
            printf("  H   |\n");
        }
    }
    printf("\n");
}

int existElem(Tstdnt studentArray[], int longi, int num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (studentArray[i].matricula == num)
        {
            return i;
        }
    }
    return -1;
}

void displayOneStdnt(Tstdnt studentArray, int position)
{
    printf("| %-3d | %-10d | %-6d | %-12s | %-12s | %-12s | %-4d |", position + 1, studentArray.matricula, studentArray.status, studentArray.LastName1, studentArray.Lastname2, studentArray.name, studentArray.age);
    if (studentArray.sex == 0)
    {
        printf("  M   |\n");
    }
    else
    {
        printf("  H   |\n");
    }
}

int binarySearch(Tstdnt studentArray[], int left, int right, int number)
{
    int medium;
    while (left <= right)
    {
        medium = left + (right - left) / 2;


        if (studentArray[medium].matricula == number)
        {
            return medium;
        }

        if (studentArray[medium].matricula < number) 
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


void nameMen(char tempName[])
{
    char nameMen1[30][30] = {"JUAN", "PEDRO", "LUIS", "MIGUEL", "CARLOS", "JAVIER", "MANUEL", "JOSE", "FERNANDO", "ALBERTO", "RICARDO", "ENRIQUE", "ANTONIO", "ALEJANDRO", "EMILIO", "ARTURO", "JORGE", "EDUARDO", "HECTOR", "FRANCISCO", "RAUL", "ROBERTO", "ERNESTO", "GUILLERMO", "ARMANDO", "MARIO", "DANIEL", "OSCAR", "ISRAEL", "SALVADOR"};
    strcpy(tempName, nameMen1[numRandom(0, 29)]);
}

void nameWomen(char tempName[])
{
    char nameWomen1[30][30] = {"MARiA", "ANA", "LAURA", "PATRICIA", "CARMEN", "SOFIA", "ISABEL", "PAULA", "BEATRIZ", "ELENA", "GABRIELA", "ROSA", "CLARA", "VICTORIA", "LOURDES", "ADRIANA", "NATALIA", "SUSANA", "MARTA", "PILAR", "SONIA", "ALEJANDRA", "JULIA", "RAQUEL", "ANTONIA", "GLORIA", "SILVIA", "AURORA", "CONSUELO", "MERCEDES"};
    strcpy(tempName, nameWomen1[numRandom(0, 29)]);
}

void LastName(char tempLastName[])
{
    char LastName1[120][60] = {"RAMOS", "MORENO", "FERNANDEZ", "TORRES", "RAMIREZ", "JIMENEZ", "NUNEZ", "VEGA", "ROJAS", "IGLESIAS", "PACHECO", "VALENCIA", "MORA", "SILVA", "GOMEZ", "CORDERO", "SERRANO", "MEDINA", "ALVAREZ", "SOTO", "LARA", "HERRERA", "GUERRERO", "ORTIZ", "PARDO", "ROLDAN", "SUAREZ", "SALAZAR", "CASTILLO", "AGUILAR", "ROMAN", "ZAMORA", "DIAZ", "CASTANEDA", "VARGAS", "QUINTERO", "MOLINA", "CABRERA", "GONZALES", "CRUZ", "DELGADO", "VILLANUEVA", "RIOS", "REYES", "FLORES", "ROJAS", "ARIAS", "LOPEZ", "MALDONADO", "MENDEZ", "CERVANTES", "ESPINOSA", "CHACON", "SOLIS", "TOVAR", "SANDOVAL", "VALENCIA", "RIVERA", "ROSALES", "DURAN", "RUBIO", "MENDOZA", "BAUTISTA", "VASQUEZ", "ROMERO", "MERCADO", "ESPINOSA", "ESCOBAR", "SOSA", "BARRIOS", "LEON", "SOTO", "OCHOA", "CONTRERAS", "CERVANTES", "VALENZUELA", "MIRANDA", "PAREDES", "BELTRAN", "ESPINOZA", "PENA", "CASILLAS", "VARELA", "HIDALGO", "GUZMAN", "MENENDEZ", "ALVARADO", "ESTRELLA", "HERNANDEZ", "OSORIO", "MACIAS", "URIBE", "GARZA", "VALDES", "CAMACHO", "LEAL", "MUNGUIA", "SOLANO", "MACIEL", "CALZADA", "ALCALA", "BARAJAS", "PARRA", "ELIZONDO", "PALACIOS", "CASAS", "VENTURA", "MONTES", "MUNOZ", "LUGO", "SOSA", "OJEDA", "FRANCO", "ARELLANO", "PIZARRO", "CHAVEZ", "ROBLES", "CARRANZA", "URBINA"};
    strcpy(tempLastName, LastName1[numRandom(0, 99)]);
}
