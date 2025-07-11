/*#include <iostream>
#include "src/def.cpp"
using namespace std;

int main() { 
   
    string entrada;
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
        cin >> entrada;

 // Validate that the input contains only digits

        bool esNumero = true;
        for (char c : entrada) {
            if (c < '0' || c > '9') {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "Entrada inválida. Debes escribir solo números.\n";
            continue;
        }

        opcion = stoi(entrada); // Convert only if it was validated

        
        switch (opcion) {
            case 1:
                intentarJugarAventura(nerysia, 0, obtenerConfigNerysia());
                break;
            case 2:
                intentarJugarAventura(infernum, 1, obtenerConfigInfernum());
                break;
            case 3:
                intentarJugarAventura(thornia, 2, obtenerConfigThornia());
                break;
            case 4:
                mostrarPremios();
                break;
            case 0:
                cout << "Hasta pronto, " << nombreJugador << "!!!!!\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}*/#include <iostream>
#include "src/def.cpp"
using namespace std;

int main() {
    string entrada;
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
        cin >> entrada;

        // Validate that it is a valid integer number

        bool esNumero = true;
        for (char c : entrada) {
            if (c < '0' || c > '9') {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "Entrada invalida. Debes ingresar solo numeros.\n";
            continue;
        }

        opcion = stoi(entrada);

        switch (opcion) {
            case 1:
                intentarJugarAventura(nerysia, 0, obtenerConfigNerysia());
                break;
            case 2:
                intentarJugarAventura(infernum, 1, obtenerConfigInfernum());
                break;
            case 3:
                intentarJugarAventura(thornia, 2, obtenerConfigThornia());
                break;
            case 4:
                mostrarPremios();
                break;
            case 0:
                cout << "Hasta pronto, " << nombreJugador << "!!!!!\n";
                break;
            default:
                cout << "Opcion invalida. Elige entre 0 y 4.\n";
        }
    } while (opcion != 0);

    return 0;
}
