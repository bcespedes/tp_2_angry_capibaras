#ifndef ESCRITOR_H
#define ESCRITOR_H


#include <iostream>


using namespace std;


class Escritor {

private:

    string nombre_;
    string apellido_;
    string nacionalidad_;
    int anio_nacimiento_;
    int anio_fallecimiento_;

public:

    // PRE:
    // POST:
    Escritor();

    // PRE:
    // POST:
    Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);

    // PRE:
    // POST:
    string devolver_nombre_completo();

    // PRE:
    // POST:
    string devolver_nacionalidad();

    // PRE:
    // POST:
    bool validar_fallecimiento();

    // PRE:
    // POST:
    void asignar_fallecimiento(int anio);

    // PRE:
    // POST:
    void mostrar_escritor();

};


#endif