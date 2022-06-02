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

    // ATRIBUTOS
    Lista <Escritor*>* lista_escritores_;
    Lista <Lectura*>* lista_lecturas_;

    // METODOS
    char ingresar_tipo_lectura();
    char ingresar_si_es_anonimo();
    int ingresar_genero();
    Escritor* no_es_escritor_anonimo(int indice, int cantidad_escritores);
    Lectura* crear_novela_historica(string titulo, int duracion, int anio, Escritor* escritor);
    Lectura* crear_novela(string titulo, int duracion, int anio, Escritor* escritor);
    Lectura* crear_cuento(string titulo, int duracion, int anio, Escritor* escritor);
    Lectura* crear_poema(string titulo, int duracion, int anio, Escritor* escritor);
    Lectura* crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* escritor);
    int ingresar_indice_lista(string instruccion, int cantidad_datos);
    int ingresar_anio_correcto(int anio_inferior);
    Escritor* ingresar_escritor();

public:

    // PRE: -
    // POST: Crea un procesador de opciones. 
    ProcesadorDeOpciones(Lista<Escritor *>* lista_escritores, Lista<Lectura *>* lista_lecturas);

    // PRE: La lista_lectura esta creada.
    // POST: Agrega una lectura a la lista.
    void agregar_lectura();

    // PRE: La lista_lectura esta creada.
    // POST: Quita una lectura de la lista.
    void quitar_lectura();

    // PRE: La lista_escritores esta creada.
    // POST: Agrega un escritor a la lista.
    void agregar_escritor();

    // PRE: La lista escritores no esta vacia.
    // POST: Si el escritor no tiene un fallecimiento asignado, se le pide un anio al usuario y se actualiza.
    void asignar_fallecimiento_escritor();

    // PRE: La lista escritores no esta vacia.
    // POST: Muestra por pantalla todos los escritores. 
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
    void cocinar_pastel_de_papa();

    // PRE:
    // POST:
    ~ProcesadorDeOpciones();

};


# endif