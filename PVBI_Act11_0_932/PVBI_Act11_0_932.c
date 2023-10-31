/*

*/

//***** LIBRARIES *****
#include "Frijoles.h"

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
    char sex;
    char placeBirth[3];
    char curp[18];
} Tstdnt;
//***** GLOBAL CONSTANT *****
const int N = 2000;
//***** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

void menuAdd(int position, Tstdnt students[]);
int msge_menuAdd();
Tstdnt addManual(Tstdnt students[], int position);


//****** USEFUL FUNCTIONS **********
Tbirthday getBirthday();
int existElem(Tstdnt students[], int longi, int num);
int getAge(Tbirthday birth);
void getCURP(Tstdnt stdntData, char CURP[]);
void convertNumber(Tstdnt studnt, char CURP[18]);
Tstdnt addOneStdnt();

//***** MAIN FUNCTION *****
int main()
{
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
            menuAdd(position, students);
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

void menuAdd(int position, Tstdnt students[])
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
            for(i = 0; i < 100; i++)
            {
                students[position + i] = addOneStdnt();
            }
            break;
        }
    } while (op != 3);
    printf("Regresando al menu principal\n");
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
        tempStdnt.sex = 'H';
        tempStdntCURP.sex = 'H';
    }
    else
    {
        tempStdnt.sex = 'M';
        tempStdntCURP.sex = 'H';
    }

    displayStates(tempStdnt.placeBirth);
    strcpy(tempStdntCURP.placeBirth, tempStdnt.placeBirth);

    getCURP(tempStdntCURP, curp);
    strcpy(tempStdnt.curp,curp);
    
    return tempStdnt;
}

//************* USEFUL FUNCTIONS DEVELOPMENT ******
Tbirthday getBirthday()
{
    Tbirthday tempStdnt;
    tempStdnt.year = valid("Ingresa el anio de tu nacimiento: ", 1894, 2023);
    if (tempStdnt.year == 2023)
    {
        tempStdnt.month = valid("Ingresa el mes de tu nacimiento: ", 1, 10);
        if (tempStdnt.month == 2)
        {
            tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 28);
        }
        else
        {
            if (tempStdnt.month == 1 || tempStdnt.month == 3 || tempStdnt.month == 5 || tempStdnt.month == 7 || tempStdnt.month == 8 || tempStdnt.month == 10 || tempStdnt.month == 12)
            {
                tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 31);
            }
            else
            {
                tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 30);
            }
        }
    }
    else
    {
        if (isLapYear(tempStdnt.year))
        {
            tempStdnt.month = valid("Ingresa el mes de tu nacimiento: ", 1, 12);
            if (tempStdnt.month == 2)
            {
                tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 29);
            }
            else
            {
                if (tempStdnt.month == 1 || tempStdnt.month == 3 || tempStdnt.month == 5 || tempStdnt.month == 7 || tempStdnt.month == 8 || tempStdnt.month == 10 || tempStdnt.month == 12)
                {
                    tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 31);
                }
                else
                {
                    tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 30);
                }
            }
        }
        else
        {
            tempStdnt.month = valid("Ingresa el mes de tu nacimiento: ", 1, 12);
            if (tempStdnt.month == 2)
            {
                tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 28);
            }
            else
            {
                if (tempStdnt.month == 1 || tempStdnt.month == 3 || tempStdnt.month == 5 || tempStdnt.month == 7 || tempStdnt.month == 8 || tempStdnt.month == 10 || tempStdnt.month == 12)
                {
                    tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 31);
                }
                else
                {
                    tempStdnt.day = valid("Ingresa el dia de tu nacimiento: ", 1, 30);
                }
            }
        }
    }
    return tempStdnt;
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
        printf("No ingresaste apellido paterno\n");
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
        printf("No ingresaste apellido materno\n");
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

    CURP[10] = stdntData.sex;

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

    strcpy(stdntData.curp,CURP);

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

Tstdnt addOneStdnt()
{

}


