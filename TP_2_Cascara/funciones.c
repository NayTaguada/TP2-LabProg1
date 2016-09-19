#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>

#define VACIO 0

void iniciarVector (EPersona inicio[]){
    int i;
    for(i = 0; i<20; i++){
        inicio[i].estado = VACIO;
        printf("El vector es: %d\n", inicio[i].estado);
    }
}

