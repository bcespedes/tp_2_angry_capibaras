# ifndef LECTOR_LECTURAS_H
# define LECTOR_LECTURAS_H


# include "Lector.h"
# include "Utilidades.h"


class LectorLecturas : public Lector {

public:

    // PRE:
    // POST:
    Escritor* obtener_escritor(Lista<Escritor *>* lista, int referencia);

    // PRE:
    // POST:
    Lectura* crear_historica(string titulo, int minutos, int anio, string tema, Escritor* escritor);

    // PRE:
    // POST:
    Lectura* crear_novela(string titulo, int duracion, int anio, Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas);

    // PRE:
    // POST:
    Lectura* crear_cuento(string titulo, int duracion, int anio,  Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas);

    // PRE:
    // POST:
    Lectura* crear_poema(string titulo, int duracion, int anio, Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas);

    // PRE:
    // POST:
    Lectura* crear_lectura(ifstream &archivo_lecturas, Lista<Escritor *>* lista_escritores);

    // PRE:
    // POST:
    static void insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura *>* lista_lectura);

    // PRE:
    // POST:
    static generos convertir_a_genero(string genero);

    // PRE:
    // POST:
    Lista<Lectura *>* procesar_lecturas(Lista<Escritor *>* lista_escritores);

    // PRE:
    // POST:
    bool validar_archivo(ifstream &archivo_lecturas);

};


# endif