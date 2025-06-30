#include <iostream>
#include "src/def.cpp"
using namespace std;

int main() {
    int opcion;
    introduccionJuego();

    do {
        cout << "\n=== Selecciona una aventura ===\n";
        cout << "1. Nerysia (Mundo de Agua)\n";
        cout << "2. Infernum (Mundo de Fuego)\n";
        cout << "3. Thornia (Mundo Apocaliptico)\n";
        cout << "4. Mostrar progreso\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                intentarJugarAventura(nerysia, 0);
                break;
            case 2:
                intentarJugarAventura(infernum, 1);
                break;
            case 3:
                intentarJugarAventura(thornia, 2);
                break;
            case 4:
                mostrarPremios();
                break;
            case 0:
                cout << "¡Hasta pronto, " << nombreJugador << "!\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}