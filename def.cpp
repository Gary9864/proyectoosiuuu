#include "header.h"
#include <iostream>
#include <fstream>

// Variables globales
bool aventurasJugadas[3] = {false, false, false};
string premiosJugador[20];
int cantidadPremios = 0;
string nombreJugador;

// Aventuras definidas

Aventura nerysia = {
    "Nerysia (Mundo de Agua)",
    {
        {"Los peces globo atacan la aldea.", 
            {{"Usar espinas", "Asustas a los peces y se van."},
             {"Usar espada", "Te lastimas pero logras defenderte."},
             {"Usar tinta", "Los confundes y huyen asustados."}},
        "Perla brillante", 2},

        {"Un tiburon bloquea el paso.",
            {{"Calmarlo", "Logras calmarlo y se hace tu aliado."},
             {"Huir", "Escapas pero pierdes provisiones."},
             {"Pelear", "Lo vences pero quedas herido."}},
        "Cola de sirena", 0},

        {"Corrientes peligrosas te arrastran.",
            {{"Nadar contra corriente", "Gastas energía pero sobrevives."},
             {"Buscar refugio", "Encuentras una cueva segura."},
             {"Dejarse llevar", "Te alejas demasiado del objetivo."}},
        "Concha mágica", 1},

        {"Encuentras un cofre cerrado.",
            {{"Forzarlo", "Se rompe y pierdes parte del tesoro."},
             {"Buscar la llave", "Encuentras la llave y abres sin daño."},
             {"Ignorarlo", "Te pierdes el tesoro pero sigues sano."}},
        "Perla negra", 1},

        {"Una gran medusa aparece.",
            {{"Atacar", "La derrotas con dificultad."},
             {"Esquivar", "Logras esquivarla ileso."},
             {"Dialogar", "Sorprendentemente te ayuda."}},
        "Tridente marino", 2}
    }
};

Aventura infernum = {
    "Infernum (Mundo de Fuego)",
    {
        {"El volcán comienza a rugir.",
            {{"Escalar", "Subes rápido pero te quemas."},
             {"Esperar", "El volcán se calma un poco."},
             {"Buscar ruta alterna", "Encuentras un camino seguro."}},
        "Gema ardiente", 2},

        {"Un golem de lava te ataca.",
            {{"Luchar", "Ganas pero te quemas."},
             {"Usar agua", "Lo derrotas sin daño."},
             {"Huir", "Escapas con heridas leves."}},
        "Escama ígnea", 1},

        {"Rocas incandescentes bloquean el paso.",
            {{"Saltar", "Cruzas con riesgo alto."},
             {"Romperlas", "Requiere fuerza y tiempo."},
             {"Rodear", "Tomas camino largo pero seguro."}},
        "Anillo volcánico", 2},

        {"Encuentras un lago de lava.",
            {{"Construir puente", "Tarda pero cruzas bien."},
             {"Volar sobre él", "Cruzas rápido con magia."},
             {"Atravesar directo", "Te quemas gravemente."}},
        "Pluma fénix", 1},

        {"El coloso ardiente aparece.",
            {{"Atacar frontal", "Lo vences con gran esfuerzo."},
             {"Debilitar primero", "Lo haces vulnerable y vences."},
             {"Huir", "Te salvas pero pierdes mucho."}},
        "Corona ígnea", 1}
    }
};

Aventura thornia = {
    "Thornia (Mundo Apocaliptico)",
    {
        {"Lianas mutantes bloquean el camino.",
            {{"Cortarlas", "Las vences pero te hieres."},
             {"Quemarlas", "Las destruyes completamente."},
             {"Buscar atajo", "Tomas ruta segura."}},
        "Espina venenosa", 2},

        {"Te ataca un enjambre tóxico.",
            {{"Defenderse", "Te defiendes pero quedas débil."},
             {"Correr", "Escapas ileso."},
             {"Usar humo", "Ahuyentas al enjambre."}},
        "Antídoto especial", 1},

        {"Encuentras un laboratorio abandonado.",
            {{"Investigar", "Descubres recursos útiles."},
             {"Ignorar", "No arriesgas nada."},
             {"Destruir", "Evitas riesgos futuros."}},
        "Sérum mutante", 0},

        {"Mutantes te rodean.",
            {{"Negociar", "Te ayudan a cambio de recursos."},
             {"Luchar", "Ganas pero pierdes equipo."},
             {"Esconderse", "No te encuentran pero pierdes tiempo."}},
        "Máscara táctica", 0},

        {"Planta reina te enfrenta.",
            {{"Quemarla", "La destruyes con fuego."},
             {"Envenenarla", "La debilitas y vences."},
             {"Dialogar", "Logras un acuerdo de paz."}},
        "Flor de cristal", 2}
    }
};

// Funciones

void agregarPremio(string premio) {
    if (cantidadPremios < 20) {
        premiosJugador[cantidadPremios++] = premio;
    }
}

void mostrarPremios() {
    cout << "\n--- Premios obtenidos ---\n";
    if (cantidadPremios == 0) {
        cout << "No tienes premios aún.\n";
    } else {
        for (int i = 0; i < cantidadPremios; i++) {
            cout << i + 1 << ". " << premiosJugador[i] << "\n";
        }
    }
    cout << endl;
}

void jugarNivel(const Nivel& nivel) {
    cout << "\nSituacion: " << nivel.situacion << "\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << nivel.decisiones[i].texto << "\n";
    }

    int opcion;
    do {
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Intenta de nuevo.\n";
        }
    } while (opcion < 1 || opcion > 3);

    cout << "\n" << nivel.decisiones[opcion - 1].consecuencia << "\n";

    if ((opcion - 1) == nivel.opcionGanadora) {
        cout << "¡Ganaste el premio: " << nivel.premio << "!\n";
        agregarPremio(nivel.premio);
    } else {
        cout << "Sobreviviste, pero sin premio.\n";
    }
}

void jugarAventura(const Aventura& aventura) {
    cout << "\n--- Bienvenido a " << aventura.nombre << " ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "\n--- Nivel " << i + 1 << " ---";
        jugarNivel(aventura.niveles[i]);
    }
    cout << "\n¡Has completado la aventura!\n";
}

void intentarJugarAventura(const Aventura& aventura, int indiceAventura) {
    if (indiceAventura < 0 || indiceAventura >= 3) {
        cout << "Indice de aventura invalido.\n";
        return;
    }
    if (aventurasJugadas[indiceAventura]) {
        cout << "\nYa jugaste la aventura \"" << aventura.nombre << "\" anteriormente.\n";
    } else {
        jugarAventura(aventura);
        aventurasJugadas[indiceAventura] = true;
    }
}

void introduccionJuego() {
    cout << "Antes de comenzar, dime tu nombre: ";
    cin >> nombreJugador;
    cout << "\nMuy bien, " << nombreJugador << ". Prepárate para tu destino...\n";
}

void guardarProgreso(string nombre, string aventuras, string premios) {
    ofstream archivo("progreso.txt");
    archivo << "Nombre: " << nombre << endl;
    archivo << "Aventuras completadas: " << aventuras << endl;
    archivo << "Premios: " << premios << endl;
    archivo.close();
}

void leerProgreso() {
    ifstream archivo("progreso.txt");
    string linea;
    if (!archivo.is_open()) {
        cout << "No hay progreso guardado.\n";
        return;
    }
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}
char universos[3][3];

void inicializarUniversos() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            universos[i][j] = '-';
}

void marcarVisitado(int f, int c) {
    universos[f][c] = 'V';
}

void mostrarUniversos() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << universos[i][j] << " ";
        cout << endl;
    }
}                                                                       