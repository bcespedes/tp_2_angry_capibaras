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
    void insertar_lecturas_a_cola(Cola<Lectura *> *cola);
    void insertar_lectura_a_cola_(Cola<Lectura *>* cola, int *vector_posiciones, int cantidad);
    bool esta_en_vector(int *vector_posiciones, int pos, int cantidad);




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

    // PRE: La lista_escritores esta creada.
    // POST: Si el escritor no tiene un fallecimiento asignado, se le pide un anio al usuario y se actualiza.
    void asignar_fallecimiento_escritor();

    // PRE: La lista_escritores esta creada.
    // POST: Muestra por pantalla todos los escritores. En caso de no haber, se le informa al usuario
    void listar_escritores();

    // PRE:La lista_lectura esta creada.
    // POST: muestra una lectura aleatoria 
    void sortear_lectura();

    // PRE: La lista_lectura esta creada.
    // POST: muestra por pantalla todas las lecturas. En caso de no haber se le informa al usuario
    void listar_lecturas();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las lecturas entre periodos de tiempo ingresados por el usuario
    void listar_periodo_lecturas();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las lecturas del autor determinado por el usuario
    void listar_lecturas_de();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las novelas del genero determinado por el usuario.
    void listar_novelas_genero();

    // PRE:
    // POST:
    void crear_cola_ordenada();

    // PRE:
    // POST: 50% de posibilidades de cocinar un delicioso pastel de papa.
    //       50% de posibilidades de que ocurra la desgracia, fatalidad einfortunio de no tener los suficientes ingredientes.
    void cocinar_pastel_de_papa();

    // PRE:
    // POST: destruye el procesador de opciones, eliminando las listas y liberando su memoria. 
    ~ProcesadorDeOpciones();

};


# endif