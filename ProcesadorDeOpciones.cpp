# include "ProcesadorDeOpciones.h"


ProcesadorDeOpciones::ProcesadorDeOpciones(Lista<Escritor *>* lista_escritores, Lista<Lectura *>* lista_lecturas) {

    lista_escritores_ = lista_escritores;
    lista_lecturas_ = lista_lecturas;
}


char ProcesadorDeOpciones::ingresar_tipo_lectura() {

    string tipo_lectura = "XX";
    cout << "Tipos de lectura disponibles:" << endl;
    cout << "\n[N] - Novela\n\n[C] - Cuento\n\n[P] - Poema" << endl << endl;
    while((toupper(tipo_lectura[0]) != 'C' && toupper(tipo_lectura[0]) != 'P' && toupper(tipo_lectura[0]) != 'N') || tipo_lectura.length() > 1) {
        cout << "Ingrese la letra segun el tipo de lectura a agregar: ";
        getline(cin, tipo_lectura);
        if((toupper(tipo_lectura[0]) != 'C' && toupper(tipo_lectura[0]) != 'P' && toupper(tipo_lectura[0]) != 'N') || tipo_lectura.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }
    
    return tipo_lectura[0];
}


char ProcesadorDeOpciones::ingresar_si_es_anonimo() {

    string anonimo = "XX";
    while((toupper(anonimo[0]) != 'S' && toupper(anonimo[0]) != 'N') || anonimo.length() > 1) {
        cout << "\nSu escritor es anonimo? (S / N): ";
        getline(cin, anonimo);
        if((toupper(anonimo[0]) != 'S' && toupper(anonimo[0]) != 'N') || anonimo.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return anonimo[0];
}


Escritor* ProcesadorDeOpciones::no_es_escritor_anonimo(int indice, int cantidad_escritores) {

    Utilidades validador;
    Escritor* escritor;
    cout << endl;

    for(int i = 0; i < lista_escritores_ -> devolver_cantidad(); i++)
        cout << "[" << i + 1 << "] - " << lista_escritores_ -> consulta(i) -> devolver_nombre_completo() << endl << endl;

    while (!validador.validar_opcion(indice, cantidad_escritores) && indice != OPCION_ALTERNATIVA) {

        indice = validador.validar_entero(indice, "Ingrese el indice del escritor de la lectura correspondiente."
        " Si su escritor no aparece en la lista ingrese -1: ", OPCION_ALTERNATIVA);

        if(!validador.validar_opcion(indice, cantidad_escritores) && indice != OPCION_ALTERNATIVA)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    if(indice == OPCION_ALTERNATIVA) {
        cout << "\nProceda a agregar un nuevo escritor:\n" << endl;
        agregar_escritor();
        indice = cantidad_escritores + 1;
        cout << "\nAhora prosiga creando su lectura." << endl;
    }

    escritor = lista_escritores_ -> consulta(indice - 1);

    return escritor;
}


int ProcesadorDeOpciones::ingresar_genero() {

    Utilidades validador;
    int genero = 0;
    cout << "Generos disponibles:" << endl;
    cout << "\n[1] - Drama\n\n[2] - Comedia\n\n[3] - Ficcion\n\n[4] - Suspenso\n\n[5] - Terror\n\n[6] - Romantica \n\n[7] - Historica" << endl << endl;
    while(!validador.validar_opcion(genero, HISTORICA)) {

        genero = validador.validar_entero(genero, "Ingrese el indice correspondiente al genero de la novela: ", OPCION_MINIMA);

        if(!validador.validar_opcion(genero, HISTORICA))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return genero;
}


Lectura* ProcesadorDeOpciones::crear_novela_historica(string titulo, int duracion, int anio, Escritor* escritor) {

    Lectura* novela_historica;
    string tema;
    cout << "\nIngrese el tema historico de la novela: ";
    getline(cin, tema);
    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    novela_historica = new Historica(titulo, duracion, anio, escritor, HISTORICA, tema_historico);

    return novela_historica;
}


Lectura* ProcesadorDeOpciones::crear_novela(string titulo, int duracion, int anio, Escritor* escritor) {

    Lectura* novela;
    cout << endl;
    int genero = ingresar_genero();

    if(genero == 7)
        novela = crear_novela_historica(titulo, duracion, anio, escritor);
    else
        novela = new Novela(titulo, duracion, anio, escritor, (generos) genero);

    return novela;
}


Lectura* ProcesadorDeOpciones::crear_cuento(string titulo, int duracion, int anio, Escritor* escritor) {

    Lectura* cuento;
    cout << "\nIngrese el libro donde se publico el cuento: ";
    string libro_publicado;
    getline(cin, libro_publicado);
    cuento = new Cuento(titulo, duracion, anio, escritor, libro_publicado);

    return cuento;
}


Lectura* ProcesadorDeOpciones::crear_poema(string titulo, int duracion, int anio, Escritor* escritor) {

    Utilidades validador;
    Lectura* poema;
    int cant_versos = 0;

    cout << endl;
    cant_versos = validador.validar_entero(cant_versos, "Ingrese la cantidad de versos del poema: ", OPCION_MINIMA);

    poema = new Poema(titulo, duracion, anio, escritor, cant_versos);

    return poema;
}


Lectura* ProcesadorDeOpciones::crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* escritor) {
    
    Lectura* lectura;

    if(toupper(tipo_lectura) == 'N')
        lectura = crear_novela(titulo, duracion, anio, escritor);
    else if(toupper(tipo_lectura) == 'C')
        lectura = crear_cuento(titulo, duracion, anio, escritor);
    else
        lectura = crear_poema(titulo, duracion, anio, escritor);
    cout << "\n\nSe agrego la lectura " << titulo << " a la lista correctamente.\n" << endl;

    return lectura;
}


void ProcesadorDeOpciones::agregar_lectura() {

    Utilidades validador, insertador;
    string titulo;
    unsigned int duracion = 0, anio = 0;
    char anonimo = 'X';
    int indice = 0, cantidad_escritores = lista_escritores_ -> devolver_cantidad();
    Escritor* escritor = NULL;
    Lectura* lectura;

    char tipo_lectura = ingresar_tipo_lectura();

    cout << "\nIngrese el titulo de la lectura: ";
    getline(cin, titulo);

    cout << endl;
    duracion = validador.validar_entero(duracion, "Ingrese la duracion en minutos de su lectura: ", OPCION_MINIMA);

    cout << endl;
    anio = validador.validar_entero(anio, "Ingrese el anio de publicacion: ", OPCION_MINIMA);

    if(!lista_escritores_ -> vacia())
        anonimo = ingresar_si_es_anonimo();
    else
        cout << "\nNo hay escritores cargados, por lo tanto su lectura se creara con escritor anonimo." << endl;

    if(toupper(anonimo) == 'N')
        escritor = no_es_escritor_anonimo(indice, cantidad_escritores);

    lectura = crear_lectura(tipo_lectura, titulo, duracion, anio, escritor);
    insertador.insertar_lectura_ordenada(lectura, lista_lecturas_);

}


int ProcesadorDeOpciones::ingresar_indice_lista(string instruccion, int cantidad_datos) {

    Utilidades validador;
    int indice = 0;
    while(!validador.validar_opcion(indice, cantidad_datos)) {

        indice = validador.validar_entero(indice, instruccion, OPCION_MINIMA);

        if(!validador.validar_opcion(indice, cantidad_datos))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return indice;
}


void ProcesadorDeOpciones::quitar_lectura() {

    if(!lista_lecturas_ -> vacia()) {

        lista_lecturas_ -> imprimir_lista2();

        int indice = ingresar_indice_lista("Ingrese el indice de la lectura a eliminar: ", lista_lecturas_ -> devolver_cantidad());
        cout << "\nSe ha eliminado " << lista_lecturas_ -> consulta(indice - 1) -> obtener_titulo() << " correctamente." << endl;
        lista_lecturas_ -> baja(indice - 1);
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::agregar_escritor() {

    Utilidades validador;
    string nombre, apellido, nacionalidad;
    int anio_nacimiento = 0, anio_fallecimiento = 0;

    cout << "Ingrese el nombre del escritor a agregar: ";
    getline(cin, nombre);

    cout << "\nIngrese el apellido del escritor a agregar: ";
    getline(cin, apellido);

    cout << "\nIngrese la nacionalidad del escritor a agregar: ";
    getline(cin, nacionalidad);

    cout << endl;
    anio_nacimiento = validador.validar_entero(anio_nacimiento, "Ingrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ", OPCION_ALTERNATIVA);

    cout << endl;
    anio_fallecimiento = validador.validar_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ", OPCION_ALTERNATIVA);

    Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    lista_escritores_ -> alta(escritor, lista_escritores_ -> devolver_cantidad());

    cout << "\n\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente.\n" << endl;
}


void ProcesadorDeOpciones::asignar_fallecimiento_escritor() {

    if(!lista_escritores_ -> vacia()) {
        Utilidades validador;
        int anio_fallecimiento = 0;

        lista_escritores_ -> imprimir_lista();

        int indice = ingresar_indice_lista("Ingrese el indice del escritor a asignarle el anio: ", lista_escritores_ -> devolver_cantidad());

        if(lista_escritores_ -> consulta(indice - 1) -> validar_fallecimiento()) {

            cout << endl;
            anio_fallecimiento = validador.validar_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor: ", OPCION_MINIMA);

            lista_escritores_ -> consulta(indice - 1) -> asignar_fallecimiento(anio_fallecimiento);
            cout << "\nSe ha asignado el anio de fallecimiento en " << anio_fallecimiento <<
            " para " << lista_escritores_ -> consulta(indice - 1) -> devolver_nombre_completo() << " correctamente." << endl;
        }
        else
            cout << "\nEste escritor ya tiene anio de fallecimiento asignado" << endl;
    }
    else
        cout << LISTA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::listar_escritores() {

    if(!lista_escritores_ -> vacia())
        lista_escritores_ -> imprimir_lista();
    else
        cout << LISTA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::sortear_lectura() {

    if(!lista_lecturas_ -> vacia()) {
        srand((unsigned int) time(NULL));
        int sorteo = rand() % (lista_lecturas_ -> devolver_cantidad() + 0);
        cout << "Se leera la lectura numero: " << sorteo + 1 << " - " << lista_lecturas_ -> consulta(sorteo) -> obtener_titulo() << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_lecturas() {

    if(!lista_lecturas_ -> vacia())
        lista_lecturas_ -> imprimir_lista2();
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::ingresar_anio_correcto(int anio_inferior) {

    Utilidades validador;
    int anio_superior = 0;

    cout << endl;
    while(anio_superior <= anio_inferior) {

        anio_superior = validador.validar_entero(anio_superior, "Ingrese el anio hasta donde desea mostrar las lecturas: ", OPCION_MINIMA);

        if(anio_superior <= anio_inferior)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return anio_superior;
}


void ProcesadorDeOpciones::listar_periodo_lecturas() {

    if(!lista_lecturas_ -> vacia()) {

        Utilidades validador;
        int contador = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();
        unsigned int anio_inferior = 0;

        anio_inferior = validador.validar_entero(anio_inferior, "Ingrese el anio desde donde desea mostrar las lecturas: ", OPCION_MINIMA);

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
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_lecturas_de() {

    if(!lista_lecturas_ -> vacia()) {

        int contador = 0,
        cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();

        for(int i = 0; i < lista_escritores_ -> devolver_cantidad(); i++)
            cout << "[" << i + 1 << "] - " << lista_escritores_ -> consulta(i) -> devolver_nombre_completo() << endl << endl;

        int indice = ingresar_indice_lista("Ingrese el indice del escritor del cual desea conocer las obras: ", lista_escritores_ -> devolver_cantidad());
        
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
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_novelas_genero() {

    if(!lista_lecturas_ -> vacia()) {
        int contador = 0, cantidad_lecturas = lista_lecturas_ -> devolver_cantidad();
        Utilidades conversor_a_genero;

        int genero = ingresar_genero();

        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> coinciden_generos(genero)) {
                contador++;
                if(contador == 1)
                    cout << "\nLas novelas del genero " << conversor_a_genero.obtener_nombre_genero((generos) genero) << " son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }

        if(contador == 0)
            cout << "\nNo se han encontrado novelas de ese genero." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


ProcesadorDeOpciones::~ProcesadorDeOpciones() {

    delete lista_escritores_;
    delete lista_lecturas_;
}