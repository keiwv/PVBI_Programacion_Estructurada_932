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

//***** FUNCTION PROTOTYPE *********
void menu();
int msge_menu();

void exam_niv();
void table_multi();
void range_mdia();
void weight_user();
void asig_grade();
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

    scanf("%d", &op);

    return op;
}

//********************
void exam_niv()
{
    int i, cal1, cal2, cal3, cal4, cal5, promedio, derecho, noderecho;
    derecho = 0;
    noderecho = 0;
    printf("EXAMEN DE NIVELACION\n");

    for (i = 1; i <= 41; i++)
    {
        printf("Ingresa la calificacion de la primera unidad: ");
        scanf("%d", &cal1);
        printf("Ingresa la calificacion de la segunda unidad: ");
        scanf("%d", &cal2);
        printf("Ingresa la calificacion de la tercera unidad: ");
        scanf("%d", &cal3);
        printf("Ingresa la calificacion de la cuarta unidad: ");
        scanf("%d", &cal4);
        printf("Ingresa la calificacion de la quinta unidad: ");
        scanf("%d", &cal5);

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

    system("PAUSE");
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
        printf("\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);

    } while (op != 0);
}
//**********************
void range_mdia()
{
    int n, min, max, num, i, count, sum, op;
    float average;

    do
    {
        system("CLS");
        printf("CANTIDAD DE NUMEROS (MEDIA Y SUMA DE LOS NUMEROS)\n");
        printf("Ingrese la cantidad de numeros a leer: ");
        scanf("%d", &n);

        printf("Ingrese el valor mínimo del rango: ");
        scanf("%d", &min);

        printf("Ingrese el valor máximo del rango: ");
        scanf("%d", &max);

        for (i = 0, sum = 0, count = 0; i < n; i++)
        {
            printf("Numero %d: ", i + 1);
            scanf("%d", &num);

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
            printf("Suma de valores válidos: %d\n", sum);
            printf("Media de los numeros validos: %.2f\n", average);
        }
        else
        {
            printf("No se encontraron numeros validos en el rango");
        }
        printf("\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);

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
        printf("Ingrese el numero de turistas a bordo: ");
        scanf("%d", &numTourists);

        for (int i = 0; i < numTourists; i++)
        {
            printf("Ingrese el peso del turista %d: ", i + 1);
            scanf("%f", &touristWeight);
            totalWeight += touristWeight;
        }

        averageWeight = totalWeight / numTourists;

        if (numTourists <= 10)
        {
            printf("Se cumple la condicion 1: Maximo de 10 turistas.\n");
        }
        else
        {
            printf("No se cumple la condicion 1: Exceso de turistas a bordo.\n");
        }

        excessWeight = totalWeight * 0.15;
        weightWithExcess = totalWeight + excessWeight;

        if (weightWithExcess <= 700)
        {
            printf("Se cumple la condicion 2: Maximo de 700 kilos de pasajeros con un máximo de 15%% de sobrepeso.\n");
        }
        else
        {
            printf("No se cumple la condicion 2: Exceso de peso total con sobrepeso.\n");
        }

        printf("El peso promedio de los turistas es: %.2f kilos.\n", averageWeight);
        printf("\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);
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
            printf("Ingrese la calificacion del primer parcial: ");
            scanf("%d", &calp1);

            printf("Ingrese la calificacion del segundo parcial: ");
            scanf("%d", &calp2);

            printf("Ingrese la calificacion del tercer parcial: ");
            scanf("%d", &calp3);

            promedio = (calp1 + calp2 + calp3) / 3F;
            if (promedio >= 60)
            {
                if (intentos < 3)
                {
                    printf("Aprobado con un promedio de %d\n", promedio);
                    i = 4;
                }
                else
                {
                    printf("Has sido dado de baja por alcanzar el maximo de intentos.\n");
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
                    printf("Has sido dado de baja por alcanzar el maximo de intentos. \n");
                    i = 4;
                }
            }
        }
        printf("El peso promedio de los turistas es: %.2f kilos.\n", averageWeight);
        printf("\nDesea salir?\n");
        printf("0.- No\n");
        printf("1.- Si\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);
    } while (op != 1);

    system("PAUSE");
}