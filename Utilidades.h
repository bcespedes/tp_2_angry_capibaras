# ifndef UTILIDADES_H
# define UTILIDADES_H


# include "Lectura.h"


class Utilidades {

public:

    //PRE:
    //POST:
    Utilidades();

    //PRE:
    //POST:
    void limpiar_pantalla();

    //PRE:
    //POST:
    bool validar_opcion(int opcion, int opcion_max);

    //PRE:
    //POST:
    int validar_entero(int a_validar, string instruccion, int valor_minimo);

    //PRE:
    //POST
    void insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura *>* lista_lectura);

};


# endif