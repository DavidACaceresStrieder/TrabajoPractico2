#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona Lista[20];

    Inicializar(Lista);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                AgregarPersona(Lista);
                break;

            case 2:
                system("cls");
                BorrarPersona(Lista);
                break;

            case 3:
                system("cls");
                ImprimirLista(Lista);
                break;

            case 4:
                system("cls");
                ImprimirGrafico(Lista);
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
