#include "cuento.h"

Cuento::Cuento(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, string libro) 
    : Lectura(titulo, minutos, anio, autor){
        libro_ = libro;
}

string Cuento::obtener_libro(){
    return libro_;
}

void Cuento::mostrar_lectura(){
    
    cout << "Cuento" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Libro: " << libro_ << endl;
    
    cout << "Autor : ";

    if(autor_ != nullptr){
        autor_->mostrar_escritor();
    }
    else cout << "ANONIMO" << endl;
    cout << endl;
}