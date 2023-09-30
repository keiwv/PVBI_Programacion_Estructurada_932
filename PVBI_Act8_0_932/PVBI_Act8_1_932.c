/*
Brayan Ivan Perez Ventura - 372781

Created code: September 26th 2023 / Modified code: September 26th 2023

DESCRIPTION
In this program, it will display a menu where:
    1.- Fill Vector 1 (manually)
    2.- Fill Vector 2 (radomly)
    3.- Fill Vector 3 (with Vector 1 and Vector 2)
    4.- Display the vectors
    5.- Fill Matrix 4x4
    6.- Display matrix
    0.- Leave (End the program)

Note: The program will have to repeat as many times as the user wish for.
Note 2: Vector 1 out of 10 positions, numbers from 30 to 70
Note 3: Vector 2 out of 10 positions with random numbers from 1 to 20 (with no repeating)
Note 4: Vector 3 out of 20 positions with the data from Vector 1 and Vector 2
Note 5: Matrix 4x4, fill it with data from Vector 1 and Vector 2.

PVBI_Act8_1_932
*/

//**** LIBRARIES ******
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//**** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

int valid(char msge[], int ri, int rf);
int existElem(int vector[], int longi, int num);

void vector1(int vector[]);
void vector2(int vector2[]);

//**** MAIN FUNCTION ****
int main()
{
    menu();
    return 0;
}
//**** PROTOTYPE FUNCTIONS DEVELOPMENT **********
// *********** MENU ************
void menu()
{
    int vector[10], vector_2[10];
    int op;
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            vector1(vector);
            break;
        case 2:
            vector2(vector_2);
            break;
        }
    } while (op != 0);
}
// ********** MESSAGE MENU ************
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Llenar vector 1 (Manualmente)\n");
    printf("2.- Llenar vector 2 aleatoriamente\n");
    printf("3.- Llenar Vector 3 (Con Vector 1 y Vector 2)\n");
    printf("4.- Imprimir vectores\n");
    printf("5.- Llenar matriz 4x4\n");
    printf("6.- Imprimir matriz\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 6);
    return op;
}
// ********** VALID NUMBER FUNCTION **********
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
//************* EXIST *******
int existElem(int vector[], int longi, int num)
{
    int i;

    for (i = 0; i < longi; i++)
    {
        if (vector[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

//*********** VECTOR 1 **************
void vector1(int vector[])
{
    int i;
    printf("\nRellenar Vector 1 (Con valores de 30 al 70) \n");
    for (i = 0; i < 10; i++)
    {
        printf("Ingresa el valor de la celda [%d]: ", i + 1);
        vector[i] = valid(" ", 30, 70);
    }
    printf("Datos ingresados correctamente\n");
    system("PAUSE");
}

//*********** VECTOR 2 ***************
void vector2(int vector_2[])
{
    int i, num;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        while (existElem(vector_2, 10, num = ((rand() % 20) + 1)));
        vector_2[i] = num;
    }
    for (i = 0; i < 10; i++)
    {
        printf("Celda [%d] = %d\n", i+1, vector_2[i]);
    }
    printf("\nValores aleatorios guardados correctamente en el vector.\n");
    system("PAUSE");
}


