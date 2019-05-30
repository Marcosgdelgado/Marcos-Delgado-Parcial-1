#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
/*int Informes_listarPorCriterio(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
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
}*/


int musicos_MAStreinta(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[], int sizeIns)
{
    int retorno=-1;
    int i;
    int j;
    int m;

    if(arrayMusico!=NULL && sizeMusico>=0)
    {
        for(i=0;i<sizeMusico;i++)
        {
           if(arrayMusico[i].edadMusico > 30 && arrayMusico[i].isEmpty==0)
           {
               for(j=0;j<sizeOrquesta;j++)
               {
                   if(arrayMusico[i].idOrquesta== arrayOrquesta[j].idOrquesta)
                   {
                        for(m=0;m<sizeIns;m++)
                        {
                            if(arrayMusico[i].idInstrumento==arrayInstrumento[m].idInstrumento)
                            {
                                printf("\nID Musico: %d\nNombre: %s\nApellido: %s\nEDAD: %d\nInstrumento: %s\nOrquesta: %s\n\n"
                                       , arrayMusico[i].idMusico, arrayMusico[i].varString,arrayMusico[i].varLongString,
                                        arrayMusico[i].edadMusico,arrayInstrumento[m].varString, arrayOrquesta[j].varString);
                            }
                        }
                   }
               }

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
     if(arrayMusico!=NULL && sizeMusico>=0)
    {
            utn_getUnsignedInt("Ingrese ID","Error",1,sizeof(int),1,sizeMusico,3,&id);

    retorno =0;
    }
    return retorno;
}*/
int ListarxLugar(Orquesta arrayOrquesta[], int size)
{
    int retorno= -1;
    int i;
    char lugar[100];

    orquesta_listar(arrayOrquesta,size);
    utn_getTexto("\nIngrese lugar:\n","Error!",1,100,2,lugar);

    for(i=0;i<size;i++)
    {
        if(arrayOrquesta[i].isEmpty==0)
        {
            if(!strcmp(arrayOrquesta[i].varLongString,lugar))
            {
                printf("\nIDOrquesta  Nombre    Tipo  Lugar\n %d       %s       %d     %s\n",
                        arrayOrquesta[i].idOrquesta,arrayOrquesta[i].varString,arrayOrquesta[i].tipoOrquesta,
                        arrayOrquesta[i].varLongString);
            }

        }
    }
    return retorno;
}
int listarXorquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno=-1;
    int auxId;
    int posicion;
    int i;
    int j;

    orquesta_listar(arrayOrquesta,sizeOrquesta);
    utn_getSignedInt("\nIngrese ID orquesta:\n","\nERROR!!\n",1,sizeof(int),1,sizeOrquesta,2,&auxId);
    if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxId,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
    else
    {
       for(i=0;i<sizeMusico;i++)
       {
           if(arrayMusico[i].idOrquesta==auxId)
           {
               for(j=0;j<sizeInstrumento;j++)
               {
                   if(arrayMusico[i].idInstrumento==arrayInstrumento[j].idInstrumento)
                   {
                                      printf("\nMUSICO\nNombre: %s\nApellido: %s\nEdad: %d\nINSTRUMENTO\nNombre: %s\nTipo: ",
                   arrayMusico[i].varString,arrayMusico[i].varLongString,arrayMusico[i].edadMusico,arrayInstrumento[j].varString,arrayMusico[i].idInstrumento);
                            switch(arrayMusico[i].idInstrumento)
                            {
                                case 1:
                                printf("Cuerdas\n");
                                break;
                                case 2:
                                printf("Viento-Madera\n");
                                break;
                                case 3:
                                printf("Viento-Metal\n");
                                break;
                                case 4:
                                printf("Percusion\n");
                                break;

                                default:
                                    printf("Opcion incorrecta.\n");
                            }
                   }
               }

           }
       }
        retorno=0;
    }
   return retorno;
}

int imprimirCuerdas(Instrumento arrayInstrumento[],int sizeInstrumento,Musico arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int i;
    int j;
    for(i=0;i<sizeInstrumento;i++)
    {
        if(arrayInstrumento[i].tipoInstrumento==1)
        {
            for(j=0;j<sizeMusico;j++)
            {
                if(arrayInstrumento[i].idInstrumento==arrayMusico[j].idInstrumento)
                {
                    musico_ordenarPorString(arrayMusico,sizeMusico);
                    printf("\nMUSICO\nNombre: %s\nApellidos: %s\nEdad: %d\nINSTRUMENTO\nNombre: %s\nTipo:Cuerda\n",
                           arrayMusico[j].varString,arrayMusico[j].varLongString,
                           arrayMusico[j].edadMusico, arrayInstrumento[i].varString);
                }
            }

            retorno=0;
        }

    }

    return retorno;
}



//A)listar orquesta con mas de 5 musicos, imprimir id orquesta, nombre, tipo y lugar
int orquestas_CincoMusicos(Orquesta arrayOrquestas[], int sizeOrquesta,Musico arrayMusicos[], int sizeMusico)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;

    for(i=0;i<sizeMusico-1;i++)
    {
        if(arrayMusicos[i].isEmpty==0)
        {
            for(j=i+1;j<sizeMusico;j++)
            {
                if(arrayMusicos[j].isEmpty==0)
                {
                    if(arrayMusicos[i].idOrquesta== arrayMusicos[j].idOrquesta)
                    {
                        contador++;
                        if(contador>=5)
                        {
                            printf("\nID: %d\nNombre: %s\nTipo: %d\nLugar: %s\n",arrayOrquestas[i].idOrquesta,arrayOrquestas[i].varString,
                                   arrayOrquestas[i].tipoOrquesta, arrayOrquestas[i].varLongString);
                                   retorno=0;
                        }
                    }
                }
            }
        }
    }

return retorno;
    }

//D)una orquesta se encuentra comleta si posee un total de 5 cuerdas, 3 de viento y 2 de percusion, Listar orquestas completas
int orquesta_completa(Orquesta arrayOrquesta[],Musico arrayMusico[],Instrumento arrayInstrumento[],int sizeOrquesta,int sizeMusico,int sizeInstrumento)
{
    int auxMusico;
    int auxOrquesta;
    int auxInstrumento;
    int retorno=-1;
    int i;
    int j;
    int m;

   /* for(i=0; i < sizeMusico; i++)
    {
        if()
    }
*/

}
//F)imprimir oquesta con mas musicos, indicando todos sus datos y la cantidad de musicos que posee
int orquesta_conMasMusicos(Orquesta arrayOrquestas[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico)
{
    int retorno=-1;
    int i;
    int j;
    int auxID=0;



        for(i=0;i<sizeMusico-1;i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                for(j=i+1;j<sizeMusico;j++)
                {
                    if(arrayOrquestas[j].isEmpty==0)
                    {
                        if(arrayMusico[i].idOrquesta == arrayMusico[j].idOrquesta)
                        {
                            auxID++;
                            printf("\nID ORQUESTA: %d\nContador: %d\n",arrayMusico[i].idOrquesta, auxID);
                            retorno=0;
                        }

                    }
                 }
            }
        }
         //retorno=0;
return retorno;
}
//H)Imprimir promedio de musicos por orquestas
int promedioMusicosXorquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico)
{
    //int retorno=-1;
    int i;
    int j;
    float contadorMusico=0;
    float contadorOrquesta=0;
    float auxResultado;

    if(arrayMusico!=NULL && sizeMusico>=0)
    {

            for(i=0;i<sizeMusico;i++)
            {
                if(arrayMusico[i].isEmpty==0)
                {
                    contadorMusico++;
                }
            }
    }
        if(arrayOrquesta!=NULL && sizeOrquesta>=0)
    {
        for(j=0;j<sizeOrquesta;j++)
        {
            if(arrayOrquesta[j].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        //retorno=0;
    }
    auxResultado=contadorMusico/contadorOrquesta;

    printf("\nEl promedio de musicos por orquestas es: %.2f\ncontador musico: %.2f\ncontador orquesta: %.2f\n",auxResultado,contadorMusico,contadorOrquesta);

return 0;
}




