#include "Torneo.h"

Torneo::~Torneo() {
    // Liberar memoria de los videojuegos registrados
    for (auto& par : videojuegosDisponibles) {
        delete par.second;
    }
    // Liberar memoria de los jugadores registrados
    for (auto& par : jugadoresRegistrados) {
        delete par.second;
    }
}

void Torneo::registrarVideojuego(const std::string& codigo, const std::string& nombre, const std::string& genero, int nivelDificultad) {
    if (videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {
        std::cout << "Error: El videojuego con código " << codigo << " ya está registrado.\n";
        return;
    }
    if (nivelDificultad < 1 || nivelDificultad > 5) {
        std::cout << "Error: El nivel de dificultad debe estar entre 1 y 5.\n";
        return;
    }

    videojuegosDisponibles[codigo] = new Videojuego(codigo, nombre, genero, nivelDificultad);
    std::cout << "Videojuego registrado con éxito.\n";
}

void Torneo::mostrarVideojuegos() const {
    if (videojuegosDisponibles.empty()) {
        std::cout << "No hay videojuegos registrados.\n";
        return;
    }
    std::cout << "Lista de videojuegos disponibles:\n";
    for (const auto& par : videojuegosDisponibles) {
        std::cout << "- " << par.second->getNombre() << " (Género: " << par.second->getGenero() << ", Dificultad: " << par.second->getNivelDificultad() << ")\n";
    }
}

void Torneo::registrarJugador(const std::string& nickname, int nivelRanking) {
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {
        std::cout << "Error: El jugador con nickname " << nickname << " ya está registrado.\n";
        return;
    }
    if (nivelRanking < 1 || nivelRanking > 100) {
        std::cout << "Error: El nivel de ranking debe estar entre 1 y 100.\n";
        return;
    }

    jugadoresRegistrados[nickname] = new Jugador(nickname, nivelRanking);
    std::cout << "Jugador registrado con éxito.\n";
}

void Torneo::mostrarJugadores() const {
    if (jugadoresRegistrados.empty()) {
        std::cout << "No hay jugadores registrados.\n";
        return;
    }
    std::cout << "Lista de jugadores registrados:\n";
    for (const auto& par : jugadoresRegistrados) {
        std::cout << "- " << par.second->getNombre() << " (Ranking: " << par.second->getNivelRanking() << ")\n";
    }
}

void Torneo::inscribirJugadorEnVideojuego(const std::string& nickname, const std::string& codigoVideojuego) {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Error: No existe un jugador con nickname " << nickname << ".\n";
        return;
    }
    if (videojuegosDisponibles.find(codigoVideojuego) == videojuegosDisponibles.end()) {
        std::cout << "Error: No existe un videojuego con código " << codigoVideojuego << ".\n";
        return;
    }

    Jugador* jugador = jugadoresRegistrados[nickname];
    Videojuego* videojuego = videojuegosDisponibles[codigoVideojuego];

    if (jugador->estaInscritoEn(videojuego)) {
        std::cout << "Error: El jugador ya está inscrito en este videojuego.\n";
        return;
    }

    jugador->inscribirEnVideojuego(videojuego);
    std::cout << "Jugador inscrito con éxito en el videojuego " << videojuego->getNombre() << ".\n";
}

void Torneo::mostrarJuegosDeJugador(const std::string& nickname) const {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Error: No existe un jugador con nickname " << nickname << ".\n";
        return;
    }

    jugadoresRegistrados.at(nickname)->mostrarVideojuegos();
}

void Torneo::calcularPromedioDificultad(const std::string& nickname) const {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Error: No existe un jugador con nickname " << nickname << ".\n";
        return;
    }

    double promedio = jugadoresRegistrados.at(nickname)->calcularPromedioDificultad();
    std::cout << "El promedio de dificultad de los videojuegos inscritos por " << nickname << " es: " << promedio << "\n";
}

void Torneo::inicializarVideojuegos() {
    registrarVideojuego("COD123", "Call of Duty", "FPS", 4);
    registrarVideojuego("LOL456", "League of Legends", "MOBA", 3);
}

void Torneo::inicializarJugadores() {
    registrarJugador("PlayerOne", 75);
    registrarJugador("GamerX", 60);
}
