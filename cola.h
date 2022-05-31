#ifndef COLA_H
#define COLA_H


#include "nodo.h"


template <typename Tipo>

class Cola {

private:

    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

public:

    //PRE: -
    //POST: Crea una cola vacia.
    Cola();

    //PRE: -
    //POST: devuelve true si la cola esta llena, false en caso contrario
    bool vacia();

    //PRE: La cola no esta llena - e es un dato valido
    //POST: Agrega el dato e al final de la cola.
    void alta(Tipo e);

    //PRE: La cola no puede estar vacia.
    //POST: Elimina el primer elemento de la cola.
    Tipo baja();

    //PRE: La cola no puede estar vacia
    //POST: Devuelve el primer elemento de la cola (sin modificarla).
    Tipo consulta();

    //PRE: -
    //POST: destruye la cola.
    ~Cola();

};

template <typename Tipo>

Cola<Tipo>::Cola() {

    primero = nullptr;
    ultimo = nullptr;
}


template <typename Tipo>

bool Cola<Tipo>::vacia() {

    return ultimo == nullptr;
}


template <typename Tipo>

Tipo Cola<Tipo>::consulta() {

    return primero -> obtener_dato();
}


template <typename Tipo>

void Cola<Tipo>::alta(Tipo d) {

    Nodo<Tipo>* nuevo = new Nodo<Tipo>(d);

    if(primero)
        ultimo -> cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    
    ultimo = nuevo;
}


template <typename Tipo>

Tipo Cola<Tipo>::baja() {

    Nodo<Tipo>* borrar = primero;

    Tipo dato = borrar -> obtener_dato();

    primero = primero -> obtener_siguiente();

    if(!primero)
        ultimo = nullptr;

    borrar = NULL;
 
    return dato;
}


template <typename Tipo>

Cola<Tipo>::~Cola() {

    while(!vacia())
        baja();
}


#endif