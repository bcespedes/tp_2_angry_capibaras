#ifndef LECTOR_LECTURAS_H
#define LECTOR_LECTURAS_H

#include "lector.h"


class Lector_lecturas : public Lector{

public:
    
    Escritor *obtener_escritor(Lista<Escritor *> *lista, int referencia);
    void insertar_historica(string titulo, int minutos, int anio, generos genero, string tema, Lista<Lectura *> *lista_lectura, Escritor *escritor);
    void insertar_novela(string titulo, int minutos, int anio, generos genero, Lista<Lectura *> *lista_lectura, Escritor *escritor);
    void insertar_cuento(string titulo, int minutos, int anio, string libro,Lista<Lectura *> *lista_lectura, Escritor *escritor);
    void insertar_poema(string titulo, int minutos, int anio, int versos, Lista<Lectura *> *lista_lectura, Escritor *escritor);

    generos convertir_a_genero(string genero);

    
    
    
    Lista<Lectura *> *procesar_lecturas(Lista<Escritor *> *lista_escritores);
    bool validar_archivo(ifstream &archivo_lecturas);

};

#endif