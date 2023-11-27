//*******LIBRARIES*************
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//*******PROTOTYPE FUNCTIONS *********
int valid(char msge[], int ri, int rf);
int counter(char array[]);
void mayus(char array[]);
int vowels(char array[], int position);
int alfaSpace(char array[]);
void ask(char displayMsge[], char array[]);
int numRandom(int ri, int rf);
int isLapYear(int year);
int spaceCounter(char array[]);
char noVowelsApComp(char array[], int startPosition);
char getConsonant(char array[], int startPosition);
int nameCompound(char array[]);
int antiSonant(char array[]);

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

int alfaSpace(char cadena[])
{
    int i = 0;
    if (cadena[0] == ' ')
    {
        return -1; // Space at the start has been found
    }
    if (cadena[0] == '\0')
    {
        return 1; // No characters has been found
    }

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == -20)
        {
            cadena[i] = 'Y';
        }
        if (cadena[i] == -104)
        {
            cadena[i] = 'Y';
        }
        if (cadena[i] == -105)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -93)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -106)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -107)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -109)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -28)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -108)
        {
            cadena[i] = 'O';
        }
        if (cadena[i] == -115)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -116)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -117)
        {
            cadena[i] = 'I';
        }
        if (cadena[i] == -118)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -120)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -119)
        {
            cadena[i] = 'E';
        }
        if (cadena[i] == -123)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -125)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -58)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -124)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -122)
        {
            cadena[i] = 'A';
        }
        if (cadena[i] == -21)
        {
            cadena[i] = 'U';
        }
        if (cadena[i] == -22)
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

void ask(char displayMsge[], char array[])
{
    printf("%s", displayMsge);
    fflush(stdin);
    gets(array);
}

int numRandom(int ri, int rf)
{
    int range = (rf - ri + 1);
    return rand() % range + ri;
}

int isLapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
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


