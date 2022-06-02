# ifndef FUNCIONALIDAD_H
# define FUNCIONALIDAD_H


# include "constantes.h"
# include "Utilidades.h"
# include "LectorLecturas.h"
# include "Cola.h"
# include "stdlib.h"
# include "time.h"
# include <string.h>


class ProcesadorDeOpciones {

private:

    Lista<Escritor *>* lista_escritores_;
    Lista<Lectura *>* lista_lecturas_;
    char ingresar_tipo_lectura();
    char ingresar_si_es_anonimo();
    Escritor* no_es_autor_anonimo(int indice, int cantidad_escritores);
    int ingresar_genero();
    Lectura* crear_novela_historica(string titulo, int duracion, int anio, Escritor* autor);
    Lectura* crear_novela(string titulo, int duracion, int anio, Escritor* autor);
    Lectura* crear_cuento(string titulo, int duracion, int anio, Escritor* autor);
    Lectura* crear_poema(string titulo, int duracion, int anio, Escritor* autor);
    Lectura* crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* autor);
    int ingresar_indice_lectura(string instruccion);
    int ingresar_indice_escritor(string instruccion);
    int ingresar_anio_correcto(int anio_inferior);

public:

    // PRE:
    // POS:
    ProcesadorDeOpciones(Lista<Escritor *>* lista_escritores, Lista<Lectura *>* lista_lecturas);

    // PRE:
    // POST:
    void agregar_lectura();

    // PRE:
    // POST:
    void quitar_lectura();

    // PRE:
    // POST:
    void agregar_escritor();

    // PRE:
    // POST:
    void asignar_fallecimiento_escritor();

    // PRE:
    // POST:
    void listar_escritores();

    // PRE:
    // POST:
    void sortear_lectura();

    // PRE:
    // POST:
    void listar_lecturas();

    // PRE:
    // POST:
    void listar_periodo_lecturas();

    // PRE:
    // POST:
    void listar_lecturas_de();

    // PRE:
    // POST:
    void listar_novelas_genero();

    // PRE:
    // POST:
    void crear_cola_ordenada();

    // PRE:
    // POST:
    ~ProcesadorDeOpciones();

};


# endif