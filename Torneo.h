#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>
#include <map>
#include <vector>
#include "Videojuego.h"
#include "Jugador.h"

class Torneo {
private:
    std::map<std::string, Videojuego*> videojuegosDisponibles; // Catálogo oficial de videojuegos
    std::map<std::string, Jugador*> jugadoresRegistrados; // Jugadores en el torneo

public:
    // Constructor y destructor
    Torneo() = default;
    ~Torneo();

    // Métodos de gestión de videojuegos
    void registrarVideojuego(const std::string& codigo, const std::string& nombre, const std::string& genero, int nivelDificultad);
    void mostrarVideojuegos() const;

    // Métodos de gestión de jugadores
    void registrarJugador(const std::string& nickname, int nivelRanking);
    void mostrarJugadores() const;

    // Inscripciones y consultas
    void inscribirJugadorEnVideojuego(const std::string& nickname, const std::string& codigoVideojuego);
    void mostrarJuegosDeJugador(const std::string& nickname) const;
    void calcularPromedioDificultad(const std::string& nickname) const;

    // Métodos de inicialización
    void inicializarVideojuegos();
    void inicializarJugadores();
};

#endif // TORNEO_H
