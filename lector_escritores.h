#ifndef LECTOR_ESCRITORES_H
#define LECTOR_ESCRITORES_H

#include "lector.h"


class Lector_escritores : public Lector{

public:
    Lista<Escritor *> *procesar_escritores();
    void faltan_anios(string &anio_nacimiento, string &anio_fallecimiento);
    void falta_fallecimiento(string &anio_fallecimiento);
    void validar_anios_fin_archivo(int leidos, string &anio_nacimiento, string &anio_fallecimiento);
    Escritor *crear_escritor(ifstream &archivo_escritores);
    //static void insertar_escritor(string nombre, string apellido, string nacionalidad, string anio_nacimiento, string anio_fallecimiento, Lista<Escritor *> *lista, int indice);
    bool validar_archivo(ifstream &archivo_escritores);

};

#endif