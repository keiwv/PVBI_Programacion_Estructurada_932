/*
Brayan Ivan Perez Ventura - 372781

Created code: September 22th 2023 / Modified code: September 24th 2023

DESCRIPTION
The program starts in the main function, which displays a menu using the menu function.
The user can select an option from the menu, and their choice is validated using the msge_menu and valid functions.
Depending on the user's choice, various string manipulation functions are called on the input string stored in the array variable.
The manipulated string is then displayed to the user, this process continues until the user chooses to exit the program by selecting option 0.

Every case in switch function (line 56) does:
Option 1: Converts the input text to uppercase and displays it.
Option 2: Reverses the input text and displays it.
Option 3: Prints the input text in a line-by-line fashion.
Option 4: Reverses the input text and then prints it in a line-by-line fashion.
Option 5: Reverses the input text and generates a descending pattern.
Option 6: Reverses the input text, generates a descending pattern, and displays it.
Option 7: Reverses the input text and generates a descending pattern while removing characters from the left.
Option 8: Reverses the input text, generates a descending pattern while removing characters from the left, and displays it.
Option 9: Removes vowels from the input text and displays the result.
Option 10: Extracts and displays only the vowels from the input text.

PVBI_Act7_1_932
*/

//****** LIBRARIES *********
#include <stdio.h>
#include <stdlib.h>

// ***** FUNCTION PROTOTYPES *************
void menu();
int msge_menu();

int valid(char msge[], int ri, int rf);
void ask(char array[]);
int counter(char array[]);

void mayus(char array[]);
void reverse(char array[]);
void line(char array[]);
void descending(char array[]);
void reverseDescending(char array[]);
void noVowels(char array[]);
void vowels(char array[]);

//**** MAIN FUNCTION ***
int main()
{
    menu();
    return 0;
}

//**** DEVELOPMENT FUNCTIONS **********
//********* MENU FUNCTION *********
void menu()
{
    int op;
    char array[40];
    do
    {
        op = msge_menu();
        if (op != 0)
        {
            ask(array);
            mayus(array);
        }
        switch (op)
        {
        case 1:
            printf("Texto introducido en mayusculas: %s\n", array);
            system("PAUSE");
            break;
        case 2:
            reverse(array);
            printf("Texto introducido invertido: %s\n", array);
            system("PAUSE");
            break;
        case 3:
            printf("Texto introducido en linea: \n");
            line(array);
            system("PAUSE");
            break;
        case 4:
            printf("Texto introducido en invertido y en linea: \n");
            reverse(array);
            line(array);
            system("PAUSE");
            break;
        case 5:
            printf("Texto introducido en descendente: \n");
            descending(array);
            system("PAUSE");
            break;
        case 6:
            reverse(array);
            printf("Texto introducido en invertido descendente: \n");
            descending(array);
            system("PAUSE");
            break;
        case 7:
            printf("Texto introducido en descendente borrando desde izquierda: \n");
            reverseDescending(array);
            system("PAUSE");
            break;
        case 8:
            reverse(array);
            printf("Texto introducido en descendente invertido borrando desde izquierda: \n");
            reverseDescending(array);
            system("PAUSE");
            break;
        case 9:
            printf("Texto sin vocales: ");
            noVowels(array);
            system("PAUSE");
            break;
        case 10:
            printf("Texto sin consonantes: ");
            vowels(array);
            system("PAUSE");
        }
    } while (op != 0);
    printf("Saliendo del programa\n");
}
//****** MESSAGES TO THE MENU ************
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Salida 1\n");
    printf("2.- Salida 2\n");
    printf("3.- Salida 3\n");
    printf("4.- Salida 4\n");
    printf("5.- Salida 5\n");
    printf("6.- Salida 6\n");
    printf("7.- Salida 7\n");
    printf("8.- Salida 8\n");
    printf("9.- Salida 9\n");
    printf("10.- Salida 10\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 10);
    return op;
}
//****** VALID FUNCTION ********
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
//****** ASK FOR THE USER INPUT FUNCTION***********
void ask(char array[])
{
    printf("\nIntroduce una sentencia de no mayor 50 caracteres: ");
    fflush(stdin);
    gets(array);
}
//****** COUNTER FOR THE ARRAY FUNCTION **********
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
//*********** FUNCTIONS TO CONVERT AN ARRAY ***********
//****MAYUS CONVERT ******
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
//****REVERSE CONVERT ******
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

//****PRINT IN LINE FUNCTION ******
void line(char array[])
{
    int length, i;
    char letter;
    length = counter(array);

    for (i = 0; i <= length; i++)
    {
        letter = array[i];
        printf("%c\n", letter);
    }
}

//**** DESCENDING PATTERN ******
void descending(char array[])
{
    int length, i, j;
    length = counter(array);

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i; j++)
        {
            printf("%c", array[j]);
        }
        printf("\n");
    }
}

//**** REVERSE DESCENDING PATTERN ******
void reverseDescending(char array[])
{
    int length, i, j;
    length = counter(array);

    for (i = 0; i < length; i++)
    {
        for (j = i; j < length; j++)
        {
            printf("%c", array[j]);
        }
        printf("\n");
    }
}

//****NO VOWELS FUNCTION ******
void noVowels(char array[])
{
    int i;
    char tempword;
    for (i = 0; array[i] != '\0'; i++)
    {
        tempword = array[i];
        if ((tempword == 'A') || (tempword == 'E') || (tempword == 'I') || (tempword == 'O') || (tempword == 'U'))
        {
        }
        else
        {
            printf("%c", tempword);
        }
    }
    printf("\n");
}
//**** ONLY VOWELS FUNCTION ******
void vowels(char array[])
{
    int i;
    char tempword;
    for (i = 0; array[i] != '\0'; i++)
    {
        tempword = array[i];
        if ((tempword == 'A') || (tempword == 'E') || (tempword == 'I') || (tempword == 'O') || (tempword == 'U'))
        {
            printf("%c", tempword);
        }
    }
    printf("\n");
}
