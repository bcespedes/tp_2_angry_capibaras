#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){

     limpiar_pantalla();
     mensaje_bienvenida();
     opcion_elegida = 0;
     Lector_escritores e;
     Lector_lecturas l;
     cargar_archivos(l,e);
     
     //mostrar_menu();
     cout << ESCRIBA_OPCION;
     cin >> opcion_elegida;

     while (!es_opcion_valida()){
          limpiar_pantalla();
          mostrar_menu();
          cout << OPCION_INVALIDA;
          cin >> opcion_elegida;
     }
     
     limpiar_pantalla();
     procesar_opcion();

}

void Menu::cargar_archivos(Lector_lecturas l, Lector_escritores e){
     Lista<Escritor *> *lista_escritores = e.procesar_escritores();
     Lista<Lectura *> *lista_lecturas = l.procesar_lecturas(lista_escritores);
     //lista_escritores->~Lista();
     //lista_lecturas->~Lista(); 
     //Devolver un objeto funcionalidad con listas en los metodos
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

void Menu::procesar_opcion(){

     switch (opcion_elegida){
          case AGREGAR_LECTURA:
               break;
          case QUITAR_LECTURA:
               break;
          case 3:
               break;
          case 4:
               break;
          case 5:
               break;
          case 6:
               break;
          case 7:
               break;
          case 8:
               break;
          case 9:
               break;
          case 10:
               break;
          case 11:
               break;

          default:
               cout << OPCION_INVALIDA << endl;
     
     

     }
}

/*
void Menu::elegir_opcion(int opcion_elegida){
      this -> opcion_elegida = opcion_elegida;
}
*/



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


Menu::~Menu(){

}

