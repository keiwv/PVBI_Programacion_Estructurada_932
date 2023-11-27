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

typedef struct _IndexStrct
{
    Tkey enrollment;
    int index;
} TIndexStrct;

// *** PROTOTYPE FUNCTIONS ****
int msge_menu();
void menu();
int LoadBinaryFile();
void getIndexFile(int max_registers);

// *** MAIN FUNCTION ***
int main()
{
    system("gcc.exe RegisterCounter.c -o RegisterCounter.exe");
    menu();
    return 0;
}

int msge_menu()
{
    printf("------ M E N U ------\n");
    printf("1.- Agregar\n");
    printf("2.- Eliminar\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Mostrar\n");
    printf("6.- Generar archivo de texto\n");
    printf("7.- Empaquetar\n");
    printf("0.- Salir\n");
    return valid("Selecciona una opcion: ", 0, 7);
}

void menu()
{
    int op;
    int max_registers;
    max_registers = LoadBinaryFile();
    getIndexFile(max_registers);
    max_registers += max_registers * 0.25;
    TWrkr employees[max_registers];
    do
    {
        system("CLS");
        // printf("Registros: %d\n", max_registers);
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

int LoadBinaryFile()
{
    int count = 0;
    char cmd[50];
    sprintf(cmd, "RegisterCounter.exe %s", "datos.dat");
    count = system(cmd);
    if (count == -1)
    {
        printf("El archivo no fue encontrado\n");
        count = 0;
    }
    return count;
}

void getIndexFile(int max_registers)
{
    TIndexStrct index[max_registers];
    TWrkr reg;
    int i = 0;

    FILE *fa;
    FILE *pa;

    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa))
        {
            index[i].enrollment = reg.enrollment;
            index[i].index = i;
            //printf("index = %d ----- enrollment = %d\n", i, index[i].enrollment);
            i++;
        }
        fclose(fa);
        pa = fopen("datos_index.dat", "wb");
        if (pa)
        {
            fwrite(index, sizeof(TIndexStrct), i, pa);
            fclose(pa);
        }
    }
    else
    {
        printf("Archivno no encontrado\n");
    }
}