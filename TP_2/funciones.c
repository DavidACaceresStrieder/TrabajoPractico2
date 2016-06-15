#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

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
int AgregarPersona(EPersona lista[]){
    int i,auxint=-1;

    for(i=0;i<20;i++){
        if(lista[i].estado==0){
            break;
        }
        if(i==20){
            printf("Lista LLena");
            return 0;
        }
    }

    system("cls");
    printf("Ingresar Nombre: \n");
    fflush(stdin);
    gets(lista[i].nombre);


    printf("Ingresar edad: \n");
    while(auxint==-1){
        scanf("%i",&auxint);
        if(auxint>0 && auxint<110){
            lista[i].edad=auxint;
        }
        else{
            printf("Error:edad no valida, reingrese: \n");
            auxint=-1;
        }
    }


    printf("Ingresar DNI: \n");
    auxint=-1;
    while(auxint==-1){
        scanf("%i",&auxint);
        if(auxint<14000000){
            printf("Error:edad no valida, reingrese: \n");
            auxint=-1;
        }
        if(auxint>99999999){
            printf("Error:edad no valida, reingrese: \n");
            auxint=-1;
        }
    }
    lista[i].dni=auxint;
    lista[i].estado=1;
    return 1;
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
            if(lista[i].edad<=18){
                grup1++;
            }
            if(lista[i].edad<=35 && lista[i].edad>18){
                grup2++;
            }
            if(lista[i].edad>35){
                grup3++;
            }
        }
    }

    max=grup1;

    if(grup2>max){
        max=grup2;
    }
    if(grup3>max){
        max=grup3;
    }


    for(i=max;i>0;i--){

        if(i<=grup1){
            printf("*\t");
        }
        else{
            printf("\t");
        }

        if(i<=grup2){
            printf("*\t");
        }
        else{
            printf("\t");
        }

        if(i<=grup3){
            printf("*\n");
        }
        else{
            printf("\n");
        }
    }
    system("pause");
}

void ImprimirLista(EPersona lista[]){

    EPersona aux;
    int i,j;

    for(i=0;i<20;i++){
        for(j=i+1;j<19;j++){
            if(lista[i].estado==1 && lista[j].estado==1){
                if(lista[i].edad==lista[j].edad){
                    if(strcmp(lista[i].nombre,lista[j].nombre!=0)){
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                    else{
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                }
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
    system("pause");
}
