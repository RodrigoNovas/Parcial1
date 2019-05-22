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

