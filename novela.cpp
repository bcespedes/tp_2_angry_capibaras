#include "novela.h"
#include "historica.h"

Novela::Novela(string titulo, unsigned int minutos, unsigned int anio, Escritor *autor, generos genero)
 : Lectura(titulo, minutos, anio, autor){
    genero_ = genero;
}

generos Novela::obtener_genero(){
    return genero_;
}

generos Novela::convertir_a_genero(string genero){
    generos gen;
    
    if(genero == "DRAMA") gen = DRAMA;
    if(genero == "FICCION") gen = FICCION;
    if(genero == "TERROR") gen = TERROR;
    if(genero == "COMEDIA") gen = COMEDIA;
    if(genero == "SUSPENSO") gen = SUSPENSO;
    if(genero == "ROMANTICA") gen = ROMANTICA;

    return gen;
}//ver que onda


void Novela::mostrar_lectura(){
    
    cout << "Novela" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Genero: " << genero_ << endl;

    if(autor_ != nullptr){
        autor_->mostrar_escritor();
    }
    else cout << "ANONIMO" << endl;
    
}