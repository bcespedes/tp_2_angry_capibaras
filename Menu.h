# ifndef MENU_H
# define MENU_H


# include "constantes.h"
# include "Lector.h"
# include "LectorEscritores.h"
# include "LectorLecturas.h"
# include "ProcesadorDeOpciones.h"


class Menu {

private:

     int opcion_elegida;
     bool cerrar_menu = false;
     void mensaje_bienvenida();
     void mensaje_despedida();
     void tecla_continuar();

public:

     // PRE:
     // POST:
     Menu();

     // PRE:
     // POST:
     ~Menu();

private:

     void mostrar_menu(); //privada o publica ver
     bool procesar_opcion(ProcesadorDeOpciones* procesador_opciones);//privada o publica ver
     ProcesadorDeOpciones* cargar_archivos(LectorEscritores lector_escritores, LectorLecturas lector_lecturas);//privada o publica ver

};


# endif