#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;
            array[posicion].isEmpty=0;
//            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("\nALTA INSTRUMENTO\n\nNombre instrumento:\n ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getUnsignedInt("\nTipo de instrument:\n1- Cuerdas\n2-Viento-Madera\n3-Viento-Metal\n4-Percusion\n","\nError",1,sizeof(int),1,4,1,&array[posicion].tipoInstrumento);           //mensaje + cambiar campo varInt
            retorno=0;
        }
                printf("ALTA OK");
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray, int sizeLista)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        instrumento_listar(array,sizeLista);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumento=0;
            array[posicion].varInt=0;
//            array[posicion].varFloat=0;
            strcpy(array[posicion].varString,"");
            strcpy(array[posicion].varLongString,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idInstrumento==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idInstrumento=0;
                array[i].varInt=0;
//                array[i].varFloat=0;
                strcpy(array[i].varString,"");
                strcpy(array[i].varLongString,"");
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n ID: %d\n varInt: %d\n Nombre: %s\n Tipo: %s",
                       array[posicion].idInstrumento,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\nModificar INSTRUMENTO: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar
                        break;
 //                   case 'B':
 //                       utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("Modificar nombre:\n ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar
                        break;
                    case 'D':
                        utn_getTexto("Modificar tipo:\n ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
//    float bufferFloat;                                           buffer varFloat
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].varString);
            bufferId=array[i].idInstrumento;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].varInt;
//            bufferFloat=array[i].varFloat;
            strcpy(bufferLongString,array[i].varLongString);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)                           //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);
                array[j + 1].idInstrumento=array[j].idInstrumento;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].varInt=array[j].varInt;
//                array[j + 1].varFloat=array[j].varFloat;
                strcpy(array[j + 1].varLongString,array[j].varLongString);

                j--;
            }
            strcpy(array[j + 1].varString,bufferString);
            array[j + 1].idInstrumento=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].varInt=bufferInt;
//            array[j + 1].varFloat=bufferFloat;
            strcpy(array[j + 1].varLongString,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n Nombre instrumento: %s\nTipo: ",
                       array[i].idInstrumento,array[i].varString);
            switch(array[i].tipoInstrumento)
            {
                case 1:
                printf("Cuerdas\n");
//                system("pause");
                break;
                case 2:
                printf("Viento-Madera\n");
//                system("pause");
                break;
                case 3:
                printf("Viento-Metal\n");
//                system("pause");
                break;
                case 4:
                printf("Percusion\n");
//                system("pause");
                break;

                default:
                    printf("Opcion incorrecta.\n");

            }
        }
        retorno=0;
    }
    return retorno;
}
void instrumento_hardcodearDatos(Instrumento array[], int size, int *contadorID)
{
    int i;
    char nombres[][20]= {"Inst1","Inst2","Inst3","Inst4", "Inst5"};
    int tipo[]= {1,2,2,3,4};

    for(i=0; i<size; i++)
    {
        (*contadorID)++;
        array[i].idInstrumento= *contadorID;
        strcpy(array[i].varString,nombres[i]);
        array[i].tipoInstrumento= tipo[i];
        array[i].isEmpty=0;
    }
}
