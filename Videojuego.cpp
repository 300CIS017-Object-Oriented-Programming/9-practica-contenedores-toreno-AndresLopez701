#include "Videojuego.h"

// Constructor
Videojuego::Videojuego(string cod, string nom, string gen, int clasif) {
    codigo = cod;
    nombre = nom;
    genero = gen;
    clasificacion = clasif;
}

// Método para mostrar datos del videojuego
void Videojuego::mostrar() {
    cout << "Código: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Clasificación: " << clasificacion << endl;
}

// Métodos adicionales si necesitas obtener los atributos
string Videojuego::getCodigo() const {
    return codigo;
}

string Videojuego::getNombre() const {
    return nombre;
}

int Videojuego::getClasificacion() const {
    return clasificacion;
}
