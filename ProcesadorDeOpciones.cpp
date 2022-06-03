# include "ProcesadorDeOpciones.h"


ProcesadorDeOpciones::ProcesadorDeOpciones(Lista<Escritor*>* lista_escritores, Lista<Lectura*>* lista_lecturas) {

    lista_escritores_ = lista_escritores;
    lista_lecturas_ = lista_lecturas;
}


char ProcesadorDeOpciones::ingresar_tipo_lectura() {

    string tipo_lectura_ingresada = "XX";
    char tipo_lectura = 'X';
    cout << "Tipos de lectura disponibles:" << endl;
    cout << "\n[N] - Novela\n\n[C] - Cuento\n\n[P] - Poema" << endl << endl;
    
    while((tipo_lectura != CUENTO && tipo_lectura != POEMA && tipo_lectura != NOVELA) || tipo_lectura_ingresada.length() > 1) {

        cout << "Ingrese la letra segun el tipo de lectura a agregar: ";
        getline(cin, tipo_lectura_ingresada);
        tipo_lectura = (char) toupper(tipo_lectura_ingresada[0]);

        if((tipo_lectura != CUENTO && tipo_lectura != POEMA && tipo_lectura != NOVELA) || tipo_lectura_ingresada.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }
    
    return tipo_lectura;
}


char ProcesadorDeOpciones::ingresar_si_es_anonimo() {

    string anonimo_ingresado = "XX";
    char anonimo = 'X';
    cout << endl;

    while((anonimo != 'S' && anonimo != 'N') || anonimo_ingresado.length() > 1) {
    
        cout << "Su escritor es anonimo? (S / N): ";
        getline(cin, anonimo_ingresado);
        anonimo = (char) toupper(anonimo_ingresado[0]);
    
        if((anonimo != 'S' && anonimo != 'N') || anonimo_ingresado.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return anonimo;
}


Escritor* ProcesadorDeOpciones::no_es_escritor_anonimo(int indice, int cantidad_escritores) {

    Utilidades validador;
    Escritor* escritor;
    cout << endl;

    for(int i = 0; i < lista_escritores_ -> obtener_cantidad(); i++)
        cout << "[" << i + 1 << "] - " << lista_escritores_ -> consulta(i) -> obtener_nombre_completo() << endl << endl;

    while (!validador.validar_opcion(indice, cantidad_escritores) && indice != OPCION_ALTERNATIVA) {

        indice = validador.validar_ingreso_entero(indice, "Ingrese el indice del escritor de la lectura correspondiente."
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

        genero = validador.validar_ingreso_entero(genero, "Ingrese el indice correspondiente al genero de la novela: ", OPCION_MINIMA);

        if(!validador.validar_opcion(genero, HISTORICA))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return genero;
}


Lectura* ProcesadorDeOpciones::crear_novela_historica(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* novela_historica;
    string tema;
    cout << "\nIngrese el tema historico de la novela: ";
    getline(cin, tema);
    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    novela_historica = new Historica(titulo, duracion, anio, escritor, leido, HISTORICA, tema_historico);

    return novela_historica;
}


Lectura* ProcesadorDeOpciones::crear_novela(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* novela;
    cout << endl;
    int genero = ingresar_genero();

    if(genero == 7)
        novela = crear_novela_historica(titulo, duracion, anio, escritor, leido);
    else
        novela = new Novela(titulo, duracion, anio, escritor, leido, (generos) genero);

    return novela;
}


Lectura* ProcesadorDeOpciones::crear_cuento(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* cuento;
    cout << "\nIngrese el libro donde se publico el cuento: ";
    string libro_publicado;
    getline(cin, libro_publicado);
    cuento = new Cuento(titulo, duracion, anio, escritor, leido, libro_publicado);

    return cuento;
}


Lectura* ProcesadorDeOpciones::crear_poema(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Utilidades validador;
    Lectura* poema;
    int cant_versos = 0;

    cout << endl;
    cant_versos = validador.validar_ingreso_entero(cant_versos, "Ingrese la cantidad de versos del poema: ", OPCION_MINIMA);

    poema = new Poema(titulo, duracion, anio, escritor, leido, cant_versos);

    return poema;
}


Lectura* ProcesadorDeOpciones::crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* escritor) {
    
    Lectura* lectura;
    bool leido = false;

    if(toupper(tipo_lectura) == NOVELA)
        lectura = crear_novela(titulo, duracion, anio, escritor, leido);
    else if(toupper(tipo_lectura) == CUENTO)
        lectura = crear_cuento(titulo, duracion, anio, escritor, leido);
    else
        lectura = crear_poema(titulo, duracion, anio, escritor, leido);
    cout << "\n\nSe agrego la lectura " << titulo << " a la lista correctamente.\n" << endl;

    return lectura;
}


void ProcesadorDeOpciones::agregar_lectura() {

    Utilidades validador, insertador;
    string titulo;
    unsigned int duracion = 0, anio = 0;
    char anonimo = 'X';
    int indice = 0, cantidad_escritores = lista_escritores_ -> obtener_cantidad();
    Escritor* escritor = NULL;
    Lectura* lectura;

    char tipo_lectura = ingresar_tipo_lectura();

    cout << "\nIngrese el titulo de la lectura: ";
    getline(cin, titulo);

    cout << endl;
    duracion = validador.validar_ingreso_entero(duracion, "Ingrese la duracion en minutos de su lectura: ", OPCION_MINIMA);

    cout << endl;
    anio = validador.validar_ingreso_entero(anio, "Ingrese el anio de publicacion: ", OPCION_MINIMA);

    if(!lista_escritores_ -> vacia())
        anonimo = ingresar_si_es_anonimo();
    else
        cout << "\nNo hay escritores cargados, por lo tanto su lectura se creara con escritor anonimo." << endl;

    if(toupper(anonimo) == NOVELA)
        escritor = no_es_escritor_anonimo(indice, cantidad_escritores);

    lectura = crear_lectura(tipo_lectura, titulo, duracion, anio, escritor);
    insertador.insertar_lectura_ordenada(lectura, lista_lecturas_);

}


int ProcesadorDeOpciones::ingresar_indice_lista(string instruccion, int cantidad_datos) {

    Utilidades validador;
    int indice = 0;
    while(!validador.validar_opcion(indice, cantidad_datos)) {

        indice = validador.validar_ingreso_entero(indice, instruccion, OPCION_MINIMA);

        if(!validador.validar_opcion(indice, cantidad_datos))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return indice;
}


void ProcesadorDeOpciones::quitar_lectura() {

    if(!lista_lecturas_ -> vacia()) {

        lista_lecturas_ -> imprimir_lista_lecturas();

        int indice = ingresar_indice_lista("Ingrese el indice de la lectura a eliminar: ", lista_lecturas_ -> obtener_cantidad());
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
    anio_nacimiento = validador.validar_ingreso_entero(anio_nacimiento, "Ingrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ", OPCION_ALTERNATIVA);

    cout << endl;
    anio_fallecimiento = validador.validar_ingreso_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ", OPCION_ALTERNATIVA);

    Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    lista_escritores_ -> alta(escritor, lista_escritores_ -> obtener_cantidad());

    cout << "\n\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente.\n" << endl;
}


void ProcesadorDeOpciones::asignar_fallecimiento_escritor() {

    if(!lista_escritores_ -> vacia()) {
        Utilidades validador;
        int anio_fallecimiento = 0;

        lista_escritores_ -> imprimir_lista_escritores();

        int indice = ingresar_indice_lista("Ingrese el indice del escritor a asignarle el anio: ", lista_escritores_ -> obtener_cantidad());

        if(lista_escritores_ -> consulta(indice - 1) -> verificar_fallecimiento()) {

            cout << endl;
            anio_fallecimiento = validador.validar_ingreso_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor: ", OPCION_MINIMA);

            lista_escritores_ -> consulta(indice - 1) -> asignar_fallecimiento(anio_fallecimiento);
            cout << "\nSe ha asignado el anio de fallecimiento en " << anio_fallecimiento <<
            " para " << lista_escritores_ -> consulta(indice - 1) -> obtener_nombre_completo() << " correctamente." << endl;
        }
        else
            cout << "\nEste escritor ya tiene anio de fallecimiento asignado" << endl;
    }
    else
        cout << LISTA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::listar_escritores() {

    if(!lista_escritores_ -> vacia())
        lista_escritores_ -> imprimir_lista_escritores();
    else
        cout << LISTA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::sortear_lectura() {

    if(!lista_lecturas_ -> vacia()) {
        srand((unsigned int) time(NULL));
        int sorteo = rand() % (lista_lecturas_ -> obtener_cantidad() + 0);
        cout << "Se leera la lectura numero: " << sorteo + 1 << " - " << lista_lecturas_ -> consulta(sorteo) -> obtener_titulo() << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_lecturas() {

    if(!lista_lecturas_ -> vacia())
        lista_lecturas_ -> imprimir_lista_lecturas();
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::ingresar_anio_correcto(int anio_inferior) {

    Utilidades validador;
    int anio_superior = 0;

    cout << endl;
    while(anio_superior <= anio_inferior) {

        anio_superior = validador.validar_ingreso_entero(anio_superior, "Ingrese el anio hasta donde desea mostrar las lecturas: ", OPCION_MINIMA);

        if(anio_superior <= anio_inferior)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return anio_superior;
}


void ProcesadorDeOpciones::listar_periodo_lecturas() {

    if(!lista_lecturas_ -> vacia()) {

        Utilidades validador;
        int contador = 0, cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();
        unsigned int anio_inferior = 0;

        anio_inferior = validador.validar_ingreso_entero(anio_inferior, "Ingrese el anio desde donde desea mostrar las lecturas: ", OPCION_MINIMA);

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


Escritor* ProcesadorDeOpciones::ingresar_escritor() {

    for(int i = 0; i < lista_escritores_ -> obtener_cantidad(); i++)
        cout << "[" << i + 1 << "] - " << lista_escritores_ -> consulta(i) -> obtener_nombre_completo() << endl << endl;

    int indice = ingresar_indice_lista("Ingrese el indice del escritor del cual desea conocer las obras: ", lista_escritores_ -> obtener_cantidad());
    
    Escritor* escritor = lista_escritores_ -> consulta(indice - 1);

    return escritor;
}


void ProcesadorDeOpciones::listar_lecturas_de() {

    if(!lista_lecturas_ -> vacia()) {

        int contador_lecturas = 0,
        cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();

        Escritor* escritor = ingresar_escritor();

        for(int i = 0; i < cantidad_lecturas; i++) {

            if(lista_lecturas_ -> consulta(i) -> obtener_escritor() == escritor) {
                contador_lecturas++;

                if(contador_lecturas == 1)
                    cout << "\nLas obras de " << escritor -> obtener_nombre_completo() << " son:" << endl;

                cout << endl << contador_lecturas << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }

        if(contador_lecturas == 0)
            cout << "\nEste escritor no tiene cargada ninguna lectura." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_novelas_genero() {

    if(!lista_lecturas_ -> vacia()) {

        int contador_novelas = 0, cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();
        Utilidades conversor_a_genero;

        int genero = ingresar_genero();

        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> coinciden_generos(genero)) {
                contador_novelas++;
                if(contador_novelas == 1)
                    cout << "\nLas novelas del genero " << conversor_a_genero.obtener_nombre_genero((generos) genero) << " son:" << endl;
                cout << endl << contador_novelas << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }

        if(contador_novelas == 0)
            cout << "\nNo se han encontrado novelas de ese genero." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::obtener_indice_maximos_minutos(int cantidad_elementos, Lectura* lectura) {

    int indice_maximos_minutos = 0;
    for(int i = 0; i < cantidad_elementos; i++) {
        if((lectura -> comparar_por_duracion(lista_lecturas_ -> consulta(i)) == -1)) {
            indice_maximos_minutos = i;
            lectura = lista_lecturas_ -> consulta(indice_maximos_minutos);
        }
    }

    return indice_maximos_minutos;
}


int ProcesadorDeOpciones::obtener_indices_en_orden(int cantidad_elementos, Lectura* lectura, int* vector_indices) {

    Utilidades buscador;
    int indice = 0;
    for(int i = 0; i < cantidad_elementos; i++) {
        if(lectura -> comparar_por_duracion(lista_lecturas_ -> consulta(i)) == 1 && !buscador.esta_elemento_en_vector(vector_indices, cantidad_elementos - 1, i) && !lista_lecturas_ -> consulta(i) -> obtener_leido()) {
            indice = i;
            lectura = lista_lecturas_ -> consulta(indice);
        }
    }

    return indice;
}


char ProcesadorDeOpciones::ingresar_si_quiere_seguir_leyendo() {

    string seguir_leyendo_ingresado = "XX";
    char seguir_leyendo = 'X';
    cout << endl;

    while((seguir_leyendo != 'S' && seguir_leyendo != 'N') || seguir_leyendo_ingresado.length() > 1) {
    
        Utilidades limpiador;
        cout << "Quiere leer esta lectura? (S / N): ";
        getline(cin, seguir_leyendo_ingresado);
        seguir_leyendo = (char) toupper(seguir_leyendo_ingresado[0]);
    
        if((seguir_leyendo != 'S' && seguir_leyendo != 'N') || seguir_leyendo_ingresado.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;

        else if(seguir_leyendo == 'S') {
            limpiador.limpiar_pantalla();
            cout << "Has leido esa lectura!\n" << endl;
        }
        else
            cout << "Has dejado de leer por ahora" << endl;
    }

    return seguir_leyendo;
}


void ProcesadorDeOpciones::crear_cola_ordenada() {

    Cola<Lectura *>* cola_lecturas = new Cola<Lectura *>();

    Lectura* lectura = lista_lecturas_ -> consulta(0);

    int cantidad_recorridos = -1, indice = 0, indice_maximos_minutos = 0, cantidad_elementos = lista_lecturas_ -> obtener_cantidad();

    int vector_indices[cantidad_elementos - 1];

    char seguir_leyendo = 'X';

    // Se crea un vector estatico, a priori se sabe la cantidad de elementos, no tiene sentido hacerlo dinamico.
    std::fill_n(vector_indices, cantidad_elementos - 1, -1);

    // Se rellena el vector con -1 por si acaso, ya que al estar relleno de numeros basura se nos puede generar un numero que justo coincida con un indice en la lista.
    int cantidad_elementos_cola = 0;

    for(int i = 0; i < lista_lecturas_ -> obtener_cantidad(); i++) {
        if(lista_lecturas_ -> consulta(i) -> obtener_leido() == false)
            cantidad_elementos_cola++;
    }

    cout << cantidad_elementos_cola << "<- cantidad cola" << endl;

    indice_maximos_minutos = obtener_indice_maximos_minutos(cantidad_elementos, lectura);
    // Se busca el elemento que tiene el mayor tiempo de lectura.

    while(cola_lecturas -> obtener_cantidad() < cantidad_elementos_cola) {
        indice = obtener_indices_en_orden(cantidad_elementos, lectura, vector_indices);
        cantidad_recorridos++;
        vector_indices[cantidad_recorridos] = indice;
        cola_lecturas -> alta(lista_lecturas_ -> consulta(indice));
        lectura = lista_lecturas_ -> consulta(indice_maximos_minutos);
    }
    // Se colocan todos los elementos en orden en la cola desde el primero hasta el ultimo - 1.
    bool leido = true;

    if(lista_lecturas_ -> consulta(indice_maximos_minutos) -> obtener_leido() == false)
        cola_lecturas -> alta(lista_lecturas_ -> consulta(indice_maximos_minutos));

    if(!cola_lecturas ->vacia()) {
        while(seguir_leyendo != 'N' && !cola_lecturas -> vacia()){
            cola_lecturas -> consulta() -> mostrar_lectura();
            seguir_leyendo = ingresar_si_quiere_seguir_leyendo();
            if(seguir_leyendo == 'S') {
                cola_lecturas -> consulta() -> asignar_leido(leido);
                cola_lecturas -> consulta() -> mostrar_lectura();
                cout << cola_lecturas -> consulta() -> obtener_leido() << endl;
                cola_lecturas -> baja();
            }
        }
    }
    else
        cout << "LA COLA ESTA VACIA!!!";
    // Solo para mostrar que la cola se creo en orden.

}


void ProcesadorDeOpciones::cocinar_pastel_de_papa() {
    #ifdef _WIN32
        srand((unsigned int) time(NULL));
        if ((rand() % 2) + 1 ==  2)
            system("start https://ibb.co/w68fpdp");
        else 
            system("start https://ibb.co/ZmVg5gD");

     #else
        srand((unsigned int) time(NULL));
        if ((rand() % 2) + 1 ==  2)
            system("xdg-open https://ibb.co/w68fpdp");
        else 
            system("xdg-open https://ibb.co/ZmVg5gD");
     #endif
     cout << "Has descubierto un secreto" << endl;
}


ProcesadorDeOpciones::~ProcesadorDeOpciones() {

    delete lista_escritores_;
    delete lista_lecturas_;
}