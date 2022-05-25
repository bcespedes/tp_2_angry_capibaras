#ifndef ESCRITOR_H
#define ESCRITOR_H


#include <iostream>
using namespace std;

class Escritor{

private:
    string nombre_;
    string apellido_;
    string nacionalidad_;
    int anio_nacimiento_;
    int anio_fallecimiento_;

public:
    Escritor();
    Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);
    string devolver_nombre_completo();
    string devolver_nacionalidad();
    void fallecimiento(int anio);
    void mostrar_escritor();

};

#endif