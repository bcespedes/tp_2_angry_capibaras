#include "lector_escritores.h"


void Lector_escritores::faltan_anios(string &anio_nacimiento, string &anio_fallecimiento) {

    anio_nacimiento = "-1";
    anio_fallecimiento = "-1";
}


void Lector_escritores::falta_fallecimiento(string &anio_fallecimiento) {

    anio_fallecimiento = "-1";
}


void Lector_escritores::validar_anios_fin_archivo(int leido, string &anio_nacimiento, string &anio_fallecimiento) {

    if(leido == 5)
        anio_fallecimiento = "-1";

    else if(leido == 4) {
        anio_nacimiento = "-1";
        anio_fallecimiento = "-1";
    }
}


Escritor* Lector_escritores::crear_escritor(ifstream &archivo_escritores) {

    string nombre, apellido, nacionalidad, referencia, anio_nacimiento, anio_fallecimiento;

    int leido = 0;
            
    archivo_escritores >> referencia;
    archivo_escritores.ignore();
    getline(archivo_escritores, nombre, ' ');
    getline(archivo_escritores, apellido);
    getline(archivo_escritores, nacionalidad);
    leido = 4;
    if(getline(archivo_escritores, anio_nacimiento))       
        leido++;
    if(anio_nacimiento.empty()) {
        faltan_anios(anio_nacimiento, anio_fallecimiento);
        leido++;  
    }      
    else if(getline(archivo_escritores, anio_fallecimiento))
        leido++;
    if(anio_fallecimiento.empty())
        falta_fallecimiento(anio_fallecimiento);
    validar_anios_fin_archivo(leido, anio_nacimiento, anio_fallecimiento);

    Escritor* e = new Escritor(nombre, apellido, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));

    return e;
}


bool Lector_escritores::validar_archivo(ifstream &archivo_escritores) {

    bool abierto = true;
    if(!archivo_escritores.is_open()) {
        cout << "No se pudo abrir el archivo escritores, puede agregarlos manualmente!\n" << endl;
        abierto = false;
    }

    return abierto;
}


Lista<Escritor *>* Lector_escritores::procesar_escritores() {

    ifstream archivo_escritores(ESCRITORES);

    Lista<Escritor*>* lista_escritores = new Lista<Escritor *>();
    if(validar_archivo(archivo_escritores)) { 

        int indice = 0;
        
        while(!archivo_escritores.eof()) {

            Escritor* e = crear_escritor(archivo_escritores);
            lista_escritores -> alta(e, indice);
            indice++;

        }

    }

    archivo_escritores.close();

    return lista_escritores;
}