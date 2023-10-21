//*******LIBRARIES*************
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

//*******PROTOTYPE FUNCTIONS *********
int valid(char msge[], int ri, int rf);
int existElem(int vector[], int longi, int num);
int counter(wchar_t array[]);
void mayus(char array[]);
void reverse(char array[]);
void line(char array[]);
void descending(char array[]);
void reverseDescending(char array[]);
void noVowels(char array[]);
int vowels(wchar_t array[]);
void minus(char array[]);
void capital(char array[]);
void noSpace(char array[]);
int alfaSpace(wchar_t array[]);
void alfaSpaceValid(char array[]);
int palindrome(char array[]);
void printArr(char array[]);
void fillVectorNoRepeat(int vect[], int n, int ri, int rf);
void printArNum(char array[], int num);
void ask(wchar_t array[], int size);

//******* FUNCTIONS DEVELOPMENT *******
int valid(char msge[], int ri, int rf)
{
    int op;
    char array[40];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);
        op = atoi(array);
    } while (op < ri || op > rf);
    return op;
}

int existElem(int vector[], int longi, int num)
{
    int i;

    for (i = 0; i < longi; i++)
    {
        if (vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int counter(wchar_t array[])
{
    int length;
    length = 0;
    while (array[length] != L'\0')
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

int vowels(wchar_t array[])
{
    int i;
    for (i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == L'A')
        {
            return i;
        }
        if (array[i] == L'E')
        {
            return i;
        }
        if (array[i] == L'I')
        {
            return i;
        }
        if (array[i] == L'O')
        {
            return i;
        }
        if (array[i] == L'U')
        {
            return i;
        }
    }
    return -1;
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

int alfaSpace(wchar_t cadena[])
{
    int i;
    int exist = 0;
    for (i = 0; cadena[i] != L'\0'; i++)
    {
        if (i > 0)
        {
            exist = 1;
        }
    }
    if (exist == 0)
    {
        return -1;
    }
    if (cadena[0] == L' ')
    {
        return -1;
    }
    return 1; // La cadena está vacía o solo contiene espacios en blanco
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
        } while (existElem(vect, i, num) != -1);
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

void bubbleSort(int vector[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[i])
            {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
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

void ask(wchar_t array[], int size)
{
    fflush(stdin);
    fgetws(array, size, stdin);
}