#include <iostream>
#include "Videojuego.h"
#include "Jugador.h"

using namespace std;

int main() {
    // Crear algunos videojuegos de prueba
    Videojuego juego1("COD123", "Call of Duty", "FPS", 4);
    Videojuego juego2("LOL456", "League of Legends", "MOBA", 3);

    // Crear un jugador de prueba
    Jugador jugador1("PlayerOne", 75);

    // Mostrar información del jugador
    cout << "Información del jugador antes de inscripciones:" << endl;
    jugador1.mostrar();
    cout << endl;

    // Inscribir al jugador en los videojuegos
    jugador1.inscribirEnVideojuego(&juego1);
    jugador1.inscribirEnVideojuego(&juego2);

    // Mostrar los videojuegos en los que el jugador está inscrito
    cout << "Videojuegos en los que el jugador está inscrito:" << endl;
    for (auto videojuego : jugador1.getVideojuegosInscritos()) {
        videojuego->mostrar();
        cout << endl;
    }

    return 0;
}
