/*
Brayan Ivan Perez Ventura - 372781

Created code: October 3rd 2023 / Modified code: Octuber 4th 2023

DESCRIPTION
In this program, we will create a menu and functions where it will display and execute:
    1.- Fill Vector
    2.- Fill Matrix
    3.- Display Vector
    4.- Display Matriz
    5.- Order Vector
    6.- Search a value in Vector
    0.- Leave from the program.

Instructions for each option:
    1.- Fill the vector with 15 numbers, the numbers will be generated randomly in a range 100 to 200 (no repeated)
    2.- Fill the matrix 4x4 with random numbers (generated), the range will be 1 to 16 (no repeated)
    3.- Display the vector, where the function gets parameters (vector, size and name of the vector)
    4.- Display the matrix, where the function gets parameters (matrix, lines and columns and the matrix's name), in this function, it will not get the size.
    5.- Use the function to order the vector by the method "Burbuja mejorada"
    6.- Search for a number in the vector using the method "búsqueda secuencial"
    0.- Leave from the program.
PVBI_Act _ _932
*/
//**** LIBRARIES ******
#include "Frijoles.h"
#include <time.h>

//**** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

void findNumber(int Vector_1[], int n);

//**** MAIN FUNCTION ****
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
//**** PROTOTYPE FUNCTIONS DEVELOPMENT **********

void menu()
{
    int op, n, m;
    n = 15;
    m = 4;
    int Vector_1[15];
    int matrix[m][m];
    do
    {
        system("CLS");
        op = msge_menu();
        switch (op)
        {
        case 1:
            fillVectorNoRepeat(Vector_1, n, 100, 200);
            printArr("Vector llenado satisfactoriamente");
            break;
        case 2:
            fillMatrixNoRepeat(m, m, matrix, 1, 16);
            printArr("Matriz llenado correctamente");
            break;
        case 3:
            printVector(Vector_1, n);
            break;
        case 4:
            printMatrix(m, m, matrix);
            break;
        case 5:
            bubbleSort(Vector_1, n);
            printArr("Vector ordenado correctamente");
            break;
        case 6:
            findNumber(Vector_1, n);
            break;
        }
        if (op != 0)
        {
            printArr("\nPresiona ENTER para continuar... ");
            getchar();
        }
    } while (op != 0);
    printArr("Saliendo del programa\n");
}

int msge_menu()
{
    int op;
    printArr("M E N U\n");
    printArr("1.- LLENAR VECTOR\n");
    printArr("2.- LLENAR MATRIZ\n");
    printArr("3.- IMPRIMIR VECTOR\n");
    printArr("4.- IMPRIMIR MATRIZ\n");
    printArr("5.- ORDENAR VECTOR\n");
    printArr("6.- BUSCAR VALOR EN VECTOR\n");
    printArr("0.- SALIR\n");
    op = valid("Selecciona una opcion: ", 0, 6);
    return op;
}

void findNumber(int Vector_1[], int n)
{
    int valueSearch, elementExist;
    valueSearch = valid("Ingresa el valor que desees buscar en el vector (numeros entre 100 y el 200):  ", 100, 200);
    elementExist = existElem(Vector_1, n, valueSearch);
    if (elementExist != -1)
    {
        printArNum("El numero ha sido encontrado exitosamente, esta en la posicion: %d ", elementExist);
    }
    else
    {
        printArr("El numero introducido no esta en el vector");
    }
}
