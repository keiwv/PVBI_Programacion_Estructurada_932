/*

*/

//**** LIBRARIES ****
#include "Frijoles.h"
#include "data.h"
#include <time.h>
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

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void genDataReg();

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
    int op;
    int n = 10;
    int rf = 2;
    Tstdnt studentArray[10];
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            fillReg(studentArray);
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
    printArr("1.- Agregar 10 registros automatico\n");
    printArr("2.- Agregar manual\n");
    printArr("3.- Eliminar registros\n");
    printArr("4.- Buscar\n");
    printArr("5.- Ordenar\n");
    printArr("6.- Imprimir\n");
    printArr("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 6);
    return op;
}

//**********
void genDataReg(Tstdnt studentArray[], int i)
{
    char tempArray[50];
    //*** status ***
    studentArray[i].status = rand() % 1;

    //**** Matricula ***
    studentArray[i].matricula = (rand() % 1000) + 3000;

    copyArray(studentArray[i].LastName1, LastName[(rand() % 30) + 1]);
    copyArray(studentArray[i].Lastname2, LastName[(rand() % 30) + 1]);
    copyArray(studentArray[i].name, nameMen[(rand() % 30) + 1]);

}
void fillReg(Tstdnt studentArray[])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        genDataReg(studentArray, i);
        printf("%s ", studentArray[i].LastName1);
        printf("%s ", studentArray[i].Lastname2);
        printf("%s -- ", studentArray[i].name);
        printf("%d -- ", studentArray[i].matricula);
        printf("%d -- ", studentArray[i].status);
        printf("\n");
    }
    system("PAUSE");
}

