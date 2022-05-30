#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){

     limpiar_pantalla();
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
          limpiar_pantalla();
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

}

bool Menu::procesar_opcion(Funcionalidad &f){
     //cerrar_menu = false;
     switch (opcion_elegida){
          case AGREGAR_LECTURA: 
               break;
          case QUITAR_LECTURA:
               f.quitar_lectura();
               tecla_continuar();
               break;
          case 3:
               break;
          case 4:
               f.asignar_fallecimiento_escritor();
               tecla_continuar();
               break;
          case 5:
               f.listar_escritores();
               tecla_continuar();
               break;
          case 6:
               f.sortear_lectura();
               tecla_continuar();
               break;
          case 7:
               f.listar_lecturas();
               tecla_continuar();
               break;
          case 8:
               f.listar_periodo_lecturas();
               tecla_continuar();
               break;
          case 9:
               f.listar_lecturas_de();
               tecla_continuar();
               break;
          case 10:
               break;
          case 11:
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

void Menu::limpiar_pantalla(){
#ifdef _WIN32
        system("cls");
#else
        system ("clear");
#endif
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
limpiar_pantalla();
}

Menu::~Menu(){

}

