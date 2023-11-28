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

void addRegister(int position, int max_registers);
void deleteRegister(int position, int max_registers, int ord);
void findRegister(int position, int ord);
int OrderIndex(int position, int flag);
int displayReg(int position, int flag);
void genTxT(int position, int flag);
void packageFile(int position);

//***** USEFUL FUNCTIONS ******
TWrkr generateRegister();
int fillRegister(TWrkr employess[]);
int fillIndexRegister(TIndexStrct Index[]);
void displayListEmp(TWrkr employee, int i);
int existElem(TIndexStrct employee[], int longi, Tkey num);
void getTempFiles(int n);
void addRegisterData(TWrkr employee);
void addRegisterIndex(TIndexStrct employeeIndx);
int binarySearch(TIndexStrct employee[], int left, int right, Tkey number);
void displayRegEmp(TWrkr employee);
void addOneEmplyeeTxT(TWrkr employee, int position, FILE *fa);
void getTXT(TIndexStrct Indexs[], int position, char fileName[], int flag);
//***** ORDER FUNCTIONS *****
void bubbleSort(TIndexStrct employees[], int n);
void quicksort(TIndexStrct employees[], int low, int high);
int partition(TIndexStrct employees[], int low, int high);
void swap(TIndexStrct employees[], int i, int j);

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
    getIndexFile(position);
    getTempFiles(position);
    max_registers = position * 1.25;
    int ord = 0;
    do
    {
        system("CLS");
        // printf("Registros: %d\n", max_registers);
        op = msge_menu();
        system("CLS");

        switch (op)
        {
        case 1:
            if (position + 1 < max_registers)
            {
                addRegister(position, max_registers);
                ord = 0;
                position++;
            }
            else
            {
                printf("Vector lleno\n");
            }
            break;
        case 2:
            deleteRegister(position, max_registers, ord);
            break;
        case 3:
            findRegister(position, ord);
            break;
        case 4:
            ord = OrderIndex(position, ord);
            break;
        case 5:
            ord = displayReg(position, ord);
            break;
        case 6:
            genTxT(position, ord);
            break;
        case 7:
            packageFile(position);
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
}

void addRegister(int position, int max_registers)
{
    TIndexStrct employees[max_registers];
    TWrkr tempEmployee;
    TIndexStrct temp;
    tempEmployee = generateRegister();
    fillIndexRegister(employees);
    do
    {
        tempEmployee.enrollment = numRandom(300000, 399999);
    } while (existElem(employees, position, tempEmployee.enrollment) != -1);

    addRegisterData(tempEmployee);
    temp.enrollment = tempEmployee.enrollment;
    temp.index = position;
    addRegisterIndex(temp);
    displayRegEmp(tempEmployee);
    printf("Aniadido correctamente\n");
}

void findRegister(int position, int ord)
{
    int index;
    TIndexStrct indexFile[position];
    TWrkr regTemp;
    FILE *fa;
    index = valid("Ingrese la matricula del estudiante a eliminar: ", 300000, 399999);
    fillIndexRegister(indexFile);
    if (ord)
    {
        index = binarySearch(indexFile, 0, position, index);
    }
    else
    {
        index = existElem(indexFile, position, index);
    }

    if (index != -1)
    {
        fa = fopen("datos.dat", "rb");
        fseek(fa, index * sizeof(TWrkr), SEEK_SET);
        fread(&regTemp, sizeof(TWrkr), 1, fa);
        fclose(fa);

        if (regTemp.status)
        {
            displayRegEmp(regTemp);
        }
        else
        {
            printf("Alumno eliminado con anterioridad\n");
        }
    }
}

void deleteRegister(int position, int max_registers, int ord)
{
    int index;
    TIndexStrct indexFile[max_registers];
    TWrkr regTemp;
    FILE *fa;
    index = valid("Ingrese la matricula del estudiante a eliminar: ", 300000, 399999);
    fillIndexRegister(indexFile);
    if (ord)
    {
        index = binarySearch(indexFile, 0, position, index);
    }
    else
    {
        index = existElem(indexFile, position, index);
    }

    if (index != -1)
    {
        fa = fopen("datos.dat", "rb");
        fseek(fa, index * sizeof(TWrkr), SEEK_SET);
        fread(&regTemp, sizeof(TWrkr), 1, fa);
        fclose(fa);

        if (regTemp.status)
        {
            displayRegEmp(regTemp);
            if (valid("Desea eliminarlo? (1.- Si, 0.- No): ", 0, 1))
            {
                regTemp.status = 0;
                fa = fopen("datos.dat", "rb+");
                fseek(fa, index * sizeof(TWrkr), SEEK_SET);
                fwrite(&regTemp, sizeof(TWrkr), 1, fa);
                fclose(fa);
                printf("Eliminado con exito\n");
            }
        }
        else
        {
            printf("Alumno eliminado con anterioridad\n");
        }
    }
    else
    {
        printf("El alumno no existe\n");
    }
}

int OrderIndex(int position, int flag)
{
    TIndexStrct Index[position];
    FILE *fa;

    if (flag)
    {
        printf("El vector ya ha sido ordenado con anterioridad");
    }
    else
    {
        fillIndexRegister(Index);
        bubbleSort(Index, position);
        fa = fopen("datos_index.dat", "wb");
        fwrite(Index, sizeof(TWrkr), 1, fa);
        fclose(fa);
        printf("El vector ha sido ordenado\n");
        return 1;
    }
    return flag;
}

int displayReg(int position, int flag)
{
    FILE *fa;
    TWrkr temp;
    int i = 0;
    fa = fopen("datos.dat", "rb");
    if (valid("Imprimir datos\n 1.- Ordenado\n0.- Normal\n Selecciona una opcion: ", 0, 1))
    {
        TIndexStrct Indexs[position];
        fillIndexRegister(Indexs);
        if (!flag)
        {
            bubbleSort(Indexs, position);
            flag = 1;
        }

        for (i = 0; i < position; i++)
        {
            fseek(fa, Indexs[i].index * sizeof(TWrkr), SEEK_SET);
            fread(&temp, sizeof(TWrkr), 1, fa);
            if (temp.status)
            {
                displayListEmp(temp, i);
            }
        }
        fclose(fa);
    }
    else
    {
        system("CLS");
        if (fa)
        {
            while (fread(&temp, sizeof(TWrkr), 1, fa))
            {
                if (temp.status)
                {
                    displayListEmp(temp, i);
                    i++;
                }
            }
            fclose(fa);
        }
    }
    return flag;
}

void genTxT(int position, int flag)
{
    TWrkr temp;
    if (valid("Generar archivo de texto\n 1.- Ordenado\n0.- Normal\n Selecciona una opcion: ", 0, 1))
    {
        TIndexStrct Indexs[position];
        fillIndexRegister(Indexs);
        if (!flag)
        {
            bubbleSort(Indexs, position);
            flag = 1;
        }
        getTXT(Indexs, position, "datos_activos.txt", 1);
        getTXT(Indexs, position, "datos_inactivos.txt", 0);
        printf("Archivos generados correctamente\n");
    }
    else
    {
        FILE *fa, *pa, *ma;
        int i = 0, j = 0;
        fa = fopen("datos.dat", "rb");
        pa = fopen("datos_activos.txt", "w");
        ma = fopen("datos_inactivos.txt", "w");
        if (fa)
        {
            while (fread(&temp, sizeof(TWrkr), 1, fa))
            {
                if (temp.status)
                {
                    addOneEmplyeeTxT(temp, i, pa);
                    i++;
                }
                else
                {
                    addOneEmplyeeTxT(temp, j, ma);
                    j++;
                }
            }
            fclose(fa);
            printf("Archivos generados correctamente\n");
        }
        fclose(pa);
        fclose(ma);
    }
}

void packageFile(int position)
{
    FILE *fa;
    TWrkr vectTemp[position];
    TWrkr vectTempActive[position];
    int j = 0;
    fillRegister(vectTemp);
    rename("datos.dat", "datos.bak");
    fa = fopen("datos.dat", "wb");
    if (fa)
    {
        for (int i = 0; i < position; i++)
        {
            if (vectTemp[i].status)
            {
                vectTempActive[j++] = vectTemp[i];
            }
        }
        fwrite(vectTempActive, sizeof(TWrkr), j, fa);
        fclose(fa);
        printf("Empaquetado correctamente\n");
    }
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

    temp.cellPhone = numRandom(1000000, 1999999);

    temp.status = 1;

    return temp;
}

int fillRegister(TWrkr employess[])
{
    FILE *fa;
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

int existElem(TIndexStrct employee[], int longi, Tkey num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (employee[i].enrollment == num)
        {
            return employee[i].index;
        }
    }
    return -1;
}

void getTempFiles(int n)
{
    TWrkr tempWrkr[n];

    fillRegister(tempWrkr);

    rename("datos.dat", "datos_backup.dat");

    FILE *fa;
    fa = fopen("datos.dat", "wb");

    fwrite(tempWrkr, sizeof(TWrkr), n, fa);
    fclose(fa);
}

void addRegisterData(TWrkr employee)
{
    FILE *fa;
    fa = fopen("datos.dat", "ab");
    fseek(fa, 0, SEEK_END);
    fwrite(&employee, sizeof(TWrkr), 1, fa);
    fclose(fa);
}

void addRegisterIndex(TIndexStrct employeeIndx)
{
    FILE *fa;
    fa = fopen("datos_index.dat", "ab");
    fseek(fa, 0, SEEK_END);
    fwrite(&employeeIndx, sizeof(TIndexStrct), 1, fa);
    fclose(fa);
}

int binarySearch(TIndexStrct employee[], int left, int right, Tkey number)
{
    int medium;
    while (left <= right)
    {
        medium = left + (right - left) / 2;

        if (employee[medium].enrollment == number)
        {
            return employee[medium].index;
        }

        if (employee[medium].enrollment < number)
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

void getTXT(TIndexStrct Indexs[], int position, char fileName[], int flag)
{
    int i;
    FILE *fa;
    FILE *pa;
    TWrkr temp;
    int j;
    fa = fopen(fileName, "w");
    pa = fopen("datos.dat", "rb");
    fprintf(fa, "%-10s %-12s %-15s %-20s %-15s %-10s %-10s %-8s %-5s %-10s\n",
            "No.",
            "Matricula",
            "Nombre",
            "Ap. Paterno",
            "Ao. Materno",
            "Sexo",
            "Posicion",
            "Estado",
            "Edad",
            "Num. Cel");

    j = 0;
    for (i = 0; i < position; i++)
    {
        fseek(pa, Indexs[i].index * sizeof(TWrkr), SEEK_SET);
        fread(&temp, sizeof(TWrkr), 1, pa);
        if (temp.status == flag)
        {
            addOneEmplyeeTxT(temp, j, fa);
            j++;
        }
    }
    fclose(pa);
    fclose(fa);
}

void addOneEmplyeeTxT(TWrkr employee, int position, FILE *fa)
{
    fprintf(fa, "%-10d %-12d %-15s %-20s %-15s %-10s %-10s %-10s %-5d 646%-10d\n",
            position + 1,
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

//**** ORDER FUNCTIONS ****
void swap(TIndexStrct employees[], int i, int j)
{
    TIndexStrct temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;
}

int partition(TIndexStrct employees[], int low, int high)
{
    TIndexStrct pivot;
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

void quicksort(TIndexStrct employees[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(employees, low, high);

        quicksort(employees, low, pi - 1);
        quicksort(employees, pi + 1, high);
    }
}

void bubbleSort(TIndexStrct employees[], int n)
{
    int i, j;
    TIndexStrct temp;
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
