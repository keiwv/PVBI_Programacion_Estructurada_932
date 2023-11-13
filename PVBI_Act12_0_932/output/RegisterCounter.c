/*
Brayan Ivan Perez Ventura - 372781
Created code: November 12th 2023 / Modified code: November 12th 2023

This code we count how many registers a txt has.
    it also skips headers.

RegisterCounter
*/

#include <stdio.h>
#include <string.h>

int main(int args, char *arg[])
{
    FILE *fa;
    int position = 0;
    char fileName[50];
    int tempNum;
    int tempNum2;
    char firstName[20], lastName1[20], lastName2[20];
    int age;
    char gender[10];

    strcpy(fileName, arg[1]);
    strcat(fileName, ".txt");

    fa = fopen(fileName, "r");
    if (fa)
    {
        if ((strcmp(fileName, "activos.txt") != 0) && (strcmp(fileName, "eliminados.txt") != 0))
        {
            fscanf(fa, "%*[^\n]");
            fgetc(fa);
        }
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s",
                   &tempNum, &tempNum2, firstName, lastName1, lastName2, &age, gender);
            position++;
        } while (!feof(fa));
        fclose(fa);
        return position - 1;
    }
    else
    {
        return -1;
    }
    return 0;
}