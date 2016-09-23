#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

typedef struct{

    int menor18;
    int de19a35;
    int mayor35;

}gEdades;


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);

void iniciarVector (EPersona inicio[]);

void agregarPersona (EPersona inicio[],int personas);

void borrarPersonas(EPersona inicio[], int personas);

void listaxNombres(EPersona inicio[],char orden);

gEdades personasGrupos(EPersona inicio[]);

void graficoEdades(gEdades cPersonas);

char vLargoDeString(EPersona inicio[],int i);

char pasarAMayus(char letra);

char verificarEdad(EPersona inicio[],int i);

char validarDNI(EPersona inicio[],int i);

int funcionMenu (int opcion);

#endif // FUNCIONES_H_INCLUDED
