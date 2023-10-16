/*

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

#define STDNTSIZE 500
char nameMen[30][30] = {"JUAN", "PEDRO", "LUIS", "MIGUEL", "CARLOS", "JAVIER", "MANUEL", "JOSE", "FERNANDO", "ALBERTO", "RICARDO", "ENRIQUE", "ANTONIO", "ALEJANDRO", "EMILIO", "ARTURO", "JORGE", "EDUARDO", "HECTOR", "FRANCISCO", "RAUL", "ROBERTO", "ERNESTO", "GUILLERMO", "ARMANDO", "MARIO", "DANIEL", "OSCAR", "ISRAEL", "SALVADOR"};

char nameWomen[30][30] = {"MARÍA", "ANA", "LAURA", "PATRICIA", "CARMEN", "SOFIA", "ISABEL", "PAULA", "BEATRIZ", "ELENA", "GABRIELA", "ROSA", "CLARA", "VICTORIA", "LOURDES", "ADRIANA", "NATALIA", "SUSANA", "MARTA", "PILAR", "SONIA", "ALEJANDRA", "JULIA", "RAQUEL", "ANTONIA", "GLORIA", "SILVIA", "AURORA", "CONSUELO", "MERCEDES"};

char LastName[120][60] = {"RAMOS", "MORENO", "FERNANDEZ", "TORRES", "RAMIREZ", "JIMENEZ", "NUNEZ", "VEGA", "ROJAS", "IGLESIAS", "PACHECO", "VALENCIA", "MORA", "SILVA", "GOMEZ", "CORDERO", "SERRANO", "MEDINA", "ALVAREZ", "SOTO", "LARA", "HERRERA", "GUERRERO", "ORTIZ", "PARDO", "ROLDAN", "SUAREZ", "SALAZAR", "CASTILLO", "AGUILAR", "ROMAN", "ZAMORA", "DIAZ", "CASTANEDA", "VARGAS", "QUINTERO", "MOLINA", "CABRERA", "GONZALES", "CRUZ", "DELGADO", "VILLANUEVA", "RIOS", "REYES", "FLORES", "ROJAS", "ARIAS", "LOPEZ", "MALDONADO", "MENDEZ", "CERVANTES", "ESPINOSA", "CHACON", "SOLIS", "TOVAR", "SANDOVAL", "VALENCIA", "RIVERA", "ROSALES", "DURAN", "RUBIO", "MENDOZA", "BAUTISTA", "VASQUEZ", "ROMERO", "MERCADO", "ESPINOSA", "ESCOBAR", "SOSA", "BARRIOS", "LEON", "SOTO", "OCHOA", "CONTRERAS", "CERVANTES", "VALENZUELA", "MIRANDA", "PAREDES", "BELTRAN", "ESPINOZA", "PENA", "CASILLAS", "VARELA", "HIDALGO", "GUZMAN", "MENENDEZ", "ALVARADO", "ESTRELLA", "HERNANDEZ", "OSORIO", "MACIAS", "URIBE", "GARZA", "VALDES", "CAMACHO", "LEAL", "MUNGUIA", "SOLANO", "MACIEL", "CALZADA", "ALCALA", "BARAJAS", "PARRA", "ELIZONDO", "PALACIOS", "CASAS", "VENTURA", "MONTES", "MUNOZ", "LUGO", "SOSA", "OJEDA", "FRANCO", "ARELLANO", "PIZARRO", "CHAVEZ", "ROBLES", "CARRANZA", "URBINA"};

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void genDataReg(Tstdnt studentArray[], int i, int position);
void fillReg(Tstdnt studentArray[], int position);
void displayReg(Tstdnt studentArray[], int position);
int existElem(Tstdnt studentArray[], int longi, int num);

void newStdnt(Tstdnt studentArray[], int position);
void deleteStdnt(Tstdnt studentArray[], int position);
void displayOneStdnt(Tstdnt studentArray[], int position);
void searchStdnt(Tstdnt studentArray[], int position, int flag);
int binarySearch(Tstdnt studentArray[], int left, int right, int number);
void bubbleSort(Tstdnt studentArray[], int n);

//**** MAIN FUNCTIONS ****
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu()
{
    int op, position;
    int flag;
    position = 0;
    Tstdnt studentArray[STDNTSIZE];
    do
    {
        op = msge_menu();
        if (position == STDNTSIZE)
        {
            printf("Cantidad maxima de registros llena\n");
            system("PAUSE");
        }
        else
        {
            switch (op)
            {
            case 1:
                fillReg(studentArray, position);
                position += 10;
                flag = 0;
                system("PAUSE");
                break;
            case 2:
                newStdnt(studentArray, position);
                flag = 0;
                position += 1;
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
                flag = 1;
                system("PAUSE");
                break;
            case 6:
                displayReg(studentArray, position);
                system("PAUSE");
                break;
            }
        }

    } while (op != 0);
}
//***********
int msge_menu()
{
    int op;
    system("CLS");
    printArr("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
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

//**********
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
    studentArray[i].status = numRandom(0, 1);

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

void fillReg(Tstdnt studentArray[], int position)
{
    int i;
    for (i = position; i < position + 10; i++)
    {
        genDataReg(studentArray, i, position);
    }
    displayReg(studentArray, position + 10);
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
    printf("\t\t\t10 registros creados correctamente!\n");
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

void newStdnt(Tstdnt studentArray[], int position)
{

    char tempSentence[30];

    printf("0.- Inactivo\t 1.- Activo\n");
    studentArray[position].status = valid("Por favor, introduce el status del alumno: ", 0, 1);

    printf("Por favor, introduce la matricula del estudiante:");
    do
    {
        studentArray[position].matricula = valid(" ", 300000, 399999);
    } while (existElem(studentArray, position, studentArray[position].matricula) != -1);

    do //*** GET LAST NAME 1 ***
    {
        printf("Por favor, introduce el apellido paterno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) != 0);

    strcpy(studentArray[position].LastName1, tempSentence); // Copy input to studentArray

    do // **** GET LAST NAME 2 ****
    {
        printf("Por favor, introduce el apellido materno del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) != 0);

    strcpy(studentArray[position].Lastname2, tempSentence); // Copy input to studentArray

    do //*** GET NAME *****
    {
        printf("Por favor, introduce el nombre del estudiante en mayusculas: ");
        ask(tempSentence);
    } while (alfaSpace(tempSentence) != 0);

    strcpy(studentArray[position].name, tempSentence); // Copy input to studentArray
    //*** GET STUDENT AGE ***
    studentArray[position].age = valid("Introduce la edad del estudiante: ", 18, 40);
    //**** GET STUDENT SEX*****
    printf("0.- Mujer\t 1.- Hombre\n");
    studentArray[position].sex = valid("Introduce el sexo del estudiante: ", 0, 1);

    printf("\n\tINFORMACION DEL ESTUDIANTE AGREGADO RECIENTEMENTE\n");
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

void displayOneStdnt(Tstdnt studentArray[], int position)
{
    printf("| %-3s | %-10s | %-6s | %-12s | %-12s | %-12s | %-4s | %-3s |\n", "No.", "Matricula", "Status", "Ap. Paterno", "Ap. Materno", "Nombre", "Edad", "Sexo");
    printf("| %-3d | %-10d | %-6d | %-12s | %-12s | %-12s | %-4d |", position + 1, studentArray[position].matricula, studentArray[position].status, studentArray[position].LastName1, studentArray[position].Lastname2, studentArray[position].name, studentArray[position].age);
    if (studentArray[position].sex == 0)
    {
        printf("  M   |\n\n");
    }
    else
    {
        printf("  H   |\n\n");
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
        displayOneStdnt(studentArray, index);
    }
    else
    {
        printf("El estudiante no ha sido encontrado\n");
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
