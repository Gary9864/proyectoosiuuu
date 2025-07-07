#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

// Structure for decisions
struct Decision {
    string texto;
    string consecuencia;
};

// Structure for a level
struct Nivel {
    string situacion;
    Decision decisiones[3];
    string premio;
    int opcionGanadora; // index (0, 1, 2)
};

// Structure for adventure
struct Aventura {
    string nombre;
    Nivel niveles[5];
};

// Configuration for minigames: enable and type per level (5 levels)
struct ConfigMinijuegos {
    bool activar[5];  // true if there is a minigame at that level
    int tipo[9];      // minigame type: 1=Memory, 2=Treasure, 3=Simon, 4=Count etc
};

// Global variables

extern bool aventurasJugadas[3];
extern string premiosJugador[20];
extern int cantidadPremios;
extern string nombreJugador;

// Function declarations
//function to add reward
void agregarPremio(string premio);
//function to show rewards
void mostrarPremios();
//function to play level
bool jugarNivel(const Nivel& nivel, const ConfigMinijuegos& config, int indiceNivel);
//vvoid jugarNivel(const Nivel& nivel); 
//function to play adventure
void jugarAventura(const Aventura& aventura, const ConfigMinijuegos& config);
//function to try to play adventure, to validate how many times an adventure has been played
void intentarJugarAventura(const Aventura& aventura, int indiceAventura, const ConfigMinijuegos& config);
//function for game introduction
void introduccionJuego();
//function to save progress using files
void guardarProgreso(string nombre, string aventuras, string premios);
//read progress and call it
void leerProgreso();
//functions to configure the minigames
ConfigMinijuegos obtenerConfigNerysia();
ConfigMinijuegos obtenerConfigInfernum();
ConfigMinijuegos obtenerConfigThornia();

// Minigame declarations
void minijuegoMemoria();
void minijuegoTesoro();
void minijuegoSimon();
void minijuegoContar();
string minijuegoDuelo();
void minijuegoPesca();
void minijuegoObjetosPerdidos();
void abrirCofre();
void elegirPuerta();

// Adventure declarations
extern Aventura nerysia;
extern Aventura infernum;
extern Aventura thornia;

#endif