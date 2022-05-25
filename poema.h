#ifndef POEMA_H
#define POEMA_H

#include "lectura.h"



class Poema: public Lectura{
private:
    int versos_;
public:
    Poema(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, int versos);
    int obtener_versos();
    void mostrar_lectura();
    
};

#endif