# ifndef CUENTO_H
# define CUENTO_H


# include "Lectura.h"


class Cuento: public Lectura {

private:

    string libro_;

public:

    // PRE:
    // POST:
    Cuento(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, string libro);

    // PRE:
    // POST:
    string obtener_libro();

    // PRE:
    // POST:
    void mostrar_lectura();

    // PRE:
    // POST:
    bool coinciden_generos(int genero);

};


# endif