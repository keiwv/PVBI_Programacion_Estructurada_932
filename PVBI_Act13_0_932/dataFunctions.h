#include "Frijoles.h"

void nameMen(char tempName[])
{
    char nameMen1[30][30] = {"JUAN", "PEDRO", "LUIS", "MIGUEL", "CARLOS", "JAVIER", "MANUEL", "JOSE", "FERNANDO", "ALBERTO", "RICARDO", "ENRIQUE", "ANTONIO", "ALEJANDRO", "EMILIO", "ARTURO", "JORGE", "EDUARDO", "HECTOR", "FRANCISCO", "RAUL", "ROBERTO", "ERNESTO", "GUILLERMO", "ARMANDO", "MARIO", "DANIEL", "OSCAR", "ISRAEL", "SALVADOR"};
    strcpy(tempName, nameMen1[numRandom(0, 29)]);
}

void nameWomen(char tempName[])
{
    char nameWomen1[30][30] = {"MARiA", "ANA", "LAURA", "PATRICIA", "CARMEN", "SOFIA", "ISABEL", "PAULA", "BEATRIZ", "ELENA", "GABRIELA", "ROSA", "CLARA", "VICTORIA", "LOURDES", "ADRIANA", "NATALIA", "SUSANA", "MARTA", "PILAR", "SONIA", "ALEJANDRA", "JULIA", "RAQUEL", "ANTONIA", "GLORIA", "SILVIA", "AURORA", "CONSUELO", "MERCEDES"};
    strcpy(tempName, nameWomen1[numRandom(0, 29)]);
}

void LastName(char tempLastName[])
{
    char LastName1[120][60] = {"RAMOS", "MORENO", "FERNANDEZ", "TORRES", "RAMIREZ", "JIMENEZ", "NUNEZ", "VEGA", "ROJAS", "IGLESIAS", "PACHECO", "VALENCIA", "MORA", "SILVA", "GOMEZ", "CORDERO", "SERRANO", "MEDINA", "ALVAREZ", "SOTO", "LARA", "HERRERA", "GUERRERO", "ORTIZ", "PARDO", "ROLDAN", "SUAREZ", "SALAZAR", "CASTILLO", "AGUILAR", "ROMAN", "ZAMORA", "DIAZ", "CASTANEDA", "VARGAS", "QUINTERO", "MOLINA", "CABRERA", "GONZALES", "CRUZ", "DELGADO", "VILLANUEVA", "RIOS", "REYES", "FLORES", "ROJAS", "ARIAS", "LOPEZ", "MALDONADO", "MENDEZ", "CERVANTES", "ESPINOSA", "CHACON", "SOLIS", "TOVAR", "SANDOVAL", "VALENCIA", "RIVERA", "ROSALES", "DURAN", "RUBIO", "MENDOZA", "BAUTISTA", "VASQUEZ", "ROMERO", "MERCADO", "ESPINOSA", "ESCOBAR", "SOSA", "BARRIOS", "LEON", "SOTO", "OCHOA", "CONTRERAS", "CERVANTES", "VALENZUELA", "MIRANDA", "PAREDES", "BELTRAN", "ESPINOZA", "PENA", "CASILLAS", "VARELA", "HIDALGO", "GUZMAN", "MENENDEZ", "ALVARADO", "ESTRELLA", "HERNANDEZ", "OSORIO", "MACIAS", "URIBE", "GARZA", "VALDES", "CAMACHO", "LEAL", "MUNGUIA", "SOLANO", "MACIEL", "CALZADA", "ALCALA", "BARAJAS", "PARRA", "ELIZONDO", "PALACIOS", "CASAS", "VENTURA", "MONTES", "MUNOZ", "LUGO", "SOSA", "OJEDA", "FRANCO", "ARELLANO", "PIZARRO", "CHAVEZ", "ROBLES", "CARRANZA", "URBINA"};
    strcpy(tempLastName, LastName1[numRandom(0, 99)]);
}

void displayStates(char state[])
{
    int i;
    int tempNum;
    char states[33][50] =
        {
            "Aguascalientes",
            "Baja California",
            "Baja California Sur",
            "Campeche",
            "Chiapas",
            "Chihuahua",
            "Coahuila de Zaragoza",
            "Colima",
            "Ciudad de Mexico",
            "Durango",
            "Guanajuato",
            "Guerrero",
            "Hidalgo",
            "Jalisco",
            "Mexico",
            "Michoacan de Ocampo",
            "Morelos",
            "Nayarit",
            "Nuevo Leon",
            "Oaxaca",
            "Puebla",
            "Queretaro",
            "Quintana Roo",
            "San Luis Potosi",
            "Sinaloa",
            "Sonora",
            "Tabasco",
            "Tamaulipas",
            "Tlaxcala",
            "Veracruz de Ignacio de la Llave",
            "Yucatan",
            "Zacatecas",
            "Extranjero"};
    printf("LISTA DE ESTADOS DE LOS ESTADOS UNIDOS MEXICANOS\n");
    for (i = 0; i < 33; i++)
    {
        printf("%d.- %s\n", i + 1, states[i]);
    }
    tempNum = valid("Introduce el estado en el que naciste: ", 1, 33);
    strcpy(state, states[tempNum - 1]);
}

void getState(char state[])
{
    char states[33][50] =
        {
            "Aguascalientes",
            "Baja California",
            "Baja California Sur",
            "Campeche",
            "Chiapas",
            "Chihuahua",
            "Coahuila",
            "Colima",
            "Ciudad de Mexico",
            "Durango",
            "Guanajuato",
            "Guerrero",
            "Hidalgo",
            "Jalisco",
            "Mexico",
            "Michoacan",
            "Morelos",
            "Nayarit",
            "Nuevo Leon",
            "Oaxaca",
            "Puebla",
            "Queretaro",
            "Quintana Roo",
            "San Luis Potosi",
            "Sinaloa",
            "Sonora",
            "Tabasco",
            "Tamaulipas",
            "Tlaxcala",
            "Veracruz",
            "Yucatan",
            "Zacatecas",
            "Extranjero"};
    int getNum;
    getNum = numRandom(0, 32);
    strcpy(state, states[getNum]);
}

void getJobPositions(char Job[])
{
    char Job_Positions[32][30] =
        {
            "Dev. de Software",
            "Ing. de Redes",
            "Analista de Datos",
            "Disenador Grafico",
            "Especialista RRHH",
            "Gerente de Proyectos",
            "Cons. Financiero",
            "Medico General",
            "Enfermero",
            "Abogado",
            "Analista Mkt Digital",
            "Esp. Seg. Informatica",
            "Ing. Civil",
            "Contadora",
            "Prof. Primaria",
            "Chef Ejecutivo",
            "Tec. Soporte Tecnico",
            "Disenador UX",
            "Asist. Administrativo/a",
            "Analista de Ventas",
            "Inv. Cientifico",
            "Analista de Sistemas",
            "Psic. Organizacional",
            "Esp. Logistica",
            "Ing. Electrico",
            "Editor/a de Contenidos",
            "Arquitecto/a",
            "Asesor/a Serv. Cliente",
            "Traductor/a",
            "Esp. Energias Renovables",
            "Rep. Ventas Internacionales",
            "Trab. Social"};
    strcpy(Job, Job_Positions[numRandom(0, 31)]);
}

void displayJobPositions(char Job[])
{
    int tempNum, i;
    char Job_Positions[32][30] =
        {
            "Dev. de Software",
            "Ing. de Redes",
            "Analista de Datos",
            "Disenador Grafico",
            "Especialista RRHH",
            "Gerente de Proyectos",
            "Cons. Financiero",
            "Medico General",
            "Enfermero",
            "Abogado",
            "Analista Mkt Digital",
            "Esp. Seg. Informatica",
            "Ing. Civil",
            "Contadora",
            "Prof. Primaria",
            "Chef Ejecutivo",
            "Tec. Soporte Tecnico",
            "Disenador UX",
            "Asist. Administrativo/a",
            "Analista de Ventas",
            "Inv. Cientifico",
            "Analista de Sistemas",
            "Psic. Organizacional",
            "Esp. Logistica",
            "Ing. Electrico",
            "Editor/a de Contenidos",
            "Arquitecto/a",
            "Asesor/a Serv. Cliente",
            "Traductor/a",
            "Esp. Energias Renovables",
            "Rep. Ventas Internacionales",
            "Trab. Social"};
    printf("LISTA DE PUESTOS DE TRABAJO\n");
    for (i = 0; i < 33; i++)
    {
        printf("%d.- %s\n", i + 1, Job_Positions[i]);
    }
    tempNum = valid("Selecciona el estado: ", 1, 33);
    strcpy(Job, Job_Positions[tempNum - 1]);
}