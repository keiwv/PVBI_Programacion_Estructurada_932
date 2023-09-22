/*
Brayan Ivan Perez Ventura - 372781

Created code:  / Modified code:

DESCRIPTION


PVBI_Act _ _932
*/
//****** LIBRARIES *********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ***** FUNCTION PROTOTYPES *************
void menu();
int msge_menu();

int valid(char msge[], int ri, int rf);
int leave();
void ask(char array[]);

void mayus(char array[]);
void reverse(char array[]);

//**** MAIN FUNCTION ***
int main()
{
    menu();
    return 0;
}

//**** DEVELOPMENT FUNCTIONS **********
//*********** MENU FUNCTION *********
void menu()
{
    int op;
    char array[100];
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            ask(array);
            mayus(array);
            printf("Texto introducido en mayusculas: %s\n", array);
            system("PAUSE");
            break;
        case 2:
            ask(array);
            mayus(array);
            reverse(array);
            printf("Texto introducido invertido: %s\n", array);
            system("PAUSE");
            break;
        }
    } while (op != 0);
}
//******* MESSAGES TO THE MENU ************
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Salida 1\n");
    printf("2.- Salida 2\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 9);
    return op;
}
//********** VALID FUNCTION ********
int valid(char msge[], int ri, int rf)
{
    int num;
    char array[100];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);
        num = atoi(array);
    } while (num < ri || num > rf);

    return num;
}
//***** LEAVE FUNCTION ********
int leave()
{
    int op;
    printf("\nDesea salir?\n");
    printf("0.- No\n");
    printf("1.- Si\n");
    op = valid("Selecciona una opcion: ", 0, 1);
    return op;
}
//************************
void ask(char array[])
{
    printf("\nIntroduce una sentencia de no mayor 50 caracteres: ");
    fflush(stdin);
    gets(array);
}

//*********** EXERCISES (1 - 9) ***********
//****EXERCISE 1******
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
//****EXERCISE 2******
void reverse(char array[])
{
    int length, start, end;
    char temp;

    while (array[length] != '\0')
    {
        length++;
    }

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

//****EXERCISE 3******
//****EXERCISE 4******
//****EXERCISE 5******
//****EXERCISE 6******
//****EXERCISE 7******
//****EXERCISE 8******
//****EXERCISE 9******

