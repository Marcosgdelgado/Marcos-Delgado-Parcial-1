#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


int musicos_MAStreinta(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],int sizeOrquesta,
                        Instrumento arrayInstrumento[], int sizeIns);

int ListarxLugar(Orquesta arrayOrquesta[], int size);

int listarXorquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,
                    Instrumento arrayInstrumento[],int sizeInstrumento);

int imprimirCuerdas(Instrumento arrayInstrumento[],int sizeInstrumento,Musico arrayMusico[], int sizeMusico);

int orquestas_CincoMusicos(Orquesta arrayOrquestas[], int sizeOrquesta,Musico arrayMusicos[], int sizeMusico);

int orquesta_conMasMusicos(Orquesta arrayOrquestas[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico);

int orquesta_completa(Orquesta arrayOrquesta[],Musico arrayMusico[],Instrumento arrayInstrumento[],
                      int sizeOrquesta,int sizeMusico,int sizeInstrumento);

int promedioMusicosXorquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico);

#endif // INFORMES_H_INCLUDED
