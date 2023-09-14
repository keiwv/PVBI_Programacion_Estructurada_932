/*
Brayan Ivan Perez Ventura - 372781

Código creado: 12 de Septiembre del 2023 / Código modificado: 12 de Septiembre del 2023

Act 6 Part 1:
This algorithm will display a menu, where the user will be able to pick an option.
Each option will have a different program.
1.- FIBONACCI <-- In this program, the program will ask for the amount of digits will be displayed for the Fibonacci method.
2.- FACTORIAL <-- In this program, the program will ask the user for a number and it will display the factorial of a number.
3.- CANTIDAD DE DIGITOS <-- In this program, the program will ask the user for a number and it will display how many digits it has.

PVBI_Act6_1_932
*/
//**** LIBRARIES ******
#include <stdio.h>
#include <stdlib.h>

//***** FUNCTION PROTOTYPE *********
void menu();
int msge_menu();
void fibonacci_menu();
int msge_fibonacci();

void fibonacci_for();
void fibonacci_while();
void factorial();

//***** MAIN FUNCTION *************
int main()
{

    menu();

    return 0;
}
//***** FUNCTION DEVELOPMENT **********
void menu()
{
    int op;
    do
    {
        op = msge_menu();

        switch (op)
        {
        case 1:
            fibonacci_menu();
            break;
        case 2:
            factorial();
            break;
        case 3:
            break;
        }
    } while (op != 0);
}

int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- FIBONACCI\n");
    printf("2.- FACTORIAL\n");
    printf("3.- CANTIDAD DE DIGITOS\n");
    printf("0.- SALIR\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &op);
    return op;
}

void fibonacci_menu()
{
    int op;
    do
    {
        op = msge_fibonacci();
        switch (op)
        {
            case 1:
                fibonacci_for();
                break;
        }
    } while (op != 0);
}

int msge_fibonacci()
{
    int op;
    system("CLS");
    printf("FIBONACCI\n");
    printf("1.- Fibonacci con for\n");
    printf("2.- Fibonacci con while\n");
    printf("3.- Fibonacci con do while\n");
    printf("0.- Salir\n");
    printf("Selecciona una opción: ");
    scanf("%d", &op);
    return op;
}

void fibonacci_for()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nMETODO DE FIBONACCI POR FOR\n");
        printf("Introduce la cantidad de numeros Fibonacci que desees imprimir: ");
        scanf("%d", &num);

        for (i = 0, tempnum = 0, tempnum2 = 1; i <= num; i++)
        {
            printf("%d  ", tempnum);

            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
        }
        printf("\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);

    } while (op != 1);
}

void fibonacci_while()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("METODO DE FIBONACCI POR WHILE\n");
        printf("Introduce la cantidad de números Fibonacci que desees imprimir: ");
        scanf("%d", &num);
        i = 0;
        tempnum = 0;
        tempnum2 = 1;

        while (i <= num)
        {
            printf("%d ", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
        }
        printf("\n Desea salir? \n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);

    } while (op != 1);
}

void factorial()
{
    int op, num, i, result, tempnum;
    do
    {
        printf("\nOBTENER UN FACTORIAL\n");
        printf("Por favor, ingresa un numero al que desee conocer su factorial: ");
        scanf("%d", &num);

        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            for (i = 1, result = 1; i <= num; i++)
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
            }
        }
        printf("\n\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);

    } while (op != 1);
}
