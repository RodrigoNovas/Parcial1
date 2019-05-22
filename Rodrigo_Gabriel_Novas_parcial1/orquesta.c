#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "funcionesGet.h"
#include "orquesta.h"
#include "musico.h"
static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int orquesta_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eOrquesta orquestas, ORQUESTAS
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int orquesta_init(eOrquesta* orquestas,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        orquestas[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, orquestas de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int orquesta_findIsEmpty(eOrquesta* orquestas,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(orquestas[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la orquestas
 * \param eEmployee empleado, orquestas de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int orquesta_findById(eOrquesta* orquestas ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(orquestas[i].isEmpty== ESTADO_OCUPADO && orquestas[i].idOrquestas== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, orquestas de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int orquesta_remove(eOrquesta* orquestas,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(orquestas[i].idOrquestas==id)
             {
                 orquestas[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la orquestas de eEmpleados
 * \param eEmployee empleado, orquestas de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int orquesta_add(eOrquesta* orquestas,int cantidad)
{
    int posicionAux,retorno=-1;
    int auxTipo;

    if(cantidad>=0)
    {
        posicionAux= orquesta_findIsEmpty(orquestas,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE:\n","\tERROR\nCARACTER NO VALIDO",orquestas[posicionAux].nombre);
            getValidString("INGRESE LUGAR:\n","\tERROR\nCARACTER NO VALIDO",orquestas[posicionAux].lugar);
            printf("\n-------------TIPO DE ORQUESTA----------\n");
            printf("\tINGRESE EL NUMERO 1 PARA SINFONICA\n \tINGRESE EL NUMERO 2 PARA FILARMONICA\n \tINGRESE EL NUMERO 3 PARA CAMARA\n");
            auxTipo=getValidIntOpcion("INGRESE TIPO DE ORQUESTA:\n","\tERROR\nCARACTER NO VALIDO",1, 3);
            orquestas[posicionAux].tipo = auxTipo;
            orquestas[posicionAux].idOrquestas= orquesta_array_generarProximoId();
            system("cls");
            orquestas[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO ORQUESTA CON EXITO!!!\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la orquestas de empleados
 * \param eEmployee empleado, orquestas de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void orquesta_hardcodearDatos(eOrquesta* orquestas , int cantidad)
{
    int i;
    char nombres[][20]= {"Orquesta1","Orquesta2","Orquesta3","Orquesta4"};
    char lugar[][20]= {"Lugar1","Lugar1","Lugar3","Lugar3"};
    int tipo[]= {1,2,3,3};

    for(i=0; i<cantidad; i++)
    {
        orquestas[i].idOrquestas=orquesta_array_generarProximoId();
        strcpy(orquestas[i].nombre,nombres[i]);
        strcpy(orquestas[i].lugar,lugar[i]);
        orquestas[i].tipo= tipo[i];
        orquestas[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la orquestas
 * \param eEmployee empleado, orquestas de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int orquesta_modificar(eOrquesta* orquestas, int cantidad,int id)
{
    int idAux,retorno=-1,opcion;
    int auxTipo;
    idAux= orquesta_findById(orquestas,cantidad,id);

    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-TIPO\n3-LUGAR\n4-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,4);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",orquestas[idAux].nombre);
                break;

            case 2:
                system("cls");
                auxTipo=getValidIntOpcion("INGRESE TIPO\n","\tERROR\nCARACTER NO VALIDO\n",1,3);
                orquestas[idAux].tipo= auxTipo;
                break;
            case 3:
                system("cls");
                getValidString("INGRESE LUGAR\n","\tERROR\nCARACTER NO VALIDO\n",orquestas[idAux].lugar);
                break;
            }
        }
        while(opcion!=4);
        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una orquestas de orquesta
 * \param eOrquesta, orquestas de
 * \param int cantidad de array
 * \return void
 */
void orquesta_listar(eOrquesta* orquestas,int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(orquestas[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("%d\t%s\t%d\t%s\n",orquestas[i].idOrquestas,orquestas[i].nombre,orquestas[i].tipo,orquestas[i].lugar);
        }
    }
}


/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, orquestas de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void orquesta_admin(eOrquesta* orquestas, eMusico* musicos,int cantidad, int cantidadMusicos)
{
    int opcion,idAux;
    char auxLugar[30];
    do
    {
        system("cls");
        printf("\tMENU -ORQUESTA-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            orquesta_add(orquestas,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tTIPO\tLUGAR\n");
            orquesta_listar(orquestas,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE ORQUESTA A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(orquesta_modificar(orquestas,cantidad,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\tTIPO\n\n");
            orquesta_listar(orquestas,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE ORQUESTA A DAR DE BAJA(SE ELIMINAR LOS MUSICOS QUE LA COMPONEN)\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(orquesta_remove(orquestas,cantidad,idAux)==0){
                getChar("ID DADO DE BAJA\n");
                musico_removeByOrquesta(musicos,cantidadMusicos,idAux);}
                else{
                    printf("ID NO DISPONIBLE");
            }
                break;

        case 4:
            system("cls");
            printf("\nSE LISTARA ORDENADO ALFABETICAMENTE POR NOMBRE DE LA ORQUESTA\n");
            printf("ID\tNOMBRE\tTIPO\n\n");
            //orquesta_ordenar(orquestas,cantidad);
            orquesta_listar(orquestas,cantidad);
            //---------------------------------------------------------------------------------
           // printf("\n");
            //getValidString("INGRESE LUGAR\n","\tERROR\nCARACTER NO VALIDO\n", auxLugar[30]);
            //orquesta_listar_Lugar(orquestas, cantidad, auxLugar[30]);
            getChar("");
            break;
        }

    }while(opcion!=5);
}


/** \brief ordena los elemento de la socio
 * \param esocio
 * \param cantidad int
 * \return void
 */
void orquesta_ordenar(eOrquesta* orquestas,int cantidad)
{
    int i,j;
    eOrquesta aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(orquestas[i].nombre,orquestas[j].nombre)>0)
            {
                aux=orquestas[i];
                orquestas[i]=orquestas[j];
                orquestas[j]=aux;
            }
        }
    }
}


//---------------------------------------------------------------------------------

void orquesta_listar_Lugar(eOrquesta* orquestas,int cantidad, char lugar[])
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(orquestas[i].isEmpty== ESTADO_OCUPADO)
        {
            if (strcmp(orquestas[i].lugar, lugar)==0)
            {
                printf("%d\t%s\t%d\t%s\n",orquestas[i].idOrquestas,orquestas[i].nombre,orquestas[i].tipo,orquestas[i].lugar);
            }
            else{
                printf("\nNo se encuentra lugar");
            }
        }
    }
}



