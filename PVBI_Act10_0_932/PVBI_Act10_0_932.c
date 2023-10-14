/*
Brayan Ivan Perez Ventura - 372781

Created code: October 10th 2023 / Modified code: Octuber 14th 2023

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

//**** LIBRARIES ****
#include "Frijoles.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
//*******************
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

#define STDNTSIZE 500 // Max size of the registers.

char nameMen[30][30] = {"JUAN", "PEDRO", "LUIS", "MIGUEL", "CARLOS", "JAVIER", "MANUEL", "JOSE", "FERNANDO", "ALBERTO", "RICARDO", "ENRIQUE", "ANTONIO", "ALEJANDRO", "EMILIO", "ARTURO", "JORGE", "EDUARDO", "HECTOR", "FRANCISCO", "RAUL", "ROBERTO", "ERNESTO", "GUILLERMO", "ARMANDO", "MARIO", "DANIEL", "OSCAR", "ISRAEL", "SALVADOR"};

char nameWomen[30][30] = {"MARÍA", "ANA", "LAURA", "PATRICIA", "CARMEN", "SOFIA", "ISABEL", "PAULA", "BEATRIZ", "ELENA", "GABRIELA", "ROSA", "CLARA", "VICTORIA", "LOURDES", "ADRIANA", "NATALIA", "SUSANA", "MARTA", "PILAR", "SONIA", "ALEJANDRA", "JULIA", "RAQUEL", "ANTONIA", "GLORIA", "SILVIA", "AURORA", "CONSUELO", "MERCEDES"};

char LastName[120][60] = {"RAMOS", "MORENO", "FERNANDEZ", "TORRES", "RAMIREZ", "JIMENEZ", "NUNEZ", "VEGA", "ROJAS", "IGLESIAS", "PACHECO", "VALENCIA", "MORA", "SILVA", "GOMEZ", "CORDERO", "SERRANO", "MEDINA", "ALVAREZ", "SOTO", "LARA", "HERRERA", "GUERRERO", "ORTIZ", "PARDO", "ROLDAN", "SUAREZ", "SALAZAR", "CASTILLO", "AGUILAR", "ROMAN", "ZAMORA", "DIAZ", "CASTANEDA", "VARGAS", "QUINTERO", "MOLINA", "CABRERA", "GONZALES", "CRUZ", "DELGADO", "VILLANUEVA", "RIOS", "REYES", "FLORES", "ROJAS", "ARIAS", "LOPEZ", "MALDONADO", "MENDEZ", "CERVANTES", "ESPINOSA", "CHACON", "SOLIS", "TOVAR", "SANDOVAL", "VALENCIA", "RIVERA", "ROSALES", "DURAN", "RUBIO", "MENDOZA", "BAUTISTA", "VASQUEZ", "ROMERO", "MERCADO", "ESPINOSA", "ESCOBAR", "SOSA", "BARRIOS", "LEON", "SOTO", "OCHOA", "CONTRERAS", "CERVANTES", "VALENZUELA", "MIRANDA", "PAREDES", "BELTRAN", "ESPINOZA", "PENA", "CASILLAS", "VARELA", "HIDALGO", "GUZMAN", "MENENDEZ", "ALVARADO", "ESTRELLA", "HERNANDEZ", "OSORIO", "MACIAS", "URIBE", "GARZA", "VALDES", "CAMACHO", "LEAL", "MUNGUIA", "SOLANO", "MACIEL", "CALZADA", "ALCALA", "BARAJAS", "PARRA", "ELIZONDO", "PALACIOS", "CASAS", "VENTURA", "MONTES", "MUNOZ", "LUGO", "SOSA", "OJEDA", "FRANCO", "ARELLANO", "PIZARRO", "CHAVEZ", "ROBLES", "CARRANZA", "URBINA"};

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

    //**** MAIN SWITCH FUNCTIONS *******
void fillReg(Tstdnt studentArray[], int position);
void newStdnt(Tstdnt studentArray[], int position);
void deleteStdnt(Tstdnt studentArray[], int position);
void searchStdnt(Tstdnt studentArray[], int position, int flag);
void bubbleSort(Tstdnt studentArray[], int n);
void displayRegActive(Tstdnt studentArray[], int position);

    //**** AUXILIAR PROTOTYPE FUNCTIONS ***********
void genDataReg(Tstdnt studentArray[], int i, int position);
void displayReg(Tstdnt studentArray[], int position);
int existElem(Tstdnt studentArray[], int longi, int num);
void displayOneStdnt(Tstdnt studentArray[], int position);
int binarySearch(Tstdnt studentArray[], int left, int right, int number);

//**** MAIN FUNCTION ****
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//***** MENU DEVELOPMENT *****
void menu()
{
    int op, position; // op will save user's input (menu);          position will be controlling the max size of the array. It will increase everytime someone adds new register. It will be the position of the max size.
    int flag;         // We will use this flag to know if it's ordered (use a different search method) or if it's not.
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
                newStdnt(studentArray, position);
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
            bubbleSort(studentArray, position);
            printf("Los registros han sido ordenados correctamente por matricula de menor a mayor\n");
            flag = 1;
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

//****** MAIN SWITCH FUNCTIONS DEVELOPMENT *****
void fillReg(Tstdnt studentArray[], int position)
{
    int i;
    for (i = position; i < position + 10; i++)
    {
        genDataReg(studentArray, i, position);
    }
    displayReg(studentArray, position + 10);
}

void newStdnt(Tstdnt studentArray[], int position)
{

    char tempSentence[30];

    studentArray[position].status = 1;

    do
    {
        studentArray[position].matricula = valid("Por favor, introduce la matricula del estudiante: ", 300000, 399999); // We validate user's input in a range between the lowest student registration and the highest number.
    } while (existElem(studentArray, position, studentArray[position].matricula) != -1);                                // If it already exists, it will be looping until their input is not in the array.

    do //*** GET LAST NAME 1 ***
    {
        printf("Por favor, introduce el apellido paterno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(studentArray[position].LastName1, tempSentence); // Copy input to studentArray

    do // **** GET LAST NAME 2 ****
    {
        printf("Por favor, introduce el apellido materno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(studentArray[position].Lastname2, tempSentence); // Copy input to studentArray

    do //*** GET NAME *****
    {
        printf("Por favor, introduce el nombre del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(studentArray[position].name, tempSentence); // Copy input to studentArray
    //*** GET STUDENT AGE ***
    studentArray[position].age = valid("Introduce la edad del estudiante: ", 18, 40);
    //**** GET STUDENT SEX*****
    printf("0.- Mujer\t 1.- Hombre\n");
    studentArray[position].sex = valid("Introduce el sexo del estudiante: ", 0, 1);

    printf("\n\tINFORMACION DEL ESTUDIANTE AGREGADO RECIENTEMENTE\n");
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
    displayOneStdnt(studentArray, position);
}

void deleteStdnt(Tstdnt studentArray[], int position)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea eliminar: ", 300000, 399999);
    index = existElem(studentArray, position, num);
    if (index != -1)
    {
        if (studentArray[index].status != 0) // Student has been found and also it's actived (1)
        {
            studentArray[index].status = 0;
            printf("El estudiante ha sido dado de baja correctamente.\n");
        }
        else // Student has been found, but it's already inactived (0)
        {
            printf("El estudiante ya estaba dado de baja con anterioridad.\n");
        }
    }
    else // Student wasn't found
    {
        printf("La matricula ingresada no pertecene a ningun estudiante\n");
    }
}

void searchStdnt(Tstdnt studentArray[], int position, int flag)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea buscar: ", 300000, 399999);
    if (flag == 0) // If it's not ordered from smallest to largest
    {
        index = existElem(studentArray, position, num);
    }
    else // if so
    {
        index = binarySearch(studentArray, 0, position - 1, num);
    }
    if (index != -1) // Check what function returned
    {
        printf("El estudiante ha sido encontrado con exito\n");
        printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
        displayOneStdnt(studentArray, index);
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
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
    for (i = 0; i < position; i++)
    {
        if (studentArray[i].status == 1)
        {
            displayOneStdnt(studentArray, i);
        }
    }
}

//****** AUXILIAR PROTOTYPE FUNCTIONS DEVELOPMENT *****
void genDataReg(Tstdnt studentArray[], int i, int position)
{
    // *** GET LAST NAME ***
    int index1, index2;

    //*** COPY LAST NAME 1 AND 2 ****
    do
    {
        // LAST NAME 1
        index1 = numRandom(0, 99);
        strcpy(studentArray[i].LastName1, LastName[index1]);

        // LAST NAME 2
        index2 = numRandom(0, 99);
        strcpy(studentArray[i].Lastname2, LastName[index2]);
    } while (index1 == index2);

    //*** STATUS ***
    studentArray[i].status = 1;

    //**** STUDENT REGISTRATION *********
    do
    {
        studentArray[i].matricula = numRandom(300000, 399999);
    } while (existElem(studentArray, position, studentArray[i].matricula) != -1);

    //**** GENERATE SEX AND NAME ****
    if (numRandom(0, 1) == 1)
    {
        strcpy(studentArray[i].name, nameMen[numRandom(1, 29)]);
        studentArray[i].sex = 1; // MEN = 1
    }
    else
    {
        strcpy(studentArray[i].name, nameWomen[numRandom(1, 29)]);
        studentArray[i].sex = 0; // WOMEN = 0
    }

    //**** GENERATE AGE *********
    studentArray[i].age = numRandom(18, 40);
}

void displayReg(Tstdnt studentArray[], int position)
{
    int i;
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");

    for (i = 0; i < position; i++)
    {
        printf("| %-3d | %-10d | %-6d | %-12s | %-12s | %-12s | %-4d |", i + 1, studentArray[i].matricula, studentArray[i].status, studentArray[i].LastName1, studentArray[i].Lastname2, studentArray[i].name, studentArray[i].age);
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

void displayOneStdnt(Tstdnt studentArray[], int position)
{
    printf("| %-3d | %-10d | %-6d | %-12s | %-12s | %-12s | %-4d |", position + 1, studentArray[position].matricula, studentArray[position].status, studentArray[position].LastName1, studentArray[position].Lastname2, studentArray[position].name, studentArray[position].age);
    if (studentArray[position].sex == 0)
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
    while (left <= right)
    {
        int medium = left + (right - left) / 2;

        // Check if number is present at mid
        if (studentArray[medium].matricula == number)
        {
            return medium;
        }

        if (studentArray[medium].matricula < number) // If number greater, ignore left half
        {
            left = medium + 1;
        }
        else // If number is smaller, ignore right half
        {
            right = medium - 1;
        }
    }

    // If we reach here, then element was not present
    return -1;
}


