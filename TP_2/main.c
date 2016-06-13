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
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                AgregarPersona(Lista);
                break;

            case 2:
                BorrarPersona(Lista);
                break;

            case 3:
                ImprimirLista(Lista);
                break;

            case 4:
                ImprimirGrafico(Lista);
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
