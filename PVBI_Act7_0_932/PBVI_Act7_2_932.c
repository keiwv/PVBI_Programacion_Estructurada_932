/*
Brayan Ivan Perez Ventura - 372781

Created code: September 24th 2023 / Modified code: September 25th 2023

DESCRIPTION:
In this program, it will display a menu where it's gonna display the next outputs (with no description).
OUTPUT 1: This function converts all lowercase letters in the array to uppercase.
OUTPUT 2: This function converts all uppercase letters in the array to lowercase.
OUTPUT 3: This function capitalizes the first letter of each word in the input text stored in the array. It also capitalizes the first letter of the entire text.
OUTPUT 4: This function counts the number of characters in the input text and returns the count as an integer.
OUTPUT 5: This function reverses the characters in the input text, effectively reversing the text itself.
OUTPUT 6: This function removes all spaces from the input text stored in the array.
OUTPUT 7: This function checks various conditions in the input text and returns an integer code indicating if certain conditions are met. These conditions include checking for two consecutive spaces, symbols in the text, numbers in the text, and whether the text starts or ends with a space.
OUTPUT 8: This function calls five of the previous text manipulation functions in sequence on a copy of the input text. It prints the results of each operation, including converting to uppercase, converting to lowercase, capitalizing, removing spaces, and reversing the text. It also prints the original text.
OUTPUT 9: This function checks if the input text stored in the array is a palindrome and prints the result, indicating whether it is or it is not.

PVBI_Act7_2_932
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
int alfaSpace(char array[]);
void alfaSpaceValid(char array[]);
void previusFunctions(char array[]);
int palindrome(char array[]);

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
    op = valid("Selecciona una opcion: ", 0, 9);
    return op;
}

void menu()
{
    int op, countnum, polindrome;
    char array[100];
    do
    {
        op = msge_menu();
        if ((op != 0) && (op != 7) && (op != 9))
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
            printf("Texto sin espacios: %s\n", array);
            system("PAUSE");
            break;
        case 7:
            alfaSpaceValid(array);
            system("PAUSE");
            break;
        case 8:
            previusFunctions(array);
            system("PAUSE");
            break;
        case 9:
            alfaSpaceValid(array);
            polindrome = palindrome(array);
            if (polindrome)
            {
                printf("Es palindromo\n");
            }
            else
            {
                printf("No es palindromo\n");
            }
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
    fflush(stdin);
    gets(array);
}
//***************************
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
    int i, flag;
    char word;
    flag = 1;
    minus(array); // We convert the array in lower case, so it's easily to deal with.
    word = array[0];
    if (word >= 97) // First letter becomes upper case
    {
        if (word <= 122)
        {
            array[0] = array[0] - 32;
        }
    }
    for (i = 1; array[i] != '\0'; i++)
    {
        word = array[i];
        if ((word >= 65) && (flag))
        {
            if (word <= 90)
            {
                array[i] = array[i] + 32;
            }
        }
        flag = 1;
        if (word == 32)
        {
            if (array[i + 1] >= 97)
            {
                if (array[i + 1] <= 122)
                {
                    array[i + 1] = array[i + 1] - 32;
                    flag = 0;
                }
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

    length = counter(array); // We ask for the length of the array

    start = 0;
    end = length - 1;

    /*
        In this loop, it will be looping until the left size and the right size meets at the middle of the loop.
        It will be switching letters from the start and the end (array)
    */
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
    for (i = 0, j = 0; array[i] != '\0'; i++)
    {
        if (array[i] != 32) // It will join if it's different from the space number (ASCII number)
        {
            array[j++] = array[i]; // Saves the array in a new array.
        }
    }
}

//**** OUTPUT 7 ****
int alfaSpace(char array[])
{
    /*
        return 0: All conditions were met
        return 1: Two spaces
        return 2: There's symbols in the text.
        return 3: There's numbers in the text.
        return 4: It starts or ends with a space in the text.
    */
    int i, count;
    char letter;
    count = counter(array);
    if (array[0] == 32)
    {
        return 4;
    }
    if (array[count - 1] == 32)
    {
        return 4;
    }
    for (i = 0; array[i] != '\0'; i++)
    {
        letter = array[i];

        if (letter == 32) // Looking for double space
        {
            if (array[i + 1] == 32)
            {
                return 1;
            }
        }
        if (letter >= 33) // Looking for symbols
        {
            if (letter <= 47)
            {
                return 2;
            }
        }
        if (letter >= 48) // Looking for numbers
        {
            if (letter <= 57)
            {
                return 3;
            }
        }
        if (letter >= 58) // Looking for symbols
        {
            if (letter <= 64)
            {
                return 2;
            }
        }
        if (letter >= 91) // Looking for symbols
        {
            if (letter <= 96)
            {
                return 2;
            }
        }
        if (letter >= 123) // Looking for symbols
        {
            return 2;
        }
    }
    return 0;
}

void alfaSpaceValid(char array[])
{
    int resVerified;
    do
    {
        ask(array);                     // Ask for an array (text)
        resVerified = alfaSpace(array); // We get the number

        if (resVerified == 1)
        {
            printf("Existe dos espacios en el texto introducido\n");
        }
        if (resVerified == 2)
        {
            printf("Existen símbolos en el texto introducido\n");
        }
        if (resVerified == 3)
        {
            printf("Existen numeros en el texto introducido\n");
        }
        if (resVerified == 4)
        {
            printf("Existe un espacio al inicio o final del texto introducido\n");
        }
    } while (resVerified != 0);
}

//**** OUTPUT 8 ****
void previusFunctions(char array[])
{
    int i, j, count;
    count = counter(array);
    char tempArray[count];

    for (i = 0; i <= 5; i++)
    {
        for (j = 0; j < count; j++)
        {
            tempArray[j] = array[j]; // We save the array in a temp array so we can modify as many times we need.
        }
        if (i == 0)
        {
            mayus(tempArray);
            printf("Texto introducido en mayusculas: %s\n", tempArray);
        }
        if (i == 1)
        {
            minus(tempArray);
            printf("Texto introducido en minusculas: %s\n", tempArray);
        }
        if (i == 2)
        {
            capital(tempArray);
            printf("Texto introducido en Capital: %s\n", tempArray);
        }
        if (i == 3)
        {
            noSpace(tempArray);
            printf("Texto introducido sin espacios: %s\n", tempArray);
        }
        if (i == 4)
        {
            reverse(tempArray);
            printf("Texto introducido alreves: %s\n", tempArray);
        }
        if (i == 5)
        {
            printf("Texto original: %s\n", tempArray);
        }
    }
}

//**** OUTPUT 9 ****
int palindrome(char array[])
{
    int count;
    count = counter(array); // We get how many columns it has.
    noSpace(array);
    minus(array);           // We make the array lower case, we don't have to deal with different upper case.
    for (int i = 0; i < count / 2; i++)
    {
        if (array[i] != array[count - 1 - i])
        {
            return 0; // it is not a palindrome
        }
    }
    return 1; // it is a palindrome
}