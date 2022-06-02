# ifndef LECTOR_H
# define LECTOR_H


# include <fstream>
# include "Escritor.h"
# include "Lista.h"
# include "Historica.h"
# include "Poema.h"
# include "Cuento.h"


const string ESCRITORES = "escritores.txt";
const string LECTURAS = "lecturas.txt";


class Lector {
    
protected:

    int obtener_referencia(string referencia);

public:

    Lector();
    /*Lista<Lectura *> *procesar_lecturas();
    Lista<Escritor *> *procesar_escritores();*/
    //virtual void procesar_archivos() = 0;
    virtual bool validar_archivo(ifstream &archivo) = 0;

};


# endif