#ifndef CUENTO_H
#define CUENTO_H

#include "lectura.h"

class Cuento: public Lectura{
private:
    string libro_;
public:
    Cuento(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, string libro);
    string obtener_libro();
    void mostrar_lectura();
    void mostrar_solo_novelas(int genero);


};

#endif