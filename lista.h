#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"


template <typename Tipo>

class Lista{

private:

    int cantidad;
    Nodo<Tipo> *primero;
    Nodo<Tipo> *actual;
    
    
public:
    //PRE: -
    //POST: Crea una lista vacia
    Lista();

    //PRE: -
    //POST: Mueve el actual al inicio de la lista
    void inicializar();

    void desinicializar();
    //PRE:
    //POST: Devuelve true si hay un nodo siguiente, false si se esta en el final
    bool hay_siguiente();

    //PRE:
    //POST: Devuelve el dato de actual y mueve el actual+ hacia la siguiente posicion.
    Tipo siguiente();


    //PRE: -
    //POST: Devuelve true si esta vacia, false en caso contrario.
    bool vacia();

    //PRE: e es un dato valido. 0 <= Pos <= obtener.cantidad()+1
    //POST: Agrega el elem en la posicion pos. (empieza en 0)
    void alta(Tipo e, int pos); 
    
    void agregar_al_final(Tipo e);
    
    //PRE: 0 <= Pos <= obtener.cantidad()
    //POST: Da de baja al elemento en pos
    void baja(int pos);

    //PRE: 0 <= Pos <= obtener.cantidad()
    //POST: Devuelve el elemento en pos
    Tipo consulta(int pos);

    void imprimir_lista();

    void imprimir_lista2();

    int devolver_cantidad();

    //PRE: -
    //POST: Destruye la lista.
    ~Lista();

private:

    Nodo<Tipo> *obtener_nodo(int pos);

};

template <typename Tipo>

Lista<Tipo>::Lista(){
    cantidad = 0;
    primero = NULL;
    actual = NULL;
}

template <typename Tipo>

void Lista<Tipo>::inicializar(){
    actual = primero;
}

template <typename Tipo>

void Lista<Tipo>::desinicializar(){
    actual = NULL;
}

template <typename Tipo>

bool Lista<Tipo>::hay_siguiente(){
    return actual->obtener_siguiente() != NULL;
}

template <typename Tipo>

Tipo Lista<Tipo>::siguiente(){
    Tipo devolver = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return devolver;
}

template <typename Tipo>

bool Lista<Tipo>::vacia(){
    return (primero == NULL);
}

template <typename Tipo>
int Lista<Tipo>::devolver_cantidad(){
    return cantidad;
}

template <typename Tipo>

Nodo<Tipo> *Lista<Tipo>::obtener_nodo(int pos){

    Nodo<Tipo>*aux = primero;
    int contador = 0;

    while(contador < pos){
        aux = aux->obtener_siguiente();
        contador++;
    }

    return aux;
}

template <typename Tipo>

Tipo Lista<Tipo>::consulta(int pos){
    Nodo<Tipo> *aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

template <typename Tipo>

void Lista<Tipo>::alta(Tipo e, int pos){
    Nodo<Tipo> *nuevo = new Nodo<Tipo>(e);

    if( pos == 0){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;

    }
    else{

        Nodo<Tipo> *anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());

        anterior->cambiar_siguiente(nuevo);

    }
    cantidad++;
}

template <typename Tipo>

void Lista<Tipo>::agregar_al_final(Tipo e){
    int posicion = 0;
    inicializar();
    while(hay_siguiente()){
        actual = actual->obtener_siguiente();
        posicion++;
    }
    alta(e, posicion +1);
    actual = NULL;   
    cantidad++; 
}

template <typename Tipo>

void Lista<Tipo>::baja(int pos){
    Nodo<Tipo> *borrar = primero;

    if(pos == 0){
        primero = primero->obtener_siguiente();
    }
    else{
        Nodo<Tipo> *anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;

    //delete borrar->obtener_dato();
    delete borrar; //:)
}

template <typename Tipo>

void Lista<Tipo>::imprimir_lista(){
    inicializar();
    while(actual != NULL){
        actual->obtener_dato()->mostrar_escritor(); //cambiar la lista tiene templates
        actual = actual->obtener_siguiente();
    }
}

template <typename Tipo>

void Lista<Tipo>::imprimir_lista2(){
    inicializar();
    while(actual != NULL){
        actual->obtener_dato()->mostrar_lectura();
        actual = actual->obtener_siguiente();
    }
}


template <typename Tipo>

Lista<Tipo>::~Lista(){
    while(!vacia()){
        baja(0);
    }
}







#endif