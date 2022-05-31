#ifndef LECTOR_LECTURAS_H
#define LECTOR_LECTURAS_H

#include "lector.h"


class Lector_lecturas : public Lector{

public:
    
    Escritor *obtener_escritor(Lista<Escritor *> *lista, int referencia);
    Lectura *crear_historica(string titulo, int minutos, int anio, string tema, Escritor *escritor);
    Lectura *crear_novela(string titulo, int duracion, int anio, Lista<Escritor *> *lista_escritores, ifstream &archivo_lecturas);
    Lectura *crear_cuento(string titulo, int duracion, int anio,  Lista<Escritor *> *lista_escritores, ifstream &archivo_lecturas);
    Lectura *crear_poema(string titulo, int duracion, int anio, Lista<Escritor *> *lista_escritores, ifstream &archivo_lecturas);
    Lectura *crear_lectura(ifstream &archivo_lecturas, Lista<Escritor *> *lista_escritores);

    static void insertar_lectura_ordenada(Lectura *lectura, Lista<Lectura *> *lista_lectura);
    static generos convertir_a_genero(string genero);

        
    Lista<Lectura *> *procesar_lecturas(Lista<Escritor *> *lista_escritores);
    bool validar_archivo(ifstream &archivo_lecturas);

};

#endif