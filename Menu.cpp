#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){

     Funcionalidad::limpiar_pantalla();
     mensaje_bienvenida();
     opcion_elegida = 0;
     Lector_escritores e;
     Lector_lecturas l;
     //Funcionalidad f = cargar_archivos(l,e);
     
     Lista<Escritor *> * le = cargar_archivo_e(e);
     Lista<Lectura *> * ll = cargar_archivo_l(l,le);

     Funcionalidad f(le,ll);

     //bool cerrar_menu = false;
     //mostrar_menu();

     while (!cerrar_menu){
          mostrar_menu();
          cout << ESCRIBA_OPCION;
          cin >> opcion_elegida;
          Funcionalidad::limpiar_pantalla();
          cerrar_menu = procesar_opcion(f);
     }

     //limpiar_pantalla();
     //procesar_opcion(f);
     //f.~Funcionalidad();
     

     le->~Lista();
     ll->~Lista();

     delete le;
     delete ll;
     
}
/*
Funcionalidad Menu::cargar_archivos(Lector_lecturas l, Lector_escritores e){
     Lista<Escritor *> *lista_escritores = e.procesar_escritores();
     Lista<Lectura *> *lista_lecturas = l.procesar_lecturas(lista_escritores);
     Funcionalidad f(lista_escritores, lista_lecturas);
     //return f;
     lista_escritores->~Lista();
     lista_lecturas->~Lista();

     delete lista_lecturas;
     delete lista_escritores;
     //Devolver un objeto funcionalidad con listas en los metodos
}
*/
Lista<Escritor *> *Menu::cargar_archivo_e(Lector_escritores e){
     Lista<Escritor *> *lista_escritores = e.procesar_escritores();
     return lista_escritores;
}

Lista<Lectura *> *Menu::cargar_archivo_l(Lector_lecturas l,Lista<Escritor *>*& lista_escritores){
     Lista<Lectura *> *lista_lecturas = l.procesar_lecturas(lista_escritores);
     return lista_lecturas;
}

void Menu::mostrar_menu(){

     cout << OPCION_1 << endl;
     cout << OPCION_2 << endl;
     cout << OPCION_3 << endl;
     cout << OPCION_4 << endl;
     cout << OPCION_5 << endl;
     cout << OPCION_6 << endl;
     cout << OPCION_7 << endl;
     cout << OPCION_8 << endl;
     cout << OPCION_9 << endl;
     cout << OPCION_10 << endl;
     cout << OPCION_11 << endl;
     cout << OPCION_12 << endl;
}

bool Menu::procesar_opcion(Funcionalidad &f){
     //cerrar_menu = false;
     switch (opcion_elegida){
          case AGREGAR_LECTURA: 
               f.agregar_lectura();
               tecla_continuar();
               break;
          case QUITAR_LECTURA:
               f.quitar_lectura();
               tecla_continuar();
               break;
          case AGREGAR_ESCRITOR:
               f.agregar_escritor();
               tecla_continuar();
               break;
          case CAMBIAR_FALLECIMIENTO:
               f.asignar_fallecimiento_escritor();
               tecla_continuar();
               break;
          case LISTAR_ESCRITORES:
               f.listar_escritores();
               tecla_continuar();
               break;
          case SORTEAR_LECTURA:
               f.sortear_lectura();
               tecla_continuar();
               break;
          case LISTAR_LECTURAS:
               f.listar_lecturas();
               tecla_continuar();
               break;
          case LISTAR_LECTURAS_POR_PERIODOS:
               f.listar_periodo_lecturas();
               tecla_continuar();
               break;
          case LISTAR_LECTURA_POR_ESCRITOR:
               f.listar_lecturas_de();
               tecla_continuar();
               break;
          case LISTAR_NOVELAS_POR_GENERO:
          //listar por genero
               break;
          case ARMAR_COLA:
               //armar cola
               break;
          case SALIR:
               cerrar_menu = true;
               break;
          default:
               cout << OPCION_INVALIDA << endl;
               cout << endl;     
     }         

     return cerrar_menu;
}


bool Menu::es_opcion_valida(){
     return (opcion_elegida >= OPCION_MINIMA && opcion_elegida <= OPCION_MAXIMA);
}



void Menu::mensaje_bienvenida(){
     cout << MENSAJE_BIENVENIDA << endl;
}

void Menu::tecla_continuar(){
cout << endl;
#ifdef _WIN32
        system("pause");
#else
        cout << "Presione Enter para continuar: ";
        cin.ignore();
        cin.ignore();
        
     
#endif
Funcionalidad::limpiar_pantalla();
}

Menu::~Menu(){

}

