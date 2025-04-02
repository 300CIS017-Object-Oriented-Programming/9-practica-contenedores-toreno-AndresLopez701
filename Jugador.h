#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include "Videojuego.h"  // Asegúrate de incluir Videojuego.h si estás manejando videojuegos en esta clase.

using namespace std;

class Jugador {
private:
    string nickname;
    int nivelRanking;
    vector<Videojuego*> videojuegosInscritos;  // Vector de punteros a Videojuego

public:
    // Constructor
    Jugador(string nick, int nivel);

    // Métodos
    void mostrar();  // Mostrar datos del jugador
    void inscribirEnVideojuego(Videojuego* videojuego);  // Método para inscribir un jugador en un videojuego
    vector<Videojuego*> getVideojuegosInscritos();  // Método para obtener los videojuegos en los que está inscrito el jugador
};

#endif // JUGADOR_H
