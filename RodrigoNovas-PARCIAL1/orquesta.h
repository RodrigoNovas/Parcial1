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
