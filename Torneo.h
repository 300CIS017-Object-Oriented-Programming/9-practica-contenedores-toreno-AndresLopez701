#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
using namespace std;

class Videojuego {
private:
    string codigo;
    string nombre;
    string genero;
    int nivelDificultad;

public:
    // Constructor
    Videojuego(string cod, string nom, string gen, int nivel);

    // Método para mostrar datos del videojuego
    void mostrar();
};

#endif // VIDEOJUEGO_H
