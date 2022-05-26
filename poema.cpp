#include "poema.h"

Poema::Poema(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, int versos) 
    : Lectura(titulo, minutos, anio, autor){
        versos_ = versos;
}

int Poema::obtener_versos(){
    return versos_;
}

void Poema::mostrar_lectura(){

    cout << "Poema" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Cant de versos: " << versos_ << endl;
    
    cout << "Autor : ";
    if(autor_ != nullptr){
        autor_->mostrar_escritor();
    }
    else cout << "ANONIMO" << endl;
    cout << endl;
}