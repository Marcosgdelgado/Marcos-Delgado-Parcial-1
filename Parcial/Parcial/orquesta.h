#ifndef orquesta_H_INCLUDED
#define orquesta_H_INCLUDED
#define TEXT_SIZE 20

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
//    float varFloat;
//    char varChar;
    char varLongString[TEXT_SIZE];
    int tipoOrquesta;

}Orquesta;


#endif // orquesta_H_INCLUDED

int orquesta_Inicializar(Orquesta arrayOrquesta[], int sizeOrquesta);                                    //cambiar Orquesta
int orquesta_buscarEmpty(Orquesta arrayOrquesta[], int sizeOrquesta, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarID(Orquesta arrayOrquesta[], int sizeOrquesta, int valorBuscado, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarInt(Orquesta arrayOrquesta[], int sizeOrquesta, int valorBuscado, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarString(Orquesta arrayOrquesta[], int sizeOrquesta, char* valorBuscado, int* indice);                    //cambiar Orquesta
int orquesta_alta(Orquesta arrayOrquesta[], int sizeOrquesta, int* contadorID);                          //cambiar Orquesta
int orquesta_baja(Orquesta arrayOrquesta[], int sizeArray, int sizeOrquesta);                                      //cambiar Orquesta
//int orquesta_bajaValorRepetidoInt(Orquesta arrayOrquesta[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta arrayOrquesta[], int sizeOrquesta);                                //cambiar Orquesta
int orquesta_ordenarPorString(Orquesta arrayOrquesta[],int sizeOrquesta);                              //cambiar Orquesta
int orquesta_listar(Orquesta arrayOrquesta[], int sizeOrquesta);                      //cambiar Orquesta
void orquesta_hardcodearDatos(Orquesta arrayOrquesta[], int sizeOrquesta, int* contadorID);
//int bajaxOrquesta(Orquesta arrayOrquesta[], int sizeOquesta,Musico arrayMusico[], int sizeMusico);
