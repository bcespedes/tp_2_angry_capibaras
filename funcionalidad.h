#ifndef FUNCIONALIDAD_H
#define FUNCIONALIDAD_H

#include "lista.h"
#include "escritor.h"
#include "lectura.h"
#include "cola.h"
//#include "lector.h"
#include "lector_escritores.h"
#include "lector_lecturas.h"
#include "stdlib.h"
#include "time.h"
#include <string.h>

class Funcionalidad{
private:
    Lista<Escritor *> *lista_escritores_;
    Lista<Lectura *> *lista_lecturas_;

    Lectura *crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor *autor);

    bool validar_opcion(int opcion, int opcion_max);
public:
    Funcionalidad(Lista<Escritor *> *lista_escritores, Lista<Lectura *> *lista_lecturas);//ver si pasar referencia o con puntero esta OK
    void agregar_lectura();
    void quitar_lectura();
    void agregar_escritor();
    void asignar_fallecimiento_escritor();
    void listar_escritores();
    void sortear_lectura();
    void listar_lecturas();
    void listar_periodo_lecturas();
    void listar_lecturas_de();
    void listar_novelas_genero();
    void crear_cola_ordenada();
    static void limpiar_pantalla();

    void salir();

    ~Funcionalidad();
};






#endif