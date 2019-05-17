#include <stdio.h>
#include <stdlib.h>
#include "instrumento.h"
#define CANTIDAD_INSTRUMENTOS 20
#define CANTIDAD_ORQUESTAS 50
/*#define CANTIDAD_SOCIOS 8
#define CANTIDAD_AUTORES 7*/
int main()
{
   int opcion;


    eInstrumento arrayInstrumentos[CANTIDAD_INSTRUMENTOS];
    instrumento_init(arrayInstrumentos, CANTIDAD_INSTRUMENTOS);

    eOrquesta arrayOrquesta[CANTIDAD_ORQUESTAS];
    orquesta_init(arrayInstrumentos, CANTIDAD_ORQUESTAS);


    instrumento_hardcodearDatos(arrayInstrumentos,4);
    orquesta_hardcodearDatos(arrayOrquesta,4);


    do
    {
        system("cls");
        printf("\t-MENU PRINCIPAL-\n");
        opcion= getValidIntOpcion("\n1-ADMINISTRAR INSTRUMENTOS\n2-ADMINISTRAR ORQUESTA\n3-ADMINISTRAR MUSICOS\n4-SALIR","ERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1:
           instrumento_admin(arrayInstrumentos,CANTIDAD_INSTRUMENTOS);
            system("cls");
            break;
        }
        case 2:
           orquesta_admin(arrayOrquesta,CANTIDAD_ORQUESTAS);
            system("cls");
            break;
        }
        }while(opcion!=4);
}
