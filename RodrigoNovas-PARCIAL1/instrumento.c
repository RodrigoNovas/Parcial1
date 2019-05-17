#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "instrumento.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int instrumento_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eInstrumento instrumentos, INSTRUMENTOS
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int instrumento_init(eInstrumento* instrumentos,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        instrumentos[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, instrumentos de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int instrumento_findIsEmpty(eInstrumento* instrumentos,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(instrumentos[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la instrumentos
 * \param eEmployee empleado, instrumentos de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int instrumento_findById(eInstrumento* instrumentos ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(instrumentos[i].isEmpty== ESTADO_OCUPADO && instrumentos[i].idInstrumentos== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, instrumentos de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int instrumento_remove(eInstrumento* instrumentos,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(instrumentos[i].idInstrumentos==id)
             {
                 instrumentos[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la instrumentos de eEmpleados
 * \param eEmployee empleado, instrumentos de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int instrumento_add(eInstrumento* instrumentos,int cantidad)
{
    int posicionAux,retorno=-1;
    int auxTipo;

    if(cantidad>=0)
    {
        posicionAux= instrumento_findIsEmpty(instrumentos,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE:\n","\tERROR\nCARACTER NO VALIDO",instrumentos[posicionAux].nombre);
            printf("\n-------------TIPO DE INSTRUMENTO----------\n");
            printf("\tINGRESE EL NUMERO 1 PARA CUERDAS\n \tINGRESE EL NUMERO 2 PARA VIENTO-MADERA\n \tINGRESE EL NUMERO 3 PARA VIENTO-METAL\n \tINGRESE EL NUMERO 4 PARA PERCUSIÓN\n");
            auxTipo=getValidIntOpcion("INGRESE TIPO DE INSTRUMENTO:\n","\tERROR\nCARACTER NO VALIDO",1, 4);
            instrumentos[posicionAux].tipo = auxTipo;
            instrumentos[posicionAux].idInstrumentos= instrumento_array_generarProximoId();
            system("cls");
            instrumentos[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO INSTRUMENTO CON EXITO!!!\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la instrumentos de empleados
 * \param eEmployee empleado, instrumentos de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void instrumento_hardcodearDatos(eInstrumento* instrumentos , int cantidad)
{
    int i;
    char nombres[][20]= {"Guitarra","Piano","Triangulo","Xilofono"};
    int tipo[]= {1,2,3,4,5};

    for(i=0; i<cantidad; i++)
    {
        instrumentos[i].idInstrumentos=instrumento_array_generarProximoId();
        strcpy(instrumentos[i].nombre,nombres[i]);
        instrumentos[i].tipo= tipo[i];
        instrumentos[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la instrumentos
 * \param eEmployee empleado, instrumentos de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int instrumento_modificar(eInstrumento* instrumentos, int cantidad,int id)
{
    int idAux,retorno=-1,opcion;
    int auxTipo;
    idAux= instrumento_findById(instrumentos,cantidad,id);

    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-TIPO\n3-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,4);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",instrumentos[idAux].nombre);
                break;

            case 2:
                system("cls");
                auxTipo=getValidIntOpcion("INGRESE TIPO\n","\tERROR\nCARACTER NO VALIDO\n",1,4);
                instrumentos[idAux].tipo= auxTipo;
                break;
            }
        }
        while(opcion!=3);
        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una instrumentos de instrumento
 * \param eInstrumento, instrumentos de instrumento
 * \param int cantidad de array
 * \return void
 */
void instrumento_listar(eInstrumento* instrumentos,int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(instrumentos[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("%d\t%s",instrumentos[i].idInstrumentos,instrumentos[i].nombre);

            switch(instrumentos[i].tipo)
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


/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, instrumentos de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void instrumento_admin(eInstrumento* instrumentos,int cantidad)
{
    int opcion,idAux;

    do
    {
        system("cls");
        printf("\tMENU -INTRUMENTOS-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            instrumento_add(instrumentos,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tTIPO\n");
            instrumento_listar(instrumentos,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE INSTRUMENTO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(instrumento_modificar(instrumentos,cantidad,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\tTIPO\n\n");
            instrumento_listar(instrumentos,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE INSTRUMENTO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(instrumento_remove(instrumentos,cantidad,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4:
            system("cls");
            printf("\nSE LISTARA ORDENADO ALFABETICAMENTE POR NOMBRE DEL INSTRUMENTO\n");
            printf("ID\tNOMBRE\tTIPO\n\n");
            instrumento_ordenar(instrumentos,cantidad);
            instrumento_listar(instrumentos,cantidad);
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
void instrumento_ordenar(eInstrumento* instrumentos,int cantidad)
{
    int i,j;
    eInstrumento aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(instrumentos[i].nombre,instrumentos[j].nombre)>0)
            {
                aux=instrumentos[i];
                instrumentos[i]=instrumentos[j];
                instrumentos[j]=aux;
            }
        }
    }
}
