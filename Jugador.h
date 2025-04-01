#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
    string nickname;
    int nivelRanking;

public:
    // Constructor
    Jugador(string nick, int nivel);

    // Método para mostrar datos del jugador
    void mostrar();
};

#endif // JUGADOR_H
