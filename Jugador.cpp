#include "Jugador.h"

// Constructor
Jugador::Jugador(string nick, int nivel) {
    nickname = nick;
    nivelRanking = nivel;
}

// Método para mostrar los datos del jugador
void Jugador::mostrar() {
    cout << "Nickname: " << nickname << endl;
    cout << "Nivel de Ranking: " << nivelRanking << endl;
}
