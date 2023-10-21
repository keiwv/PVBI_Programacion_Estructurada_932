/*

*/

//**** LIBRARIES ****
#include "Frijoles.h"
//*******************

//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void askNames(char name[]);
void askLastName1(char LastName1[]);
void askLastName2(char LastName2[]);
int askSex();
void askState(char state[]);
void printCURP(char firstFourLetters[], int day, int month, int year, int sex, char state[]);
// AUXILIAR FUNCTIONS
void displayStates(char state[]);
char getConsonant(char array[]);
int nameCompound(char array[]);
int Apcompound(char array[]);
char fourLetters(char name[], char LastName1[], char LastName2[], char firstFourLetters[5]);
char noVowelsApComp(char array[], int startPosition);
//**** MAIN FUNCTIONS ****
int main()
{
    menu();
    return 0;
}
//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu()
{
    int op;
    char name[50], LastName1[30], LastName2[30];
    int day, month, year;
    int sex;
    char state[4];
    char firstFourLetters[5];
    do
    {
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            askNames(name);
            break;
        case 2:
            askLastName1(LastName1);
            break;
        case 3:
            askLastName2(LastName2);
            break;
        case 4:
            day = valid("Ingresa el dia de tu nacimiento: ", 1, 31);
            month = valid("Ingresa el mes de tu nacimiento: ", 1, 12);
            year = valid("Ingresa el anio de tu nacimiento: ", 1894, 2023);
            year = year % 100;
            printf("Se han guardado correctamente la fecha de nacimiento.\n");
            break;
        case 5:
            sex = askSex();
            break;
        case 6:
            askState(state);
            break;
        case 7:
            fourLetters(name, LastName1, LastName2, firstFourLetters);
            printCURP(firstFourLetters, day, month, year, sex, state);
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

//***********
int msge_menu()
{
    int op;
    system("CLS");
    printArr("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printArr("1.- Ingresar Nombre\n");
    printArr("2.- Ingresar Apellido Paterno\n");
    printArr("3.- Ingresa Apellido Materno\n");
    printArr("4.- Ingresa el Dia de Nacimiento\n");
    printArr("5.- Seleccionar sexo\n");
    printArr("6.- Lugar de nacimiento\n");
    printArr("7.- Imprimir CURP\n");
    printArr("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 7);
    return op;
}

//**********
void askNames(char name[])
{
    do
    {
        printf("Introduce el nombre: ");
    } while (alfaSpace(name) != 1);
}

void askLastName1(char LastName1[])
{
    do
    {
        printArr("Por favor, ingresa el apellido paterno: ");
    } while (alfaSpace(LastName1) != 1);
}

void askLastName2(char LastName2[])
{
    do
    {
        printArr("Por favor, ingresa el apellido materno: ");
    } while (alfaSpace(LastName2) != 1);
}

int askSex()
{
    int sex;
    printf("0.- Mujer\t 1.- Hombre\n");
    sex = valid("Introduce el sexo del estudiante: ", 0, 1);
    return sex;
}

void askState(char state[])
{
    int isForeign;
    system("CLS");
    isForeign = valid("¿Eres extranjero? (1.- Si, 0.- No): ", 0, 1);

    if (isForeign)
    {
        strcpy(state, "NE"); // Asigna "NE" para extranjeros
    }
    else
    {
        system("CLS");
        displayStates(state);
    }
}

void printCURP(char firstFourLetters[], int day, int month, int year, int sex, char state[])
{
    int temp;
    /*char tempArray[4];
    temp = vowels(LastName1);

    tempArray[0] = compound(LastName1);
    tempArray[1] = LastName1[temp];
    tempArray[2] = compound(LastName2);
    tempArray[3] = compound(name);
    tempArray[4] = '\0'*/

    printf("%02d", year);
    printf("%02d", month);
    printf("%02d", day);
    if (sex == 0)
    {
        printf("M");
    }
    else
    {
        printf("H");
    }
}

//***************************

//**** AUXILIAR FUNCTIONS *****
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
            "Ciudad de Mexico",
            "Coahuila",
            "Colima",
            "Durango",
            "Estado de Mexico",
            "Guanajuato",
            "Guerrero",
            "Hidalgo",
            "Jalisco",
            "Michoacan",
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
            "Veracruz",
            "Yucatan",
            "Zacatecas"};
    char twoLetterState[32][3] =
        {
            "AG", // AGUASCALIENTES
            "BC", // BAJA CALIFORNIA
            "BS", // BAJA CALIFORNIA SUR
            "CC", // CAMPECHE
            "CL", // COAHUILA
            "CM", // COLIMA
            "CS", // CHIAPAS
            "CH", // CHIHUAHUA
            "DF", // DISTRITO FEDERAL
            "DG", // DURANGO
            "GT", // GUANAJUATO
            "GR", // GUERRERO
            "HG", // HIDALGO
            "JC", // JALISCO
            "MC", // MÉXICO
            "MN", // MICHOACÝN
            "MS", // MORELOS
            "NT", // NAYARIT
            "NL", // NUEVO LEÓN
            "OC", // OAXACA
            "PL", // PUEBLA
            "QT", // QUERÉTARO
            "QR", // QUINTANA ROO
            "SP", // SAN LUIS POTOSÝ
            "SL", // SINALOA
            "SR", // SONORA
            "TC", // TABASCO
            "TS", // TAMAULIPAS
            "TL", // TLAXCALA
            "VZ", // VERACRUZ
            "YN", // YUCATÝN
            "ZS", // ZACATECAS
        };

    printf("LISTA DE ESTADOS DE LOS ESTADOS UNIDOS MEXICANOS\n");
    for (i = 0; i < 32; i++)
    {
        printf("%d.- %s\n", i + 1, states[i]);
    }
    tempNum = valid("Introduce el estado en el que naciste: ", 1, 32);
    strcpy(state, twoLetterState[tempNum - 1]);
}

char getConsonant(char array[])
{
    int i;
    char tempword;
    int flag = 0;
    for (i = 0; array[i] != '\0'; i++)
    {
        tempword = array[i];

        if ((tempword != 'A') && (tempword != 'E') && (tempword != 'I') && (tempword != 'O') && (tempword != 'U'))
        {
            if (flag == 1)
            {
                return tempword;
            }
            flag = 1;
        }
    }

    return -1;
}

int nameCompound(char array[])
{
    char contra[9][6] = {"MA", "MA.", "M.", "M", "JOSE", "J.", "J", "MARIA"};
    char temp[20];
    int i = 0;
    int k = 0;
    int n = 0;
    int l = 0;
    while (array[i] != '\0')
    {
        int j = 0;
        while (array[k] != ' ' && array[k] != '\0')
        {
            temp[j] = array[k];
            j++;
            k++;
        }
        temp[j] = '\0';
        for (l = 0; l < 8; l++)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n += strlen(temp)+1;
            }
        }
        k++;
        i++;
    }
    if (n > 0)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int Apcompound(char array[])
{
    char contra[19][5] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
    char temp[20];
    int i = 0;
    int k = 0;
    int n = 0;
    int l = 0;
    while (array[i] != '\0')
    {
        int j = 0;
        while (array[k] != ' ' && array[k] != '\0')
        {
            temp[j] = array[k];
            j++;
            k++;
        }
        temp[j] = '\0';
        for (l = 0; l < 19; l++)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n += strlen(temp) + 1;
            }
        }
        k++;
        i++;
    }

    if (n > 0)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

char fourLetters(char name[], char LastName1[], char LastName2[], char firstFourLetters[5])
{
    int startPosition;
    startPosition = Apcompound(LastName1);
    firstFourLetters[0] = LastName1[startPosition];
    firstFourLetters[1] = noVowelsApComp(LastName1, startPosition);
    printf("%c\n", firstFourLetters[0]);
    printf("%c\n", firstFourLetters[1]);
    system("PAUSE");
}

char noVowelsApComp(char array[], int startPosition)
{
    int positionVowel;
    positionVowel = vowels(array, startPosition);
    return array[positionVowel];
}
