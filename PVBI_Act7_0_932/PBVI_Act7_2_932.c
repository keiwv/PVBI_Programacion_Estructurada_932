/*
Brayan Ivan Perez Ventura - 372781

Created code: September 24th 2023 / Modified code: September 24th 2023

DESCRIPTION:


PVBI_Act7_1_932
*/

//**** LIBRARIES ****
#include <stdio.h>
#include <stdlib.h>

//**** PROTOTYPE FUNCTIONS ****
int msge_menu();
void menu();

int valid(char msge[], int ri, int rf);
void ask(char array[]);

void mayus(char array[]);
void minus(char array[]);
void capital(char array[]);
int counter(char array[]);
void reverse(char array[]);
void noSpace(char array[]);

//**** MAIN FUNCTION ****
int main()
{
    menu();
    return 0;
}
//**** DEVELOPMENT FUNCTIONS ****
//**** MENU FUNCTIONS ****

int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U PARTE 2\n");
    printf("1.- Salida 1\n");
    printf("2.- Salida 2\n");
    printf("3.- Salida 3\n");
    printf("4.- Salida 4\n");
    printf("5.- Salida 5\n");
    printf("6.- Salida 6\n");
    printf("7.- Salida 7\n");
    printf("8.- Salida 8\n");
    printf("9.- Salida 9\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 10);
    return op;
}

void menu()
{
    int op, countnum;
    char array[100];
    do
    {
        op = msge_menu();
        if (op != 0)
        {
            ask(array);
        }

        switch (op)
        {
        case 1:
            mayus(array);
            printf("Texto introducido en mayusculas: %s\n", array);
            system("PAUSE");
            break;
        case 2:
            minus(array);
            printf("Texto introducido en minusculas: %s\n", array);
            system("PAUSE");
            break;
        case 3:
            capital(array);
            printf("Texto introducido en Capital: %s\n", array);
            system("PAUSE");
            break;
        case 4:
            countnum = counter(array);
            printf("La cantidad de caracteres del texto introducido: %d\n", countnum);
            system("PAUSE");
            break;
        case 5:
            reverse(array);
            printf("Texto introduciddo pero invertido: %s\n", array);
            system("PAUSE");
            break;
        case 6:
            noSpace(array);
            system("PAUSE");
            break;
        }
    } while (op != 0);
}

int valid(char msge[], int ri, int rf)
{
    int num;
    char array[40];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);
        num = atoi(array);
    } while (num < ri || num > rf);

    return num;
}

void ask(char array[])
{
    printf("\nIntroduce una sentencia de no mayor 50 caracteres: ");
    fflush(stdin);
    gets(array);
}

//**** OUTPUT 1 ****
void mayus(char array[])
{
    int i;
    char word;
    for (i = 0; array[i] != '\0'; i++)
    {
        word = array[i];
        if (word >= 'a')
        {
            if (word <= 'z')
            {
                array[i] = array[i] - 32;
            }
        }
    }
}

//**** OUTPUT 2 ****
void minus(char array[])
{
    int i;
    char word;
    for (i = 0; array[i] != '\0'; i++)
    {
        word = array[i];
        if (word >= 'A')
        {
            if (word <= 'Z')
            {
                array[i] = array[i] + 32;
            }
        }
    }
}
//**** OUTPUT 3 ****
void capital(char array[])
{
    int i;
    char word;
    word = array[0];
    if (word >= 'a')
    {
        if (word <= 'z')
        {
            array[0] = array[0] - 32;
        }
    }
    for (i = 1; array[i] != '\0'; i++)
    {
        word = array[i];
        if (word >= 'A')
        {
            if (word <= 'Z')
            {
                array[i] = array[i] + 32;
            }
        }
    }
}

//**** OUTPUT 4 ****
int counter(char array[])
{
    int length;
    length = 0;
    while (array[length] != '\0')
    {
        length++;
    }
    return length;
}
//**** OUTPUT 5 ****
void reverse(char array[])
{
    int length, start, end;
    char temp;

    length = counter(array);

    start = 0;
    end = length - 1;

    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

// **** OUTPUT 6 ****
void noSpace(char array[])
{
    int i, j;
    char newArray[50];
    for (i = 0, j = 0; array[i] != '\0'; i++)
    {
        if (array[i] != 32) // Replace ' ' with 32 if you want to preserve spaces in the result
        {
            newArray[j] = array[i];
            j++;
        }
    }

    newArray[j] = '\0';

    printf("El texto \"%s\" sin espacios: %s\n", array, newArray);
}