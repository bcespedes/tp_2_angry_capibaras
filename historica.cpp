#include "historica.h"
#include <string.h>


Historica::Historica(string titulo, unsigned int minutos, unsigned int anio, Escritor* autor, generos genero, char *tema)
 : Novela(titulo, minutos, anio, autor, genero) {

    tema_ = tema;
    /*new char[strlen(tema)];
    strcpy(tema_, tema);*/
}


char* Historica::obtener_tema() {

    return tema_;
}


void Historica::mostrar_lectura() {
    
    cout << "Novela" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Genero: HISTORICA" << endl;
    cout << "Tema historico: " << tema_ << endl;

    cout << "Autor: ";
    if(autor_ != nullptr)
        autor_ -> mostrar_escritor();
    else
        cout << "ANONIMO" << endl << endl;
}


bool Historica::coinciden_generos(int genero) {

    bool coinciden = false;

    if(genero_ == genero)
        coinciden = true;

    return coinciden;
}


Historica::~Historica() {

    delete [] tema_;
}