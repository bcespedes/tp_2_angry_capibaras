#include "escritor.h"

Escritor::Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento){
    nombre_ = nombre;
    apellido_ = apellido;
    nacionalidad_ = nacionalidad;
    anio_nacimiento_ = anio_nacimiento;
    anio_fallecimiento_ = anio_fallecimiento;
}





string Escritor::devolver_nombre_completo(){
    return (nombre_ + " ") + apellido_;
};

string Escritor::devolver_nacionalidad(){
    return nacionalidad_;
}

void Escritor::fallecimiento(int anio){
    if(anio_fallecimiento_ == -1)
        anio_fallecimiento_ = anio;
}

void Escritor::mostrar_escritor(){

    cout << devolver_nombre_completo() << endl;
    cout << "Nacionalidad: " << nacionalidad_ << endl;
    if(anio_fallecimiento_ != -1 && anio_nacimiento_ != -1)
        cout << anio_nacimiento_ << " - " << anio_fallecimiento_ << endl;
    else cout << anio_nacimiento_ << " - " << "actualidad o desconocido" << endl;

}

Escritor::Escritor(){
}