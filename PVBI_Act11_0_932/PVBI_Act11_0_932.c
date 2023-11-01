/*

*/

//***** LIBRARIES *****
#include "DataFunctions.h"

//***** STRUCTURES ******
typedef struct _Name
{
    char name[50];
    char lastName1[30];
    char LastName2[30];
} Tname;

typedef struct _Birthday
{
    int year;
    int month;
    int day;
} Tbirthday;
typedef struct _stdnt
{
    int status;
    int matricula;
    Tname personalName;
    Tbirthday date;
    int age;
    char sex[10];
    char placeBirth[3];
    char state[40];
    char curp[18];
} Tstdnt;
//***** GLOBAL CONSTANT *****
const int N = 2000;
//***** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

int menuAdd(int position, Tstdnt students[]);
int msge_menuAdd();
Tstdnt addManual(Tstdnt students[], int position);

void deleteStdnt(Tstdnt students[], int position);
void searchStdnt(Tstdnt students[], int position, int flag);
void orderStdnts(Tstdnt students[], int position, int flag);
void displayReg(Tstdnt students[], int position);
void getTXT(Tstdnt students[], int position);
//****** USEFUL FUNCTIONS **********
Tbirthday getBirthday();
int existElem(Tstdnt students[], int longi, int num);
int getAge(Tbirthday birth);
void getCURP(Tstdnt stdntData, char CURP[]);
void convertNumber(Tstdnt studnt, char CURP[18]);
Tstdnt addOneStdnt(Tstdnt studentArray[], int position);
Tbirthday randomBirthday();
void displayOneStdntList(Tstdnt students);
void displayOneStdnt(Tstdnt students);
int binarySearch(Tstdnt studentArray[], int left, int right, int number);
void bubbleSort(Tstdnt studentArray[], int n);

void swap(Tstdnt students[], int i, int j);
int partition(Tstdnt students[], int low, int high);
void quicksort(Tstdnt students[], int low, int high);

//***** MAIN FUNCTION *****
int main()
{
    srand(time(NULL)); // Set a seed for random numbers
    menu();
    return 0;
}

//***** PROTOTYPE FUNCTIONS DEVELOPMENT *****
void menu()
{
    int op;
    int position = 0;
    int flagOrd = 0;
    int tempPosition = 0;
    Tstdnt students[N];
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            position = menuAdd(position, students);
            if (tempPosition != position)
            {
                flagOrd = 0;
            }
            break;
        case 2:
            if (position != 0)
            {
                deleteStdnt(students, position);
            }
            else
            {
                printf("No hay nada para eliminar:)\n");
            }
            break;
        case 3:
            if (position != 0)
            {
                searchStdnt(students, position, flagOrd);
            }
            else
            {
                printf("No hay nada para buscar:)\n");
            }
            break;
        case 4:
            if (position != 0)
            {
                orderStdnts(students, position, flagOrd);
                flagOrd = 1;
            }
            else
            {
                printf("No hay nada para ordenar:)\n");
            }
            break;
        case 5:
            if (position != 0)
            {
                displayReg(students, position);
            }
            else
            {
                printf("No hay nada que imprimir:)\n");
            }
            break;
        case 6:
            if (position != 0)
            {
                getTXT(students, position);
                position = 0;
                printf("El archivo ha sido generado correctamente y se ha eliminado el registro.\n");
            }
            else
            {
                printf("No hay nada para almacenar:)\n");
            }
            break;
        }
        if (op != 0 || op != 6)
        {
            system("PAUSE");
        }
        tempPosition = position;
    } while (op != 0);
    printf("Saliendo del programa");
}

int msge_menu()
{
    printf("-----MENU DE REGISTROS----\n");
    printf("1.- Agregar\n");
    printf("2.- Eliminar registro\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Imprimir\n");
    printf("6.- Archivo de texto\n");
    printf("0.- Salir\n");

    return valid("Por favor, selecciona una opcion: ", 0, 6);
}

int menuAdd(int position, Tstdnt students[])
{
    int op;
    int i;
    do
    {
        system("CLS");
        op = msge_menuAdd();
        system("CLS");
        switch (op)
        {
        case 1:
            if (N > position + 1)
            {
                students[position] = addManual(students, position);
                students[position].status = 1;
                position += 1;
                printf("Estudiante anadido correctamente\n");
            }
            else
            {
                printf("Tamanio maximo alcanzado.\n");
            }
            break;
        case 2:
            if (N > position + 100)
            {
                for (i = 0; i < 100; i++)
                {
                    students[position + i] = addOneStdnt(students, position);
                    students[position + i].status = 1;
                }
                position += 100;
                printf("100 estudiantes han sido añadidos correctamente\n");
            }
            else
            {
                printf("Tamanio maximo alcanzado.\n");
            }
            break;
        }
        if (op != 3)
        {
            system("PAUSE");
        }
    } while (op != 3);
    return position;
}

int msge_menuAdd()
{
    printf("1.- Manual (1)\n");
    printf("2.- Automatico (100)\n");
    printf("3.- Regresar al inicio\n");

    return valid("Selecciona una opcion: ", 1, 3);
}

Tstdnt addManual(Tstdnt students[], int position)
{
    Tstdnt tempStdnt;
    Tstdnt tempStdntCURP;
    char tempSentence[50];
    char curp[18];

    do
    {
        tempStdnt.matricula = valid("Por favor, introduce la matricula del estudiante: ", 300000, 399999);
    } while (existElem(students, position, tempStdnt.matricula) != -1);

    do
    {
        ask("Por favor, introduce el nombre: ", tempSentence);
        strcpy(tempStdnt.personalName.name, tempSentence);
    } while (alfaSpace(tempSentence) == -1 || tempSentence[0] == '\0');
    strcpy(tempStdntCURP.personalName.name, tempSentence);

    do
    {
        printf("Presiona ENTER si no tienes apellido paterno\n");
        ask("Por favor, introduce el primer apellido: ", tempSentence);
        strcpy(tempStdnt.personalName.lastName1, tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(tempStdntCURP.personalName.lastName1, tempSentence);

    do
    {
        printf("Presiona ENTER si no tienes apellido materno\n");
        ask("Por favor, introduce el segundo apellido: ", tempSentence);
        strcpy(tempStdnt.personalName.LastName2, tempSentence);
    } while (alfaSpace(tempSentence) == -1);

    strcpy(tempStdntCURP.personalName.LastName2, tempSentence);

    tempStdnt.date = getBirthday();
    tempStdntCURP.date = tempStdnt.date;

    tempStdnt.age = getAge(tempStdnt.date);
    tempStdntCURP.age = tempStdnt.age;

    printf("1.- Hombre\n2.- Mujer\n");
    if (valid("Por favor, introduce tu sexo: ", 1, 2) == 1)
    {
        strcpy(tempStdnt.sex, "Hombre");
        strcpy(tempStdntCURP.sex, "Hombre");
    }
    else
    {
        strcpy(tempStdnt.sex, "Mujer");
        strcpy(tempStdntCURP.sex, "Mujer");
    }

    displayStates(tempStdnt.state, tempStdnt.placeBirth);
    strcpy(tempStdntCURP.placeBirth, tempStdnt.placeBirth);

    getCURP(tempStdntCURP, curp);
    strcpy(tempStdnt.curp, curp);

    return tempStdnt;
}

void deleteStdnt(Tstdnt students[], int position)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea eliminar: ", 300000, 399999);
    index = existElem(students, position, num);
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
        printf("La matricula ingresada no pertecene a ningun estudiante\n");
    }
}

void searchStdnt(Tstdnt students[], int position, int flag)
{
    int num, index;
    num = valid("Ingrese la matricula del estudiante que desea buscar: ", 300000, 399999);
    if (flag == 0)
    {
        index = existElem(students, position, num);
    }
    else
    {
        index = binarySearch(students, 0, position, num);
    }

    if (index != -1)
    {
        printf("El alumno ha sido encontrado: \n");
        displayOneStdnt(students[index]);
    }
    else
    {
        printf("La matricula no ha sido registrada\n");
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

void displayReg(Tstdnt students[], int position)
{
    int i;
    printf("%-10s %-10s %-10s %-10s %-12s %-4s %-18s\n", "Matricula", "Ape Pa", "Ape Ma", "Nombre",
           "Fecha de Nac", "Sexo", "CURP");
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
            printf("%-10s %-10s %-10s %-10s %-12s %-4s %-18s\n", "Matricula", "Ape Pa", "Ape Ma", "Nombre",
                   "Fecha de Nac", "Sexo", "CURP");
        }
    }
    printf("----------------------------------\n");
    printf("\nSe han imprimido todos los estudiantes\n");
}

void getTXT(Tstdnt students[], int position)
{
    int i;
    FILE *fa;
    fa = fopen("C:/PVBI_Programacion_Estructurada_932/PVBI_Act11_0_932/Registers.txt", "w");
    fprintf(fa, "%-6s %-10s %-15s %-15s %-10s %-18s %-5s %-5s %s\n", "No.", "Matricula", "Ape Paterno", "Ape Materno", "Nombre",
            "Fecha de Nacimiento", "Edad", "Sexo", "CURP");

    for (i = 0; i < position; i++)
    {
        fprintf(fa, "%-6d %-10d %-15s %-15s %-10s %02d-%02d-%04d %11d %8s %10s\n", i + 1, students[i].matricula, 
                students[i].personalName.lastName1, 
                students[i].personalName.LastName2, students[i].personalName.name,
                students[i].date.day, students[i].date.month, students[i].date.year, students[i].age, students[i].sex, students[i].curp);
    }
    fclose(fa);
}

//************* USEFUL FUNCTIONS DEVELOPMENT ******
Tbirthday getBirthday()
{
    Tbirthday tempBirthday;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysBis[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    tempBirthday.year = valid("Ingresa tu anio de nacimiento: ", 1900, 2023);
    tempBirthday.month = valid("Ingresa tu mes de nacimiento: ", 1, 12);

    if (isLapYear(tempBirthday.year))
    {
        tempBirthday.day = valid("Ingresa tu dia de nacimiento: ", 1, daysBis[tempBirthday.month]);
    }
    else
    {
        tempBirthday.day = valid("Ingresa tu dia de nacimiento: ", 1, days[tempBirthday.month]);
    }

    return tempBirthday;
}

int existElem(Tstdnt students[], int longi, int num)
{
    int i;

    for (i = 0; i < longi; i++)
    {
        if (students[i].matricula == num)
        {
            return i;
        }
    }
    return -1;
}

int getAge(Tbirthday birth)
{
    int age;
    age = 2023 - birth.year;
    if (birth.month > 11)
    {
        age = age - 1;
    }
    return age;
}

void getCURP(Tstdnt stdntData, char CURP[])
{
    char firstFourLetters[5];
    char temp[2];
    int startPosition, startPosition2, startPosition3;
    startPosition = nameCompound(stdntData.personalName.lastName1);
    startPosition2 = nameCompound(stdntData.personalName.LastName2);
    startPosition3 = nameCompound(stdntData.personalName.name);

    if (stdntData.personalName.lastName1[0] != '\0')
    {
        CURP[0] = stdntData.personalName.lastName1[startPosition];
        CURP[1] = noVowelsApComp(stdntData.personalName.lastName1, startPosition);
        CURP[13] = getConsonant(stdntData.personalName.lastName1, startPosition);
    }
    else
    {
        CURP[0] = 'X';
        CURP[1] = 'X';
        CURP[13] = 'X';
    }

    if (stdntData.personalName.LastName2[0] != '\0')
    {
        CURP[2] = stdntData.personalName.LastName2[startPosition2];
        CURP[14] = getConsonant(stdntData.personalName.LastName2, startPosition2);
    }
    else
    {
        CURP[2] = 'X';
        CURP[14] = 'X';
    }

    CURP[3] = stdntData.personalName.name[startPosition3];
    CURP[15] = getConsonant(stdntData.personalName.name, startPosition3);

    firstFourLetters[0] = CURP[0];
    firstFourLetters[1] = CURP[1];
    firstFourLetters[2] = CURP[2];
    firstFourLetters[3] = CURP[3];
    firstFourLetters[4] = '\0';

    if (antiSonant(firstFourLetters))
    {
        CURP[1] = 'X';
    }

    convertNumber(stdntData, CURP);

    CURP[10] = stdntData.sex[0];

    for (int i = 0; i < 2; i++)
    {
        CURP[11 + i] = stdntData.placeBirth[i];
    }

    if (stdntData.date.year < 2000)
    {
        CURP[16] = '0';
    }
    else
    {
        if (stdntData.date.year <= 2009)
        {
            CURP[16] = 'A';
        }
        else
        {
            if (stdntData.date.year <= 2019)
            {
                CURP[16] = 'B';
            }
            else
            {
                CURP[16] = 'C';
            }
        }
    }
    sprintf(temp, "%d", numRandom(0, 9));
    CURP[17] = temp[0];
    CURP[18] = '\0';

    strcpy(stdntData.curp, CURP);
}

void convertNumber(Tstdnt studnt, char CURP[18])
{
    char date[6];
    studnt.date.year = studnt.date.year % 100;

    sprintf(date, "%02d%02d%02d", studnt.date.year, studnt.date.month, studnt.date.day);

    for (int i = 0; i < 6; i++)
    {
        CURP[4 + i] = date[i];
    }
}

Tstdnt addOneStdnt(Tstdnt studentArray[], int position)
{
    Tstdnt tempStudentArray;
    char curp[18];

    do
    {
        tempStudentArray.matricula = numRandom(300000, 399999);
    } while (existElem(studentArray, position, tempStudentArray.matricula) != -1);

    // Name
    LastName(tempStudentArray.personalName.lastName1);
    LastName(tempStudentArray.personalName.LastName2);

    if (numRandom(0, 1) == 1)
    {
        nameMen(tempStudentArray.personalName.name);
        strcpy(tempStudentArray.sex, "Hombre");
    }
    else
    {
        nameWomen(tempStudentArray.personalName.name);
        strcpy(tempStudentArray.sex, "Mujer");
    }

    // Get random birthday and age
    tempStudentArray.date = randomBirthday();
    tempStudentArray.age = getAge(tempStudentArray.date);

    getState(tempStudentArray.state, tempStudentArray.placeBirth);

    getCURP(tempStudentArray, curp);
    strcpy(tempStudentArray.curp, curp);

    return tempStudentArray;
}

Tbirthday randomBirthday()
{
    Tbirthday tempBirthday;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysBis[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    tempBirthday.year = numRandom(1900, 2023);
    tempBirthday.month = numRandom(1, 12);

    if (isLapYear(tempBirthday.year))
    {
        tempBirthday.day = numRandom(1, daysBis[tempBirthday.month]);
    }
    else
    {
        if (tempBirthday.year == 2023)
        {
            tempBirthday.month = numRandom(1, 10);
            tempBirthday.day = numRandom(1, days[tempBirthday.month]);
        }
        else
        {
            tempBirthday.day = numRandom(1, days[tempBirthday.month]);
        }
    }
    return tempBirthday;
}

void displayOneStdntList(Tstdnt students)
{
    printf("%-10d %-10s %-10s %-10s %02d-%02d-%04d   %-4c%-18s\n",
           students.matricula,
           students.personalName.lastName1,
           students.personalName.LastName2,
           students.personalName.name,
           students.date.day,
           students.date.month,
           students.date.year,
           students.sex[0],
           students.curp);
}

void displayOneStdnt(Tstdnt students)
{
    printf("----------------------------------\n");
    printf("MATRICULA:    %d\n", students.matricula);
    printf("NOMBRE:       %s\n", students.personalName.name);
    printf("AP. PAT:      %s\n", students.personalName.lastName1);
    printf("AP. MAT:      %s\n", students.personalName.LastName2);
    printf("FECHA DE NAC: %02d/%02d/%d\n", students.date.day, students.date.month, students.date.year);
    printf("EDAD:         %02d\n", students.age);
    printf("SEXO:         %s\n", students.sex);
    printf("LUGAR NAC:    %s\n", students.state);
    printf("CURP:         %s", students.curp);
    printf("\n----------------------------------\n");
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

//**** FUNCTIONS FOR QUICKSORT ***
void swap(Tstdnt students[], int i, int j)
{
    Tstdnt temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(Tstdnt students[], int low, int high)
{
    Tstdnt pivot;
    pivot.matricula = students[high].matricula;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].matricula <= pivot.matricula)
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

