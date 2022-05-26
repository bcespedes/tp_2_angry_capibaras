#include "funcionalidad.h"

Funcionalidad::Funcionalidad(Lista<Escritor *> *lista_escritores, Lista<Lectura *> *lista_lecturas){
    lista_escritores_ = lista_escritores;
    lista_lecturas_ = lista_lecturas;
}

void Funcionalidad::agregar_lectura(Lectura *lectura){
    lista_lecturas_->alta(lectura, 0);
}

bool Funcionalidad::igualdad_cadena(string titulo1, string titulo2){
    bool igualdad = false;
    if(titulo1.length() == titulo2.length()){
    
        int i;
        for(i = 0; titulo1[i] != '\0' && tolower(titulo1[i]) == tolower(titulo2[i]); i++);

        if(i == titulo1.length() - 1)
            igualdad = true;
    }
    return igualdad;
}

void Funcionalidad::quitar_lectura(){

    lista_lecturas_->imprimir_lista2();
    string titulo;
    cout << "Ingrese la lectura a eliminar: " << endl;
    cin >> titulo;
    int pos = 0;
    string lectura;
    //string lectura = lista_lecturas_.consulta(0)->obtener_titulo();
    while(!igualdad_cadena(titulo, lista_lecturas_->consulta(pos)->obtener_titulo())){
        cout << "buenas" << endl;
        pos++;
    }
    /*do{
        string lectura = lista_lecturas_->consulta(pos)->obtener_titulo();
        pos++;
    }
    while(!igualdad_cadena(titulo, lectura) && pos < lista_lecturas_->devolver_cantidad()+1);*/


    lista_lecturas_->baja(pos);

}

void Funcionalidad::agregar_escritor(Escritor *escritor){
    lista_escritores_->alta(escritor, 0);
}

void Funcionalidad::asignar_fallecimiento_escritor(int anio_fallecimiento){

}

void Funcionalidad::listar_escritores(){
    lista_escritores_->imprimir_lista();
}

Lectura *Funcionalidad::sortear_lectura(){
    srand(time(NULL));
    int sorteo = rand()%(lista_lecturas_->devolver_cantidad(), 0);
    return lista_lecturas_->consulta(sorteo);
}

void Funcionalidad::listar_lecturas(){
    lista_lecturas_->imprimir_lista2();
}

