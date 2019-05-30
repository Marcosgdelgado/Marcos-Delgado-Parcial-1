#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "orquesta.h"
#include "utn.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"

#define QTY_TIPO 6

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

    instrumento_hardcodearDatos(arrayInstrumento,5, &contadorIdInstrumento);
    orquesta_hardcodearDatos(arrayOrquesta,4,&contadorIdOrquesta);
    harcodearMusicos(arrayMusico,6,&contadorIdMusico);



    do
    {
        utn_getUnsignedInt("\n\n*****MENU*****\n\n1) Altas:\n-Orquesta\n-Musico\n-Instrumento\n\n2)Modificar\n-Orquesta\n-Musico\n-Instrumento\n \n3) Baja: \n-Orquesta\n-Musico\n\n \n4) Listar:\n-Orquesta\n-Musico\n-Instrumento\n\n5) *INFORMES* \n\n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,9,1,&opcion);
        switch(toupper(opcion))
        {
            case 1: //Alta
                system("cls");
                utn_getChar("\nA) Alta orquesta\nB) Alta musico\nC) Alta instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_alta(arrayOrquesta,QTY_TIPO,&contadorIdOrquesta);
                        system("pause");
                        system("cls");
                         break;
                case 'B':
                        musico_alta(arrayMusico,QTY_TIPO,&contadorIdMusico,arrayOrquesta,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'C':
                        instrumento_alta(arrayInstrumento,QTY_TIPO,&contadorIdInstrumento);
                        system("pause");
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 2: //Modificar
                system("cls");
                utn_getChar("\nA) Modificar orquesta\nB) Modificar musico\nC) Modificar instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_modificar(arrayOrquesta,QTY_TIPO);
                        system("cls");
                         break;
                case 'B':
                        musico_modificar(arrayMusico,QTY_TIPO,arrayOrquesta,QTY_TIPO);
                        system("cls");
                         break;
                case 'C':
                        instrumento_modificar(arrayInstrumento,QTY_TIPO);
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 3: //Baja
                system("cls");
                utn_getChar("\nA) Baja orquesta\nB) Baja musico\nC) Baja instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        //orquesta_baja(arrayOrquesta,QTY_TIPO,QTY_TIPO);
                        bajaxOrquesta(arrayOrquesta,QTY_TIPO,arrayMusico,QTY_TIPO);
                        system("cls");
                         break;
                case 'B':
                        musico_baja(arrayMusico,QTY_TIPO,QTY_TIPO);
                        system("cls");
                         break;
                case 'C':
                        instrumento_baja(arrayInstrumento,QTY_TIPO,QTY_TIPO);
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 4://Listar
                system("cls");
                utn_getChar("\nA) Listar orquesta\nB) Listar musico\nC) Listar instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_listar(arrayOrquesta,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'B':
                        musico_listar(arrayMusico,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'C':
                        instrumento_listar(arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 5:
                system("cls");
                utn_getChar("\nA) Musicos de mas 30 años\nB) Informar orquestas por musicos\nC) Listar orquestas por lugar\nD) Listar por orquesta\nE) Imprimir cuerdas\nF) Orquestas con mas de 5 musicos\nG) Orquestas con mas musicos\nH) Imprimir promedio\nS)Menu anterior\n",
                            "*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                    case 'A':
                    system("cls");
                        musicos_MAStreinta(arrayMusico,QTY_TIPO,arrayOrquesta,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'B':
                    system("cls");
//                        informar_OrquestaXmusicos(arrayMusico,QTY_TIPO,arrayOrquesta,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'C':
                    system("cls");
                        ListarxLugar(arrayOrquesta,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'D':
                    system("cls");
                        listarXorquesta(arrayMusico,QTY_TIPO,arrayOrquesta,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'E':
                    system("cls");
                        imprimirCuerdas(arrayInstrumento,QTY_TIPO,arrayMusico,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'F':
                    system("cls");
                        orquestas_CincoMusicos(arrayMusico,QTY_TIPO,arrayMusico,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'G':
                    system("cls");
                        orquesta_conMasMusicos(arrayInstrumento,QTY_TIPO,arrayMusico,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    case 'H':
                    system("cls");
                        promedioMusicosXorquesta(arrayOrquesta,QTY_TIPO,arrayMusico,QTY_TIPO);
                    system("pause");
                    system("cls");
                    break;
                    //Informes_listarPorCriterio(arrayMusico,arrayOrquesta,QTY_TIPO,QTY_TIPO,&contadorIdMusico);
                    case 'S':
                            break;
                    default:
                        printf("\nOpcion incorrecta\n");
                }
            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
