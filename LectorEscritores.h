# ifndef LECTOR_ESCRITORES_H
# define LECTOR_ESCRITORES_H


# include "Lector.h"


class LectorEscritores : public Lector {

public:
    
    // PRE:
    // POST:
    Lista<Escritor *>* procesar_escritores();
    
    // PRE:
    // POST:
    void faltan_anios(string &anio_nacimiento, string &anio_fallecimiento);

    // PRE:
    // POST:
    void falta_fallecimiento(string &anio_fallecimiento);

    // PRE:
    // POST:
    void validar_anios_fin_archivo(int leidos, string &anio_nacimiento, string &anio_fallecimiento);

    // PRE:
    // POST:
    Escritor* crear_escritor(ifstream &archivo_escritores);

    // PRE:
    // POST:
    bool validar_archivo(ifstream &archivo_escritores);

};


# endif