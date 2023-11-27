//*******LIBRARIES*************
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
//*******PROTOTYPE FUNCTIONS *********
int valid(char msge[], int ri, int rf);
int existElem(int vector[], int longi, int num);
int counter(char array[]);
void mayus(char array[]);
void reverse(char array[]);
void line(char array[]);
void descending(char array[]);
void reverseDescending(char array[]);
void noVowels(char array[]);
int vowels(char array[], int position);
void minus(char array[]);
void capital(char array[]);
int spaceCounter(char array[]);
int alfaSpace(char array[]);
int palindrome(char array[]);
void printArr(char array[]);
void fillVectorNoRepeat(int vect[], int n, int ri, int rf);
void printArNum(char array[], int num);
void ask(char array[]);
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

int counter(char array[])
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

int vowels(char array[], int position)
{
    int i;
    for (i = position + 1; array[i] != '\0'; i++)
    {
        if (array[i] == 'A')
        {
            return i;
        }
        if (array[i] == 'E')
        {
            return i;
        }
        if (array[i] == 'I')
        {
            return i;
        }
        if (array[i] == 'O')
        {
            return i;
        }
        if (array[i] == 'U')
        {
            return i;
        }
        if (array[i] == 'X')
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

int spaceCounter(char array[])
{
    int i, j;
    for (i = 0, j = 0; array[i] != '\0'; i++)
    {
        if (array[i] == ' ')
        {
            j++;
        }
    }
    return j;
}

int alfaSpace(char cadena[])
{
    fflush(stdin);
    gets(cadena);
    int i = 0;
    if (cadena[0] == ' ')
    {
        return -1; // Space at the start has been found
    }
    if (cadena[0] == '\0')
    {
        return -1; // No characters has been found
    }

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] == -20)
        {
            cadena[i] = 'Y';
        }
        if(cadena[i] == -104)
        {
            cadena[i] = 'Y';
        }
        if(cadena[i] == -105)
        {
            cadena[i] = 'U';
        }
        if(cadena[i] == -93)
        {
            cadena[i] = 'U';
        }
        if(cadena[i] == -106)
        {
            cadena[i] = 'U';
        }
        if(cadena[i] == -107)
        {
            cadena[i] = 'O';
        }
        if(cadena[i] == -109)
        {
            cadena[i] = 'O';
        }
        if(cadena[i] == -28)
        {
            cadena[i] = 'O';
        }
        if(cadena[i] == -108)
        {
            cadena[i] = 'O';
        }
        if(cadena[i] == -115)
        {
            cadena[i] = 'I';
        }
        if(cadena[i] == -116)
        {
            cadena[i] = 'I';
        }
        if(cadena[i] == -117)
        {
            cadena[i] = 'I';
        }
        if(cadena[i] == -118)
        {
            cadena[i] = 'E';
        }
        if(cadena[i] == -120)
        {
            cadena[i] = 'E';
        }
        if(cadena[i] == -119)
        {
            cadena[i] = 'E';
        }
        if(cadena[i] == -123)
        {
            cadena[i] = 'A';
        }
        if(cadena[i] == -125)
        {
            cadena[i] = 'A';
        }
        if(cadena[i] == -58)
        {
            cadena[i] = 'A';
        }
        if(cadena[i] == -124)
        {
            cadena[i] = 'A';
        }
        if(cadena[i] == -122)
        {
            cadena[i] = 'A';
        }
        if(cadena[i] == -21)
        {
            cadena[i] = 'U';
        }
        if(cadena[i] == -22)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -29)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -30)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -27)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -103)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -34)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -41)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -44)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -46)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -73)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -74)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -113)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -57)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -91)
        {
            cadena[i] = 'X';
        }
        if (cadena[i] == -92)
        {
            cadena[i] = 'X';
        }
        if (cadena[i] == '/')
        {
            cadena[i] = 'X';
        }
        if (cadena[i] == '-')
        {
            cadena[i] = 'X';
        }
        if (cadena[i] == -102)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -127)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -23)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -75)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -96)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -114)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -126)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -112)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -45)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -42)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -95)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -40)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -32)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -94)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == 103)
        {
            cadena[i] = 'O';
        }
    }

    mayus(cadena);
    i = 0;
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
                return -1; // Minus not allowed
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
                    if (cadena[i] == '.')
                    {
                    }
                    else
                    {
                        if (cadena[i] >= 48)
                        {
                            if (cadena[i] <= 57)
                            {
                                return -1;
                            }
                        }
                        else
                        {
                            if (cadena[i] == 22)
                            {
                                cadena[i] = 'X';
                            }
                            else
                            {
                                cadena[i] = 'X';
                            }
                        }
                    }
                }
            }
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        return -1; // It ends with a spaces (not allowed)
    }
    return 1; // Return 1 if it
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

void ask(char array[])
{
    fflush(stdin);
    gets(array);
}

int numRandom(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}
