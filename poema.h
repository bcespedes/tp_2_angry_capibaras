#ifndef POEMA_H
#define POEMA_H


#include "lectura.h"


class Poema: public Lectura {

private:

    int versos_;

public:

    // PRE:
    // POST:
    Poema(string titulo, unsigned int minutos, unsigned int anio, Escritor* autor, int versos);

    // PRE:
    // POST:
    int obtener_versos();

    // PRE:
    // POST:
    void mostrar_lectura();

    // PRE:
    // POST:
    bool coinciden_generos(int genero);
    
};


#endif