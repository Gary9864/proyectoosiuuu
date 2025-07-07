#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

// Estructura para decisiones
struct Decision {
    string texto;
    string consecuencia;
};

// Estructura para un nivel
struct Nivel {
    string situacion;
    Decision decisiones[3];
    string premio;
    int opcionGanadora; // índice (0, 1, 2)
};

// Estructura para aventura
struct Aventura {
    string nombre;
    Nivel niveles[5];
};

// Configuración para minijuegos: activar y tipo por nivel (5 niveles)
struct ConfigMinijuegos {
    bool activar[5];  // true si hay minijuego en ese nivel
    int tipo[7];      // tipo de minijuego: 1=Memoria, 2=Tesoro, 3=Simon, 4=Contar
};

// Variables globales

extern bool aventurasJugadas[3];
extern string premiosJugador[20];
extern int cantidadPremios;
extern string nombreJugador;

// Declaración de funciones
//funcion agregar premio
void agregarPremio(string premio);
//funcion mostrar premios
void mostrarPremios();
//funcion jugar nivel
bool jugarNivel(const Nivel& nivel, const ConfigMinijuegos& config, int indiceNivel);
//void jugarNivel(const Nivel& nivel);
//funcion jugar aventura
void jugarAventura(const Aventura& aventura, const ConfigMinijuegos& config);
//funcion intentar jugar aventura para validar las veces que ha jugado una aventura
void intentarJugarAventura(const Aventura& aventura, int indiceAventura, const ConfigMinijuegos& config);
//funcion introduccion al juego
void introduccionJuego();
//funcion para guardar proceso y hacer uso de archivos
void guardarProgreso(string nombre, string aventuras, string premios);
//leemos progreso y lo mandamos a llamar
void leerProgreso();
//funciones para configurar los minijuegos
ConfigMinijuegos obtenerConfigNerysia();
ConfigMinijuegos obtenerConfigInfernum();
ConfigMinijuegos obtenerConfigThornia();

// Declaración de minijuegos
void minijuegoMemoria();
void minijuegoTesoro();
void minijuegoSimon();
void minijuegoContar();
string minijuegoDuelo();
void minijuegoPesca();
void minijuegoObjetosPerdidos();


// Declaración de aventuras
extern Aventura nerysia;
extern Aventura infernum;
extern Aventura thornia;

#endif