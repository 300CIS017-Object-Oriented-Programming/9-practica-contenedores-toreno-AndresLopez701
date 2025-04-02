#include "Torneo.h"

// Constructor
Torneo::Torneo(string nom) {
    nombre = nom;
}

// Agregar jugador al torneo
void Torneo::agregarJugador(Jugador* jugador) {
    // Añadir el jugador al mapa de jugadores registrados
    jugadoresRegistrados[jugador->getNickname()] = jugador;
}

// Agregar videojuego al torneo
void Torneo::agregarVideojuego(Videojuego* videojuego) {
    // Añadir el videojuego al catálogo de videojuegos disponibles
    videojuegosDisponibles[videojuego->getCodigo()] = videojuego;
}

// Inscribir jugador en un videojuego
void Torneo::inscribirJugadorEnVideojuego(string nickname, string codigo) {
    // Verificar si el jugador y el videojuego existen
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end() &&
        videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {

        Jugador* jugador = jugadoresRegistrados[nickname];
        Videojuego* videojuego = videojuegosDisponibles[codigo];

        // Inscribir al jugador en el videojuego
        jugador->inscribirEnVideojuego(videojuego);
        cout << "Jugador " << nickname << " inscrito en el videojuego " << videojuego->getNombre() << endl;
        } else {
            cout << "Error: Jugador o videojuego no encontrado." << endl;
        }
}

// Mostrar los videojuegos en los que un jugador está inscrito
void Torneo::mostrarVideojuegosDeJugador(string nickname) {
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {
        Jugador* jugador = jugadoresRegistrados[nickname];
        cout << "Videojuegos en los que está inscrito el jugador " << nickname << ":" << endl;

        for (auto videojuego : jugador->getVideojuegosInscritos()) {
            videojuego->mostrar();
            cout << endl;
        }
    } else {
        cout << "Error: Jugador no encontrado." << endl;
    }
}
