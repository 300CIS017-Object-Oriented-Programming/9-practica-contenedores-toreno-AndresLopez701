#include <iostream>
#include "Videojuego.h"
#include "Jugador.h"

using namespace std;

int main() {
    // Crear un videojuego de prueba
    Videojuego juego1("COD123", "Call of Duty", "FPS", 4);

    // Crear un jugador de prueba
    Jugador jugador1("PlayerOne", 75);

    // Mostrar información de los objetos creados
    cout << "Información del videojuego:" << endl;
    juego1.mostrar();
    cout << endl;

    cout << "Información del jugador:" << endl;
    jugador1.mostrar();
    cout << endl;

    return 0;
}
