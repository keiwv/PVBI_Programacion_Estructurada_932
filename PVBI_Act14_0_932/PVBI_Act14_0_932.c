/*


*/

// ******** LIBRARIES *********
#include "dataFunctions.h"

// ******** STRUCTURES ********
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

// *** PROTOTYPE FUNCTIONS ****
int msge_menu();
void menu();
void LoadBinaryFile();


// *** MAIN FUNCTION ***
int main()
{
    menu();
    return 0;
}

int msge_menu()
{
    printf("----- M E N U ------\n");
    printf("1.- Agregar\n");
    printf("2.- Eliminar\n");
    printf("3.- Buscar\n");
    printf("4. Ordenar\n");
    printf("5.- Mostrar");
    printf("6.- Generar archivo de texto\n");
    printf("7.- Empaquetar\n");
    printf("0.- Salir");
    return valid("Selecciona una opcion: ", 0, 7);
}

void menu()
{
    int op;
    int max_registers;
    max_registers = LoadBinaryFile();
    TWrkr employees[max_registers];

    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");

        switch (op)
        {
        case 1:

            break;
        
        default:
            break;
        }
    } while (op != 0);
    
}

void LoadBinaryFile()
{

}