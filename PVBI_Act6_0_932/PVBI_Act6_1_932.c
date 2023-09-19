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
#include <limits.h>

//***** FUNCTION PROTOTYPE *********
void menu();
int msge_menu();
void fibonacci_menu();
int msge_fibonacci();
void factorial_menu();
int msge_factorial();
void dgts_menu();
int msge_dgts();

int valid(char msge[], int ri, int rf);
int leave();

void fibonacci_for();
void fibonacci_while();
void fibonacci_dowhile();

void factorial_for();
void factorial_while();
void factorial_dowhile();

void dgts_for();
void dgts_while();
void dgts_dowhile();

//***** MAIN FUNCTION *************
int main()
{

    menu();

    return 0;
}
//***** FUNCTION DEVELOPMENT **********
//***** MENU DEVELOPMENT ********
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
            factorial_menu();
            break;
        case 3:
            dgts_menu();
            break;
        }
    } while (op != 0);
}
//********************
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- FIBONACCI\n");
    printf("2.- FACTORIAL\n");
    printf("3.- CANTIDAD DE DIGITOS\n");
    printf("0.- SALIR\n");
    op = valid("Selecciona una opcion: ", 0, 3);
    return op;
}
//********************
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
        case 2:
            fibonacci_while();
            break;
        case 3:
            fibonacci_dowhile();
        }
    } while (op != 0);
}
//********************
int msge_fibonacci()
{
    int op;
    system("CLS");
    printf("FIBONACCI\n");
    printf("1.- Fibonacci con for\n");
    printf("2.- Fibonacci con while\n");
    printf("3.- Fibonacci con do while\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 3);
    return op;
}
//********************
void factorial_menu()
{
    int op;
    do
    {
        op = msge_factorial();
        switch (op)
        {
        case 1:
            factorial_for();
            break;
        case 2:
            factorial_while();
            break;
        case 3:
            factorial_dowhile();
            break;
        }
    } while (op != 0);
}
//********************
int msge_factorial()
{
    int op;
    system("CLS");
    printf("FACTORIAL DE UN NUMERO\n");
    printf("1.- Factorial con for\n");
    printf("2.- Factorial con while\n");
    printf("3.- Factorial con do while\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 3);
    return op;
}
//********************
void dgts_menu()
{
    int op;
    do
    {
        op = msge_dgts();
        switch (op)
        {
        case 1:
            dgts_for();
            break;
        case 2:
            dgts_while();
            break;
        case 3:
            dgts_dowhile();
            break;
        }
    } while (op != 0);
}
//********************
int msge_dgts()
{
    int op;
    system("CLS");
    printf("DIGITOS EN UN NUMERO ENTERO\n");
    printf("1.- Digitos con for\n");
    printf("2.- Digitos con while\n");
    printf("3.- Digitos con do while\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 3);
    return op;
}
//********************
int valid(char msge[], int ri, int rf)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}
//********************
int leave()
{
    int op;
    printf("\n\nDesea salir?\n");
    printf("0.- No\n");
    printf("1.- Si\n");
    op = valid("Selecciona una opcion: ", 0, 1);
    return op;
}
//********************
//*** FIBBONACI DEVELOPMENT ********
//*********************************
void fibonacci_for()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nMETODO DE FIBONACCI POR FOR\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);

        for (i = 0, tempnum = 0, tempnum2 = 1; i <= num; i++)
        {
            printf("%d  ", tempnum);

            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
        }
        op = leave();

    } while (op != 1);
}
//********************
void fibonacci_while()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nMETODO DE FIBONACCI POR WHILE\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);
        i = 0;
        tempnum = 0;
        tempnum2 = 1;

        while (i <= num)
        {
            printf(" %d ", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
            i++;
        }
        op = leave();

    } while (op != 1);
}
//********************
void fibonacci_dowhile()
{
    int op, num, i, tempnum, tempnum2, result;
    do
    {
        printf("\nMETODO DE FIBONACCI POR WHILE\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);
        i = 0;
        tempnum = 0;
        tempnum2 = 1;
        do
        {
            printf("%d", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
            i++;
        } while (i <= num);
        op = leave();
    } while (op != 1);
}

//**** FACTORIAL DEVELOPMENT ********
//***********************************
void factorial_for()
{
    int op, num, i, result, tempnum;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);

        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            for (i = num, result = 1, tempnum = 1; i != 0; i--)
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
            }
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();

    } while (op != 1);
}
//********************
void factorial_while()
{
    int op, num, i, result, tempnum;
    i = 1;
    result = 1;
    tempnum = 1;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR WHILE\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);
        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            i = num;
            while (i != 0)
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
                i--;
            }
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();
    } while (op != 1);
}
//********************
void factorial_dowhile()
{
    int op, num, i, result, tempnum;
    i = 1;
    result = 1;
    tempnum = 1;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR DO WHILE\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);
        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            i = num;
            do
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
                i--;
            } while (i != 0);
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();
    } while (op != 1);
}

//*** DIGITS DEVELOPMENT ********
//*******************************
void dgts_for()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);

        for (i = 1, tempnum = 1, result = 1; tempnum <= num; i++)
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
        }
        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}
//********************
void dgts_while()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);
        i = 1;
        tempnum = 1;
        result = 0;
        while (tempnum <= num)
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
            i++;
        }

        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}
//********************
void dgts_dowhile()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);
        i = 1;
        tempnum = 1;
        result = 0;
        do
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
            i++;
        } while (tempnum <= num);

        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}
//********************
