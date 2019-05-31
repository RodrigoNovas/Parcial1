#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "musico.h"
#include "instrumento.h"
#include "funcionesGet.h"
#include "orquesta.h"


void musico_listar_Edad(eMusico* ,int );

void musico_listar_Instrumento(eMusico* , eInstrumento* ,int , int );

void musico_listar_Orquesta(eMusico* ,eInstrumento* ,int ,  int , int );

void orquesta_listar_Lugar(eOrquesta* ,int );

int inf_orquestaMasMusicos(eOrquesta* ,int ,eMusico* ,int );

int inf_orquestaMayor5(eOrquesta* , eMusico*, int , int );

int inf_orquestasCompletas(eOrquesta* , eMusico* , eInstrumento* , int , int , int );

int informes_promedioDeInstrumentos(eMusico* , eOrquesta* ,  int , int );

void informes_admin(eMusico* ,eInstrumento* ,eOrquesta*  , int ,int , int );
