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


int Funcionalidad::validar_entero(int a_validar, string instruccion, int valor_minimo) {

    cout << instruccion;
    cin >> a_validar;
    while(!cin.good() || a_validar < valor_minimo) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nNo has ingresado un valor esperado.\nIntentalo nuevamente. ";
        cout << instruccion;
        cin >> a_validar;
    }

    return a_validar;
}


char Funcionalidad::ingresar_tipo_lectura() {

    string tipo_lectura = "XX";
    cout << "Tipos de lectura disponibles:" << endl;
    cout << "\n[C] - Cuento\n\n[P] - Poema\n\n[N] - Novela" << endl << endl;
    while((toupper(tipo_lectura[0]) != 'C' && toupper(tipo_lectura[0]) != 'P' && toupper(tipo_lectura[0]) != 'N') || tipo_lectura.length() > 1) {
        cout << "Ingrese la letra segun el tipo de lectura a agregar: ";
        getline(cin, tipo_lectura);
        if((toupper(tipo_lectura[0]) != 'C' && toupper(tipo_lectura[0]) != 'P' && toupper(tipo_lectura[0]) != 'N') || tipo_lectura.length() > 1)
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }
    
    return tipo_lectura[0];
}

char Funcionalidad::ingresar_si_es_anonimo() {

    string anonimo = "XX";
    while((toupper(anonimo[0]) != 'S' && toupper(anonimo[0]) != 'N') || anonimo.length() > 1) {
        cout << "\nSu autor es anonimo? (S / N): ";
        getline(cin, anonimo);
        if((toupper(anonimo[0]) != 'S' && toupper(anonimo[0]) != 'N') || anonimo.length() > 1)
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    return anonimo[0];
}


Escritor* Funcionalidad::no_es_autor_anonimo(int indice, int cantidad_escritores) {

    Escritor* autor;
    cout << endl;
    lista_escritores_ -> imprimir_lista();
    while (!validar_opcion(indice, cantidad_escritores) && indice != -1) {

        indice = validar_entero(indice, "Ingrese el indice del escritor de la lectura correspondiente."
        " Si su escritor no aparece en la lista ingrese -1: ", -1);

        if(!validar_opcion(indice, cantidad_escritores) && indice != -1)
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    if(indice == -1) {
        cout << "\nProceda a agregar un nuevo escritor:\n" << endl;
        cin.ignore();
        agregar_escritor();
        indice = cantidad_escritores + 1;
        cout << "\nAhora prosiga creando su lectura." << endl;
    }
    else
        cin.ignore();
    autor = lista_escritores_ -> consulta(indice - 1);

    return autor;
}


int Funcionalidad::ingresar_genero() {

    int genero = 0;
    cout << "Generos disponibles:" << endl;
    cout << "\n[1] - Drama\n\n[2] - Comedia\n\n[3] - Ficcion\n\n[4] - Suspenso\n\n[5] - Terror\n\n[6] - Romantica \n\n[7] - Historica" << endl << endl;
    while(!validar_opcion(genero, 7)) {

        genero = validar_entero(genero, "Ingrese el indice correspondiente al genero de la novela: ", 1);

        if(!validar_opcion(genero, 7))
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    return genero;
}


Lectura* Funcionalidad::crear_novela_historica(string titulo, int duracion, int anio, Escritor* autor) {

    Lectura* novela_historica;
    string tema;
    cout << "\nIngrese el tema historico de la novela: ";
    getline(cin, tema);
    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    novela_historica = new Historica(titulo, duracion, anio, autor, HISTORICA, tema_historico);

    return novela_historica;
}


Lectura* Funcionalidad::crear_novela(string titulo, int duracion, int anio, Escritor* autor) {

    Lectura* novela;
    cout << endl;
    int genero = ingresar_genero();

    cin.ignore();
    if(genero == 7)
        novela = crear_novela_historica(titulo, duracion, anio, autor);
    else
        novela = new Novela(titulo, duracion, anio, autor, (generos) genero);

    return novela;
}


Lectura* Funcionalidad::crear_cuento(string titulo, int duracion, int anio, Escritor* autor) {

    Lectura* cuento;
    cout << "\nIngrese el libro donde se publico el cuento: ";
    string libro_publicado;
    getline(cin, libro_publicado);
    cuento = new Cuento(titulo, duracion, anio, autor, libro_publicado);

    return cuento;
}


Lectura* Funcionalidad::crear_poema(string titulo, int duracion, int anio, Escritor* autor) {
    
    Lectura* poema;
    int cant_versos = 0;

    cout << endl;
    cant_versos = validar_entero(cant_versos, "Ingrese la cantidad de versos del poema: ", 1);

    poema = new Poema(titulo, duracion, anio, autor, cant_versos);
    cin.ignore();

    return poema;
}


Lectura* Funcionalidad::crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* autor) {
    
    Lectura* lectura;

    if(toupper(tipo_lectura) == 'N')
        lectura = crear_novela(titulo, duracion, anio, autor);
    else if(toupper(tipo_lectura) == 'C')
        lectura = crear_cuento(titulo, duracion, anio, autor);
    else
        lectura = crear_poema(titulo, duracion, anio, autor);
    cout << "\n\nSe agrego la lectura " << titulo << " a la lista correctamente.\n" << endl;

    return lectura;
}


void Funcionalidad::agregar_lectura() {

    if(!lista_escritores_ -> vacia()) {
        string titulo; 
        unsigned int duracion = 0, anio = 0;
        int indice = 0, cantidad_escritores = lista_escritores_ -> devolver_cantidad();
        Escritor* autor = NULL;
        Lectura* lectura;

        char tipo_lectura = ingresar_tipo_lectura();

        cout << "\nIngrese el titulo de la lectura: ";
        getline(cin, titulo);

        cout << endl;
        duracion = validar_entero(duracion, "Ingrese la duracion en minutos de su lectura: ", 1);

        cout << endl;
        anio = validar_entero(anio, "Ingrese el anio de publicacion: ", 0);

        cin.ignore();
        char anonimo = ingresar_si_es_anonimo();

        if(toupper(anonimo) == 'N')
            autor = no_es_autor_anonimo(indice, cantidad_escritores);

        lectura = crear_lectura(tipo_lectura, titulo, duracion, anio, autor);
        Lector_lecturas::insertar_lectura_ordenada(lectura, lista_lecturas_);

    }
    else
        cout << "No se encontraron escritores, agregue un escritor desde el menu!" << endl;
}


int Funcionalidad::ingresar_indice_lectura() {

    int indice = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();
    while(!validar_opcion(indice, cantidad_lecturas)) {

        indice = validar_entero(indice, "Ingrese el indice de la lectura a eliminar: ", 1);

        if(!validar_opcion(indice, cantidad_lecturas))
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    return indice;
}


void Funcionalidad::quitar_lectura() {

    if(!lista_lecturas_ -> vacia()) {

        lista_lecturas_ -> imprimir_lista2();

        int indice = ingresar_indice_lectura();
        cout << "\nSe ha eliminado " << lista_lecturas_ -> consulta(indice - 1) -> obtener_titulo() << " correctamente." << endl;
        lista_lecturas_ -> baja(indice - 1);
        cin.ignore();
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::agregar_escritor() {

    string nombre, apellido, nacionalidad;
    int anio_nacimiento = 0, anio_fallecimiento = 0;

    cout << "Ingrese el nombre del escritor a agregar: ";
    getline(cin, nombre);

    cout << "\nIngrese el apellido del escritor a agregar: ";
    getline(cin, apellido);

    cout << "\nIngrese la nacionalidad del escritor a agregar: ";
    getline(cin, nacionalidad);

    cout << endl;
    anio_nacimiento = validar_entero(anio_nacimiento, "Ingrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ", -1);

    cout << endl;
    anio_fallecimiento = validar_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ", -1);

    Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    lista_escritores_ -> alta(escritor, lista_escritores_ -> devolver_cantidad());

    cout << "\n\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente.\n" << endl;
    cin.ignore();
}


int Funcionalidad::ingresar_indice_escritor() {

    int indice = 0, cantidad_escritores = lista_escritores_ -> devolver_cantidad();
    while(!validar_opcion(indice, cantidad_escritores)) {

        indice = validar_entero(indice, "Ingrese el indice del escritor a asignarle el anio: ", 1);

        if(!validar_opcion(indice, cantidad_escritores))
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    return indice;
}


void Funcionalidad::asignar_fallecimiento_escritor() {

    if(!lista_escritores_ -> vacia()) {
        int anio_fallecimiento = 0;

        lista_escritores_ -> imprimir_lista();

        int indice = ingresar_indice_escritor();

        if(lista_escritores_ -> consulta(indice - 1) -> validar_fallecimiento()) {

            cout << endl;
            anio_fallecimiento = validar_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor: ", 0);

            lista_escritores_ -> consulta(indice-1) -> asignar_fallecimiento(anio_fallecimiento);
            cout << "\nSe ha asignado el anio de fallecimiento en " << anio_fallecimiento <<
            " para " << lista_escritores_ -> consulta(indice - 1) -> devolver_nombre_completo() << " correctamente." << endl;
        }
        else
            cout << "\nEste escritor ya tiene anio de fallecimiento asignado" << endl;
        cin.ignore();
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


unsigned int Funcionalidad::ingresar_anio_correcto(unsigned int anio_inferior) {

    unsigned int anio_superior = 0;

    cout << endl;
    while(anio_superior <= anio_inferior) {

        anio_superior = validar_entero(anio_superior, "Ingrese el anio hasta donde desea mostrar las lecturas: ", 1);

        if(anio_superior <= anio_inferior)
            cout << "\nHas ingresado algo erroneo.\nIntentalo nuevamente. ";
    }

    return anio_superior;
}


void Funcionalidad::listar_periodo_lecturas() {

    if(!lista_lecturas_ -> vacia()) {

        int contador = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();
        unsigned int anio_inferior = 0;

        anio_inferior = validar_entero(anio_inferior, "Ingrese el anio desde donde desea mostrar las lecturas: ", 1);

        unsigned int anio_superior = ingresar_anio_correcto(anio_inferior);

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
        cin.ignore();
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_lecturas_de() {

    if(!lista_escritores_ -> vacia()) {

        int contador = 0,
        cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

        lista_escritores_ -> imprimir_lista();

        int indice = ingresar_indice_escritor();
        
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
        cin.ignore();
    }
    else
        cout << "La lista esta vacia!" << endl;
}


void Funcionalidad::listar_novelas_genero() {
    if(!lista_lecturas_ -> vacia()) {
        unsigned int contador = 0;
        int cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

        int genero = ingresar_genero();

        cout << endl;
        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> coinciden_generos(genero)) {
                lista_lecturas_ -> consulta(i) -> mostrar_lectura();
                contador++;
            }
        }

        if(contador == 0)
            cout << "No se han encontrado novelas de ese genero." << endl;
        cin.ignore();
    }
    else
        cout << "La lista esta vacia!" << endl;
}


Funcionalidad::~Funcionalidad() {

    delete lista_escritores_;
    delete lista_lecturas_;
}