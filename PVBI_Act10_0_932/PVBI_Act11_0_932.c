/*

*/

//**** LIBRARIES ****
#include "Frijoles.h"
#include <time.h>
#include <string.h>
//*******************
typedef struct _stdnt
{
    int status;
    int matricula;
    char LastName1[30];
    char Lastname2[30];
    char name[50];
    int age;
    int sex;
} Tstdnt;

char nameMen[30][30] = {
    "Juan",
    "Pedro",
    "Luis",
    "Miguel",
    "Carlos",
    "Javier",
    "Manuel",
    "Jose",
    "Fernando",
    "Alberto",
    "Ricardo",
    "Enrique",
    "Antonio",
    "Alejandro",
    "Emilio",
    "Arturo",
    "Jorge",
    "Eduardo",
    "Hector",
    "Francisco",
    "Raul",
    "Roberto",
    "Ernesto",
    "Guillermo",
    "Armando",
    "Mario",
    "Daniel",
    "Oscar",
    "Israel",
    "Salvador"};

char nameWomen[30][30] = {
    "María",
    "Ana",
    "Laura",
    "Patricia",
    "Carmen",
    "Sofia",
    "Isabel",
    "Paula",
    "Beatriz",
    "Elena",
    "Gabriela",
    "Rosa",
    "Clara",
    "Victoria",
    "Lourdes",
    "Adriana",
    "Natalia",
    "Susana",
    "Marta",
    "Pilar",
    "Sonia",
    "Alejandra",
    "Julia",
    "Raquel",
    "Antonia",
    "Gloria",
    "Silvia",
    "Aurora",
    "Consuelo",
    "Mercedes"
    };

char LastName[120][60] = {
    "Ramos",
    "Moreno",
    "Fernandez",
    "Torres",
    "Ramirez",
    "Jimenez",
    "Nunez",
    "Vega",
    "Rojas",
    "Iglesias",
    "Pacheco",
    "Valencia",
    "Mora",
    "Silva",
    "Gomez",
    "Cordero",
    "Serrano",
    "Medina",
    "Alvarez",
    "Soto",
    "Lara",
    "Herrera",
    "Guerrero",
    "Ortiz",
    "Pardo",
    "Roldan",
    "Suarez",
    "Salazar",
    "Castillo",
    "Aguilar",
    "Roman",
    "Zamora",
    "Diaz",
    "Castaneda",
    "Vargas",
    "Quintero",
    "Molina",
    "Cabrera",
    "Gonzales",
    "Cruz",
    "Delgado",
    "Villanueva",
    "Rios",
    "Reyes",
    "Flores",
    "Rojas",
    "Arias",
    "Lopez",
    "Maldonado",
    "Mendez",
    "Cervantes",
    "Espinosa",
    "Chacon",
    "Solis",
    "Tovar",
    "Sandoval",
    "Valencia",
    "Rivera",
    "Rosales",
    "Duran",
    "Rubio",
    "Mendoza",
    "Bautista",
    "Vasquez",
    "Romero",
    "Mercado",
    "Espinosa",
    "Escobar",
    "Sosa",
    "Barrios",
    "Leon",
    "Soto",
    "Ochoa",
    "Contreras",
    "Cervantes",
    "Valenzuela",
    "Miranda",
    "Paredes",
    "Beltran",
    "Espinoza",
    "Pena",
    "Casillas",
    "Varela",
    "Hidalgo",
    "Guzman",
    "Menendez",
    "Alvarado",
    "Estrella",
    "Hernandez",
    "Osorio",
    "Macias",
    "Uribe",
    "Garza",
    "Valdes",
    "Camacho",
    "Leal",
    "Munguia",
    "Solano",
    "Maciel",
    "Calzada",
    "Alcala",
    "Barajas",
    "Parra",
    "Elizondo",
    "Palacios",
    "Casas",
    "Ventura",
    "Montes",
    "Munoz",
    "Lugo",
    "Sosa",
    "Ojeda",
    "Franco",
    "Arellano",
    "Pizarro",
    "Chavez",
    "Robles",
    "Carranza",
    "Urbina"
};


//**** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

void genDataReg(Tstdnt studentArray[], int i);
void fillReg(Tstdnt studentArray[]);

//**** MAIN FUNCTIONS ****
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu()
{
    int op;
    Tstdnt studentArray[500];
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            fillReg(studentArray);
            break;
        }
    } while (op != 0);
}
//***********
int msge_menu()
{
    int op;
    system("CLS");
    printArr("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printArr("1.- Agregar 10 registros automatico\n");
    printArr("2.- Agregar manual\n");
    printArr("3.- Eliminar registros\n");
    printArr("4.- Buscar\n");
    printArr("5.- Ordenar\n");
    printArr("6.- Imprimir\n");
    printArr("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 6);
    return op;
}

//**********
void genDataReg(Tstdnt studentArray[], int i)
{
    int index1 = numRandom(0, 119);
    int index2 = numRandom(0, 119);

    //*** STATUS ***
    studentArray[i].status = numRandom(0, 1);

    //**** STUDENT REGISTRATION ***
    studentArray[i].matricula = numRandom(300000, 399999);

    //*** COPY LAST NAME 1 AND 2 ****
    strcpy(studentArray[i].LastName1, LastName[index1]);
    strcpy(studentArray[i].Lastname2, LastName[index2]);

    //**** SELECT SEX AND NAME ****
    if (numRandom(0, 1) == 1)
    {
        strcpy(studentArray[i].name, nameMen[numRandom(1, 29)]);
        studentArray[i].sex = 1; // MEN = 1
    }
    else
    {
        strcpy(studentArray[i].name, nameWomen[numRandom(1, 29)]);
        studentArray[i].sex = 0; // WOMEN = 0
    }

    //**** GENERATE AGE *********
    studentArray[i].age = numRandom(18, 40);
}
void fillReg(Tstdnt studentArray[])
{
    int i;

    for (i = 0; i < 10; i++)
    {
        genDataReg(studentArray, i);
        printf("%s ", studentArray[i].LastName1);
        printf("%s ", studentArray[i].Lastname2);
        printf("%s -- ", studentArray[i].name);
        printf("%d -- ", studentArray[i].matricula);
        printf("%d -- ", studentArray[i].status);
        printf("%d -- ", studentArray[i].age);
        printf("%d -- ", studentArray[i].sex);
        printf("\n");
    }
    system("PAUSE");
}
