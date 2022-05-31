#include "funcionalidad.h"


Funcionalidad::Funcionalidad(Lista<Escritor *>* lista_escritores, Lista<Lectura *>* lista_lecturas) {

    lista_escritores_ = lista_escritores;
    lista_lecturas_ = lista_lecturas;
}


void Funcionalidad::limpiar_pantalla() {

    #ifdef _WIN32
            system("cls");
    #else
            system ("clear");
    #endif
}


bool Funcionalidad::validar_opcion(int opcion, int opcion_max) {

    return (1 <= opcion && opcion <= opcion_max);
}


Lectura* Funcionalidad::crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* autor) {
    
    Lectura* lectura;

    if(toupper(tipo_lectura) == 'N') {
        int genero = 0;
        cout << "Generos disponibles: " << endl;
        cout << "\n[1] - Drama\n[2] - Comedia\n[3] - Ficcion\n[4] - Suspenso\n[5] - Terror\n[6] - Romantica \n[7] - Historica" << endl << endl;

        while(!validar_opcion(genero, 7)) {
            cout << "Ingrese el indice correspondiente al genero de la novela: ";
            cin >> genero;
            if(!validar_opcion(genero, 7))
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }

        if(genero == 7) { //HISTORICA
            string tema;
            cout << "\nIngrese el tema historico de la novela: ";
            cin.ignore();
            getline(cin, tema);
            char* tema_historico = new char[tema.length() + 1];
            strcpy(tema_historico, tema.c_str());
            lectura = new Historica(titulo, duracion, anio, autor, HISTORICA, tema_historico);
        }
        else
            lectura = new Novela(titulo, duracion, anio, autor, (generos) genero);
    }

    else if(toupper(tipo_lectura) == 'C') {
        cout << "\nIngrese el libro donde se publico el cuento: ";
        string libro_publicado;
        cin.ignore();
        getline(cin, libro_publicado);
        lectura = new Cuento(titulo, duracion, anio, autor, libro_publicado);
    }

    else {
        cout << "\nIngrese la cantidad de versos del poema: ";
        int cant_versos;
        cin >> cant_versos;
        lectura = new Poema(titulo, duracion, anio, autor, cant_versos);
    }

    cout << "\nSe agrego la lectura " << titulo << " a la lista correctamente." << endl;

    return lectura;
}


void Funcionalidad::agregar_lectura() {

    if(!lista_escritores_ -> vacia()) {
        string titulo; 
        unsigned int duracion, anio;
        int indice = 0, cantidad_escritores = lista_escritores_ -> devolver_cantidad();
        char tipo_lectura = 'X';

        while(toupper(tipo_lectura) != 'C' && toupper(tipo_lectura) != 'P' && toupper(tipo_lectura) != 'N') {
            cout << "Ingrese el tipo de lectura (C -> Cuento, P -> Poesia, N -> Novela): ";
            cin >> tipo_lectura;
            //tipo_lectura = toupper(tipo_lectura);
            if(toupper(tipo_lectura) != 'C' && toupper(tipo_lectura) != 'P' && toupper(tipo_lectura) != 'N')
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }

        cin.ignore();
        cout << "\nIngrese el titulo de la lectura: ";
        getline(cin, titulo);

        cout << "\nIngrese la duracion en minutos de su lectura: ";
        cin >> duracion;

        cout << "\nIngrese el anio de publicacion: ";
        cin >> anio;

        cout << endl;
        lista_escritores_ -> imprimir_lista();
        while (!validar_opcion(indice, cantidad_escritores) && indice != -1) {
            cout << "Ingrese el indice del escritor de la lectura correspondiente, si su escritor no aparece en la lista ingrese -1: ";
            cin >> indice;
            if(!validar_opcion(indice, cantidad_escritores) && indice != -1)
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }

        if(indice == -1) {
            cout << "\nProceda a agregar un nuevo escritor:\n" << endl;
            agregar_escritor();
            indice = cantidad_escritores + 1;
        }

        Escritor* autor = lista_escritores_ -> consulta(indice - 1);
        Lectura* lectura = crear_lectura(tipo_lectura, titulo, duracion, anio, autor);
        Lector_lecturas::insertar_lectura_ordenada(lectura, lista_lecturas_);

    }
    else
        cout << "No se encontraron escritores, agregue un escritor desde el menu!" << endl;
}


void Funcionalidad::quitar_lectura() {

    lista_lecturas_ -> imprimir_lista2();
    int opcion = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

    if(!lista_lecturas_ -> vacia()) {
        while(!validar_opcion(opcion, cantidad_lecturas)) {
            cout << "Ingrese el indice de la lectura a eliminar: ";
            cin >> opcion;
            if(!validar_opcion(opcion, cantidad_lecturas))
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }
        cout << "\nSe ha eliminado " << lista_lecturas_ -> consulta(opcion - 1) -> obtener_titulo() << " correctamente." << endl;
        lista_lecturas_ -> baja(opcion - 1);
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::agregar_escritor() {

    string nombre, apellido, nacionalidad;
    string anio_nacimiento, anio_fallecimiento;

    cout << "Ingrese el nombre del escritor a agregar: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "\nIngrese el apellido del escritor a agregar: ";
    getline(cin, apellido);

    cout << "\nIngrese la nacionalidad del escritor a agregar: ";
    getline(cin, nacionalidad);

    cout << "\nIngrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ";
    getline(cin, anio_nacimiento);

    cout << "\nIngrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ";
    getline(cin, anio_fallecimiento);

    Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));
    lista_escritores_ -> alta(escritor, lista_escritores_ -> devolver_cantidad());

    cout << "\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente.\n" << endl;
}


void Funcionalidad::asignar_fallecimiento_escritor() {

    if(!lista_escritores_ -> vacia()) {
        int anio_fallecimiento, indice = 0, cantidad_escritores = lista_escritores_ -> devolver_cantidad();

        lista_escritores_ -> imprimir_lista();
        while(!validar_opcion(indice, cantidad_escritores)) {
            cout << "Ingrese el indice del escritor a asignarle el anio: ";
            cin >> indice;
            if(!validar_opcion(indice, cantidad_escritores))
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }

        if(lista_escritores_ -> consulta(indice - 1) -> validar_fallecimiento()) {
            cout << "\nIngrese el anio de fallecimiento del escritor: ";
            cin >> anio_fallecimiento;
            lista_escritores_ -> consulta(indice-1) -> asignar_fallecimiento(anio_fallecimiento);
        }
        else
            cout << "Este escritor ya tiene anio de fallecimiento asignado";
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_escritores() {

    if(!lista_escritores_ -> vacia())
        lista_escritores_ -> imprimir_lista();
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::sortear_lectura() {

    if(!lista_lecturas_ -> vacia()) {
        srand((unsigned int) time(NULL));
        int sorteo = rand() % (lista_lecturas_ -> devolver_cantidad() + 0);
        cout << "Se leera la lectura numero: " << sorteo + 1 << " - " << lista_lecturas_ -> consulta(sorteo) -> obtener_titulo() << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_lecturas() {

    if(!lista_lecturas_ -> vacia())
        lista_lecturas_ -> imprimir_lista2();
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_periodo_lecturas() {

    unsigned int anio_inferior = 0, anio_superior = 0;
    int contador = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

    if(!lista_lecturas_ -> vacia()) {
        cout << "Ingrese el anio desde donde desea mostrar las lecturas: ";
        cin >> anio_inferior;

        while(anio_superior <= anio_inferior) {
            cout << "Ingrese el anio hasta donde desea mostrar las lecturas: ";
            cin >> anio_superior;
            if(anio_superior <= anio_inferior)
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }

        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> obtener_anio() >= anio_inferior && lista_lecturas_ -> consulta(i) -> obtener_anio() <= anio_superior) {
                contador++;
                if(contador == 1)
                    cout << "\nLas lecturas en ese periodo de tiempo son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << " - " << lista_lecturas_ -> consulta(i) -> obtener_anio() << endl;
            }
        }

        if(contador == 0)
            cout << "\nNo se han encontrado lecturas en ese periodo de tiempo." << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_lecturas_de() {

    if(!lista_escritores_ -> vacia()) {

        int indice = 0, contador = 0,
        cantidad_escritores = lista_escritores_ -> devolver_cantidad(), cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

        lista_escritores_ -> imprimir_lista();

        while(!validar_opcion(indice, cantidad_escritores)) {
            cout << "Ingrese el indice del escritor del cual desea conocer sus obras: ";
            cin >> indice;
            if(!validar_opcion(indice, cantidad_escritores))
                cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
        }
        
        Escritor* escritor = lista_escritores_ -> consulta(indice - 1);

        for(int i = 0; i < cantidad_lecturas; i++) {

            if(lista_lecturas_ -> consulta(i) -> obtener_escritor() == escritor) {
                contador++;

                if(contador == 1)
                    cout << "\nLas obras de " << escritor -> devolver_nombre_completo() << " son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }
        if(contador == 0)
            cout << "\nEste escritor no tiene cargada ninguna lectura." << endl;
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_novelas_genero() {

    unsigned int genero = 0, contador = 0;
    int cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

    cout << "Generos disponibles: " << endl;
    cout << "\n[1] - Drama\n[2] - Comedia\n[3] - Ficcion\n[4] - Suspenso\n[5] - Terror\n[6] - Romantica \n[7] - Historica" << endl << endl;

    while(!validar_opcion(genero, 7)) {
        cout << "Ingrese el indice correspondiente al genero de la novela: ";
        cin >> genero;
        if(!validar_opcion(genero, 7))
            cout << "\nHas ingresado algo erroneo.\nImtentalo nuevamente. ";
    }

    cout << endl;
    lista_lecturas_ -> inicializar();
    for(int i = 0; i < cantidad_lecturas; i++) {
        if(lista_lecturas_ -> consulta(i) -> coinciden_generos(genero)) {
            lista_lecturas_ -> consulta(i) -> mostrar_lectura();
            contador++;
        }
    }

    if(contador == 0)
        cout << "No se han encontrado novelas de ese genero" << endl;
}


Funcionalidad::~Funcionalidad() {

    delete lista_escritores_;
    delete lista_lecturas_;
}