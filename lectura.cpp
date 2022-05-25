#include "lectura.h"

Lectura::Lectura(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor){
    titulo_ = titulo;
    minutos_ = minutos;
    anio_ = anio;
    autor_ = autor;
};

string Lectura::obtener_titulo(){
    return titulo_;
}

unsigned int Lectura::obtener_minutos(){
    return minutos_;
}

unsigned int Lectura::obtener_anio(){
    return anio_;
}

Escritor *Lectura::obtener_escritor(){
    return autor_;
}

int Lectura::comparar(Lectura *a_comparar){
    int devolver;

    if(anio_ < a_comparar->obtener_anio())
        devolver = -1;
    else if(anio_ > a_comparar->obtener_anio())
        devolver = 1;
    else devolver = 0;


    return devolver;
}

