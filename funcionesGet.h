#ifndef FUNCIONESGET_H_INCLUDED
#define FUNCIONESGET_H_INCLUDED

#endif // FUNCIONESGET_H_INCLUDED
int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);
void getString(char* mensaje,char* input);
int validarStringNumerico(char* stringNumerico);
int validarStringNumericoFlotante(char* stringNumerico);
int validarStringAlfaNumerico(char* stringNumerico);
int validarStringLetras(char* stringLetras);
int validarStringTelefonico(char* stringTelefono);
int getStringLetras(char* mensaje,char* input);
int getStringNumeros(char* mensaje,char* input);
int getStringNumerosFlotantes(char* mensaje, char* input);
int getValidInt(char* mensaje,char* mensajeError);
int getValidIntOpcion(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit);
float getValidFloat(char* mensaje,char* mensajeError);
void getValidString(char* mensaje,char* mensajeError,char* input);
void getValidStringAlfaNumerico(char* mensaje,char* mensajeError, char* input);
char getNumeroAleatorio(int desde, int hasta, int iniciar);

