#include "lector.h"
#include <string>


Lector::Lector(){

}

/*void Lector_archivos::faltan_anios(string &anio_nacimiento, string &anio_fallecimiento){
    anio_nacimiento = "-1";
    anio_fallecimiento = "-1";
}

void Lector_archivos::falta_fallecimiento(string &anio_fallecimiento){
    anio_fallecimiento = "-1";
}

void Lector_archivos::validar_anios_fin_archivo(int leido, string &anio_nacimiento, string &anio_fallecimiento){
    if(leido == 5)
        anio_fallecimiento = "-1";

    else if(leido == 4){
        anio_nacimiento = "-1";
        anio_fallecimiento = "-1";
    }
}

void Lector_archivos::insertar_escritor(string nombre, string apellido, string nacionalidad, string anio_nacimiento, string anio_fallecimiento, Lista<Escritor *> *lista, int indice){
    Escritor *e = new Escritor(nombre, apellido, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));
    //e->mostrar_escritor();
    lista->alta(e, indice);
}*/

/// esta va en lector.h 
int Lector::obtener_referencia(string referencia){
    string num = "";
    if(referencia != "ANONIMO"){
        for(int i = 1; referencia[i] != ')'; i++){
            num += referencia[i];
        }
    }
    else 
        num = "-1";

    return stoi(num);
}

/*Lista<Escritor *> *Lector_archivos::procesar_escritores(){
    ifstream archivo_escritores(ESCRITORES);

    Lista<Escritor *> *lista_escritores;
    
    if(!archivo_escritores.is_open()){
        cout << "No se pudo abrir el archivo escritores" << endl;
        lista_escritores = NULL;
    }
    
    else{
        
        string nombre, apellido, nacionalidad, referencia, anio_nacimiento, anio_fallecimiento;

        int leido = 0;
        int indice = 0;

        lista_escritores = new Lista<Escritor *>();

        
        while(!archivo_escritores.eof()){

            leido = 0;

            archivo_escritores >> referencia;
            archivo_escritores.ignore();
            getline(archivo_escritores, nombre, ' ');
            getline(archivo_escritores, apellido);
            getline(archivo_escritores, nacionalidad);
            leido = 4;
            if(getline(archivo_escritores, anio_nacimiento))
                leido++;
      
            if(anio_nacimiento.empty()){
                faltan_anios(anio_nacimiento, anio_fallecimiento);
                leido++;  
            }      
            else if(getline(archivo_escritores, anio_fallecimiento))
                leido++;
            
            if(anio_fallecimiento.empty())
                falta_fallecimiento(anio_fallecimiento);
            
            validar_anios_fin_archivo(leido, anio_nacimiento, anio_fallecimiento);

            insertar_escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento, lista_escritores, indice);
            indice++;
        }

    }

    return lista_escritores;

}*/

////////////////////////// clase lectura 77777777777777777777

/*Escritor *Lector_archivos::obtener_escritor(Lista<Escritor *> *lista, int referencia){
    return lista->consulta(referencia);
}

void Lector_archivos::insertar_historica(string titulo, int minutos, int anio, generos genero, string tema, Lista<Lectura *> *lista_lectura, Escritor *escritor){
    char *tema_historico;
    strcpy(tema_historico, tema.c_str());
    Lectura *historica = new Historica(titulo, minutos, anio, escritor, genero, tema_historico);
    lista_lectura->alta(historica, 0);
}

Lista<Lectura *> *Lector_archivos::procesar_lecturas(){
    ifstream archivo_lecturas(LECTURAS);
    Lista<Lectura *> *lista_lecturas;

    Lista<Escritor *> *lista_escritores = procesar_escritores();


    if(!archivo_lecturas.is_open()){
        cout << "No se pudo abrir el archivo_lecturasarchivo lecturas" << endl;
        lista_lecturas = NULL;
    }


    else{
        string tipo_lectura, titulo, duracion, anio, genero, tema_historico, libro_publicado, cant_versos, referencia;
        

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
                else
                    getline(archivo_lecturas, referencia);
                    
            }

            else if (tipo_lectura == "C"){
                getline(archivo_lecturas, libro_publicado);
                getline(archivo_lecturas, referencia);
            }
            else{
                getline(archivo_lecturas, cant_versos);
                getline(archivo_lecturas, referencia);

            }


            cout << "Tipo lectura: " << tipo_lectura << endl;
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

            cout << "referencia" <<  referencia << '\n' << endl;

            
        }
    }
    
}*/