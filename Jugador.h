#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include "Videojuego.h"

class Jugador {
private:
    std::string nickname;
    int nivelRanking;
    std::vector<Videojuego*> videojuegosInscritos; // Videojuegos en los que está inscrito

public:
    // Constructor
    Jugador(std::string nickname, int nivelRanking);

    // Getters
    std::string getNickname() const;
    int getNivelRanking() const;

    // Setters
    void setNivelRanking(int nuevoNivel);

    // Métodos para gestionar inscripciones
    bool inscribirEnVideojuego(Videojuego* videojuego);
    void mostrarVideojuegosInscritos() const;
    double calcularPromedioDificultad() const;

    // Mostrar información del jugador
    void mostrarDatos() const;
};

#endif // JUGADOR_H
