#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
typedef struct
{
    char nombre[31];
    int tipo;
    int idInstrumentos;
    int isEmpty;

}eInstrumento;


#endif // INSTRUMENTO_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
int instrumento_array_generarProximoId(void);
int instrumento_init(eInstrumento* ,int );
int instrumento_findIsEmpty(eInstrumento* ,int );
int instrumento_findById(eInstrumento*  ,int ,int);
int instrumento_remove(eInstrumento* ,int ,int );
int instrumento_add(eInstrumento* ,int );




void instrumento_hardcodearDatos(eInstrumento*, int );
int instrumento_modificar(eInstrumento* , int ,int );
void instrumento_listar(eInstrumento* ,int );
void instrumento_admin(eInstrumento* ,int );
void instrumento_ordenar(eInstrumento* ,int );

