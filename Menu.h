#ifndef MENU_H
#define MENU_H
#include <string>
#include "lector.h"
#include "lector_escritores.h"
#include "lector_lecturas.h"
#include "funcionalidad.h"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 11;

const std::string OPCION_1 = "1. Agregar una nueva lectura a la lista";
const std::string OPCION_2 = "2. Quitar una lectura de la lista";
const std::string OPCION_3 = "3. Agregar un escritor";
const std::string OPCION_4 = "4. Cambiar fecha de fallecimiento de un escritor";
const std::string OPCION_5 = "5. Listar los escritores";
const std::string OPCION_6 = "6. Sortear una lectura random para leer en una de las tertulias";
const std::string OPCION_7 = "7. Listar todas las lecturas";
const std::string OPCION_8 = "8. Listar las lecturas entre determinados anios";
const std::string OPCION_9 = "9. Listar las lecturas de un determinado escritor";
const std::string OPCION_10 = "10. Listar las novelas de determinado genero";
const std::string OPCION_11 = "11. Armar una cola ordenada por tiempo de lectura";
const std::string OPCION_12 = "12. Salir";

const std::string OPCION_INVALIDA = "Por favor seleccione una opcion valida" ;
const std::string ESCRIBA_OPCION = "\nEscriba una opcion: ";
const std::string MENSAJE_BIENVENIDA =  "Bienvenidos al club de lectura de Sid! Elija lo que desea realizar. \n";

enum cant_opciones{
     AGREGAR_LECTURA = 1, QUITAR_LECTURA, AGREGAR_ESCRITOR, CAMBIAR_FALLECIMIENTO, LISTAR_ESCRITORES, SORTEAR_LECTURA, LISTAR_LECTURAS,
     LISTAR_LECTURAS_POR_PERIODOS, LISTAR_LECTURA_POR_ESCRITOR, LISTAR_NOVELAS_POR_GENERO, ARMAR_COLA, SALIR
};


class Menu {

     private:
          int opcion_elegida;
          bool cerrar_menu = false;
          bool es_opcion_valida();
          void mensaje_bienvenida();
          void tecla_continuar();
     public:
          Menu();
          ~Menu();
          

     private:
          void mostrar_menu(); //privada o publica ver
          
          bool procesar_opcion(Funcionalidad &f);//privada o publica ver
          //Funcionalidad cargar_archivos(Lector_lecturas l, Lector_escritores e);//privada o publica ver
          
          

          
          Lista<Escritor *> *cargar_archivo_e(Lector_escritores e);
          Lista<Lectura *> *cargar_archivo_l(Lector_lecturas l,Lista<Escritor *>*& lista_escritores);

          //int elegir_opcion(int opcion_elegida);

};

#endif