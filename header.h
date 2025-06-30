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
void jugarNivel(const Nivel& nivel);
//funcion jugar aventura
void jugarAventura(const Aventura& aventura);
//funcion intentar jugar aventura para validar las veces que ha jugado una aventura
void intentarJugarAventura(const Aventura& aventura, int indiceAventura);
//funcion introduccion al juego
void introduccionJuego();
//funcion para guardar proceso y hacer uso de archivos
void guardarProgreso(string nombre, string aventuras, string premios);
void leerProgreso();
//funcion para usar matrices mostrando los universos a los que ha ido


// Declaración de aventuras
extern Aventura nerysia;
extern Aventura infernum;
extern Aventura thornia;

#endif
