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
typedef struct _Wrkr
{
    int status;
    Tkey enrollment;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPstion[30];
    char state[30];
    int age;
    Tkey cellPhone;
} TWrkr;


int main(int args, char *arg[])
{
    FILE *fa;
    int position = 0;
    TWrkr reg;
    char fileName[30];
    strcpy(fileName, arg[1]);
    fa = fopen(fileName, "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa))
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