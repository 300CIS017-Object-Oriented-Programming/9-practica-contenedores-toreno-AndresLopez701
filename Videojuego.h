#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>

class Videojuego {
private:
    std::string codigo;  // Código único del videojuego
    std::string nombre;
    std::string genero;
    int nivelDificultad; // Rango de 1 (fácil) a 5 (difícil)

public:
    // Constructor
    Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad);

    // Getters
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getGenero() const;
    int getNivelDificultad() const;

    // Setters con validación
    void setNivelDificultad(int nuevoNivel);

    // Mostrar información del videojuego
    void mostrarDatos() const;
};

#endif // VIDEOJUEGO_H
