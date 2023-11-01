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

//****** USEFUL FUNCTIONS **********
Tbirthday getBirthday();
int existElem(Tstdnt students[], int longi, int num);
int getAge(Tbirthday birth);
void getCURP(Tstdnt stdntData, char CURP[]);
void convertNumber(Tstdnt studnt, char CURP[18]);
Tstdnt addOneStdnt(Tstdnt studentArray[], int position);
Tbirthday randomBirthday();
void displayReg(Tstdnt students[], int position);
//******* DATA FUNCTIONS *********
void nameMen(char tempName[]);
void nameWomen(char tempName[]);
void LastName(char tempLastName[]);

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
            break;
        case 2:
            displayReg(students, position);
            break;
        }
    } while (op != 0);
    printf("Saliendo del programa");
}

int msge_menu()
{
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
        op = msge_menuAdd();
        switch (op)
        {
        case 1:
            students[position] = addManual(students, position);
            position += 1;
            break;
        case 2:
            for (i = 0; i < 100; i++)
            {
                students[position + i] = addOneStdnt(students, position);
            }
            position += 100;
            break;
        }
    } while (op != 3);
    printf("Regresando al menu principal\n");
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

    tempStdnt.matricula = 1;

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

//************* USEFUL FUNCTIONS DEVELOPMENT ******
Tbirthday getBirthday()
{
    Tbirthday tempBirthday;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysBis[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    tempBirthday.year = valid("Ingresa tu año de nacimiento: ", 1900, 2023);
    tempBirthday.month = valid("Ingresa tu mes de nacimiento: ", 1, 12);

    if (isLapYear(tempBirthday.year))
    {
        tempBirthday.day = valid("Por favor, introduce tu dia de nacimiento: ", 1, daysBis[tempBirthday.month]);
    }
    else
    {
        tempBirthday.day = valid("Por favor, introduce tu dia de nacimiento: ", 1, days[tempBirthday.month]);
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

    tempStudentArray.status = 1;
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
        tempBirthday.day = numRandom(1, days[tempBirthday.month]);
    }
    return tempBirthday;
}

void displayReg(Tstdnt students[], int position)
{
    int i, j;
    printf("----------------------------------\n");
    for (j = 0; j < position; j += 40)
    {
        for (i = j; i < j + 40; i++)
        {
            if (students[i].status == 1)
            {
                printf("Nombre: %s\n", students[i].personalName.name);
                printf("Apellido paterno: %s\n", students[i].personalName.lastName1);
                printf("Apellido materno: %s\n", students[i].personalName.LastName2);
                printf("Edad: %d\n", students[i].age);
                printf("Fecha de nacimiento: %d/%d/%d\n", students[i].date.day, students[i].date.month, students[i].date.year);
                printf("Estado: %s\n", students[i].state);
                printf("Sexo: %s\n", students[i].sex);
                printf("Curp: %s\n", students[i].curp);
                printf("posicion: %d\n", i);
                printf("----------------------------------\n");
            }
        }
        system("PAUSE");
    }
}