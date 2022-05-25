#ifndef LECTURA_H
#define LECTURA_H


#include <iostream>
#include "escritor.h"
#include "lista.h"
//#include "cuento.h"
//#include "novela.h"
//#include "poema.h"

using namespace std;


class Lectura{

protected:
    string titulo_;
    unsigned int minutos_;
    unsigned int anio_;
    Escritor *autor_;

public:
    Lectura(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor);    
    string obtener_titulo();
    unsigned int obtener_minutos();
    unsigned int obtener_anio();
    Escritor *obtener_escritor();
    int comparar(Lectura *a_comparar);
    virtual void mostrar_lectura() = 0;
};

#endif