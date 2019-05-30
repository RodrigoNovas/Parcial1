#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "INFORMES.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "funcionesGet.h"


void musico_listar_Edad(eMusico* musicos,int cantidad) //BIEN
{
    int i;

    printf("ID MUSICO\tEDAD\tNOMBRE\tAPELLIDO\tID INSTRUMENTO\t ID ORQUESTA\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
            if (musicos[i].edad>30)
            {
                 printf("%d\t%d\t%s\t%s\t%d\t%d\n",musicos[i].idMusico,musicos[i].edad,musicos[i].nombre,musicos[i].apellido, musicos[i].idInstrumento, musicos[i].idOrquesta);
            }

        }
    }
}

//-----

void musico_listar_Instrumento(eMusico* musicos, eInstrumento* instrumento,int cantidad, int cantInstrumento) //BIEN
{
    int i;
    int indiceInstrumento;
    musicos_ordenar_Apellido(musicos, cantidad);
    printf("EDAD\tNOMBRE\tAPELLIDO\tTIPO INSTRUMENTO\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
          indiceInstrumento=instrumento_findById(instrumento,cantInstrumento,musicos[i].idInstrumento);
            if (instrumento[indiceInstrumento].tipo==1)
            {

                 printf("%d\t%s\t%s\t%s",musicos[i].edad,musicos[i].nombre,musicos[i].apellido, "Cuerdas");


            }

        }
    }
}

//-----------------------------------------------------------------------------------
void musico_listar_Orquesta(eMusico* musicos,eInstrumento* instrumentos,int cantidad,  int idOrquesta, int cantInstrumento) //BIEN
{
    int i;

    int indiceInstrumento;
   // char auxNombre;
    printf("ID MUSICO\tEDAD\tNOMBRE\tAPELLIDO\tTIPO INSTRUMENTO\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
             if(musicos[i].idOrquesta==idOrquesta)
            {

                /*if(auxiliarID==instrumentos[i].idInstrumentos)
                {
                    strcpy(intrumentos[i].nombre,auxNombre);
                }*/
                indiceInstrumento=instrumento_findById(instrumentos,cantInstrumento,musicos[i].idInstrumento);
                 printf("%d\t%d\t%s\t%s\t%s\n",musicos[i].idMusico,musicos[i].edad,musicos[i].nombre,musicos[i].apellido,instrumentos[indiceInstrumento].nombre);
            switch(instrumentos[indiceInstrumento].tipo)
            {
            case 1:
                printf("\tCuerdas\n");
                break;
            case 2:
                printf("\tViento-Madera\n");
                break;
            case 3:
                printf("\tViento-Metal\n");
                break;
            case 4:
                printf("\tPercusion\n");
                break;
            }

            }

        }
    }
}


//---------------------------------------------------------------------------------

void orquesta_listar_Lugar(eOrquesta* orquestas,int cantidad)
{
    int i;
    char auxLugar [100];
    utn_getString(auxLugar,"Ingrese lugar: ","Error",1,100,10);
    for(i=0;i<cantidad;i++)
    {
        if(orquestas[i].isEmpty== ESTADO_OCUPADO)
        {
            if (!strcmp(orquestas[i].lugar, auxLugar))
            {
                printf("%d\t%s\t%d\t%s\n",orquestas[i].idOrquestas,orquestas[i].nombre,orquestas[i].tipo,orquestas[i].lugar);
            }

        }
    }
}
//----------------------------------------------
int inf_orquestaMasMusicos(eOrquesta* orquestas,int cantidadOrquesta,eMusico* musicos,int cantidadMusico)
{
    int ret= -1;
    int countMusico;
    int countMusicoMax=-1;
    int idOrquestaMax;
    int auxIdOrquesta=0;
    int auxIdMusico=0;

    if(musicos!=NULL && orquestas!=NULL && cantidadMusico>=0 && cantidadOrquesta>=0)
    {
        for(auxIdOrquesta=0;auxIdOrquesta<cantidadOrquesta;auxIdOrquesta++)
        {
            if(orquestas[auxIdOrquesta].isEmpty==ESTADO_OCUPADO)
            {
                countMusico=0;
                for(auxIdMusico=0;auxIdMusico<cantidadMusico;auxIdMusico++)
                {
                    if(musicos[auxIdMusico].idOrquesta==orquestas[auxIdOrquesta].idOrquestas)
                    {
                        countMusico++;
                    }
                }

                if(countMusico>countMusicoMax)
                {
                    countMusicoMax=countMusico;
                    idOrquestaMax=auxIdOrquesta;
                     printf("ID\tNOMBRE\tTIPO\tLUGAR\n\n");
                    printf("%d\t%s\t%d\t%s\n",orquestas[idOrquestaMax].idOrquestas,orquestas[idOrquestaMax].nombre,orquestas[idOrquestaMax].tipo,orquestas[idOrquestaMax].lugar);
                }


            }

        }

     printf("Cantidad de musicos %d\n",countMusicoMax);

        ret=0;
    }
    return ret;
}
//---------------------------------------------


int inf_orquestaMayor5(eOrquesta* Orquestas, eMusico* Musicos, int cantOrquestas, int cantMusicos)
{
    int retorno=-1;
    int i,j;
    int contadorOrquestas = 0;
    if(Orquestas!=NULL && Musicos != NULL && cantOrquestas>=0 && cantMusicos >=0)
    {
        for(i=0;i<cantOrquestas;i++)
        {
            if(Orquestas[i].isEmpty==ESTADO_LIBRE)
             continue;
            else
            {
                for(j=0;j<cantMusicos;j++)
                {
                    if(Musicos[j].isEmpty==ESTADO_LIBRE)
                    {
                        continue;
                    }
                    if(Orquestas[i].idOrquestas == Musicos[j].idOrquesta)
                    {
                        contadorOrquestas++;
                    }
                }
                if(contadorOrquestas>1)
                {   printf("ID:%d \tLUGAR:%s \tNOMBRE:%s ", Orquestas[i].idOrquestas, Orquestas[i].lugar, Orquestas[i].nombre);

                    switch(Orquestas[i].tipo)
                    {
                        case 1:
                            printf("\tTIPO: Sinfonica\n");
                            break;
                        case 2:
                            printf("\tTIPO: Filarmonica");
                            break;
                        case 3:
                            printf("\tTIPO: Camara");
                            break;
                    }

                }
                contadorOrquestas = 0;
            }
        }
        retorno=0;
    }
    return retorno;
}


//--------------------
int inf_orquestasCompletas(eOrquesta* orquestas, eMusico* musicos, eInstrumento* instrumentos, int cantOrquestas, int cantMusicos, int cantInstrumentos)
{
    int i,j,z;
    int retorno = -1;
    int contadorCuerdas = 0;
    int contadorViento = 0;
    int contadorPercusion = 0;
    int bufferTipo;
    if(musicos != NULL && instrumentos != NULL && orquestas != NULL && cantMusicos >= 0 && cantInstrumentos >= 0 && cantOrquestas >= 0)
    {
        for(i=0;i<cantOrquestas;i++)
        {
            if(orquestas[i].isEmpty==ESTADO_LIBRE)
            {
                continue;
            }
            for(j=0;j<cantMusicos;j++)
            {
                if(musicos[j].isEmpty==ESTADO_LIBRE)
                {
                    continue;
                }
                if(musicos[j].idOrquesta == orquestas[i].idOrquestas)
                {
                    for(z=0;z<cantInstrumentos;z++)
                    {
                        if(musicos[j].idInstrumento == instrumentos[z].idInstrumentos)
                        {
                            bufferTipo = instrumentos[z].tipo;
                            break;
                        }
                    }
                    switch(bufferTipo)
                    {
                        case 1:
                            contadorCuerdas++;
                            break;
                        case 2:
                            contadorViento++;
                            break;
                        case 3:
                            contadorViento++;
                            break;
                        case 4:
                            contadorPercusion++;
                            break;
                    }
                }

                    retorno = 0;
                }
            }
        }
         if(contadorCuerdas >= 1 && contadorViento >= 1 && contadorPercusion >= 1)//5- 3-2
                {
                    printf("\nNombre: %s\nLugar: %s\n", orquestas[i].nombre, orquestas[i].lugar);
                    switch(orquestas[i].tipo)
                    {
                        case 1:
                            printf("\nTIPO: Sinfonica");
                            break;
                        case 2:
                            printf("\nTIPO: Filarmonica");
                            break;
                        case 3:
                            printf("\nTIPO: Camara");
                            break;
                    }
        if(retorno==-1)
        {
            printf("No se ha encontrado ninguna orquesta completa.");
        }
    }
    return retorno;
}


//---------------------------------------------------------------------------------
int informes_promedioDeInstrumentos(eMusico* musicos, eOrquesta* Orquestas,  int cantMusicos, int cantOrquestas)
{
    int i;
    int retorno = -1;
    float contadorMusicos = 0;
    float contadorOrquestas = 0;
    float promedioMusicos;
    if(musicos != NULL && Orquestas != NULL && cantMusicos > 0 && cantOrquestas> 0)
    {
        for(i=0;i<cantMusicos;i++)
        {
            if(musicos[i].isEmpty == ESTADO_LIBRE)
            {
                continue;
            }else
            {
                contadorMusicos += 1;
            }
        }
        for(i=0;i<cantOrquestas;i++)
        {
            if(Orquestas[i].isEmpty == ESTADO_LIBRE)
            {
                continue;
            }else
            {
                contadorOrquestas += 1;
            }
        }
        retorno = 0;
    }

    promedioMusicos = contadorMusicos / contadorOrquestas;
    printf("El promedio de instrumentos es: %.2f", promedioMusicos);
    return retorno;
}




void informes_admin(eMusico* musicos,eInstrumento* instrumentos,eOrquesta* orquestas, int cantidadMusicos,int cantidadOrquestas, int cantidadInstrumentos)
{
    int opcionSub,idAux;
    int idAuxOrquesta;
  do
            {
            printf("----------MENU INFORMES-----------\n");
            opcionSub= getValidIntOpcion("\n1-INFORMAR MUSICOS MAS DE 30 ANIOS\n2-INFORMAR MUSICOS QUE TOCAN CUERDAS\n3-LISTAR TODOS LOS MUSICOS DE UNA ORQUESTA DETERMINADA\n4-INFORMAR ORQUESTA POR LUGAR\n5-INFORMAR ORQUESTA CON MAS MUSICOS\n6-INFORMAR ORQUESTA MAYOR A 5\n7-INFORMAR ORQUESTAS COMPLETAS\n8- PROMEDIOS\n 9-SALIR\n","ERROR\nOPCION NO VALIDA",1,9);
            switch(opcionSub)
            {
            case 1:
            musico_listar_Edad(musicos, cantidadMusicos);
             getChar("");
            break;
            case 2:
            musico_listar_Instrumento(musicos, instrumentos, cantidadMusicos, cantidadInstrumentos);
            getChar("");
            break;
            case 3:
            orquesta_listar(orquestas, cantidadOrquestas);
            printf("\n");
            idAuxOrquesta= getValidIntOpcion("\n Ingrese ID de orquesta", "\n Error. Caracter no valido", 1, cantidadOrquestas);
            musico_listar_Orquesta(musicos, instrumentos,cantidadMusicos, idAuxOrquesta, cantidadInstrumentos);
            getChar("");
            break;
            case 4:
            orquesta_listar(orquestas, cantidadOrquestas);
            printf("\n");
            orquesta_listar_Lugar(orquestas, cantidadOrquestas);
            getChar("");
            break;
            case 5:
            inf_orquestaMasMusicos(orquestas, cantidadOrquestas, musicos, cantidadMusicos);
            getChar("");
            break;
            case 6:
            inf_orquestaMayor5(orquestas,musicos,cantidadOrquestas,cantidadMusicos);
             getChar("");
             break;
            case 7:
            inf_orquestasCompletas(orquestas,musicos,instrumentos,cantidadOrquestas,cantidadMusicos,cantidadInstrumentos);
            getChar("");
            break;
            case 8:
            informes_promedioDeInstrumentos(musicos, orquestas, cantidadMusicos, cantidadOrquestas);
            getChar("");
            break;
            }
            }while(opcionSub!=9);
}
