# include "LectorLecturas.h"
# include <string.h>


Escritor* LectorLecturas::obtener_escritor(Lista<Escritor *>* lista, int referencia) {

    if(referencia == -1)
        return NULL;

    return lista -> consulta(referencia - 1);
}


bool LectorLecturas::validar_archivo(ifstream &archivo_lecturas) {
    bool abierto = true;
    if(!archivo_lecturas.is_open()) {
        cout << "No se pudo abrir el archivo lecturas, puede agregarlas manualmente!\n" << endl;
        abierto = false;
    }

    return abierto;
}


generos LectorLecturas::convertir_a_genero(string genero) {

    generos genero_en_enum;
    
    if(genero == "DRAMA") genero_en_enum = DRAMA;
    if(genero == "FICCION") genero_en_enum = FICCION;
    if(genero == "TERROR") genero_en_enum = TERROR;
    if(genero == "COMEDIA") genero_en_enum = COMEDIA;
    if(genero == "SUSPENSO") genero_en_enum = SUSPENSO;
    if(genero == "ROMANTICA") genero_en_enum = ROMANTICA;

    return genero_en_enum;
}


Lectura* LectorLecturas::crear_historica(string titulo, int minutos, int anio, string tema,  Escritor* escritor) {

    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    Lectura* historica = new Historica(titulo, minutos, anio, escritor, HISTORICA, tema_historico);
    return historica;
}

Lectura* LectorLecturas::crear_novela(string titulo, int duracion, int anio, Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas) {

    string genero;
    string referencia;
    getline(archivo_lecturas, genero);

    Lectura* novela;

    if(genero == "HISTORICA") {
        string tema_historico;
        getline(archivo_lecturas, tema_historico);
        getline(archivo_lecturas, referencia);
        novela = crear_historica(titulo, duracion, anio , tema_historico, obtener_escritor(lista_escritores, obtener_referencia(referencia)));
    }
    else {
        getline(archivo_lecturas, referencia);
        novela = new Novela(titulo, duracion, anio,  obtener_escritor(lista_escritores, obtener_referencia(referencia)), convertir_a_genero(genero));
    }
    
    return novela;
}

Lectura* LectorLecturas::crear_cuento(string titulo, int minutos, int anio, Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas) {

    string libro_publicado, referencia;
    
    getline(archivo_lecturas, libro_publicado);
    getline(archivo_lecturas, referencia);
    
    Lectura* cuento = new Cuento(titulo, minutos, anio, obtener_escritor(lista_escritores, obtener_referencia(referencia)), libro_publicado);

    return cuento;
}

Lectura* LectorLecturas::crear_poema(string titulo, int minutos, int anio,  Lista<Escritor *>* lista_escritores, ifstream &archivo_lecturas) {
    
    string cant_versos, referencia;

    getline(archivo_lecturas, cant_versos);
    getline(archivo_lecturas, referencia);
    
    Lectura* poema = new Poema(titulo, minutos, anio, obtener_escritor(lista_escritores, obtener_referencia(referencia)), stoi(cant_versos));
    return poema;
}

Lectura* LectorLecturas::crear_lectura(ifstream &archivo_lecturas, Lista<Escritor *>* lista_escritores) {

    string tipo_lectura, titulo, duracion, anio, referencia, genero, tema_historico, cant_versos, libro_publicado;
    archivo_lecturas >> tipo_lectura;
    archivo_lecturas.ignore();
    getline(archivo_lecturas, titulo);
    getline(archivo_lecturas, duracion);
    getline(archivo_lecturas, anio);

    Lectura* lectura;

    if(tipo_lectura == "N")
        lectura = crear_novela(titulo, stoi(duracion), stoi(anio), lista_escritores, archivo_lecturas);

    else if (tipo_lectura == "C")
        lectura = crear_cuento(titulo, stoi(duracion), stoi(anio), lista_escritores, archivo_lecturas);
        
    else
        lectura = crear_poema(titulo, stoi(duracion), stoi(anio), lista_escritores, archivo_lecturas);


    return lectura;

}

Lista<Lectura *>* LectorLecturas::procesar_lecturas(Lista<Escritor *>* lista_escritores) {

    Utilidades insertador;
    ifstream archivo_lecturas(LECTURAS);
    Lista<Lectura *>* lista_lecturas = new Lista<Lectura *>();

    if(validar_archivo(archivo_lecturas)) {

        Lectura* lectura;
        while(!archivo_lecturas.eof()) {

            lectura = crear_lectura(archivo_lecturas, lista_escritores);
            insertador.insertar_lectura_ordenada(lectura, lista_lecturas);
        }
    }

    archivo_lecturas.close();

    return lista_lecturas;
}