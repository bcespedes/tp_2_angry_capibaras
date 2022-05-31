#ifndef NOVELA_H
#define NOVELA_H

#include "lectura.h"
//#include "historica.h"

enum generos{
    DRAMA = 1,
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
    string convertir_a_string_genero();
    void mostrar_solo_novelas(int genero);
};

#endif