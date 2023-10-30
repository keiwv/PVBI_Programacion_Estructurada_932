/*

*/

//***** LIBRARIES *****
#include "Frijoles.h"
#include <string.h>

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
int existElem(Tstdnt students[], int longi, int num);
Tbirthday getBirthday();
int getAge(Tbirthday Birth);
void displayStates(char state[]);
void getCURP(Tstdnt stdntData, char CURP[]);
int nameCompound(char array[]);
char getConsonant(char array[], int startPosition);
char noVowelsApComp(char array[], int startPosition);
int antiSonant(char array[]);
void convertNumber(Tstdnt studnt, char CURP[19]);
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
    do
    {
        op = msge_menuAdd();
        switch (op)
        {
        case 1:
            position += 1;
            students[position] = addManual(students, position);
            break;
        case 2:
            printf("Automatico");
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
    } while (existElem(students, position - 1, tempStdnt.matricula) != -1);

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

//************* USEFUL FUNCTIONS ******

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

void displayStates(char state[])
{
    int i;
    int tempNum;
    char states[32][50] =
        {
            "Aguascalientes",
            "Baja California",
            "Baja California Sur",
            "Campeche",
            "Chiapas",
            "Chihuahua",
            "Coahuila de Zaragoza",
            "Colima",
            "Ciudad de Mexico",
            "Durango",
            "Guanajuato",
            "Guerrero",
            "Hidalgo",
            "Jalisco",
            "Mexico",
            "Michoacan de Ocampo",
            "Morelos",
            "Nayarit",
            "Nuevo Leon",
            "Oaxaca",
            "Puebla",
            "Queretaro",
            "Quintana Roo",
            "San Luis Potosi",
            "Sinaloa",
            "Sonora",
            "Tabasco",
            "Tamaulipas",
            "Tlaxcala",
            "Veracruz de Ignacio de la Llave",
            "Yucatan",
            "Zacatecas"};
    char twoLetterState[32][3] =
        {
            "AG", // Aguascalientes
            "BC", // Baja California
            "BS", // Baja California Sur
            "CC", // Campeche
            "CL", // Coahuila de Zaragoza
            "CM", // Colima
            "CS", // Chiapas
            "CH", // Chihuahua
            "DF", // Ciudad de México
            "DG", // Durango
            "GT", // Guanajuato
            "GR", // Guerrero
            "HG", // Hidalgo
            "JC", // Jalisco
            "MC", // México
            "MN", // Michoacán de Ocampo
            "MS", // Morelos
            "NT", // Nayarit
            "NL", // Nuevo León
            "OC", // Oaxaca
            "PL", // Puebla
            "QT", // Querétaro
            "QR", // Quintana Roo
            "SP", // San Luis Potosí
            "SL", // Sinaloa
            "SR", // Sonora
            "TC", // Tabasco
            "TS", // Tamaulipas
            "TL", // Tlaxcala
            "VZ", // Veracruz de Ignacio de la Llave
            "YN", // Yucatán
            "ZS"  // Zacatecas
        };

    printf("LISTA DE ESTADOS DE LOS ESTADOS UNIDOS MEXICANOS\n");
    for (i = 0; i < 32; i++)
    {
        printf("%d.- %s\n", i + 1, states[i]);
    }
    tempNum = valid("Introduce el estado en el que naciste: ", 1, 32);
    strcpy(state, twoLetterState[tempNum - 1]);
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

char noVowelsApComp(char array[], int startPosition)
{
    int positionVowel;
    positionVowel = vowels(array, startPosition);
    if (positionVowel == -1)
    {
        return 'X';
    }
    return array[positionVowel];
}

char getConsonant(char array[], int startPosition)
{
    int i;
    char tempword;
    for (i = startPosition + 1; array[i] != '\0'; i++)
    {
        tempword = array[i];
        if (tempword != 'A')
        {
            if (tempword != 'E')
            {
                if (tempword != 'I')
                {
                    if (tempword != 'O')
                    {
                        if (tempword != 'U')
                        {
                            return tempword;
                        }
                    }
                }
            }
        }
    }

    return 'X';
}

int nameCompound(char array[])
{
    char contra2[27][6] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y", "MA", "MA.", "M.", "M", "JOSE", "J.", "J", "MARIA"};
    char temp[20];
    int i = 0;
    int k = 0;
    int n = 0;
    int l = 0;
    int flag = 1;
    int found = 0;
    int j;
    int spaces = spaceCounter(array);
    while (i < spaces && (flag == 1))
    {
        j = 0;
        while (array[k] != ' ' && array[k] != '\0')
        {
            temp[j] = array[k];
            j++;
            k++;
        }
        temp[j] = '\0';
        flag = 0;
        found = 0;

        for (l = 0; l < 27; l++)
        {
            if (strcmp(temp, contra2[l]) == 0)
            {
                n += strlen(temp) + 1;
                flag = 1;
                found = 1;
            }
        }

        if (found == 0)
        {
            if (i != spaces)
            {
            }
            else
            {
                return n;
            }
            k++;
        }

        k++;
        i++;
    }

    return n;
}

int antiSonant(char array[])
{
    int i;
    char antisonant[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    for (i = 0; i < 81; i++)
    {
        if (strcmp(array, antisonant[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
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
