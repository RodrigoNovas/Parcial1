#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
typedef struct
{
    int idOrquestas;
    int isEmpty;
    char nombre[31];
    char lugar [31];
    int tipo;
}eOrquesta;


#endif // ORQUESTA_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "musico.h"
int orquesta_array_generarProximoId(void);
int orquesta_init(eOrquesta* ,int );
int orquesta_findIsEmpty(eOrquesta* ,int );
int orquesta_findById(eOrquesta*  ,int ,int);
int orquesta_remove(eOrquesta* ,int ,int );
int orquesta_add(eOrquesta* ,int );




void orquesta_hardcodearDatos(eOrquesta*, int );
int orquesta_modificar(eOrquesta* , int ,int );
void orquesta_listar(eOrquesta* ,int );
void orquesta_admin(eOrquesta*, eMusico* ,int, int);
void orquesta_ordenar(eOrquesta*, int );
