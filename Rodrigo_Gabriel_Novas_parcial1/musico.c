#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int musico_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, musicos de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int musico_init(eMusico* musicos ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        musicos[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, musicos de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int musico_findIsEmpty(eMusico* musicos,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(musicos[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la musicos
 * \param eEmployee empleado, musicos de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int musico_findById(eMusico* musicos ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(musicos[i].isEmpty== ESTADO_OCUPADO && musicos[i].idMusico== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 //-------------------------------------------------------------------------------
 int musico_findByIdOrquesta(eMusico* musicos,int cantidad,int idOrquesta)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(musicos[i].isEmpty== ESTADO_OCUPADO && musicos[i].idOrquesta==idOrquesta)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }
/** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, musicos de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int musico_remove(eMusico* musicos,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(musicos[i].idMusico==id)
             {
                 musicos[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 //-----------------------------------------------------------------------------------------------------
 int musico_removeByOrquesta(eMusico* musicos,int cantidad,int idOrquesta)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(musicos[i].idOrquesta==idOrquesta)
             {
                 musicos[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }

 /** \brief da por alta a un empleado en la musicos de eEmpleados
 * \param eEmployee empleado, musicos de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int musico_add(eMusico* musicos,eInstrumento* instrumentos, eOrquesta* orquestas,int cantidadMusicos, int cantidadInstrumentos,int cantidadOrquesta)
{
    int posicionAux,retorno=-1, auxEdad;

    if(cantidadMusicos>=0)
    {
        posicionAux= musico_findIsEmpty(musicos,cantidadMusicos);

        if(posicionAux!=-1)
        {   musicos[posicionAux].idMusico= musico_array_generarProximoId();
            getValidString("INGRESE NOMBRE DEL MUSICO:\n","\tERROR\nCARACTER NO VALIDO",musicos[posicionAux].nombre);
            getValidString("INGRESE APELLIDO DEL MUSICO:\n","\tERROR\nCARACTER NO VALIDO",musicos[posicionAux].apellido);
            auxEdad=getValidIntOpcion("INGRESE EDAD:\n", "\tERROR\nCARACTER NO VALIDO, LA EDAD DEBE ENCONTRARSE ENTRE 18 Y 100",18, 100);
            musicos[posicionAux].edad= auxEdad;
            system("cls");
            printf("ID\tNOMBRE\tTIPO\tLUGAR\n");
            orquesta_listar(orquestas,cantidadOrquesta);
            musicos[posicionAux].idOrquesta= getValidIntOpcion("ESCOGA ID DE ORQUESTA\n","ERROR\nID NO VALIDO",0,cantidadOrquesta);
            system("cls");
            printf("ID\tNOMBRE\n");
            instrumento_listar(instrumentos, cantidadInstrumentos);
            musicos[posicionAux].idInstrumento=getValidIntOpcion("ESCOGA ID DE INSTRUMENTO", "ERROR\n ID NO VALIDO", 0, cantidadInstrumentos);
            musicos[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO MUSICO\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la musicos de empleados
 * \param eEmployee empleado, musicos de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void musico_hardcodearDatos(eMusico* musicos , int cantidad)
{
    int i;
    char nombre[][50]= {"Mus1","Mus2","Mus3","Mus4","Mus5","Mus5"};
     char apellido[][50]= {"Amus1","Amus2","Amus3","Amus4","Amus5","Amus6"};
    int edad[]= {30,20,25,27,22,35};
    int idOrquesta[]= {1,2,4,4,1,3};
    int idInstrumento[]= {2,5,2,1,3,4};
    for(i=0; i<cantidad; i++)
    {

        musicos[i].idMusico=musico_array_generarProximoId();
        musicos[i].idInstrumento= idInstrumento[i];
        musicos[i].idOrquesta= idOrquesta[i];
        musicos[i].edad=edad[i];
        strcpy(musicos[i].apellido,apellido[i]);
        strcpy(musicos[i].nombre,nombre[i]);
        musicos[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la musicos
 * \param eEmployee empleado, musicos de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int musico_modificar(eMusico* musicos,eInstrumento* instrumentos,eOrquesta* orquestas, int cantidadMusicos,int cantidadInstrumentos,int cantidadOrquestas,int id)
{
    int idAux,retorno=-1,opcion, idAuxOrquesta, idAuxInstrum,auxOrques,auxEd;

    idAux= musico_findById(musicos,cantidadMusicos,id);
    idAuxOrquesta= musicos[idAux].idOrquesta;
    idAuxInstrum= musicos[idAux].idInstrumento;
    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-EDAD\n2-ORQUESTA\n3-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,3);

            switch(opcion)
            {
            case 1:
                system("cls");
                auxEd=getValidIntOpcion("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO, LA EDAD DEBE ENCONTRARSE ENTRE 18 Y 100\n",18,100);
                musicos[idAux].edad= auxEd;
                break;

            case 2:
                system("cls");
                printf("ID\tNOMBRE\tTIPO\tLUGAR\n");
                orquesta_listar(orquestas, cantidadOrquestas);
                auxOrques=getValidIntOpcion("INGRESE ID DE ORQUESTA\n", "\tERROR\nCARACTER NO VALIDO\n",0, cantidadOrquestas);
                musicos[idAux].idOrquesta= auxOrques;
                break;
            }

        }while(opcion!=3);

        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una autores de autor
 * \param eAutor, autores de autor
 * \param int cantidad de array
 * \return void
 */
void musico_listar(eMusico* musicos,int cantidad)
{
    int i;

    printf("ID MUSICO\tEDAD\tNOMBRE\tAPELLIDO\tID INSTRUMENTO\t ID ORQUESTA\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("%d\t%d\t%s\t%s\t%d\t%d\n",musicos[i].idMusico,musicos[i].edad,musicos[i].nombre,musicos[i].apellido, musicos[i].idInstrumento, musicos[i].idOrquesta);
        }
    }
}



/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, musicos de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void musico_admin(eMusico* musicos,eInstrumento* instrumentos,eOrquesta* orquestas,int cantidadMusicos,int cantidadOrquestas, int cantidadInstrumentos)
{
    int opcion,idAux;
    do
    {
        system("cls");
        printf("\tMENU -MUSICOS-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            musico_add(musicos, instrumentos, orquestas, cantidadMusicos, cantidadInstrumentos, cantidadOrquestas);
            break;

        case 2://MODIFICAR LIBRO
            system("cls");
            printf("ID MUSICO\tNOMBRE\tAPELLIDO\tID INSTRUMENTO\t ID ORQUESTA\n");
            musico_listar(musicos,cantidadMusicos);
            idAux=getValidIntOpcion("\nINGRESE ID DE MUSICO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadMusicos);
            if(musico_modificar(musicos,instrumentos,orquestas,cantidadMusicos,cantidadInstrumentos,cantidadOrquestas,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID MUSICO\tNOMBRE\tAPELLIDO\tID INSTRUMENTO\t ID ORQUESTA\n");
            musico_listar(musicos,cantidadMusicos);
            idAux=getValidIntOpcion("\nINGRESE ID DE MUSICO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadMusicos);
            if(musico_remove(musicos,cantidadMusicos,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            system("cls");
            musico_listar(musicos,cantidadMusicos);
            getChar("");
            break;
        }

    }while(opcion!=5);
}

//--------------------------------------------------------------------------

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


//-----------------------------------------------------------------------------------
void musico_listar_Orquesta(eMusico* musicos,int cantidad,  int idOrquesta) //BIEN
{
    int i;

    printf("ID MUSICO\tEDAD\tNOMBRE\tAPELLIDO\tTIPO INSTRUMENTO\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
             if(musicos[i].idOrquesta==idOrquesta)
            {
                 printf("%d\t%d\t%s\t%s",musicos[i].idMusico,musicos[i].edad,musicos[i].nombre,musicos[i].apellido);
            switch(musicos[i].idInstrumento)
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
//---------------------------------------------------------
void musico_listar_Instrumento(eMusico* musicos,int cantidad) //BIEN
{
    int i;
    musicos_ordenar_Apellido(musicos, cantidad);
    printf("EDAD\tNOMBRE\tAPELLIDO\tTIPO INSTRUMENTO\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(musicos[i].isEmpty== ESTADO_OCUPADO)
        {
            if (musicos[i].idInstrumento==1)
            {
                 printf("%d\t%s\t%s",musicos[i].edad,musicos[i].nombre,musicos[i].apellido);
            switch(musicos[i].idInstrumento)
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

void musicos_ordenar_Apellido(eMusico* musicos,int cantidad)
{
    int i,j;
    eMusico aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(musicos[i].apellido,musicos[j].apellido)>0)
            {
                aux=musicos[i];
                musicos[i]=musicos[j];
                musicos[j]=aux;
            }
        }
    }
}



//-------------------------------


