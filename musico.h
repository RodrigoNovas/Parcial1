#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
typedef struct
{
    int idMusico;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
    char nombre[31];
    char apellido[31];
    int edad;
}eMusico;
#endif // MUSICO_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
/*#include "orquesta.h"
#include "instrumento.h"
#include "funcionesGet.h"
#include "INFORMES.h"

int musico_array_generarProximoId(void);

int musico_init(eMusico* ,int);

int musico_findIsEmpty(eMusico*,int );


 int musico_findByIdOrquesta(eMusico*,int ,int );

 int musico_remove(eMusico*,int ,int );

  int musico_removeByOrquesta(eMusico*,int ,int );

  int musico_add(eMusico*,eInstrumento* , eOrquesta* ,int , int ,int );


  void musico_hardcodearDatos(eMusico* , int );


  void musico_hardcodearDatos(eMusico* , int );

  void musico_listar(eMusico*, eInstrumento* ,int , int );

  void musico_admin(eMusico*,eInstrumento* ,eOrquesta* ,int ,int , int );

  void musicos_ordenar_Apellido(eMusico*,int );*/
