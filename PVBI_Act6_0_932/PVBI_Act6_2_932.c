/*
Brayan Ivan Perez Ventura - 372781

Código creado: 17 de Septiembre del 2023 / Código modificado: 17 de Septiembre del 2023

Act 6 Part 2:
This algorithm will display a menu, where the user will be able to pick an option.
Each option will have a different program.
    1.- In this function, the program will ask for 40 students grades, every student will have 5 grades as input. If the average is lower than 50, they will not have right to do examen.
    2.- In this function, the program will print multiplication tables from 1 to 10, it will have a pause every table and it will clean the screen.
    3.- In this function, the program will calculate the addtion of the numers and the arithmetic average in a range of n numers given by the user.
    4.- In this function, the program will ask for the weight of each passenger with a maxinum of %15 overweight, it will display the average of weight and which of the 2 conditions was met
    5.- In this function, the program based on their 3 midterm exams, calculate the average and based on your final average, a message should be sent to the student to repeat the subject, pass or temporarily withdraw.

PVBI_Act6_2_932
*/
//**** LIBRARIES ******
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//***** FUNCTION PROTOTYPE *********
void menu();
int msge_menu();

void exam_niv();
void table_multi();
void range_mdia();
void weight_user();
void asig_grade();

int valid(char msge[], int ri, int rf);
int leave();

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
            exam_niv();
            break;
        case 2:
            table_multi();
            break;
        case 3:
            range_mdia();
            break;
        case 4:
            weight_user();
            break;
        case 5:
            asig_grade();
            break;
        }
    } while (op != 0);
}
//**********************
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Derecho a examen de nivelacion\n");
    printf("2.- Tablas de multiplicar\n");
    printf("3.- Cantidad de numeros (media aritmetica y suma)\n");
    printf("4.- Turistas y el peso\n");
    printf("5.- Examenes parciales\n");
    printf("0.- Salir\n");
    printf("Selecciona una opcion: ");

    op = valid("Selecciona una opcion: ", 0, 5);

    return op;
}

//********************
void exam_niv()
{
    int i, cal1, cal2, cal3, cal4, cal5, promedio, derecho, noderecho, op;
    derecho = 0;
    noderecho = 0;
    do
    {
        printf("EXAMEN DE NIVELACION\n");
        for (i = 0; i <= 40; i++)
        {
            cal1 = valid("Ingresa la calificacion de la primera unidad: ", 0, 100);
            cal2 = valid("Ingresa la calificacion de la primera unidad: ", 0, 100);
            cal3 = valid("Ingresa la calificacion de la primera unidad: ", 0, 100);
            cal4 = valid("Ingresa la calificacion de la primera unidad: ", 0, 100);
            cal5 = valid("Ingresa la calificacion de la primera unidad: ", 0, 100);

            promedio = (cal1 + cal2 + cal3 + cal4 + cal5) / 5;

            if (promedio >= 50)
            {
                printf("El alumno %d tiene derecho a examen\n", i);
                derecho++;
            }
            else
            {
                printf("El alumno %d no tiene derecho a examen\n", i);
                noderecho++;
            }
        }
        printf("Los alumnos con derecho a examen son: %d\n", derecho);
        printf("Los alumnos sin derecho son: %d", noderecho);
        op = leave();
    } while (op != 1);
}
//********************
void table_multi()
{
    int j, i, result, op;
    result = 0;
    do
    {
        for (i = 1; i <= 10; i++)
        {
            system("CLS");
            printf("TABLAS DE MULTIPLICAR DEL %d\n", i);
            for (j = 0; j <= 10; j++)
            {
                result = i * j;
                printf("\n%d * %d = %d", i, j, result);
            }
            printf("\n");
            system("PAUSE");
        }
        op = leave();

    } while (op != 1);
}
//**********************
void range_mdia()
{
    int n, min, max, num, i, count, sum, op;
    float average;

    do
    {
        printf("CANTIDAD DE NUMEROS (MEDIA Y SUMA DE LOS NUMEROS)\n");
        n = valid("Ingrese la cantidad de numeros a leer: ", 0, INT_MAX);
        min = valid("Ingrese el valor minimo del rango: ", 0, INT_MAX);
        max = valid("Ingrese el valor maximo del rango: ", 0, INT_MAX);

        for (i = 0, sum = 0, count = 0; i < n; i++)
        {
            printf("Numero %d: ", i + 1);
            num = valid("",min,max);

            if (num >= min)
            {
                if (num <= max)
                {
                    sum += num;
                    count++;
                }
            }
        }
        if (count > 0)
        {
            average = sum / count;
            printf("Suma de valores validos: %d\n", sum);
            printf("Media de los numeros validos: %.2f\n", average);
        }
        else
        {
            printf("No se encontraron numeros validos en el rango");
        }
        op = leave();

    } while (op != 1);
}
//**********************
void weight_user()
{
    int numTourists, op;
    float touristWeight, totalWeight, averageWeight, excessWeight, weightWithExcess;
    do
    {

        totalWeight = 0;
        weightWithExcess = 0;

        numTourists = valid("Ingrese el numero de turistas a bordo: ", 0, INT_MAX);
        for (int i = 0; i < numTourists; i++)
        {
            printf("Ingrese el peso del turista %d: ", i + 1);
            touristWeight = valid("", 0, INT_MAX);
            totalWeight += touristWeight;
        }

        averageWeight = totalWeight / numTourists;

        if (numTourists <= 10)
        {
            printf("Maximo de 10 turistas.\n");
        }
        else
        {
            printf("Exceso de turistas a bordo.\n");
        }

        excessWeight = totalWeight * 0.15;
        weightWithExcess = totalWeight + excessWeight;

        if (weightWithExcess <= 700)
        {
            printf("Maximo de 700 kilos de pasajeros con un máximo de 15%% de sobrepeso.\n");
        }
        else
        {
            printf("Exceso de peso total con sobrepeso.\n");
        }

        printf("El peso promedio de los turistas es: %.2f kilos.", averageWeight);
        op = leave();
    } while (op != 1);
}

void asig_grade()
{
    int calp1, calp2, calp3, promedio, i, intentos, op;
    intentos = 0;
    do
    {
        for (i = 0; i <= 3; i++)
        {
            calp1 = valid("Ingrese la calificacion del primer parcial: ", 0, 100);
            calp2 = valid("Ingrese la calificacion del segundo parcial: ", 0, 100);
            calp3 = valid("Ingrese la calificacion del tercer parcial: ", 0, 100);

            promedio = (calp1 + calp2 + calp3) / 3;
            if (promedio >= 60)
            {
                if (intentos < 3)
                {
                    printf("Aprobado con un promedio de %d", promedio);
                    i = 4;
                }
                else
                {
                    printf("Has sido dado de baja por alcanzar el maximo de intentos.");
                    i = 4;
                }
            }
            else
            {
                if (intentos < 3)
                {
                    printf("Debes repetir la materia, con un promedio de %d\n", promedio);
                    intentos++;
                }
                else
                {
                    printf("Has sido dado de baja por alcanzar el maximo de intentos.\n");
                    i = 4;
                }
            }
        }
        op = leave();
    } while (op != 1);

}

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