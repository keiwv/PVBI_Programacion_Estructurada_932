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
    char sex[15];
} Tstdnt;

// ------- PROTOTYPE FUNCTIONS -----
void menu();
int msge_menu();

int loadFile(Tstdnt stdnts[], int position, char txtName[]);
int tenReg(Tstdnt studentArray[], int position);
void displayReg(Tstdnt students[], int position);
void findStdnt(Tstdnt students[], int position, int flag);
void deleteStdnt(Tstdnt students[], int position, int flag);
void orderStdnts(Tstdnt students[], int position, int flag);
void getTXT(Tstdnt students[], int position);
void counterRegisters();
//***** NAMES *************
void nameMen(char tempName[]);
void nameWomen(char tempName[]);
void LastName(char tempLastName[]);

//******** USEFUL FUNCTIONS ******
Tstdnt genDataReg(Tstdnt studentArray[], int position);
int existElem(Tstdnt studentArray[], int longi, int num);
void displayOneStdntList(Tstdnt students);
int searchStdnt(Tstdnt students[], int position, int num, int flag);
int existElem(Tstdnt students[], int longi, int num);
int binarySearch(Tstdnt studentArray[], int left, int right, int number);
void displayOneStdnt(Tstdnt students);

void swap(Tstdnt students[], int i, int j);
int partition(Tstdnt students[], int low, int high);
void quicksort(Tstdnt students[], int low, int high);
void bubbleSort(Tstdnt studentArray[], int n);
//-------- MAIN FUNCTION ------
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

//-------- PROTOTYPE FUNCTIONS DEVELOPMENT ------
void menu()
{
    int op;
    int flag = 0;
    int loadFileFlag = 0;
    int position = 0;
    Tstdnt student[N];
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            if (loadFileFlag)
            {
                printf("Ya se ha cargado el archivo una vez\n");
            }
            else
            {
                if (position + 313 < N)
                {
                    position = loadFile(student, position, "datos.txt");
                    flag = 0;
                }
                else
                {
                    printf("El archivo no puede ser cargado debido a que se alcanzo el numero maximo de registros\n");
                }
            }
            break;
        case 2:
            position = tenReg(student, position);
            flag = 0;
            break;
        case 3:
            deleteStdnt(student, position, flag);
            flag = 0;
            break;
        case 4:
            findStdnt(student, position, flag);
            break;
        case 5:
            orderStdnts(student, position, flag);
            flag = 1;
            break;
        case 6:
            displayReg(student, position);
            break;
        case 7:
            getTXT(student, position);
            break;
        case 8:
            counterRegisters();
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

int loadFile(Tstdnt stdnts[], int position, char txtName[])
{
    FILE *fa;
    Tstdnt reg;
    int tempNo = 0;
    fa = fopen(txtName, "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s", &tempNo, &reg.enrollment, reg.name, reg.LastName1, reg.LastName2, &reg.age, reg.sex);
            printf("%d.- %d %s %s %s %d %s\n", position, reg.enrollment, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex);
            reg.status = 1;
            stdnts[position++] = reg;
        } while (!feof(fa));
        fclose(fa);
    }
    else
    {
        printf("El archivo no existe");
    }
    return position - 1;
}

int tenReg(Tstdnt studentArray[], int position)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i + 1 > N)
        {
            printf("El registro ha sido llenado.\n");
            return position;
        }
        studentArray[position] = genDataReg(studentArray, position);
        position++;
    }
    printf("Se han agregado 10 registros al arreglo.\n");
    return position;
}

void displayReg(Tstdnt students[], int position)
{
    int i;
    printf("Mostrando todo el registo: \n");
    for (i = 0; i < position; i++)
    {
        if (students[i].status)
        {
            displayOneStdntList(students[i]);
        }

        if ((i + 1) % 40 == 0)
        {
            system("PAUSE");
            system("CLS");
            printf("Mostrando todo el registo: \n");
        }
    }
    printf("----------------------------------");
    printf("\nSe han imprimido todos los estudiantes\n");
}

void findStdnt(Tstdnt students[], int position, int flag)
{
    int index;
    index = searchStdnt(students, position, valid("Ingresa la matricula del estudiante a buscar: ", 300000, 399999), flag);
    if (index != -1)
    {
        printf("Alumno encontrado: \n");
        printf("%-6s %-10s %-10s %-15s %-15s %-5s %s\n", "No.", "Matricula", "Nombre", "Ape Paterno", "Ape Materno", "Edad", "Sexo");
        printf("%-7d", index);
        displayOneStdntList(students[index]);
    }
    else
    {
        printf("El alumno no ha sido encontrado.\n");
    }
}

void deleteStdnt(Tstdnt students[], int position, int flag)
{
    int index;
    index = searchStdnt(students, position, valid("Ingresa el numero de enrollment que desea eliminar: ", 300000, 399999), flag);

    if (index != -1)
    {
        if (students[index].status != 0)
        {
            displayOneStdnt(students[index]);
            if (valid("Deseas eliminar el registro (0.- No / 1.- Si): ", 0, 1))
            {
                students[index].status = 0;
                printf("El estudiante ha sido dado de baja correctamente.\n");
            }
        }
        else
        {
            printf("El estudiante ya sido dado de baja con anterioridad.\n");
        }
    }
    else
    {
        printf("La enrollment ingresada no pertecene a ningun estudiante\n");
    }
}

void orderStdnts(Tstdnt students[], int position, int flag)
{
    if (flag == 1)
    {
        printf("Ya ha sido ordenado de menor a mayor\n");
    }
    else
    {
        if (position >= 200)
        {
            quicksort(students, 0, position);
        }
        else
        {
            bubbleSort(students, position);
        }
        printf("Los estudiantes han sido ordenados correctamente\n");
    }
}

void getTXT(Tstdnt students[], int position)
{
    int i;
    FILE *fa;
    char fileName[30];
    do
    {
        ask("Ingresa el nombre con el que deseas guardarlo: ", fileName);
    } while (alfaSpace(fileName) == -1);

    strcat(fileName, ".txt");
    fa = fopen(fileName, "w");

    fprintf(fa, "%-6s %-10s %-10s %-15s %-15s %-5s %s\n", "No.", "Matricula", "Nombre", "Ape Paterno", "Ape Materno", "Edad", "Sexo");

    for (i = 0; i < position; i++)
    {
        fprintf(fa, "%-6d %-10d %-10s %-15s %-15s %-5d %s\n",
                i + 1,
                students[i].enrollment,
                students[i].name,
                students[i].LastName1,
                students[i].LastName2,
                students[i].age,
                students[i].sex);
    }

    fclose(fa);
    printf("Archivo generado exitosamente!\n");
}

void counterRegisters()
{
    int count;
    char fileName[50];
    char cmd[50];
    do
    {
        ask("Ingrese el nombre del archivo que usted quiere saber la cantidad de registros: ", fileName);
    } while (alfaSpace(fileName) == -1);
    
    system("mingw32-gcc-6.3.0.exe RegisterCounter.c -o RegisterCounter"); // This line compile RegisterCounter.c.
    sprintf(cmd,"RegisterCounter.exe %s", fileName);
    count = system(cmd);

    if(count != -1)
    {
        printf("El archivo %s contiene %d registros\n", fileName, count);
    }
    else 
    {
        printf("El archivo no fue encontrado\n");
    }
}
// ********** USEFUL FUNCTIONS ***********
Tstdnt genDataReg(Tstdnt studentArray[], int position)
{
    Tstdnt tempStudentArray;

    char tempName[50];

    LastName(tempName);
    strcpy(tempStudentArray.LastName1, tempName);

    LastName(tempName);
    strcpy(tempStudentArray.LastName2, tempName);

    tempStudentArray.status = 1;

    do
    {
        tempStudentArray.enrollment = numRandom(300000, 399999);
    } while (existElem(studentArray, position, tempStudentArray.enrollment) != -1);

    if (numRandom(0, 1) == 1)
    {
        nameMen(tempName);
        strcpy(tempStudentArray.name, tempName);
        strcpy(tempStudentArray.sex, "MASCULINO");
    }
    else
    {
        nameWomen(tempName);
        strcpy(tempStudentArray.name, tempName);
        strcpy(tempStudentArray.sex, "FEMENINO");
    }

    tempStudentArray.age = numRandom(18, 40);

    return tempStudentArray;
}

int existElem(Tstdnt studentArray[], int longi, int num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (studentArray[i].enrollment == num)
        {
            return i;
        }
    }
    return -1;
}

void displayOneStdntList(Tstdnt students)
{
    printf("%-10d %-10s %-15s %-15s %-5d %s\n",
           students.enrollment,
           students.name,
           students.LastName1,
           students.LastName2,
           students.age,
           students.sex);
}

int searchStdnt(Tstdnt students[], int position, int num, int flag)
{
    if (flag == 0)
    {
        return existElem(students, position, num);
    }
    else
    {
        return binarySearch(students, 0, position, num);
    }
    return -1;
}

int binarySearch(Tstdnt studentArray[], int left, int right, int number)
{
    int medium;
    while (left <= right)
    {
        medium = left + (right - left) / 2;

        if (studentArray[medium].enrollment == number)
        {
            return medium;
        }

        if (studentArray[medium].enrollment < number)
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

void displayOneStdnt(Tstdnt students)
{
    printf("----------------------------------\n");
    printf("MATRICULA:  %d\n", students.enrollment);
    printf("NOMBRE:     %s\n", students.name);
    printf("AP. PAT:    %s\n", students.LastName1);
    printf("AP. MAT:    %s\n", students.LastName2);
    printf("EDAD:       %02d\n", students.age);
    printf("SEXO:       %s\n", students.sex);
    printf("----------------------------------\n");
}

//******* ORDER FUNCTIONS ***********

void swap(Tstdnt students[], int i, int j)
{
    Tstdnt temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(Tstdnt students[], int low, int high)
{
    Tstdnt pivot;
    pivot.enrollment = students[high].enrollment;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].enrollment <= pivot.enrollment)
        {
            i++;
            swap(students, i, j);
        }
    }
    swap(students, i + 1, high);
    return i + 1;
}

void quicksort(Tstdnt students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);

        quicksort(students, low, pi - 1);
        quicksort(students, pi + 1, high);
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
            if (studentArray[j].enrollment < studentArray[i].enrollment)
            {
                temp = studentArray[i];
                studentArray[i] = studentArray[j];
                studentArray[j] = temp;
            }
        }
    }
}
