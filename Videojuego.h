#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
using namespace std;

class Videojuego {
private:
    string codigo;
    string nombre;
    string genero;
    int clasificacion;

public:
    // Constructor
    Videojuego(string cod, string nom, string gen, int clasif);

    // Métodos para obtener los datos del videojuego
    string getCodigo() const;
    string getNombre() const;
    int getClasificacion() const;

    // Método para mostrar datos del videojuego
    void mostrar();
};

#endif // VIDEOJUEGO_H
