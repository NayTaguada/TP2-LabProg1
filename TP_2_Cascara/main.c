#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"

#define VACIO 0
#define LLENO 1
#define BAJA -1
#define VECTOR 5

int main()
{
    char seguir = 's';
    int opcion=0;
    int pAgregar=0;
    int pBorrar=0;
    char pBaja;

    gEdades cPersonas;

    EPersona inicio[VECTOR];
    iniciarVector(inicio);


    while(seguir =='s'){

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Cuantas personas desea ingresar?\n");
                scanf("%d",&pAgregar);
                agregarPersona(inicio,pAgregar);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Cuantas personas desea borrar?\n");
                scanf("%d",&pBorrar);
                borrarPersonas(inicio,pBorrar);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Desea incluir los nombres dados de bajo? S para si/N para no");
                scanf("%c",&pBaja);
                listaxNombres(inicio,pBaja);
                system("pause");
                system("cls");
                break;
            case 4:
                cPersonas = personasGrupos(inicio);
                graficoEdades(cPersonas);
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
