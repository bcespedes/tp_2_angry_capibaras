#include "funcionalidad.h"

Funcionalidad::Funcionalidad(Lista<Escritor *> *lista_escritores, Lista<Lectura *> *lista_lecturas){
    lista_escritores_ = lista_escritores;
    lista_lecturas_ = lista_lecturas;
}

/*
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
*/
bool Funcionalidad::validar_opcion(int opcion, int opcion_max){
    return (1 <= opcion && opcion <= opcion_max);

}


void Funcionalidad::quitar_lectura(){
    lista_lecturas_->imprimir_lista2();
    int opcion;
    if (!lista_lecturas_ -> vacia()){
        do{
        
        cout << "Ingrese la lectura a eliminar: ";
        cin >> opcion;

        } while(!validar_opcion(opcion, lista_lecturas_->devolver_cantidad()) );
        
        cout << "Se ha eliminado: " << lista_lecturas_->consulta(opcion - 1)->obtener_titulo() << endl;
        lista_lecturas_->baja(opcion -1);
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::asignar_fallecimiento_escritor(){
    if(!lista_escritores_ -> vacia()){
        int anio_fallecimiento;
        int indice;
        lista_escritores_ -> imprimir_lista();
        do{
        cout << "Ingrese el indice del escritor a asignarle el anio: ";
        cin >> indice;
        
        } while(!validar_opcion(indice,lista_escritores_->devolver_cantidad()));

        if(lista_escritores_->consulta(indice-1)->validar_fallecimiento()){
            cout << "Ingrese el anio de fallecimiento del escritor: ";
            cin >> anio_fallecimiento;
            lista_escritores_->consulta(indice-1)->asignar_fallecimiento(anio_fallecimiento);
        }
        else    
            cout << "Este escritor ya tiene anio de fallecimiento asignado";
    }
    else
        cout << "La lista esta vacia!" << endl;
}

void Funcionalidad::listar_escritores(){
    if(!lista_escritores_ -> vacia())
        lista_escritores_->imprimir_lista();
    else
        cout << "La lista esta vacia!" << endl;
}

void Funcionalidad::sortear_lectura(){
    if (!lista_lecturas_ -> vacia()){
        srand(time(NULL));
        int sorteo = rand()%(lista_lecturas_->devolver_cantidad()+0);
        cout << "Se leera la lectura numero: " << sorteo+1 << " - " << lista_lecturas_->consulta(sorteo) -> obtener_titulo() << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}

void Funcionalidad::listar_lecturas(){
    if (!lista_lecturas_ -> vacia())
        lista_lecturas_->imprimir_lista2();
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_periodo_lecturas(){
    unsigned int anio_inferior = 0, anio_superior = 0;
    int contador = 0;
    if (!lista_lecturas_ -> vacia()){
        cout << "Ingrese el anio desde donde desea mostrar las lecturas: ";
        cin >> anio_inferior;
        do {
        cout << "Ingrese el anio hasta donde desea mostrar las lecturas: ";
        cin >> anio_superior;
        if (anio_superior <= anio_inferior)
            cout << "Error." << endl << "Ingresaste un anio menor o igual al primero. ";
        } while (anio_superior <= anio_inferior);
        for (int i = 0; i < lista_lecturas_->devolver_cantidad(); i++)
            if (lista_lecturas_->consulta(i)->obtener_anio() >= anio_inferior && lista_lecturas_->consulta(i)->obtener_anio() <= anio_superior){
                contador++;
                if (contador == 1)
                    cout << "\nLas lecturas en ese periodo de tiempo son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_->consulta(i)->obtener_titulo() << " - " << lista_lecturas_->consulta(i)->obtener_anio() << endl;
            }
        if (contador == 0)
            cout << "\nNo se han encontrado lecturas en ese periodo de tiempo." << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_lecturas_de(){
    if(!lista_escritores_-> vacia()){
        int indice, contador = 0;
        lista_escritores_->imprimir_lista();
        do{
            cout << "Ingrese el escritor del cual desea conocer sus obras: ";
            cin >> indice;
        
        } while(!validar_opcion(indice,lista_escritores_->devolver_cantidad()));
        Escritor* escritor = lista_escritores_->consulta(indice - 1);
        for (int i = 0; i < lista_lecturas_->devolver_cantidad(); i++)
            if (lista_lecturas_->consulta(i)->obtener_escritor() == escritor){
                contador++;
                if (contador == 1)
                    cout << "\nLas obras de " << escritor->devolver_nombre_completo() << " son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_->consulta(i)->obtener_titulo() << endl;
            }
        if (contador == 0)
            cout << "\nEste escritor no tiene cargada ninguna lectura." << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}

void Funcionalidad::agregar_escritor(){
    string nombre, apellido, nacionalidad;
    string anio_nacimiento, anio_fallecimiento;
    cout << "Ingrese el nombre del escritor a agregar: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el apellido del escritor a agregar: ";
    getline(cin,apellido);


    cout << "Ingrese la nacionalidad del escritor a agregar: ";
    getline(cin,nacionalidad);


    cout << "Ingrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ";
    getline(cin,anio_nacimiento);


    cout << "Ingrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ";
    getline(cin,anio_fallecimiento);


    //Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    //lista_escritores_ -> alta(escritor,lista_escritores_->devolver_cantidad());
    
    Lector_escritores::insertar_escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento,
             lista_escritores_,lista_escritores_->devolver_cantidad());

    cout << "\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente" << endl;
}

void Funcionalidad::agregar_lectura(){
    if(!lista_escritores_ -> vacia()){
        string titulo; 
        unsigned int minutos, anio;
        int indice;
        Escritor* autor;
        char tipo_lectura;
        
        cout << "Ingrese el tipo de lectura (C -> Cuento, P -> Poesia, N -> Novela): ";
        cin >> tipo_lectura; //VALIDAR QUE SEA C o P o N XD COPON
        cin.ignore();
        cout << "Ingrese el titulo de la lectura: ";
        getline(cin, titulo);

        cout << "Ingrese la duracion en minutos de su lectura: ";
        cin >> minutos;
        cout << "Ingrese el anio de publicacion: ";
        cin >> anio;

        do{
            cout << endl;
            lista_escritores_ -> imprimir_lista();
            cout << "Elija el indice del escritor de la lectura correspondiente, si su escritor no aparece en la lista ingrese -1: ";
            cin >> indice;
            if(!validar_opcion(indice,lista_escritores_ -> devolver_cantidad()))
                limpiar_pantalla();
            }while (!validar_opcion(indice,lista_escritores_ -> devolver_cantidad()) && indice != -1);

            if (indice == -1){
                cout << "\nAgregue su escritor desde el menu (Opcion 3)!" << endl;
                return;
                }
            else{
                autor = lista_escritores_ -> consulta(indice-1);
            }
    }
    else
        cout << "La lista esta vacia, agregue un escritor desde el menu!" << endl;
    



}


void Funcionalidad::limpiar_pantalla(){
#ifdef _WIN32
        system("cls");
#else
        system ("clear");
#endif
}

/*
Funcionalidad::~Funcionalidad(){
    lista_escritores_->~Lista();
    lista_lecturas_->~Lista();
    delete lista_escritores_;
    delete lista_lecturas_;
}
*/
