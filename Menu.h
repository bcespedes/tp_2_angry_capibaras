# ifndef MENU_H
# define MENU_H


# include "constantes.h"
# include "Lector.h"
# include "LectorEscritores.h"
# include "LectorLecturas.h"
# include "ProcesadorDeOpciones.h"

class Menu {

private:

     // ATRIBUTOS
     int opcion_elegida;
     bool cerrar_menu = false;

     // METODOS
     void mensaje_bienvenida();
     void mensaje_despedida();
     void tecla_continuar();
     void mostrar_menu(); 
     bool procesar_opcion(ProcesadorDeOpciones* procesador_opciones);
     ProcesadorDeOpciones* cargar_archivos(LectorEscritores lector_escritores, LectorLecturas lector_lecturas);

public:

     // PRE:
     // POST:
     Menu();

     // PRE:
     // POST:
     ~Menu();

};


# endif