# ifndef NOVELA_H
# define NOVELA_H


# include "Lectura.h"


enum generos {
    DRAMA = 1,
    COMEDIA,
    FICCION,
    SUSPENSO,
    TERROR,
    ROMANTICA,
    HISTORICA
};


class Novela: public Lectura {

protected:

    generos genero_;

public:

    // PRE:
    // POST:
    Novela(string titulo, unsigned int minutos, unsigned int anio, Escritor* autor, generos genero);

    // PRE:
    // POST:
    generos obtener_genero();

    // PRE:
    // POST:
    void mostrar_lectura();

    // PRE:
    // POST:
    string convertir_a_string_genero();

    // PRE:
    // POST:
    bool coinciden_generos(int genero);

};


# endif