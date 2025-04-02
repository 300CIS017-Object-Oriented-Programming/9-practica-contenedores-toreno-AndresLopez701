#include <iostream>
#include "Videojuego.h"
#include "Jugador.h"
#include "Torneo.h"

using namespace std;

int main() {
    // Crear un torneo
    Torneo torneo("Campeonato Gamer 2025");

    // Crear algunos videojuegos
    Videojuego juego1("COD123", "Call of Duty", "FPS", 4);
    Videojuego juego2("LOL456", "League of Legends", "MOBA", 5);

    // Crear algunos jugadores
    Jugador jugador1("PlayerOne", 75);
    Jugador jugador2("GamerX", 60);

    // Inscribir jugadores en videojuegos
    jugador1.inscribirEnVideojuego(&juego1);
    jugador1.inscribirEnVideojuego(&juego2);
    jugador2.inscribirEnVideojuego(&juego2);

    // Agregar jugadores al torneo
    torneo.agregarJugador(&jugador1);
    torneo.agregarJugador(&jugador2);

    // Agregar videojuegos al torneo
    torneo.agregarVideojuego(&juego1);
    torneo.agregarVideojuego(&juego2);

    // Mostrar la información del torneo
    torneo.mostrarTorneo();

    return 0;
}
