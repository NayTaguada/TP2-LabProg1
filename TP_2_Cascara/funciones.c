#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define VACIO 0
#define LLENO 1
#define BAJA -1
#define VECTOR 5

char vLargoDeString(EPersona inicio[],int i){

    int aux;
    char retorno;
    inicio[i].nombre;

    aux = strlen(inicio[i].nombre);

    if (aux > 50){
        retorno = 'n';
        return retorno;
    }
}

char pasarAMayus(char letra){
    char retorno;
    retorno = toupper(letra);
    return retorno;
}

char verificarEdad(EPersona inicio[],int i){

    char retorno;
    if(inicio[i].edad < 1 || inicio[i].edad > 100){
        retorno = 'n';
        return retorno;
    }
}

char validarDNI(EPersona inicio[],int i){
    char retorno;
    if(inicio[i].dni<1000000 || inicio[i].dni>99999999){
         retorno = 'n';
         return retorno;
    }/*else{
    retorno = 's';
    return retorno;
    }*/
}

void iniciarVector (EPersona inicio[]){
    int i;
    for(i = 0; i<VECTOR; i++){
        inicio[i].estado = VACIO;
    }
}

void agregarPersona (EPersona inicio[],int personas){
    int i;
    char auxNombre,auxDni,auxEdad;
    char rtaNombre = 'S';
    char dniRta = 'S';
    char rtaEdad = 'S';
    for(i=0;i<personas;i++){
        if(inicio[i].estado == 0){
            //Validacion nombre
            do{
            printf("Ingrese el nombre N %d:\n",i);
            fflush(stdin);
            gets(inicio[i].nombre);
            auxNombre = vLargoDeString(inicio,i);
                if (auxNombre == 'n'){
                    printf("Es un nombre muy largo, desea ingresar nuevamente? S/N \n");
                    scanf("%c",&rtaNombre);
                    rtaNombre = pasarAMayus(rtaNombre);
                }else{
                    break;
                }
                    if(rtaNombre == 'N'){
                        return 0;
                    }

            }while(rtaNombre == 'S');

            //Validacion DNI
            while(dniRta == 'S'){
                printf("Ingrese el dni\n");
                scanf("%d",&inicio[i].dni);
                auxDni = validarDNI(inicio,i);
                if(auxDni == 'n'){
                    printf("Ese no es un dni valido. Desea ingresarlo nuevamente? S/N \n");
                    fflush(stdin);
                    scanf("%c",&dniRta);
                    dniRta = pasarAMayus(dniRta);
                    if(dniRta == 'N'){
                        return 0;
                    }
                }else{
                    break;
                }

            }

            //Validacion edad

            do{
                printf("Ingrese edad\n");
                scanf("%d",&inicio[i].edad);
                auxEdad = verificarEdad(inicio,i);
                if(auxEdad == 'n'){
                    printf("Esa no es una edad válida.\n");
                    printf("Desea ingresarlo nuevamente? S/N\n");
                    fflush(stdin);
                    scanf("%c",&rtaEdad);
                    rtaEdad = pasarAMayus(rtaEdad);
                }else{
                    break;
                }
                    if(rtaEdad == 'N'){
                        return 0;
                    }
            }while(rtaEdad == 'S');

            inicio[i].estado = 1;
            system("pause");
        }
    }
}

gEdades personasGrupos(EPersona inicio[]){

    int i;
    gEdades cPersonas;
    cPersonas.menor18=0;
    cPersonas.de19a35=0;
    cPersonas.mayor35=0;

    for(i=0;i<VECTOR;i++){
        if(inicio[i].edad <= 18){
            cPersonas.menor18++;
        }else if(inicio[i].edad > 18 && inicio[i].edad < 36){
            cPersonas.de19a35++;
        }else if(inicio[i].edad > 35){
        cPersonas.mayor35++;
        }
    }

    return cPersonas;

}

void borrarPersonas(EPersona inicio[], int personas){
    int i;
    char rta;
    for(i=0;i<personas;i++){
        printf("Ingrese S para borrar a: %s con DNI:%d o N para dejarlo\n",inicio[i].nombre,inicio[i].dni);
        scanf("%c",&rta);
        rta = pasarAMayus(rta);
        if(rta == 'S'){
            printf("%s ha sido borrado\n",inicio[i].nombre);
            inicio[i].estado = BAJA;
        }
    }
}

void listaxNombres(EPersona inicio[],char orden){
    int i,j;
    EPersona keeper;
    for(i=0;i<VECTOR-1;i++){
        for(j=i+1;j<VECTOR;j++){
            if((strcmp(inicio[i].nombre,inicio[j].nombre))>0){
            keeper=inicio[i];
            inicio[i]=inicio[j];
            inicio[j]=keeper;
            }
        }
    }

    if(orden == 'S') {
        for(i=0;i<VECTOR;i++){
            if(inicio[i].estado == LLENO && inicio[i].estado == BAJA){
                printf("Nombre:%s DNI:%d Edad: %d\n",inicio[i].nombre,inicio[i].edad,inicio[i].dni);
            }

        }
    }
    if(orden == 'N'){
        for(i=0;i<VECTOR;i++){
            if(inicio[i].estado == LLENO){
                printf("Nombre:%s DNI:%d Edad: %d\n",inicio[i].nombre,inicio[i].edad,inicio[i].dni);
            }

        }
    }

}

void graficoEdades(gEdades cPersonas){

int i;
int mayor;
int flag;
cPersonas.menor18;
cPersonas.de19a35;
cPersonas.mayor35;

    if(cPersonas.menor18 >= cPersonas.de19a35 && cPersonas.menor18 >= cPersonas.mayor35){
        mayor = cPersonas.menor18;
    }else{
        if(cPersonas.de19a35 >= cPersonas.menor18 && cPersonas.de19a35 >= cPersonas.mayor35)
        {
            mayor = cPersonas.de19a35;
        }
        else{
        mayor = cPersonas.mayor35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= cPersonas.menor18){
            printf("*");
        }
        if(i<= cPersonas.de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= cPersonas.mayor35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }

printf("--+-----------------");
printf("\n  |<18\t19-35\t>35");
printf("\n   %d\t%d\t%d\n", cPersonas.menor18, cPersonas.de19a35, cPersonas.mayor35);


}
