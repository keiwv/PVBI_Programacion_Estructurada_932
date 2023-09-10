/*
Brayan Ivan Perez Ventura - 372781

Código creado: 05 de Septiembre del 2023 / Código modificado: 08 de Septiembre del 2023

Despliega un menú en el cual este no se cerrará hasta que el usuario desee, así mismo, el menú estará hecho
en varias actividades propuestas por el profesor.

PVBI_Act4_1_932
*/

//*** LIBRERIAS *****
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*** PROTOTIPOS DE FUNCIONES PRINCIPALES******
int msges();
void menu();
int msges_act3();
void menu_act3();
int msges_act5();
void menu_act5();
//******** PROTOTIPO DE FUNCIONES ACTIVIDAD 3***************
void prom_cali();
void chinchampu_cond();
void chinchampu_selec();
void mayor_and();
void medio_and();
void menor_and();
void horoscopo();
//******** PROTOTIPO DE FUNCIONES ACTIVIDAD 5***************
void descen_nums();
void par_imparRandom();
void MayorMenor_Num();
void tabla_multi();

//****  FUNCION PRINCIPAL  *********
int main()
{
    menu();

    return 0;
}

//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- ACTIVIDAD 3 \n");
    printf("2.- ACTIVIDAD 5 \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            menu_act3();
            break;
        case 2:
            menu_act5();
            break;
        default:
            break;
        }
    } while (op != 0);
}
//*********************
int msges_act3()
{
    int op;
    printf("   M  E   N   U \n");
    printf("1.- Programa que lee 3 calificaciones y despliega el promedio del alumno \n");
    printf("2.- Programa que sirve para el juego del CHINCHAMPU (condicion anidada) \n");
    printf("3.- Programa que sirve para el juego del CHINCHAMPU (Seleccion multiple) \n");
    printf("4.- Programa que lee 3 numeros y despliega cual numero es el mayor (usando AND u OR) \n");
    printf("5.- Programa que lea 3 numeros y despliega el numero del medio (usando AND u OR) \n");
    printf("6.- Programa que lea 3 numeros y despliega en forma ascendente (usando AND u OR) \n");
    printf("7.- Programa que pide el mes y el día de nacimiento, imprime el signo zodiaco y su horoscopo del dia\n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//***********************
void menu_act3()
{
    int op;
    do
    {
        printf("\n");
        op = msges_act3();
        printf("\n");
        switch (op)
        {
        case 1:
            prom_cali();
            break;
        case 2:
            chinchampu_cond();
            break;
        case 3:
            chinchampu_selec();
            break;
        case 4:
            mayor_and();
            break;
        case 5:
            medio_and();
            break;
        case 6:
            menor_and();
            break;
        case 7:
            horoscopo();
            break;
        default:
            printf("Valor introducido incorrecto.");
            break;
        }
    } while (op != 0);
}
//********************
int msges_act5()
{
    int op;

    printf("   M  E   N   U \n");
    printf("1.- Funcion que que pide al usuario el valor de n, despliega enteros positivos en orden descendete \n");
    printf("2.- Funcion que genera 40 numeros aleatorios entre el 0 y 200 (si es par o impar)...\n");
    printf("3.- Funcion que genera 35 numeros (100-200) y despliega el numero mayor y menor \n");
    printf("4.- Funcion que despliega la tabla de multiplicar de un numero dado (entre 1 y 20) \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//***********************
void menu_act5()
{
    int op;
    do
    {
        printf("\n");
        op = msges_act5();
        printf("\n");
        switch (op)
        {
        case 1:
            descen_nums();
            break;
        case 2:
            par_imparRandom();
            break;
        case 3:
            MayorMenor_Num();
            break;
        case 4:
            tabla_multi();
            break;
        }
    } while (op != 0);
}

//****** FUNCIONES ACTIVIDAD 3 ************
//*****************
/*
    En esta funcion el usuario debe introducir 3 calificaciones, sacará el promedio
    y finalmente te desplegará un mensaje Si:
    Repetir
    Extraordinario
    Regular
    Bien
    Muy Bien
    Excelente
    y si es mayor a 100, dará un error.
*/
void prom_cali()
{
    system("CLS");
    int calif_1, calif_2, calif_3, promedio;

    printf("Programa que lee 3 calificaciones y despliega el promedio del alumno\n");
    printf("Ingrese la calificacion de la primera materia: ");
    scanf("%d", &calif_1);
    printf("Ingrese la calificacion de la primera materia: ");
    scanf("%d", &calif_2);
    printf("Ingrese la calificacion de la primera materia: ");
    scanf("%d", &calif_3);
    printf("\n");

    promedio = (calif_1 + calif_2 + calif_3) / 3;

    if (80 <= promedio)
    {
        if (90 <= promedio)
        {
            if (98 <= promedio)
            {
                if (promedio < 100)
                {
                    printf("Ingresa calificaciones validas");
                }
                else
                {
                    printf("Tu calificacion es: excelente");
                }
            }
            else
            {
                printf("Tu calificacion es: muy bien");
            }
        }
        else
        {
            printf("Tu calificacion es: bien");
        }
    }
    else
    {
        if (70 <= promedio)
        {
            printf("Tu calificacion es regular");
        }
        else
        {
            if (60 <= promedio)
            {
                printf("Tu calificacion es suficiente");
            }
            else
            {
                if (30 <= promedio)
                {
                    printf("Tu calificacion es para ir a extraordinario");
                }
                else
                {
                    printf("Repetir");
                }
            }
        }
    }
    printf("\n");
}
//**********************
/*
Juego CHUNCHAMPU (Piedra papel o tijera) para 1 jugador contra la computadora
Hecho por condición anidada
*/
void chinchampu_cond()
{
    system("CLS");
    int jugador, computadora;

    printf("Juguemos a Piedra, Papel, Tijera!\n");
    printf("Elige una opcion:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    printf("Tu eleccion: ");
    scanf("%d", &jugador);

    srand(time(NULL));

    computadora = rand() % 3 + 1;

    if (jugador == 1)
    {
        if (computadora == 1)
        {
            printf("Empate, ambos eligieron piedra (1).\n");
        }
        else
        {
            if (computadora == 2)
            {
                printf("La computadora gana, papel (2) cubre piedra (1).\n");
            }
            else
            {
                printf("Ganaste, piedra (1) aplasta tijera (3).\n");
            }
        }
    }
    else
    {
        if (jugador == 2)
        {
            if (computadora == 1)
            {
                printf("Ganaste, papel (2) cubre piedra (1).\n");
            }
            else
            {
                if (computadora == 2)
                {
                    printf("Empate, ambos eligieron papel (2).\n");
                }
                else
                {
                    printf("La computadora gana, tijera (3) corta papel (2).\n");
                }
            }
        }
        else
        {
            if (jugador == 3)
            {
                if (computadora == 1)
                {
                    printf("La computadora gana, piedra (1) aplasta tijera (3).\n");
                }
                else
                {
                    if (computadora == 2)
                    {
                        printf("Ganaste, tijera (3) corta papel (2).\n");
                    }
                    else
                    {
                        printf("Empate, ambos eligieron tijera (3).\n");
                    }
                }
            }
            else
            {
                printf("Selección inválida. Por favor, elige 1, 2 o 3.\n");
            }
        }
    }
}
//***********************
/*
Juego CHUNCHAMPU (Piedra papel o tijera) para 1 jugador contra la computadora
Hecho por selección múltiple
*/
void chinchampu_selec()
{
    system("CLS");
    int jugador, computadora;

    printf("Juguemos a Piedra, Papel, Tijera!\n");
    printf("Elige una opcion:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    printf("Tu eleccion: ");
    scanf("%d", &jugador);

    srand(time(NULL));

    computadora = rand() % 3 + 1;

    switch (jugador)
    {
    case 1:
        switch (computadora)
        {
        case 1:
            printf("Empate, ambos eligieron Piedra (1).\n");
            break;
        case 2:
            printf("La computadora gana, Papel (2) cubre Piedra (1).\n");
            break;
        case 3:
            printf("Ganaste, Piedra (1) aplasta Tijera (3).\n");
            break;
        default:
            printf("Selección de la computadora no válida.\n");
            break;
        }
        break;
    case 2:
        switch (computadora)
        {
        case 1:
            printf("Ganaste, Papel (2) cubre Piedra (1).\n");
            break;
        case 2:
            printf("Empate, ambos eligieron Papel (2).\n");
            break;
        case 3:
            printf("La computadora gana, Tijera (3) corta Papel (2).\n");
            break;
        default:
            printf("Selección de la computadora no válida.\n");
            break;
        }
        break;
    case 3:
        switch (computadora)
        {
        case 1:
            printf("La computadora gana, Piedra (1) aplasta Tijera (3).\n");
            break;
        case 2:
            printf("Ganaste, Tijera (3) corta Papel (2).\n");
            break;
        case 3:
            printf("Empate, ambos eligieron Tijera (3).\n");
            break;
        default:
            printf("Selección de la computadora no válida.\n");
            break;
        }
        break;
    default:
        printf("Selección inválida. Por favor, elige 1, 2 o 3.\n");
        break;
    }
}
//**************
/*
El usuario introduce 3 números y despliega el número mayor (usando AND)
*/
void mayor_and()
{
    system("CLS");
    int num1, num2, num3;

    printf("Programa que lee 3 numeros y despliega cual numero es el mayor (usando AND u OR)\n");

    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);

    if ((num1 >= num2) && (num1 >= num3))
    {
        printf("El numero mayor es: %d", num1);
    }
    else
    {
        if ((num2 >= num1) && (num2 >= num3))
        {
            printf("El numero mayor es: %d", num2);
        }
        else
        {
            printf("El numero mayor es: %d", num3);
        }
    }
    printf("\n");
}
//**************
/*
El usuario introduce 3 números y despliega el número del medio (usando AND y OR)
*/
void medio_and()
{
    system("CLS");
    int num1, num2, num3;

    printf("Programa que lee 3 numeros y despliega cual numero es de en medio (usando AND u OR)\n");

    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);

    if ((num1 < num2 && num2 < num3) || (num3 < num2 && num2 < num1))
    {
        printf("El numero medio es: %d", num2);
    }
    else
    {
        if ((num2 < num1 && num1 < num3) || (num3 < num1 && num1 < num2))
        {
            printf("El numero medio es: %d", num1);
        }
        else
        {
            printf("El numero medio es: %d", num3);
        }
    }
    printf("\n");
}
//**************
/*
El usuario introduce 3 números y se despliega el número menor (usando AND)
*/
void menor_and()
{
    system("CLS");
    int num1, num2, num3;

    printf("Programa que lee 3 numeros y despliega cual numero es el mayor (usando AND u OR)\n");

    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);

    if ((num1 < num2) && (num1 < num3))
    {
        printf("El numero menor es: %d\n", num1);
    }
    else
    {
        if ((num2 < num1) && (num2 < num3))
        {
            printf("El numero menor es: %d\n", num2);
        }
        else
        {
            printf("El numero menor es: %d\n", num3);
        }
        printf("\n");
    }
}
//***************
/*
Pide que introduzcas el mes y día de nacimiento del usuario y el programa le despliega el signo del zodiaco que le corresponde
y su correspondiente horoscopo según el signo.
*/
void horoscopo()
{
    system("CLS");
    int mes, dia;

    printf("Horoscopo del dia!\n");

    printf("Ingresa tu dia de nacimiento: ");
    scanf("%d", &dia);

    printf("Ingresa el mes de nacimiento: ");
    scanf("%d", &mes);

    if (dia <= 0)
    {
        printf("\nDia introducido incorrecto, debe ser positivo y entero\n");
        menu_act3();
    }
    if (mes <= 0)
    {
        printf("\nMes introducido incorrecto, debe ser positivo y entero\n");
        menu_act3();
    }
    printf("\n");

    if (mes >= 6)
    {
        if (mes >= 7)
        {
            if (mes >= 8)
            {
                if (mes >= 9)
                {
                    if (mes >= 10)
                    {
                        if (mes >= 11)
                        {
                            if (mes >= 12)
                            {
                                if (mes == 12)
                                {
                                    if (dia <= 21)
                                    {
                                        printf("Tu signo es Sagitario\n");
                                        printf("Horoscopo del dia para Sagitario: Hoy es un buen dia para tomar decisiones importantes y liderar proyectos. Tu energia y determinacion te llevaran lejos.\n");
                                    }
                                    else
                                    {
                                        if (dia <= 31)
                                        {
                                            printf("Tu signo es Capricornio\n");
                                            printf("Horoscopo del dia para Capricornio: Hoy es un buen dia para enfocarte en tu carrera y establecer metas a largo plazo. La perseverancia te llevara al exito.\n");
                                        }
                                        else
                                        {
                                            printf("Tu dia de nacimiento es incorrecto.\n");
                                        }
                                    }
                                }
                                else
                                {
                                    printf("Mes introducido incorrecto. Introduce una opcion correcta.\n");
                                }
                            }
                            else
                            {
                                if (dia <= 21)
                                {
                                    printf("Tu signo es Escorpio\n");
                                    printf("Horoscopo del dia para Escorpio: Hoy es un buen dia para resolver conflictos y mantener relaciones personales armoniosas. Una conversacion honesta puede ser la clave.\n");
                                }
                                else
                                {
                                    if (dia <= 30)
                                    {
                                        printf("Tu signo es Sagitario\n");
                                        printf("Horoscopo del dia para Sagitario: Manten la mente abierta y dispuesta a aprender. Puedes descubrir algo nuevo e interesante que cambiara tu perspectiva.\n");
                                    }
                                    else
                                    {
                                        printf("Tu dia de nacimiento es incorrecto.\n");
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (dia <= 22)
                            {
                                printf("Tu signo es Libra\n");
                                printf("Horoscopo del dia para Libra: Encuentra el equilibrio entre tu vida personal y profesional. Dedica tiempo a tus seres queridos y a ti mismo.\n");
                            }
                            else
                            {
                                if (dia <= 31)
                                {
                                    printf("Tu signo es Escorpio\n");
                                    printf("Horoscopo del dia para Escorpio: Hoy es un buen dia para resolver conflictos y mantener relaciones personales armoniosas. Una conversacion honesta puede ser la clave.\n");
                                }
                                else
                                {
                                    printf("Tu dia de nacimiento es incorrecto.\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        if (dia <= 22)
                        {
                            printf("Tu signo es Virgo\n");
                            printf("Horoscopo del dia para Virgo: Organiza tu vida y establece metas realistas. El enfoque y la disciplina son clave para alcanzar tus objetivos.\n");
                        }
                        else
                        {
                            if (dia >= 30)
                            {
                                printf("Tu signo es Libra\n");
                                printf("Horoscopo del dia para Libra: Encuentra el equilibrio entre tu vida personal y profesional. Dedica tiempo a tus seres queridos y a ti mismo.\n");
                            }
                            else
                            {
                                printf("Tu dia de nacimiento es incorrecto.\n");
                            }
                        }
                    }
                }
                else
                {
                    if (dia <= 22)
                    {
                        printf("Tu signo es Leo\n");
                        printf("Horoscopo del dia para Leo: Dedica tiempo a cuidar tus relaciones personales. Una conversacion honesta podria resolver cualquier conflicto pendiente.\n");
                    }
                    else
                    {
                        if (dia <= 31)
                        {
                            printf("Tu signo es Virgo\n");
                            printf("Horoscopo del dia para Virgo: Organiza tu vida y establece metas realistas. El enfoque y la disciplina son clave para alcanzar tus objetivos.\n");
                        }
                        else
                        {
                            printf("Tu dia de nacimiento es incorrecto.\n");
                        }
                    }
                }
            }
            else
            {
                if (dia <= 22)
                {
                    printf("Tu signo es Cancer\n");
                    printf("Horoscopo del dia para Cancer: Dedica tiempo a cuidar tus relaciones personales. Una conversacion honesta podria resolver cualquier conflicto pendiente.\n");
                }
                else
                {
                    if (dia <= 31)
                    {
                        printf("Tu signo es Leo\n");
                        printf("Horoscopo del dia para Leo: Dedica tiempo a cuidar tus relaciones personales. Una conversacion honesta podria resolver cualquier conflicto pendiente.\n");
                    }
                    else
                    {
                        printf("Tu dia de nacimiento es incorrecto.\n");
                    }
                }
            }
        }
        else
        {
            if (dia <= 20)
            {
                printf("Tu signo es Geminis\n");
                printf("Horoscopo del dia para Geminis: Manten la mente abierta y dispuesta a aprender. Puedes descubrir algo nuevo e interesante que cambiara tu perspectiva.\n");
            }
            else
            {
                if (dia <= 30)
                {
                    printf("Tu signo es Cancer\n");
                    printf("Horoscopo del dia para Cancer: Dedica tiempo a cuidar tus relaciones personales. Una conversacion honesta podria resolver cualquier conflicto pendiente.\n");
                }
                else
                {
                    printf("Dia de nacimiento incorrecto.\n");
                }
            }
        }
    }
    else
    {
        if (mes < 5)
        {
            if (mes < 4)
            {
                if (mes < 3)
                {
                    if (mes < 2)
                    {
                        if (mes == 1)
                        {
                            if (dia <= 19)
                            {
                                printf("Tu signo es Capricornio\n");
                                printf("Horoscopo del dia para Capricornio: Hoy es un buen dia para enfocarte en tu carrera y establecer metas a largo plazo. La perseverancia te llevara al exito.\n");
                            }
                            else
                            {
                                if (dia <= 31)
                                {
                                    printf("Tu signo es Acuario\n");
                                    printf("Horoscopo del dia para Acuario: Se innovador y piensa fuera de la caja. Tus ideas originales pueden generar cambios positivos.\n");
                                }
                                else
                                {
                                    printf("Tu dia de nacimiento es incorrecto.\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        if (dia <= 18)
                        {
                            printf("Tu signo es Acuario\n");
                            printf("Horoscopo del dia para Acuario: Se innovador y piensa fuera de la caja. Tus ideas originales pueden generar cambios positivos.\n");
                        }
                        else
                        {
                            if (dia <= 31)
                            {
                                printf("Tu signo es Piscis\n");
                                printf("Horoscopo del dia para Piscis: Dedica tiempo a cuidar tu bienestar emocional. La meditacion o el tiempo de tranquilidad pueden ser beneficiosos.\n");
                            }
                            else
                            {
                                printf("Tu dia de nacimiento es incorrecto.\n");
                            }
                        }
                    }
                }
                else
                {
                    if (dia <= 20)
                    {
                        printf("Tu signo es Piscis\n");
                        printf("Horoscopo del dia para Piscis: Dedica tiempo a cuidar tu bienestar emocional. La meditacion o el tiempo de tranquilidad pueden ser beneficiosos.\n");
                    }
                    else
                    {
                        if (dia <= 31)
                        {
                            printf("Tu signo es Aries\n");
                            printf("Horoscopo del dia para Aries: Hoy es un buen dia para tomar decisiones importantes y liderar proyectos. Tu energia y determinacion te llevaran lejos.\n");
                        }
                        else
                        {
                            printf("Tu dia de nacimiento es incorrecto.\n");
                        }
                    }
                }
            }
            else
            {
                if (dia <= 19)
                {
                    printf("Tu signo es Aries\n");
                    printf("Horoscopo del dia para Aries: Hoy es un buen dia para tomar decisiones importantes y liderar proyectos. Tu energia y determinacion te llevaran lejos.\n");
                }
                else
                {
                    if (dia <= 31)
                    {
                        printf("Tu signo es Tauro\n");
                        printf("Horoscopo del dia para Tauro: Dedica tiempo a disfrutar de las cosas hermosas de la vida y expresar tu creatividad. Tu creatividad estara en su punto mas alto hoy.\n");
                    }
                    else
                    {
                        printf("Tu dia de nacimiento es incorrecto.\n");
                    }
                }
            }
        }
        else
        {
            if (dia <= 20)
            {
                printf("Tu signo es Tauro\n");
                printf("Horoscopo del dia para Tauro: Dedica tiempo a disfrutar de las cosas hermosas de la vida y expresar tu creatividad. Tu creatividad estara en su punto mas alto hoy.\n");
            }
            else
            {
                if (dia <= 31)
                {
                    printf("Tu signo es Geminis\n");
                    printf("Horoscopo del dia para Geminis: Manten la mente abierta y dispuesta a aprender. Puedes descubrir algo nuevo e interesante que cambiara tu perspectiva.\n");
                }
                else
                {
                    printf("Dia de nacimiento incorrecto.\n");
                }
            }
        }
    }
    printf("\n");
}

//****** FUNCIONES ACTIVIDAD 5 ************
//*****************
/*
Pide al usuario que introduzca un valor entero, y el algoritmo desplegará todos los numeros
enteros positivos menos del valor introducido en orden descendente
*/
void descen_nums()
{
    system("CLS");
    int n, i;
    i = 0;
    printf("Introduce un numero positivo entero: ");
    scanf("%d", &n);

    for (i = n; 0 <= i; i--)
    {
        printf("%d  ", i);
    }
}
//***************
/*
Este algoritmo genera 40 numeros aleatorios (del 0 al 200) y despliega los números con una leyenda de cada numero si es par o impar
la cantidad de pares e impares así como la suma de los numeros pares o impares
*/
void par_imparRandom()
{

    system("CLS");
    int numrandom, i, parsum, imparsum, pares, impares;
    parsum = 0;
    imparsum = 0;
    pares = 0;
    impares = 0;
    srand(time(NULL));

    printf("Generador de 40 numeros aleatorios, los cuales se sumaran y se agregara una leyenda si es par o impar\n");
    for (i = 1; i <= 40; i++)
    {
        numrandom = rand() % 200;
        if (numrandom % 2 == 0)
        {
            parsum += numrandom;
            printf("%d.- %d es par\n", i, numrandom);
            pares++;
        }
        else
        {
            imparsum += numrandom;
            printf("%d.- %d es impar\n", i, numrandom);
            impares++;
        }
    }
    printf("\nLa suma de los numeros pares es: %d\n", parsum);
    printf("La suma de los numeros impares es: %d\n", imparsum);
    printf("Hay %d numeros pares\n", pares);
    printf("Hay %d numeros impares\n", impares);
}
//**************
/*
Esta función genera 35 numeros aleatorios del 100 al 200, al final despliega el numero mayor y el numero menor
*/
void MayorMenor_Num()
{
    system("CLS");
    int num, i, menorNum, mayorNum;

    i = 0;
    menorNum = 200; // Ambos se inicializan en sus valores contrarios. (El menor nunca será 200)
    mayorNum = 100; // Y en este, el mayor nunca será 100 (Pues el rango es de 100 a 200).
    srand(time(NULL));

    for (i = 0; i < 35; i++)
    {
        num = rand() % 100 + 100;
        if (num < menorNum)
        {
            menorNum = num;
        }
        if (num > mayorNum)
        {
            mayorNum = num;
        }
    }

    printf("El numero mayor es: %d\n", mayorNum);
    printf("El numero menor es: %d\n", menorNum);
}
//**************
/*
Esta función le pregunta al usuario que tabla de multiplicar desea obtener y enseguida
se imprime la tabla de multiplicar.
*/
void tabla_multi()
{
    system("CLS");
    int num, i, tempnum;

    i = 0;

    printf("Tabla de multiplicar\n");
    printf("Ingresa la tabla de multiplicar que deseas obtener: ");
    scanf("%d", &num);

    printf("Tabla de multiplicar del numero %d\n", num);
    for (i = 0; i <= 20; i++)
    {
        tempnum = num * i;
        printf("%dx%d = %d\n", num, i, tempnum);
    }
}