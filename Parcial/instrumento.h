#ifndef instrumento_H_INCLUDED
#define instrumento_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idInstrumento;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    int tipoInstrumento;
//    float varFloat;
//    char varChar;
    char varLongString[TEXT_SIZE];

}Instrumento;


#endif // instrumento_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);
//int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_baja(Instrumento array[], int size, int sizeLista);
//int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int size);
int instrumento_ordenarPorString(Instrumento array[],int size);
int instrumento_listar(Instrumento array[], int size);
void instrumento_hardcodearDatos(Instrumento array[], int size, int *contadorID);
