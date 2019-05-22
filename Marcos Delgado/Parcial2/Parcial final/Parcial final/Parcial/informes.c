#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h" //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && arrayOrquesta>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeMusico;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayMusico[i].isEmpty==1 && strcmp(arrayMusico[i].varString,criterio)!=0)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            else
            {
                musico_buscarID(arrayOrquesta,arrayOrquesta,arrayMusico[i].idMusico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID Musico: %d\nID Orquesta: %d",
                       arrayMusico[i].idMusico,arrayOrquesta[j].idOrquesta);
            }
        }
        retorno=0;
    }
    return retorno;
}


int informar_OrquestaXmusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[], int sizeIns)
{
    int retorno=-1;
    int contador=0;
    int i;
    int j;

    if(arrayMusico!=NULL && sizeMusico>=0)
    {
        for(i=0;i<sizeMusico;i++)
        {
           if(arrayMusico[i].edadMusico > 30 && arrayMusico[i].isEmpty==0)
           {
               printf("\nID   Nombre  Apellido    EDAD  Instrumento     Orquesta\n %d   %s      %s          %d     %d\n", arrayMusico[i].idMusico, arrayMusico[i].varString,
                                                                                        arrayMusico[i].varLongString, arrayMusico[i].edadMusico,arrayMusico[i].idInstrumento,arrayMusico[i].idOrquesta);
           retorno = 0;
           }

        }
    }
    return retorno;
}

/*
int informar_masMusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],int sizeOrquesta,Instrumento arrayInstrumento[], int sizeIns)
{
    int retorno=-1;
    int id;
    int i;
    int auxId;
     if(arrayMusico!=NULL && sizeMusico>=0)
    {

            utn_getUnsignedInt("Ingrese ID","Error",1,sizeof(int),1,sizeMusico,3,&id);
            if(musico_buscarID(arrayMusico,sizeMusico,id,&i)==-1)
            {
                printf("no existe");
            }else
            {
                printf("encontro");
            }

        for(i=0;i<sizeMusico;i++)
        {


        }
    retorno =0;
    }
    return retorno;
}
*/
