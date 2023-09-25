/*
Brayan Ivan Perez Ventura - 372781

Created code: September 24th 2023 / Modified code: September 24th 2023

DESCRIPTION:


PVBI_Act7_1_932
*/

//**** LIBRARIES ****
#include <stdio.h>
#include <stdlib.h>

//**** PROTOTYPE FUNCTIONS ****
int msge_menu();
void menu();

int valid(char msge[], int ri, int rf);

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
    op = valid("Selecciona una opcion: ", 0, 10);
    return op;
}

void menu()
{
    int op;
    do
    {
        op = msge_menu();
        switch (op)
        {
            case 1:
            //sson
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