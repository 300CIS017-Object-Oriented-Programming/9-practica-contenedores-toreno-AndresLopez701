#include "Videojuego.h"
#include <iostream>

using namespace std;

// Constructor con validación de nivel de dificultad
Videojuego::Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->genero = genero;
    setNivelDificultad(nivelDificultad); // Usa el setter para validar
}

// Getters
std::string Videojuego::getCodigo() const {
    return codigo;
}

std::string Videojuego::getNombre() const {
    return nombre;
}

std::string Videojuego::getGenero() const {
    return genero;
}

int Videojuego::getNivelDificultad() const {
    return nivelDificultad;
}

// Setter con validación
void Videojuego::setNivelDificultad(int nuevoNivel) {
    if (nuevoNivel >= 1 && nuevoNivel <= 5) {
        nivelDificultad = nuevoNivel;
    } else {
        cout << "⚠️ Error: El nivel de dificultad debe estar entre 1 y 5." << endl;
        nivelDificultad = 1; // Valor por defecto
    }
}

// Método para mostrar los datos del videojuego
void Videojuego::mostrarDatos() const {
    cout << "🎮 Videojuego: " << nombre << " (Código: " << codigo << ")" << endl;
    cout << "   Género: " << genero << " | Dificultad: " << nivelDificultad << "/5" << endl;
}
