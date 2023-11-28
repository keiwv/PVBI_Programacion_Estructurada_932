/*
Brayan Ivan Perez Ventura - 372781
Created code: November 12th 2023 / Modified code: November 12th 2023

This code we count how many registers a txt has.
    it also skips headers.

RegisterCounter
*/

#include <stdio.h>
#include <string.h>

typedef int Tkey;
typedef struct _IndexStrct
{
    Tkey enrollment;
    int index;
} TIndexStrct;


int main(int args, char *arg[])
{
    FILE *fa;
    int position = 0;
    TIndexStrct reg;
    char fileName[30];
    strcpy(fileName, arg[1]);
    fa = fopen(fileName, "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TIndexStrct), 1, fa))
        {
            position++;
        }
        fclose(fa);
        return position;
    }
    else
    {
        return -1;
    }
    return 0;
}