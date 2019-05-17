#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "orquesta.h"
#include "utn.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    char submenu;
    int contadorIdOrquesta=0;

    int contadorIdMusico=0;

    int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[QTY_TIPO];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO);

    Musico arrayMusico[QTY_TIPO];
    musico_Inicializar(arrayMusico,QTY_TIPO);

    Instrumento arrayInstrumento[QTY_TIPO];
    instrumento_Inicializar(arrayInstrumento,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n*****MENU*****\n\n1) Altas:\n-Orquesta\n-Musico\n-Instrumento\n\n2)Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(toupper(opcion))
        {
            case 1: //Alta
                utn_getChar("\nA) Alta orquesta\nB) Alta musico\nC) Alta instrumento\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_alta(arrayOrquesta,QTY_TIPO,&contadorIdOrquesta);
                         break;
                case 'B':
                        musico_alta(arrayMusico,QTY_TIPO,&contadorIdMusico);
                         break;
                case 'C':
                        instrumento_alta(arrayInstrumento,QTY_TIPO,&contadorIdInstrumento);
                         break;
                }
                break;

            case 2: //Modificar
                orquesta_modificar(arrayOrquesta,QTY_TIPO);
                musico_modificar(arrayMusico,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                orquesta_baja(arrayOrquesta,QTY_TIPO,QTY_TIPO);
                musico_baja(arrayMusico,QTY_TIPO,QTY_TIPO);
                break;

            case 4://Listar
                orquesta_listar(arrayOrquesta,QTY_TIPO);
                musico_listar(arrayMusico,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
 //               orquesta_ordenarPorString(arrayOrquesta,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}

