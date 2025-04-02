#include "Jugador.h"
#include <iostream>

using namespace std;

// Constructor con validación de nivelRanking
Jugador::Jugador(string nickname, int nivelRanking) {
    this->nickname = nickname;
    setNivelRanking(nivelRanking);  // Usa el setter para validar
}

// Getters
#include "Jugador.h"

// Constructor
Jugador::Jugador(std::string nickname, int nivelRanking)
    : nickname(nickname), nivelRanking(nivelRanking) {}

// Getters
std::string Jugador::getNickname() const {
    return nickname;
}

int Jugador::getNivelRanking() const {
    return nivelRanking;
}

// Setters
void Jugador::setNivelRanking(int nuevoNivel) {
    if (nuevoNivel >= 1 && nuevoNivel <= 100) {
        nivelRanking = nuevoNivel;
    } else {
        std::cout << "⚠️ Nivel de ranking fuera de rango (1-100)." << std::endl;
    }
}

// Inscribir jugador en un videojuego (evita duplicados)
bool Jugador::inscribirEnVideojuego(Videojuego* videojuego) {
    for (auto* vj : videojuegosInscritos) {
        if (vj->getCodigo() == videojuego->getCodigo()) {
            std::cout << "⚠️ El jugador ya está inscrito en este videojuego." << std::endl;
            return false;
        }
    }
    videojuegosInscritos.push_back(videojuego);
    return true;
}

// Mostrar videojuegos en los que está inscrito el jugador
void Jugador::mostrarVideojuegosInscritos() const {
    std::cout << "🎮 Videojuegos de " << nickname << ":" << std::endl;
    if (videojuegosInscritos.empty()) {
        std::cout << "   (No está inscrito en ningún videojuego)" << std::endl;
        return;
    }
    for (const auto* videojuego : videojuegosInscritos) {
        std::cout << "   - " << videojuego->getNombre() << " (Dificultad: "
                  << videojuego->getNivelDificultad() << ")" << std::endl;
    }
}

// Calcular promedio de dificultad de los videojuegos inscritos
double Jugador::calcularPromedioDificultad() const {
    if (videojuegosInscritos.empty()) return 0.0;

    int sumaDificultad = 0;
    for (const auto* videojuego : videojuegosInscritos) {
        sumaDificultad += videojuego->getNivelDificultad();
    }
    return static_cast<double>(sumaDificultad) / videojuegosInscritos.size();
}

// Mostrar datos del jugador
void Jugador::mostrarDatos() const {
    std::cout << "👾 Jugador: " << nickname << " | Ranking: " << nivelRanking << std::endl;
}
