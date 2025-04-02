#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>
#include <map>
#include <string>
#include "Jugador.h"
#include "Videojuego.h"

using namespace std;

class Torneo {
private:
    string nombre;
    map<string, Jugador*> jugadoresRegistrados;  // Mapa de jugadores registrados, usando su nickname como clave
    map<string, Videojuego*> videojuegosDisponibles;  // Mapa de videojuegos disponibles, usando el código como clave

public:
    // Constructor
    Torneo(string nom);

    // Métodos para agregar jugadores y videojuegos al torneo
    void agregarJugador(Jugador* jugador);
    void agregarVideojuego(Videojuego* videojuego);

    // Inscribir un jugador en un videojuego
    void inscribirJugadorEnVideojuego(string nickname, string codigo);

    // Mostrar los videojuegos en los que un jugador está inscrito
    void mostrarVideojuegosDeJugador(string nickname);
};

#endif // TORNEO_H
