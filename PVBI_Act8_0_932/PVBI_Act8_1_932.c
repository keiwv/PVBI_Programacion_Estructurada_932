/*
Brayan Ivan Perez Ventura - 372781

Created code: September 26th 2023 / Modified code: October 1st 2023

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

void vector1(int vector[], int n);
void vector2(int vector2[], int m);
void vector3(int vector3[], int vector2[], int m, int vector[], int n);
void printVectors(int vector[], int n, int vector_2[], int m, int vector_3[], int p);
void matrix(int matrix_1[][4], int vector_2[], int vector[], int n);
void printMatrix(int matrix_1[][4]);

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
    int vector[10], vector_2[10], vector_3[20], matrix_1[4][4];
    int op, n, m, p;
    n = 10;
    m = 10;
    p = 20;
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            vector1(vector, n);
            break;
        case 2:
            vector2(vector_2, m);
            break;
        case 3:
            vector3(vector_3, vector_2, m, vector, n);
            break;
        case 4:
            printVectors(vector, n, vector_2, m, vector_3, p);
            break;
        case 5:
            matrix(matrix_1, vector_2, vector, n);
            break;
        case 6:
            printMatrix(matrix_1);
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
//********** EXIST ELEMENT FUNCTION *******
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
void vector1(int vector[], int n)
{
    int i;
    printf("\nRellenar Vector 1 (Con valores de 30 al 70) \n");
    for (i = 0; i < n; i++)
    {
        printf("Ingresa el valor de la celda [%d]: ", i + 1);
        vector[i] = valid(" ", 30, 70);
    }
    printf("Datos ingresados y guardados correctamente\n");
    system("PAUSE");
}

//*********** VECTOR 2 ***************
void vector2(int vector_2[], int m)
{
    int i, num;
    srand(time(NULL));
    for (i = 0; i < m; i++)
    {
        while (existElem(vector_2, m, num = ((rand() % 20) + 1)));
        vector_2[i] = num;
    }
    printf("\nValores aleatorios generados correctamente en el vector.\n");
    system("PAUSE");
}
//************* VECTOR 3 ************

void vector3(int vector3[], int vector_2[], int m, int vector[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vector3[i] = vector[i];
        vector3[i + m] = vector_2[i];
    }
    printf("Datos guardados en el vector 3 correctamente\n");
    system("PAUSE");
}

//************ DISPLAY VECTORS ****************
void printVectors(int vector[], int n, int vector_2[], int m, int vector_3[], int p)
{
    int i;
    printf("VECTOR 1\n");
    for (i = 0; i < n; i++)
    {
        printf("Vector [%d]: [%2d]\n", i, vector[i]);
    }
    printf("VECTOR 2\n");
    for (i = 0; i < m; i++)
    {
        printf("Vector [%d]: [%2d]\n", i, vector_2[i]);
    }
    printf("VECTOR 3\n");
    for (i = 0; i < p; i++)
    {
        printf("Vector [%d]: [%2d]\n", i, vector_3[i]);
    }
    system("PAUSE");
}

//*********** MATRIX ************
void matrix(int matrix_1[][4], int vector_2[], int vector[], int n)
{
    int i, j, k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (k < n)
            {
                matrix_1[i][j] = vector[k];
            }
            else
            {
                matrix_1[i][j] = vector_2[k - n];
            }
            k++;
        }
    }
    printf("Matriz llenada correctamente\n");
    system("PAUSE");
}

//************** DISPLAY MATRIX ************
void printMatrix(int matrix_1[][4])
{
    printf("Matrix 4x4:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", matrix_1[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}

//********* END OF THE CODE *******