#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[]){
    int i;
    for(i=0;i<20;i++){
        if(lista[i].estado==0){
            return i;
        }
    }
}

int buscarPorDni(EPersona lista[], int dni){
    int i;
    for(i=0;i<20;i++){
        if(lista[i].dni==dni){
            return i;
        }
    }
}

void Inicializar(EPersona lista[]){
    int i;
    for(i=0;i<20;i++){
        lista[i].estado=0;
    }
}
void AgregarPersona(EPersona lista[]){
    int i;
    for(i=0;i<20;i++){
        if(lista[i].estado==0){
            break;
        }
    }
    printf("Ingresar Nombre: \n");
    fflush(stdin);
    gets(lista[i].nombre);
    lista[i].edad=-1;
    printf("Ingresar edad: \n");
    while(lista[i].edad==-1){
        scanf("%i",lista[i].edad);
        if(lista[i].edad<0){
            printf("Error:edad no valida, reingrese: \n");
            lista[i].edad=-1;
        }
        if(lista[i].edad>110){
            printf("Error:edad no valida, reingrese: \n");
            lista[i].edad=-1;
        }
    }

    printf("Ingresar DNI: \n");
    lista[i].dni==-1;
    while(lista[i].dni==-1){
        scanf("%i",lista[i].dni);
        if(lista[i].dni<14000000){
            printf("Error:edad no valida, reingrese: \n");
            lista[i].dni=-1;
        }
        if(lista[i].dni>99999999){
            printf("Error:edad no valida, reingrese: \n");
            lista[i].dni=-1;
        }
    }
    lista[i].estado=1;
}

void BorrarPersona(EPersona lista[]){
    char auxnombre[50];
    int i,val=0;

    printf("Ingrese el nombre de la persona a borrar: ");
    fflush(stdin);
    gets(auxnombre);
    for(i=0;i<20;i++){
        if(strcmp(auxnombre,lista[i].nombre)==0){
            val=1;
            lista[i].estado=0;
        }
    }
    if(val==1){
        printf("Persona Borrada exitosamente");
    }
    else{
        printf("Persona No encontrada");
    }
}

void ImprimirGrafico(EPersona lista[]){
    int i,max=0,grup1=0,grup2=0,grup3=0;
    for(i=0;i<20;i++){
        if(lista[i].estado==1){
            if(lista[i].edad<19){
                grup1++;
            }
            else{
                if(lista[i].edad<35){
                    grup2++;
                }
                else{
                    grup3++;
                }
            }
        }
    }
    for(i=max;i>max;i--){
        if(max<=grup1){
            printf("*");
        }
        else{
            printf("\t");
        }

        if(max<=grup2){
            printf("*");
        }
        else{
            printf("\t");
        }

        if(max<=grup3){
            printf("*");
        }
        else{
            printf("\t \n");
        }
    }

}

void ImprimirLista(EPersona lista[]){
    EPersona aux;
    int i,j;
    for(i=0;i<20;i++){
        for(j=i+1;j<19;j++){
            if(strcmp(lista[i].nombre,lista[j].nombre==1)){
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0;i<20;i++){
        if(lista[i].estado==1){
            printf("Nombre: %s \n",lista[i].nombre);
            printf("Edad: %i \n",lista[i].edad);
            printf("DNI: %i \n",lista[i].dni);
            printf("\n");
        }
    }
}
