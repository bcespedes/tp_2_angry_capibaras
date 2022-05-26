#ifndef FUNCIONALIDAD_H
#define FUNCIONALIDAD_H

#include "lista.h"
#include "escritor.h"
#include "lectura.h"
#include "lector.h"
#include "stdlib.h"
#include "time.h"
#include <string.h>

class Funcionalidad{
private:
    Lista<Escritor *> *lista_escritores_;
    Lista<Lectura *> *lista_lecturas_;

    bool igualdad_cadena(string titulo, string titulo2);

public:
    Funcionalidad(Lista<Escritor *> *lista_escritores, Lista<Lectura *> *lista_lecturas);
    void agregar_lectura(Lectura *lectura);
    void quitar_lectura();
    void agregar_escritor(Escritor *escritor);
    void asignar_fallecimiento_escritor(int anio_fallecimiento);
    void listar_escritores();
    Lectura *sortear_lectura();
    void listar_lecturas();
    void listar_periodo_lecturas(int anio1, int anio2);
    void listar_lecturas_de(Escritor *escritor);
    void listar_novelas_genero(generos genero);

    void salir();
};






#endif