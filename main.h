#include <iostream>
#include "Torneo.h"

using namespace std;

void mostrarMenu() {
    cout << "\n🎮 MENÚ DEL TORNEO 🎮\n";
    cout << "1️⃣ Registrar un videojuego\n";
    cout << "2️⃣ Registrar un jugador\n";
    cout << "3️⃣ Inscribir jugador en videojuego\n";
    cout << "4️⃣ Mostrar videojuegos de un jugador\n";
    cout << "5️⃣ Calcular promedio de dificultad\n";
    cout << "6️⃣ Mostrar todos los jugadores\n";
    cout << "7️⃣ Mostrar todos los videojuegos\n";
    cout << "0️⃣ Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Torneo torneo;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Evita problemas con el buffer

        switch (opcion) {
            case 1: { // Registrar videojuego
                string codigo, nombre, genero;
                int dificultad;

                cout << "Ingrese código del videojuego: ";
                getline(cin, codigo);
                cout << "Ingrese nombre del videojuego: ";
                getline(cin, nombre);
                cout << "Ingrese género: ";
                getline(cin, genero);
                cout << "Ingrese nivel de dificultad (1-5): ";
                cin >> dificultad;

                if (torneo.registrarVideojuego(codigo, nombre, genero, dificultad)) {
                    cout << "✅ Videojuego registrado con éxito.\n";
                } else {
                    cout << "❌ Error: El videojuego ya existe o dificultad inválida.\n";
                }
                break;
            }

            case 2: { // Registrar jugador
                string nickname;
                int ranking;

                cout << "Ingrese nickname del jugador: ";
                getline(cin, nickname);
                cout << "Ingrese nivel de ranking (1-100): ";
                cin >> ranking;

                if (torneo.registrarJugador(nickname, ranking)) {
                    cout << "✅ Jugador registrado con éxito.\n";
                } else {
                    cout << "❌ Error: El jugador ya existe o ranking inválido.\n";
                }
                break;
            }

            case 3: { // Inscribir jugador en videojuego
                string nickname, codigo;

                cout << "Ingrese nickname del jugador: ";
                getline(cin, nickname);
                cout << "Ingrese código del videojuego: ";
                getline(cin, codigo);

                if (torneo.inscribirJugadorEnVideojuego(nickname, codigo)) {
                    cout << "✅ Inscripción exitosa.\n";
                } else {
                    cout << "❌ Error: Jugador o videojuego inexistente, o ya inscrito.\n";
                }
                break;
            }

            case 4: { // Mostrar videojuegos de un jugador
                string nickname;
                cout << "Ingrese nickname del jugador: ";
                getline(cin, nickname);
                torneo.mostrarVideojuegosDeJugador(nickname);
                break;
            }

            case 5: { // Calcular promedio de dificultad
                string nickname;
                cout << "Ingrese nickname del jugador: ";
                getline(cin, nickname);
                torneo.mostrarPromedioDificultad(nickname);
                break;
            }

            case 6: // Mostrar jugadores registrados
                torneo.mostrarJugadores();
                break;

            case 7: // Mostrar videojuegos disponibles
                torneo.mostrarVideojuegos();
                break;

            case 0: // Salir
                cout << "👋 Saliendo del sistema. ¡Hasta pronto!\n";
                break;

            default:
                cout << "⚠️ Opción inválida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
