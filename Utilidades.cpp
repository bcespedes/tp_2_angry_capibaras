# include "Utilidades.h"
# include <limits>


Utilidades::Utilidades() {

}


void Utilidades::limpiar_pantalla() {

    #ifdef _WIN32
            system("cls");
    #else
            system ("clear");
    #endif
}


bool Utilidades::validar_opcion(int opcion, int opcion_max) {

    return (1 <= opcion && opcion <= opcion_max);
}


int Utilidades::validar_entero(int a_validar, string instruccion, int valor_minimo) {

    cout << instruccion;
    cin >> a_validar;
    while(!cin.good() || a_validar < valor_minimo) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nNo has ingresado un valor esperado.\nIntentalo nuevamente. ";
        cout << instruccion;
        cin >> a_validar;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return a_validar;
}


void Utilidades::insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura *>* lista_lectura) {
    int pos = 0;
    bool avanzar = true;

    lista_lectura -> inicializar();
    if(!lista_lectura -> vacia()) {
    
        while(avanzar) {
            if(lectura -> comparar(lista_lectura -> consulta(pos)) == -1) {
                avanzar = false;
                pos--;
            }
            if(!lista_lectura -> hay_siguiente()) {
                pos++;
                avanzar = false;
            }
            else {
                pos++;
                lista_lectura -> siguiente();
            }
        }
    }

    lista_lectura -> alta(lectura, pos);
}