#ifndef NOVELA_H
#define NOVELA_H

#include "lectura.h"
//#include "historica.h"

enum generos{
    DRAMA,
    COMEDIA,
    FICCION,
    SUSPENSO,
    TERROR,
    ROMANTICA,
    HISTORICA
};

class Novela: public Lectura{
protected:
    generos genero_;
public:
    Novela(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, generos genero);
    generos obtener_genero();
    void mostrar_lectura();
    generos convertir_a_genero(string genero);
};

#endif