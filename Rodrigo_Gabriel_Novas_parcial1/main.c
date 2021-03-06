#include <stdio.h>
#include <stdlib.h>
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "INFORMES.h"
#define CANTIDAD_INSTRUMENTOS 20
#define CANTIDAD_ORQUESTAS 50
#define CANTIDAD_MUSICOS 1000

int main()
{
    int opcion;
    int idAuxOrquesta;
    int opcionSub;
    eInstrumento arrayInstrumentos[CANTIDAD_INSTRUMENTOS];
    instrumento_init(arrayInstrumentos, CANTIDAD_INSTRUMENTOS);

    eOrquesta arrayOrquesta[CANTIDAD_MUSICOS];
    orquesta_init(arrayOrquesta, CANTIDAD_ORQUESTAS);

    eMusico arrayMusico[CANTIDAD_MUSICOS];
    musico_init(arrayMusico, CANTIDAD_MUSICOS);

    instrumento_hardcodearDatos(arrayInstrumentos,4);
    orquesta_hardcodearDatos(arrayOrquesta,4);
    musico_hardcodearDatos(arrayMusico, 6);

    do
    {
        system("cls");
        printf("\t-MENU PRINCIPAL-\n");
        opcion= getValidIntOpcion("\n1-ADMINISTRAR INSTRUMENTOS\n2-ADMINISTRAR ORQUESTA\n3-ADMINISTRAR MUSICOS\n4-INFORMES\n5-SALIR\n","ERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1:
           instrumento_admin(arrayInstrumentos,CANTIDAD_INSTRUMENTOS);
            system("cls");
            break;

        case 2:
           orquesta_admin(arrayOrquesta, arrayMusico, CANTIDAD_ORQUESTAS, CANTIDAD_MUSICOS);
            system("cls");
            break;
        case 3:
           musico_admin(arrayMusico, arrayInstrumentos, arrayOrquesta, CANTIDAD_MUSICOS, CANTIDAD_ORQUESTAS, CANTIDAD_INSTRUMENTOS);
            system("cls");
            break;
        case 4:
            informes_admin(arrayMusico, arrayInstrumentos,arrayOrquesta,CANTIDAD_MUSICOS,CANTIDAD_ORQUESTAS,CANTIDAD_INSTRUMENTOS);
            break;
        }
        }while(opcion!=5);
}
