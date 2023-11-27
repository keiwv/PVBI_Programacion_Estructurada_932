//*******LIBRARIES*************
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
//*******PROTOTYPE FUNCTIONS *********
int valid(char msge[], int ri, int rf);
int counter(char array[]);
void mayus(char array[]);
void reverse(char array[]);
void line(char array[]);
void descending(char array[]);
void reverseDescending(char array[]);
void noVowels(char array[]);
void vowels(char array[]);
void minus(char array[]);
void capital(char array[]);
void noSpace(char array[]);
int alfaSpace(char array[]);
void alfaSpaceValid(char array[]);
int palindrome(char array[]);
void printArr(char array[]);
void ask(char array[]);
void fillVectorNoRepeat(int vect[], int n, int ri, int rf);
void printArNum(char array[], int num);
void copyArray(char tempArray[], char tempListName[]);
int numRandom(int ri, int rf);

//******* FUNCTIONS DEVELOPMENT *******
int valid(char msge[], int ri, int rf)
{
    int op;
    char array[40];
    int result;

    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);

        result = sscanf(array, "%d", &op);

        if (result != 1 || op < ri || op > rf)
        {
            op = -1;
        }

    } while (op == -1);

    return op;
}

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

int alfaSpace(char cadena[])
{
    int i = 0;
    if (cadena[0] == ' ')
    {
        return -1; //Space at the start has been found
    }
    if (cadena[0] == '\0')
    {
        return -1; //No characters has been found
    }

    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            // Mayus allowed
        }
        else
        {
            if ((cadena[i] >= 'a' && cadena[i] <= 'z'))
            {
                return -1; //Minus not allowed
            }
            else
            {
                if (cadena[i] == ' ')
                {
                    if (cadena[i + 1] == ' ')
                    {
                        return -1; // Double Spaces not allowed
                    }
                }
                else
                {
                    return -1; // Character not allowed
                }
            }
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        return -1; // It ends with a spaces (not allowed)
    }

    return 1; //Return 1 if it 
} 

void alfaSpaceValid(char array[])
{
    int resVerified;
    do
    {
        resVerified = alfaSpace(array);

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

int palindrome(char array[])
{
    int count;
    count = counter(array); // We get how many columns it has.
    noSpace(array);
    minus(array); // We make the array lower case, we don't have to deal with different upper case.
    for (int i = 0; i < count / 2; i++)
    {
        if (array[i] != array[count - 1 - i])
        {
            return 0; // it is not a palindrome
        }
    }
    return 1; // it is a palindrome
}

void printArr(char array[])
{
    int i;
    i = 0;
    while (array[i] != '\0')
    {
        printf("%c", array[i]);
        i++;
    }
}

void ask(char array[])
{
    fflush(stdin);
    gets(array);
}

void printVector(int vector[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Vector [%d]: [%2d]\n", i, vector[i]);
    }
}

void fillVectorNoRepeat(int vect[], int n, int ri, int rf)
{
    int num, range;
    int i;
    num = 0;
    range = (rf - ri) + 1;
    for (i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % range) + ri;
        } while (-1);
        vect[i] = num;
    }
}

void fillMatrixNoRepeat(int m, int n, int matrix_1[][n], int ri, int rf)
{
    int vector[m * n];
    fillVectorNoRepeat(vector, m * n, ri, rf);

    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix_1[i][j] = vector[k++];
        }
    }
}

void printMatrix(int n, int m, int matrix[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("[%2d]\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void printArNum(char array[], int num)
{
    int i;
    i = 0;
    while (array[i] != '\0')
    {
        if ((array[i] == '%') && (array[i + 1] == 'd'))
        {
            printf("%d", num);
            i += 2;
        }
        else
        {
            printf("%c", array[i]);
            i++;
        }
    }
}

void copyArray(char tempArray[], char tempListName[])
{
    int i = 0;
    while (tempListName[i] != '\0')
    {
        tempArray[i] = tempListName[i];
        i++;
    }
    tempArray[i] = '\0';
}

int numRandom(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}
