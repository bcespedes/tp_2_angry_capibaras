# ifndef HISTORICA_H
# define HISTORICA_H


# include "Novela.h"


class Historica: public Novela {

private:

    char* tema_;

public:

    //PRE: Genero tiene que ser historica
    //POST: Crea un objeto historica
    Historica(string titulo, unsigned int minutos, unsigned int anio, Escritor* autor, generos genero, char* tema);
    
    //PRE: -
    //POST: Se devuelve el tema de la novela historica.
    char* obtener_tema();

    // PRE:
    // POST:
    void mostrar_lectura();

    // PRE:
    // POST:
    void insertar_lectura(string titulo, int minutos, int anio, generos genero, string tema, Lista<Lectura *>* lista_lectura, Escritor* autor, int referencia);

    // PRE:
    // POST:
    bool coinciden_generos(int genero);

    // PRE:
    // POST:
    ~Historica();

};


# endif