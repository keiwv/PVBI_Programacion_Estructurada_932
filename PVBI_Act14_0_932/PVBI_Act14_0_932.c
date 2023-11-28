/*


*/

// ******** LIBRARIES *********
#include "dataFunctions.h"

#define TRUE 1
#define FALSE 0

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

void addRegister(int position, int max_registers);

//***** USEFUL FUNCTIONS ******
TWrkr generateRegister();
int fillRegister(TWrkr employess[]);
int fillIndexRegister(TIndexStrct Index[]);
void displayListEmp(TWrkr employee, int i);
int existElem(TWrkr employee[], int longi, Tkey num);
void ModifyFileBinary();
// *** MAIN FUNCTION ***
int main()
{
    srand(time(NULL));
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
    int max_registers, position;
    position = LoadBinaryFile();
    max_registers = position * 1.25;
    do
    {
        system("CLS");
        printf("Registros: %d\n", max_registers);
        op = msge_menu();
        system("CLS");

        switch (op)
        {
        case 1:
            addRegister(position, max_registers);
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
    sprintf(cmd, "RegisterCounter.exe %s", "datos_index.dat");
    count = system(cmd);
    if (count == -1)
    {
        printf("El archivo no fue encontrado\n");
        count = 0;
    }
    return count;
}

/*void getIndexFile(int max_registers)
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
            // printf("index = %d ----- enrollment = %d\n", i, index[i].enrollment);
            i++;
        }
        fclose(fa);

        pa = fopen("datos_index.dat", "wb");
        fwrite(index, sizeof(TIndexStrct), i, pa);
        fclose(pa);

    }
    else
    {
        printf("Archivno no encontrado\n");
    }
}*/

void addRegister(int position, int max_registers)
{
    TWrkr employees[max_registers];
    TWrkr tempEmployee;

    tempEmployee = generateRegister();
    fillRegister(employees);
    do
    {
        tempEmployee.cellPhone = numRandom(1000000, 1999999);
    } while (existElem(employees, position, tempEmployee.cellPhone) != -1);

    do
    {
        tempEmployee.enrollment = numRandom(300000, 399999);
    } while (existElem(employees, position, tempEmployee.enrollment) != -1);




    system("PAUSE");
}

// ****** USEFUL FUNCTIONS DEVELOPMENT ****
TWrkr generateRegister()
{
    TWrkr temp;

    temp.age = numRandom(18, 40);

    if (numRandom(0, 1))
    {
        nameMen(temp.name);
        strcpy(temp.sex, "HOMBRE");
    }
    else
    {
        nameWomen(temp.name);
        strcpy(temp.sex, "MUJER");
    }

    LastName(temp.LastName1);
    LastName(temp.LastName2);

    getState(temp.state);
    getJobPositions(temp.JobPstion);

    temp.status = 1;

    return temp;
}

int fillRegister(TWrkr employess[])
{
    FILE *fa;
    TWrkr temp;
    fa = fopen("datos.dat", "rb");
    int i = 0;
    if (fa)
    {
        while (fread(&employess[i], sizeof(TWrkr), 1, fa))
        {
            i++;
        }
        fclose(fa);
        return i;
    }
    else
    {
        printf("El archivo no existe.\n");
    }
    return 0;
}

int fillIndexRegister(TIndexStrct Index[])
{
    FILE *fa;

    int i = 0;
    fa = fopen("datos_index.dat", "rb");
    if (fa)
    {
        while (fread(&Index[i], sizeof(TIndexStrct), 1, fa))
        {
            i++;
        }
        fclose(fa);
        return i;
    }
    else
    {
        printf("El archivo no existe\n");
    }
    return 0;
}

void displayListEmp(TWrkr employee, int i)
{
    printf("%-10d %-12d %-15s %-20s %-15s %-10s %-10s %-10s %-5d 646%-10d\n",
           i + 1,
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

int existElem(TWrkr employee[], int longi, Tkey num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (employee[i].enrollment == num)
        {
            return i;
        }
    }
    return -1;
}

void ModifyFileBinary(TWrkr employee, int flag)
{
    
    if (flag)
    {
        
    }
    
}