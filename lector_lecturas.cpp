#include "lector_lecturas.h"
#include <string.h>

Escritor *Lector_lecturas::obtener_escritor(Lista<Escritor *> *lista, int referencia){
    if(referencia == -1)
        return NULL;
    return lista->consulta(referencia - 1);
}

bool Lector_lecturas::validar_archivo(ifstream &archivo_lecturas){
    bool abierto = true;
    if(!archivo_lecturas.is_open()){
        cout << "No se pudo abrir el archivo lecturas" << endl;
        abierto = false;
    }
    return abierto;
}

generos Lector_lecturas::convertir_a_genero(string genero){
    generos gen;
    
    if(genero == "DRAMA") gen = DRAMA;
    if(genero == "FICCION") gen = FICCION;
    if(genero == "TERROR") gen = TERROR;
    if(genero == "COMEDIA") gen = COMEDIA;
    if(genero == "SUSPENSO") gen = SUSPENSO;
    if(genero == "ROMANTICA") gen = ROMANTICA;

    return gen;
}

void Lector_lecturas::insertar_lectura_ordenada(Lectura *lectura, Lista<Lectura *> *lista_lectura){
    int pos = 0;
    bool avanzar = true;

    lista_lectura->inicializar();
    if(!lista_lectura->vacia()){
    
        while(avanzar){
            if(lectura->comparar(lista_lectura->consulta(pos)) == -1){
                avanzar = false;
                pos--;
            }
            if(!lista_lectura->hay_siguiente()){
                pos++;
                avanzar = false;
            }
            else{
                pos++;
                lista_lectura->siguiente();
            }
        }
    }

    lista_lectura->alta(lectura, pos);
}

void Lector_lecturas::insertar_historica(string titulo, int minutos, int anio, generos genero, string tema, Lista<Lectura *> *lista_lectura, Escritor *escritor){
    char *tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    Lectura *historica = new Historica(titulo, minutos, anio, escritor, genero, tema_historico);
    insertar_lectura_ordenada(historica, lista_lectura);
}

void Lector_lecturas::insertar_novela(string titulo, int minutos, int anio, generos genero, Lista<Lectura *> *lista_lectura, Escritor *escritor){
    Lectura *novela = new Novela(titulo, minutos, anio, escritor, genero);
    insertar_lectura_ordenada(novela, lista_lectura);
}

void Lector_lecturas::insertar_cuento(string titulo, int minutos, int anio, string libro, Lista<Lectura *> *lista_lectura, Escritor *escritor){
    Lectura *cuento = new Cuento(titulo, minutos, anio, escritor, libro);
    insertar_lectura_ordenada(cuento, lista_lectura);
}

void Lector_lecturas::insertar_poema(string titulo, int minutos, int anio, int versos , Lista<Lectura *> *lista_lectura, Escritor *escritor){
    Lectura *poema = new Poema(titulo, minutos, anio, escritor, versos);
    insertar_lectura_ordenada(poema, lista_lectura);
}


Lista<Lectura *> *Lector_lecturas::procesar_lecturas(Lista<Escritor *> *lista_escritores){
    ifstream archivo_lecturas(LECTURAS);
    Lista<Lectura *> *lista_lecturas;

    if(!validar_archivo(archivo_lecturas)){
        lista_lecturas = NULL;
    }

    else{
        string tipo_lectura, titulo, duracion, anio, genero, libro_publicado, cant_versos, referencia;
        string tema_historico;

        lista_lecturas = new Lista<Lectura *>();

        while(!archivo_lecturas.eof()){

            archivo_lecturas >> tipo_lectura;
            archivo_lecturas.ignore();
            getline(archivo_lecturas, titulo);
            getline(archivo_lecturas, duracion);
            getline(archivo_lecturas, anio);

            if(tipo_lectura == "N"){
                getline(archivo_lecturas, genero);
                if(genero == "HISTORICA"){
                    getline(archivo_lecturas, tema_historico);
                    getline(archivo_lecturas, referencia);
                    insertar_historica(titulo, stoi(duracion), stoi(anio), HISTORICA, tema_historico, lista_lecturas, obtener_escritor(lista_escritores, obtener_referencia(referencia)));
                }
                else{
                    getline(archivo_lecturas, referencia);
                    insertar_novela(titulo, stoi(duracion), stoi(anio), convertir_a_genero(genero), lista_lecturas, obtener_escritor(lista_escritores, obtener_referencia(referencia)));
                }
                    
            }

            else if (tipo_lectura == "C"){
                getline(archivo_lecturas, libro_publicado);
                getline(archivo_lecturas, referencia);
                insertar_cuento(titulo, stoi(duracion), stoi(anio), libro_publicado, lista_lecturas, obtener_escritor(lista_escritores, obtener_referencia(referencia)));
            }
            else{
                getline(archivo_lecturas, cant_versos);
                getline(archivo_lecturas, referencia);
                insertar_poema(titulo, stoi(duracion), stoi(anio), stoi(cant_versos), lista_lecturas, obtener_escritor(lista_escritores, obtener_referencia(referencia)));

            }



            /*cout << "Tipo lectura: " << tipo_lectura << endl;
            cout << "Titulo: "<< titulo << endl;
            cout << "Duracion: " <<duracion << endl;
            cout << "Anio: " << anio << endl;
            if(tipo_lectura == "N"){
                cout <<"genero: " << genero << endl;
                if(genero == "HISTORICA")
                    cout << "tema historico: " << tema_historico << endl;
            }
            else if (tipo_lectura == "C")
                cout << "libro: " <<libro_publicado << endl;

            else
                cout << "versos" << cant_versos << endl;

            cout << "referencia" <<  referencia << '\n' << endl;]*/

            
        }
    }
    //lista_lecturas->imprimir_lista2();

    return lista_lecturas;
    
}