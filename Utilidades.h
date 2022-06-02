# ifndef UTILIDADES_H
# define UTILIDADES_H


# include "constantes.h"
# include "Lectura.h"
# include <limits>


class Utilidades {

public:

    // PRE:
    // POST:
    Utilidades();

    // PRE: -
    // POST: Limpia la pantalla.
    void limpiar_pantalla();

    // PRE:
    // POST:
    bool validar_opcion(int opcion, int opcion_max);

    // PRE: 
    // POST: (MUESTRA EL ERROR SI SE INGRESA ALGO < 1 ADEMAS, PARA HACER ALUSION AL UNSIGNED INT. ESPECIFICAR??)
    int validar_ingreso_entero(int a_validar, string instruccion, int valor_minimo);

    // PRE:
    // POST:
    void insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura *>* lista_lectura);

    // PRE:
    // POST:
    string obtener_nombre_genero(generos genero);

};


# endif