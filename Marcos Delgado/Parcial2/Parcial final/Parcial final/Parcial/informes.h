#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



int Informes_listarPorCriterio(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta, char* criterio);

int informar_OrquestaXmusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],
                              int sizeOrquesta, Instrumento arrayInstrumento[], int sizeIns);

int informar_masMusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],int sizeOrquesta,
                        Instrumento arrayInstrumento[], int sizeIns);

#endif // INFORMES_H_INCLUDED
