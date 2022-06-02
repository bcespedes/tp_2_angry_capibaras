#ifndef LECTURA_H
#define LECTURA_H


# include <iostream>
# include "Escritor.h"
# include "Lista.h"


using namespace std;


class Lectura {

protected:

    string titulo_;
    unsigned int minutos_;
    unsigned int anio_;
    Escritor* autor_;

public:

    // PRE:
    // POST:
    Lectura(string titulo, unsigned int minutos, unsigned int anio, Escritor* autor);   

    // PRE:
    // POST: 
    string obtener_titulo();

    // PRE:
    // POST:
    unsigned int obtener_minutos();

    // PRE:
    // POST:
    unsigned int obtener_anio();

    // PRE:
    // POST:
    Escritor* obtener_escritor();

    // PRE:
    // POST:
    int comparar(Lectura* a_comparar);

    virtual void mostrar_lectura() = 0;
    virtual bool coinciden_generos(int genero) = 0;
    virtual ~Lectura() = 0;

};


# endif