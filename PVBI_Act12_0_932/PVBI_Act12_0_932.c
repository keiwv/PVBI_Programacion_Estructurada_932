/*

    ------ TO BE ADDED --------
*/

// ------- LIBRARIES ----------
#include "dataFunctions.h"

// ------- NUMBER MAX OF REGISTERS -------
#define N 1500

// ------- STRUCTURES -------
typedef struct _alumn

{
    int status;
    int enrollment;
    char LastName1[30];
    char LastName2[30];
    char name[50];
    int age;
    char sex[10];
} Talumn;

// ------- PROTOTYPE FUNCTIONS -----
void menu();
int msge_menu();

void loadFile(Talumn stdnts[], int position);
//-------- MAIN FUNCTION ------
int main()
{
    menu();

    return 0;
}

//-------- PROTOTYPE FUNCTIONS DEVELOPMENT ------
void menu()
{
    int op;
    int position = 0;
    Talumn student[N];
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            LoadFile(student, position);
            break;
        default:
            break;
        }
        if (op != 0)
        {
            system("PAUSE");
        }
    } while (op != 0);
}

int msge_menu()
{
    printf("------- MENU -------\n");
    printf("1.- Cargar archivo\n");
    printf("2.- Agregar\n");
    printf("3.- Eliminar\n");
    printf("4.- Buscar\n");
    printf("5.- Ordenar\n");
    printf("6.- Mostrar todo\n");
    printf("7.- Generar archivo\n");
    printf("8.- Cantidad de registros en archivo\n");
    printf("9.- Mostrar borrados\n");
    printf("0.- Salir\n");
    return valid("Selecciona tu opcion: ", 0, 9);
}

int loadFile(Talumn stdnts[], int position)
{
    FILE *pa;
    Talumn reg;
    fa = fopen("datos.txt","r");
    if(fa)
    {
        do
        {
            fscanf()
        } while (!feof(fa));
        
    }
}